#pragma once

#include "TCP.h"
#include "GPIO.h"
#include "JSON.h"

class Robot
{
private:
	TCPEntity* cmdrcv;
	GPIOEntity* gpio_entity;
	Motor* motorA;
	Motor* motorB;
	
	JSONCommand* cmd;
	
	const double wheel_radius = (double)65 / 2;
	const double wheel_length = wheel_radius*wheel_radius*3.1415;
	// set the real value (?)
	// via wheel radius and encoders thing
	// then update sleep in moving methods
public:
	Robot(TCPEntity* te, GPIOEntity* ge, Motor* ma, Motor* mb);
	
	int run();
	
	void forward(const double& val);
	void backward(const double& val);
	void turn_left(const double& val);
	void turn_right(const double& val);
};
