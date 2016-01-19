#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"

class PatrolFilter{
  public:
    PatrolFilter();
    void laser_callback(const sensor_msgs::LaserScan::ConstPtr& scan);
  private:
    ros::NodeHandle nh;
    ros::Subscriber scanSub;
    ros::Publisher scanPub;
    double lower_threshold ;
    double upper_threshold ;
    int radius_size;
    int index_center;
};
