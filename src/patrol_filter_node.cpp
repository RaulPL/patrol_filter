#include "ros/ros.h"
#include "patrol_filter/PatrolFilter.h"


int main(int argc, char **argv){
  ros::init(argc, argv, "patrol_filter_node");
  PatrolFilter patrol_filter_object;
  ros::spin();
  return 0;
}
