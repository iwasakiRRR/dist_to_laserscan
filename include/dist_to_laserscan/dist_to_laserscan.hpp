#include <iostream>
#include <ros/ros.h>
#include <math.h>
#include <sensor_msgs/LaserScan.h>
#include <nav_msgs/Odometry.h>
#include <std_msgs/Int32.h>
#include <tf/transform_broadcaster.h>


class DistToLaser{
	public :
		DistToLaser();
		ros::Publisher pub;
		ros::Subscriber serial_sub;
		ros::Subscriber odom_sub;
		ros::NodeHandle nh;
		ros::Time scan_time;
		
		sensor_msgs::LaserScan laserscan;
		double theta;
		std::string two_choices[5];
		bool selection;
		unsigned int num_readings;
		double laser_frequency; 
		double ranges[];
		double intensities[];
		int count;
		void GetDirection(const nav_msgs::OdometryConstPtr& _msg);
		void MakeFakeLaser(const std_msgs::Int32 &_distance);
};
