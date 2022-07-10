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
	
	const double wheel_value = 0.005;
	// set the real value (?)
	// via wheel radius and encoders thing
	// then update sleep in moving methods
public:
	Robot(TCPEntity* te, GPIOEntity* ge, Motor* ma, Motor* mb);
	
	void forward(const int& val);
	void backward(const int& val);
	void turn_left(const int& val);
	void turn_right(const int& val);
};
