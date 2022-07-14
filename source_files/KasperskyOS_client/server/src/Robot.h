#pragma once

#include "TCP.h"
#include "GPIO.h"

class Robot
{
private:
	TCPEntity* cmdrcv;
	GPIOEntity* gpio_entity;
	Motor* motorA;
	Motor* motorB;
	
	rapidjson::Document cmd;
	
	const double wheel_radius = (double)65 / 2;
	const double wheel_length = wheel_radius*wheel_radius*3.1415;
	// set the real value (?)
	// via wheel radius and encoders thing
	// then update sleep in moving methods
public:
	Robot(TCPEntity* te, GPIOEntity* ge, Motor* ma, Motor* mb);
	
	int run();
	
	void forward(const int& val);
	void backward(const int& val);
	void turn_left(const int& val);
	void turn_right(const int& val);
};
