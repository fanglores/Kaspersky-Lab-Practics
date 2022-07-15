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
	
	if (exit_code == 0)
	{
		print("[OLEG] Executing the command...");

		if (cmd->getCommandType() == "movement")
		{
			std::string mt = cmd->getMoveType(); 
			if (mt == "forward") forward(cmd->getDistance());
			else if (mt == "backward") backward(cmd->getDistance());
			else if (mt == "left") turn_left(cmd->getAngle());
			else if (mt == "right") turn_right(cmd->getAngle());
			else print("[OLEG] MoveType is unknown!");
		}
		else
		{
			print("[OLEG] Control commands are not implemented!");
		}
	}
	else print("[OLEG] Something went wrong!");
	
	// send exit code
	char tmp_code = static_cast<char>('0' + exit_code);
	cmdrcv->Send(&tmp_code);
	return exit_code;
}

void Robot::forward(const double& val)
{
	print("[OLEG] Forward!");
	motorA->run(0);
	motorB->run(0);
	usleep(static_cast<useconds_t>(1000*val));
	motorA->stop();
	motorB->stop();
	
	usleep(static_cast<useconds_t>(1000*200));
}

void Robot::backward(const double& val)
{
	print("[OLEG] Backward!");
	motorA->run(1);
	motorB->run(1);
	usleep(static_cast<useconds_t>(1000*val));
	motorA->stop();
	motorB->stop();
	
	usleep(static_cast<useconds_t>(1000*200));
}

void Robot::turn_left(const double& val)
{
	print("[OLEG] Left!");
	motorA->run(0);
	motorB->run(1);
	usleep(static_cast<useconds_t>(1000*val));
	motorA->stop();
	motorB->stop();
	
	usleep(static_cast<useconds_t>(1000*200));
}

void Robot::turn_right(const double& val)
{
	print("[OLEG] Right!");
	motorA->run(1);
	motorB->run(0);
	usleep(static_cast<useconds_t>(1000*val));
	motorA->stop();
	motorB->stop();
	
	usleep(static_cast<useconds_t>(1000*200));
}

