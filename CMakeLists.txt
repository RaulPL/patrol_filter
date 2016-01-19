cmake_minimum_required(VERSION 2.8.3)
project(patrol_filter)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

find_package(catkin REQUIRED COMPONENTS
  filters
  laser_geometry
  roscpp
  sensor_msgs
  std_msgs
  roslib
)

catkin_package(
 INCLUDE_DIRS include
 CATKIN_DEPENDS filters laser_geometry roscpp sensor_msgs std_msgs
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_library(patrol_filter src/PatrolFilter.cpp)
target_link_libraries(patrol_filter
  ${catkin_LIBRARIES}
)

## Declare a cpp executable
add_executable(patrol_filter_node src/patrol_filter_node.cpp)
target_link_libraries(patrol_filter_node 
  patrol_filter
  ${catkin_LIBRARIES}
)

