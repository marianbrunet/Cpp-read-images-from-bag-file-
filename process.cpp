#include <ros/ros.h>
#include <rosbag/view.h>
#include <opencv2/opencv.hpp>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <sensor_msgs/Image.h>

int main (int argc, char** argv)
{
    std::cout << "Read image from bag file" << std::endl;
    std::cout << "Set image_topic_name and bagfile_name" << std::endl;

    std::string image_topic_name = "/device/image/data";
    //bag file path & name
    std::string bagfile_name = "/home/mybag.bag";
    std::cout << "topic name: " << image_topic_name << std::endl;

    cv::Mat image;
    rosbag::Bag bag;
    bag.open(bagfile_name);
    for (rosbag::MessageInstance const m : rosbag::View(bag)) {
        //image topic name
        std::string imgTopic = m.getTopic();
        if (image_topic_name == imgTopic) {
            try {
                sensor_msgs::ImageConstPtr imgMsgPtr = m.instantiate<sensor_msgs::Image>();
                image = cv_bridge::toCvCopy(imgMsgPtr)->image;
            } catch (cv_bridge::Exception& e) {
                ROS_ERROR("Image convert error");
            }
            cv::imshow("image", image);
            cv::waitKey(1);
        }
    }

    bag.close();
    return 0;

}

