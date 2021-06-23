cmake_minimum_required(VERSION 3.1)
project(readbag)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(catkin REQUIRED COMPONENTS rosbag cv_bridge)
find_package(Boost REQUIRED QUIET)
find_package(cv_bridge)
find_package(OpenCV REQUIRED)

#catkin_package(CATKIN_DEPENDS)
# Set the output folder
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# The following folders will be included
include_directories("${PROJECT_SOURCE_DIR}")
include_directories(include ${Boost_INCLUDE_DIRS})
include_directories(${catkin_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

#add_executable(row_detection ${PROJECT_SOURCE_DIR}/src/main.cpp)
file(GLOB SOURCES "*.cpp")
add_executable(readbag ${SOURCES})
 
target_link_libraries(readbag  LINK_PUBLIC ${Boost_LIBRARIES}; ${catkin_LIBRARIES};${OpenCV_LIBS})









