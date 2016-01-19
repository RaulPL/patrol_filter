#include "ros/ros.h"
#include "patrol_filter/PatrolFilter.h"

PatrolFilter::PatrolFilter(){
  scanPub = nh.advertise<sensor_msgs::LaserScan>("/scan_filtered", 50);
  scanSub = nh.subscribe("/scan", 1, &PatrolFilter::laser_callback, this);
  lower_threshold = 0.325;
  upper_threshold = 50.0;
  radius_size = 10;
  index_center = 60;

}

void PatrolFilter::laser_callback(const sensor_msgs::LaserScan::ConstPtr &input_scan){
  sensor_msgs::LaserScan filtered_scan;
  filtered_scan.header = input_scan->header;
  filtered_scan.ranges = input_scan->ranges;
  filtered_scan.angle_min = input_scan->angle_min;
  filtered_scan.angle_max = input_scan->angle_max;
  filtered_scan.angle_increment = input_scan->angle_increment;
  filtered_scan.time_increment = input_scan->time_increment;
  filtered_scan.scan_time = input_scan->scan_time;
  filtered_scan.range_min = input_scan->range_min;
  filtered_scan.range_max = input_scan->range_max;
  for (unsigned int i=0; i < input_scan->ranges.size(); i++){
    if (i > (18 - radius_size) && i < (18 + radius_size)){
      filtered_scan.ranges[i] = std::numeric_limits<float>::quiet_NaN();
      continue;
    }
    if (i > (162 - radius_size) && i < (162 + radius_size)){
      filtered_scan.ranges[i] = std::numeric_limits<float>::quiet_NaN();
      continue;
    }

    if (input_scan->ranges[i] <= lower_threshold || input_scan->ranges[i] >= upper_threshold){
      filtered_scan.ranges[i] = std::numeric_limits<float>::quiet_NaN();
    }
  }
  std::cout<<(input_scan->ranges.size())<<std::endl;
  scanPub.publish(filtered_scan);
}
