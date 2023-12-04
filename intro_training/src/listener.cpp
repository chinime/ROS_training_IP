#include <ros/ros.h>
#include <intro_training/StringWithHeader.h>
#include <iostream>

void callback(const intro_training::StringWithHeaderConstPtr& msg) {
   std::cout << msg->data << std::endl;
   // rospy.loginfo(msg.data)
}

int main(int argc, char** argv) {
   ros::init(argc, argv, "listener"); 
   
   ros::NodeHandle node_handle;
   
   ros::Subscriber subscriber = node_handle.subscribe("talker_topic", 1, &callback);
      // rospy.Subscriber('/talker_topic', StringWithHeader, self.callback)
 
   ros::spin();
   
   return 0;
}
