#include "Robot.h"

Robot::Robot(TCPEntity* te, GPIOEntity* ge, Motor* ma, Motor* mb) : cmdrcv(te), gpio_entity(ge), motorA(ma), motorB(mb)
{
	print("[Robot] Successfully initialised!");
}

void Robot::forward(const int& val)
{
	print("[Robot] Forward!");
	motorA->run(0);
	motorB->run(0);
	sleep(wheel_value*val);
	motorA->stop();
	motorB->stop();
}

void Robot::backward(const int& val)
{
	print("[Robot] Backward!");
	motorA->run(1);
	motorB->run(1);
	sleep(wheel_value*val);
	motorA->stop();
	motorB->stop();
}

void Robot::turn_left(const int& val)
{
	print("[Robot] Left!");
	motorA->run(0);
	motorB->run(1);
	sleep(wheel_value*val);
	motorA->stop();
	motorB->stop();
}

void Robot::turn_right(const int& val)
{
	print("[Robot] Right!");
	motorA->run(1);
	motorB->run(0);
	sleep(wheel_value*val);
	motorA->stop();
	motorB->stop();
}

