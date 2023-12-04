#include <ros/ros.h>
#include <intro_training/StringWithHeader.h>

int main(int argc, char** argv) // if __name__ == '__main__': 
                                 //    main()
{
   
   ros::init(argc, argv, "talker"); 
   // rospy.init_node('talker', anonymous=True)
   
   ros::NodeHandle node_handle;

   ros::Publisher publisher = node_handle.advertise<intro_training::StringWithHeader>("talker_topic", 1);
      // publisher = rospy.Publisher('talker_topic', StringWithHeader, queue_size=1)
   
   ros::Rate rate(10); // rate = rospy.Rate(10)
   
   while(ros::ok()) // while not rospy.is_shutdown():
   {
      intro_training::StringWithHeader msg;
      msg.data = "Hello";
      publisher.publish(msg); // publisher.publish(point_stamped)
      ros::spinOnce(); // rospy.spin()
      rate.sleep(); // rate.sleep()
   }
   
      
	return 0;
}
