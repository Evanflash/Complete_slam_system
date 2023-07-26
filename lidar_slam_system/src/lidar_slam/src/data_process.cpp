#include "data_process.h"

namespace lidarslam{

static const std::string PARAM_VERTICAL_SCANS = "laser.vertical_scans";
static const std::string PARAM_HORIZONTAL_SCANS = "laser.horizontal_scans";
static const std::string PARAM_ANGLE_BOTTOM = "laser.ang_bottom";
static const std::string PARAM_ANGLE_TOP = "laser.ang_top";
static const std::string PARAM_GROUND_INDEX = "laser.ground_scan_index";
static const std::string PARAM_SENSOR_ANGLE = "laser.sensor_mount_angle";
static const std::string PARAM_SEGMENT_THETA = "projection.segment_theta";
static const std::string PARAM_SEGMENT_VALID_POINT_NUM = "projection.segment_valid_point_num";
static const std::string PARAM_SEGMENT_VALID_LINE_NUM = "projection.segment_valid_line_num";

DataProcess::DataProcess(const std::string &name, Channel<DataProcessOut> &output_channel)
    : Node(name), _output_channel(output_channel)
{
    Cloudmsg = this -> create_subscription<sensor_msgs::msg::PointCloud2>(
        "/velodyne_points", 1, std::bind(&DataProcess::cloudHandler, this, std::placeholders::_1));

    pub_cloud_in = this -> create_publisher<sensor_msgs::msg::PointCloud2>("/cloud_in", 1);
    pub_corner_sharp = this -> create_publisher<sensor_msgs::msg::PointCloud2>("/corner_sharp", 1);
    pub_corner_less_sharp = this -> create_publisher<sensor_msgs::msg::PointCloud2>("/corner_less_sharp", 1);
    pub_surf_flat = this -> create_publisher<sensor_msgs::msg::PointCloud2>("/surf_flat", 1);
    pub_surf_less_flat = this -> create_publisher<sensor_msgs::msg::PointCloud2>("/surf_less_flat", 1);
    pub_segment_cloud = this -> create_publisher<sensor_msgs::msg::PointCloud2>("/segment_cloud", 1);
    pub_ground_cloud = this -> create_publisher<sensor_msgs::msg::PointCloud2>("/ground_cloud", 1);

    // 声明参数
    this -> declare_parameter(PARAM_VERTICAL_SCANS, _vertical_scans);
    this -> declare_parameter(PARAM_HORIZONTAL_SCANS, _horizontal_scans);
    this -> declare_parameter(PARAM_ANGLE_BOTTOM, _ang_bottom);
    this -> declare_parameter(PARAM_ANGLE_TOP, _ang_top);
    this -> declare_parameter(PARAM_GROUND_INDEX, _ground_scan_index);
    this -> declare_parameter(PARAM_SENSOR_ANGLE, _sensor_mount_angle);
    this -> declare_parameter(PARAM_SEGMENT_THETA, _segment_theta);
    this -> declare_parameter(PARAM_SEGMENT_VALID_LINE_NUM, _segment_valid_line_num);

    // 更新参数
    if(!this -> get_parameter(PARAM_VERTICAL_SCANS, _vertical_scans)){
        RCLCPP_WARN(this -> get_logger(), "data_process_node: %s not found", PARAM_VERTICAL_SCANS.c_str());
    }
    if(!this -> get_parameter(PARAM_HORIZONTAL_SCANS, _horizontal_scans)){
        RCLCPP_WARN(this -> get_logger(), "data_process_node: %s not found", PARAM_HORIZONTAL_SCANS.c_str());
    }
    if(!this -> get_parameter(PARAM_ANGLE_BOTTOM, _ang_bottom)){
        RCLCPP_WARN(this -> get_logger(), "data_process_node: %s not found", PARAM_ANGLE_BOTTOM.c_str());
    }
    if(!this -> get_parameter(PARAM_ANGLE_TOP, _ang_top)){
        RCLCPP_WARN(this -> get_logger(), "data_process_node: %s not found", PARAM_ANGLE_TOP.c_str());
    }
    if(!this -> get_parameter(PARAM_GROUND_INDEX, _ground_scan_index)){
        RCLCPP_WARN(this -> get_logger(), "data_process_node: %s not found", PARAM_GROUND_INDEX.c_str());
    }
    if(!this -> get_parameter(PARAM_SENSOR_ANGLE, _sensor_mount_angle)){
        RCLCPP_WARN(this -> get_logger(), "data_process_node: %s not found", PARAM_SENSOR_ANGLE.c_str());
    }
    if(!this -> get_parameter(PARAM_SEGMENT_THETA, _segment_theta)){
        RCLCPP_WARN(this -> get_logger(), "data_process_node: %s not found", PARAM_SEGMENT_THETA.c_str());
    }
    if(!this -> get_parameter(PARAM_SEGMENT_VALID_LINE_NUM, _segment_valid_line_num)){
        RCLCPP_WARN(this -> get_logger(), "data_process_node: %s not found", PARAM_SEGMENT_VALID_LINE_NUM.c_str());
    }

    _ang_resolution_X = (M_PI * 2) / _horizontal_scans;
    _ang_resolution_Y = (M_PI / 180.0) * (_ang_top - _ang_bottom) / float(_vertical_scans - 1);
    _ang_bottom = -(_ang_bottom - 0.1) * (M_PI / 180.0);
    _segment_theta *= (M_PI / 180.0);
    _sensor_mount_angle *= (M_PI / 180.0);


    _run_thread = std::thread(&DataProcess::run, this);

    _cloud_in.reset(new CloudType());
    _full_cloud.reset(new CloudType());
    _full_cloud -> resize(_vertical_scans * _horizontal_scans);

    cornerDownSampleFilter.reset(new pcl::VoxelGrid<PointType>());
    cornerDownSampleFilter -> setLeafSize(0.2, 0.2, 0.2);
    surfDownSampleFilter.reset(new pcl::VoxelGrid<PointType>());
    surfDownSampleFilter -> setLeafSize(0.4, 0.4, 0.4);
}

DataProcess::~DataProcess(){
    _run_thread.join();
}

void DataProcess::cloudHandler(const sensor_msgs::msg::PointCloud2 &laserCloudMsg){
    mtx.lock();
    queClouds.push(laserCloudMsg);
    mtx.unlock();
}

void DataProcess::run(){
    while(rclcpp::ok()){
        if(queClouds.empty()){
            sleep(1);
        }

        mtx.lock();
        oneCloud = queClouds.front();
        queClouds.pop();
        mtx.unlock();

        resetParameters();
        pcl::fromROSMsg(oneCloud, *_cloud_in);
        std::vector<int> indices;
        pcl::removeNaNFromPointCloud(*_cloud_in, *_cloud_in, indices);
        projectPointCloud();
        groundRemoval();
        calculateSmoothness();
        markCornerPoints();
        cornerCloudSegmentation();
        publishCloud();
    }
}


void DataProcess::resetParameters(){
    _cloud_in -> clear();
    _corner_sharp.reset(new CloudType());
    _corner_less_sharp.reset(new CloudType());
    _surf_flat.reset(new CloudType());
    _surf_less_flat.reset(new CloudType());
    _segment_cloud.reset(new CloudType());
    _ground_cloud.reset(new CloudType());

    _full_cloud -> clear();

    const size_t cloud_size = _vertical_scans * _horizontal_scans;
    PointType nanPoint;
    nanPoint.x = std::numeric_limits<float>::quiet_NaN();
    nanPoint.y = std::numeric_limits<float>::quiet_NaN();
    nanPoint.z = std::numeric_limits<float>::quiet_NaN();
    nanPoint.intensity = -1;
    std::fill(_full_cloud->points.begin(), _full_cloud->points.end(), nanPoint);

    _range_mat.resize(_vertical_scans, _horizontal_scans);
    _ground_mat.resize(_vertical_scans, _horizontal_scans);
    _label_mat.resize(_vertical_scans, _horizontal_scans);
    _corner_label.resize(_vertical_scans, _horizontal_scans);

    _range_mat.fill(FLT_MAX);
    _ground_mat.setZero();
    _label_mat.setZero();
    _corner_label.setZero();

    cloudCurvature.clear();
    str_index.resize(_vertical_scans, 0);
    end_index.resize(_vertical_scans, 0);
}

void DataProcess::projectPointCloud(){
    const size_t cloudSize = _cloud_in -> size();

    for (size_t i = 0; i < cloudSize; ++i) {
        PointType thisPoint = _cloud_in -> points[i];

        float range = sqrt(thisPoint.x * thisPoint.x +
                            thisPoint.y * thisPoint.y +
                            thisPoint.z * thisPoint.z);

        float verticalAngle = std::asin(thisPoint.z / range);

        int rowIdn = (verticalAngle + _ang_bottom) / _ang_resolution_Y;
        if (rowIdn < 0 || rowIdn >= _vertical_scans) {
            continue;
        }

        float horizonAngle = std::atan2(thisPoint.x, thisPoint.y);

        int columnIdn = -round((horizonAngle - M_PI_2) / _ang_resolution_X) + _horizontal_scans * 0.5;

        if (columnIdn >= _horizontal_scans){
            columnIdn -= _horizontal_scans;
        }

        if (columnIdn < 0 || columnIdn >= _horizontal_scans){
            continue;
        }

        if (range < 2){
            continue;
        }

        _range_mat(rowIdn, columnIdn) = range;

        thisPoint.intensity = (float)rowIdn + (float)columnIdn / 10000.0;

        size_t index = columnIdn + rowIdn * _horizontal_scans;

        _full_cloud -> points[index] = thisPoint;
    }
}

void DataProcess::groundRemoval(){
    for (int j = 0; j < _horizontal_scans; ++j) {
        for (int i = 0; i < _ground_scan_index; ++i) {
            int lowerInd = j + (i)*_horizontal_scans;
            int upperInd = j + (i + 1) * _horizontal_scans;

            if (_full_cloud->points[lowerInd].intensity == -1 ||
                _full_cloud->points[upperInd].intensity == -1) {
                _ground_mat(i, j) = -1;
                continue;
            }

            float dX =
                _full_cloud->points[upperInd].x - _full_cloud->points[lowerInd].x;
            float dY =
                _full_cloud->points[upperInd].y - _full_cloud->points[lowerInd].y;
            float dZ =
                _full_cloud->points[upperInd].z - _full_cloud->points[lowerInd].z;

            float vertical_angle = std::atan2(dZ , sqrt(dX * dX + dY * dY + dZ * dZ));

            if ( (vertical_angle - _sensor_mount_angle) <= M_PI / 18.0) {
                _ground_mat(i, j) = 1;
                _ground_mat(i + 1, j) = 1;
            }
        }
        
    }

    for (int i = 0; i < _vertical_scans; ++i) {
        for (int j = 0; j < _horizontal_scans; ++j) {
            if (_ground_mat(i, j) == 1 ||
                _range_mat(i, j) == FLT_MAX) {
                _label_mat(i, j) = -1;
            }
        }
    }
}

void DataProcess::calculateSmoothness(){
    for(int i = 0; i < _vertical_scans; ++i){
        std::vector<float> scan_range;
        std::vector<int> scan_index;
        scan_range.reserve(_horizontal_scans);
        scan_index.reserve(_horizontal_scans);

        for(int j = 0; j < _horizontal_scans; ++j){
            if(_range_mat(i, j) != FLT_MAX){
                scan_range.push_back(_range_mat(i, j));
                scan_index.push_back(j);
            }
        }

        // 计算曲率
        str_index[i] = cloudCurvature.size();
        int size = scan_range.size();
        for(int j = 5; j < size - 6; ++j){
            float curvature = scan_range[j - 5] + scan_range[j - 4] + scan_range[j - 3] + scan_range[j - 2] + scan_range[j - 1] +
                                scan_range[j + 5] + scan_range[j + 4] + scan_range[j + 3] + scan_range[j + 2] + scan_range[j + 1] -
                                scan_range[j] * 10;
            cloudCurvature.push_back(smoothness(curvature * curvature, scan_index[j]));
        }
        end_index[i] = cloudCurvature.size() - 1;
    }
}

void DataProcess::markCornerPoints(){
    auto cmp = [](const smoothness &l_val, const smoothness &r_val){
        return l_val.curvature < r_val.curvature;
    };

    for(int i = 0; i < _vertical_scans; ++i){
        if(str_index[i] >= end_index[i]){
            continue;
        }

        int length = end_index[i] - str_index[i];
        length /= 6;
        CloudTypePtr tempGroundCloud(new CloudType());
        for(int j = 0; j < 6; ++j){
            int sp = str_index[i] + j * length;
            int ep = sp + length - 1;

            sort(cloudCurvature.begin() + sp, cloudCurvature.begin() + ep, cmp);

            int max_num = 0;
            for(int k = ep; k >= sp; --k){
                int ind = cloudCurvature[k].index;
                if(cloudCurvature[k].curvature > 0.1 && _ground_mat(i, j) != 1){
                    if(max_num <= 20){
                        _corner_label(i, ind) = 1;
                        max_num++;
                    }else{
                        break;
                    }
                }
            }

            int min_num = 0;
            for(int k = sp; k <= ep; ++k){
                int ind = cloudCurvature[k].index;
                if(cloudCurvature[k].curvature < 0.1 && _ground_mat(i, j) == 1){
                    int index = i * _horizontal_scans + ind;
                    if(min_num <= 4){
                        _surf_flat -> push_back(_full_cloud -> points[index]);
                        min_num++;
                    }
                    tempGroundCloud -> push_back(_full_cloud -> points[index]);
                } else {
                    break;
                }
            }
        }
        downsample(tempGroundCloud, surfDownSampleFilter);
        *_surf_less_flat += *tempGroundCloud;
    }
    downsample(_surf_flat, surfDownSampleFilter);
}

void DataProcess::labelVaildableCornerPoints(int row, int col){
    const float segmentThetaThreshold = tan(_segment_theta);

    std::unordered_set<int> lineCountFlag;
    const size_t cloud_size = _vertical_scans * _horizontal_scans;
    using Coord2D = Eigen::Vector2i;
    boost::circular_buffer<Coord2D> queue(cloud_size);
    boost::circular_buffer<Coord2D> all_pushed(cloud_size);

    queue.push_back({row, col});
    all_pushed.push_back({row, col});
    lineCountFlag.insert(row);

    const Coord2D neighborIterator[2] = {{1, 0}, {-1, 0}};

    while (queue.size() > 0) {
        Coord2D fromInd = queue.front();
        queue.pop_front();

        for (const auto& iter : neighborIterator) {
            int thisIndX = fromInd.x() + iter.x();
            int thisIndY = fromInd.y() + iter.y();

            // 超出范围
            if (thisIndX < 0 || thisIndX >= _vertical_scans){
                continue;
            }

            // 地面点或无效点
            if (_label_mat(thisIndX, thisIndY) == -1){
                continue;
            }

            // 已经验证过
            if(lineCountFlag.find(thisIndX) != lineCountFlag.end()){
                continue;
            }

            float d1 = std::max(_range_mat(fromInd.x(), fromInd.y()),
                            _range_mat(thisIndX, thisIndY));
            float d2 = std::min(_range_mat(fromInd.x(), fromInd.y()),
                            _range_mat(thisIndX, thisIndY));

            float alpha = _ang_resolution_Y;
            float tang = (d2 * sin(alpha) / (d1 - d2 * cos(alpha)));

            if (tang > segmentThetaThreshold) {
                queue.push_back( {thisIndX, thisIndY } );
                lineCountFlag.insert(thisIndX);
                all_pushed.push_back(  {thisIndX, thisIndY } );
            }
        }
    }

    if(lineCountFlag.size() > _segment_valid_line_num){
        int size = all_pushed.size();
        int sum_ind = 0;
        int y_ind = all_pushed.front().y();
        while(!all_pushed.empty()){
            Coord2D ind = all_pushed.front();
            all_pushed.pop_front();
            _corner_label(ind.x(), ind.y()) = 2;
            sum_ind += ind.x();
        }
        _corner_label(int(sum_ind / size), y_ind) = 3;
    }else {
        while(!all_pushed.empty()){
            Coord2D ind = all_pushed.front();
            all_pushed.pop_front();
            _corner_label(ind.x(), ind.y()) = 0;
        }
    }
}

void DataProcess::cornerCloudSegmentation(){
    for(int i = 0; i < _vertical_scans; ++i){
        for(int j = 0; j < _horizontal_scans; ++j){
            if(_corner_label(i, j) == 1)
                labelVaildableCornerPoints(i, j);
        }
    }

    for(int i = 0; i < _vertical_scans; ++i){
        for(int j = 0; j < _horizontal_scans; ++j){
            int ind = i * _horizontal_scans + j;
            if(_corner_label(i, j) == 3){
                _corner_sharp -> push_back(_full_cloud -> points[ind]);
                _corner_less_sharp -> push_back(_full_cloud -> points[ind]);
            }else if(_corner_label(i, j) == 2){
                _corner_less_sharp -> push_back(_full_cloud -> points[ind]);
            }
            if(_label_mat(i, j) != -1){
                _segment_cloud -> push_back(_full_cloud -> points[ind]);
            } else if(_ground_mat(i, j) == 1){
                _ground_cloud -> push_back(_full_cloud -> points[ind]);
            }
        }
    }

    downsample(_corner_sharp, cornerDownSampleFilter);
    downsample(_corner_less_sharp, cornerDownSampleFilter);
}

void DataProcess::publishCloud(){
    auto publish = [&](rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr pub, CloudTypePtr cloud){
        if(pub -> get_subscription_count() == 0)
            return;
        sensor_msgs::msg::PointCloud2 msg;
        pcl::toROSMsg(*cloud, msg);
        msg.header = oneCloud.header;
        msg.header.frame_id = "map";
        pub -> publish(msg);
    };

    publish(pub_cloud_in, _cloud_in);
    publish(pub_corner_sharp, _corner_sharp);
    publish(pub_corner_less_sharp, _corner_less_sharp);
    publish(pub_surf_flat, _surf_flat);
    publish(pub_surf_less_flat, _surf_less_flat);
    publish(pub_segment_cloud, _segment_cloud);
    publish(pub_ground_cloud, _ground_cloud);

    // --------
    DataProcessOut out;
    out.corner_sharp.swap(_corner_sharp);
    out.corner_less_sharp.swap(_corner_less_sharp);
    out.surf_flat.swap(_surf_flat);
    out.surf_less_flat.swap(_surf_less_flat);
    out.segment_cloud.swap(_segment_cloud);
    out.ground_cloud.swap(_ground_cloud);
    _output_channel.send(std::move(out));
}

// 下采样
void DataProcess::downsample(CloudTypePtr cloud, pcl::VoxelGrid<PointType>::Ptr downSampleFilter){
    CloudTypePtr temp(new CloudType());
    cloud -> swap(*temp);
    downSampleFilter -> setInputCloud(temp);
    downSampleFilter -> filter(*cloud);
}

} // lidarslam