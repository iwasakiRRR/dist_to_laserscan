#include "dist_to_laserscan/dist_to_laserscan.hpp"

int main(int argc, char** argv){
	ros::init(argc, argv, "dist_to_laserdscan");
	DistToLaser dtl;
	dtl.selection = false; 
	dtl.serial_sub = dtl.nh.subscribe("serial_topic",1,&DistToLaser::MakeFakeLaser,&dtl);
	dtl.pub = dtl.nh.advertise<sensor_msgs::LaserScan>("ryo_scan", 1000);
	std::cout<<"スピン前"<<std::endl;
	ros::spin();
}
