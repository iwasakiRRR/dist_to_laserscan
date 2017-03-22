#include "dist_to_laserscan/dist_to_laserscan.hpp"

DistToLaser::DistToLaser():theta(0.0),selection(false){
	num_readings = 10;//100
	laser_frequency = 40;//40
	ranges[num_readings];
	intensities[num_readings]; 
	count = 0;
}

void DistToLaser::MakeFakeLaser(const std_msgs::Int32 &distance){
	//自分が向いている向きから−９０°の範囲に設定してあげることができれば良い
	std::cout<<"memoryの値は"<<&distance<<std::endl;
	double b_distance = distance.data;
	ros::Time scan_time = ros::Time::now();
	
	laserscan.header.stamp = scan_time;
	laserscan.header.frame_id = "laser_frame";
	laserscan.angle_min = -0.52;
	laserscan.angle_max = 0.52;
	//laserscan.angle_increment = 3.14 / num_readings;
	laserscan.angle_increment = 0.12;
	laserscan.time_increment = (1 / laser_frequency) / (num_readings);
	laserscan.range_min = 0.0;
	laserscan.range_max = 10.0;
	laserscan.ranges.resize(num_readings);
	laserscan.intensities.resize(num_readings);
	
	int math_before = num_readings / 4;
	int math_after = num_readings - math_before;
	
	/*for(unsigned int i = 0; i < num_readings; ++i){

		if(i >= math_before && i <= math_after){
			laserscan.ranges[i] = (b_distance / 100) + 0.35;
			laserscan.intensities[i] = 100;//100
		}
		else
			laserscan.ranges[i] = 0;
			laserscan.intensities[i] = 0;
	}*/
	
	for(unsigned int i = 0; i < num_readings; ++i){
	laserscan.ranges[i] = (b_distance / 100)+0.3;
	laserscan.intensities[i] = 100;//100
	}
	pub.publish(laserscan);
	std::cout<<"published"<<std::endl;
	return;
}
