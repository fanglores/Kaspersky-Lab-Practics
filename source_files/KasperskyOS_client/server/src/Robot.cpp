#include "Robot.h"

Robot::Robot(TCPEntity* te, GPIOEntity* ge, Motor* ma, Motor* mb) : cmdrcv(te), gpio_entity(ge), motorA(ma), motorB(mb)
{
	print("[OLEG] Successfully initialised!");
}

int Robot::run()
{
	int exit_code = 0;
	
	print("[OLEG] Waiting for command...");
	exit_code += cmdrcv->Receive(cmd);
	
	if(exit_code == 0)
	{
		print("[OLEG] Executing the command...");
		// document["command"] == "forward" //...
	}
	else print("[OLEG] Something went wrong!");
	
	// send exit code
	const char* tmp_code = new char('0' + exit_code);
	cmdrcv->Send(tmp_code);
	return exit_code;
}

void Robot::forward(const int& val)
{
	print("[OLEG] Forward!");
	motorA->run(0);
	motorB->run(0);
	usleep(1000*val);
	motorA->stop();
	motorB->stop();
	
	usleep(1000*200);
}

void Robot::backward(const int& val)
{
	print("[OLEG] Backward!");
	motorA->run(1);
	motorB->run(1);
	usleep(1000*val);
	motorA->stop();
	motorB->stop();
	
	usleep(1000*200);
}

void Robot::turn_left(const int& val)
{
	print("[OLEG] Left!");
	motorA->run(0);
	motorB->run(1);
	usleep(1000*val);
	motorA->stop();
	motorB->stop();
	
	usleep(1000*200);
}

void Robot::turn_right(const int& val)
{
	print("[OLEG] Right!");
	motorA->run(1);
	motorB->run(0);
	usleep(1000*val);
	motorA->stop();
	motorB->stop();
	
	usleep(1000*200);
}

