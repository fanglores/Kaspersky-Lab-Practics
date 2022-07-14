#include "GPIO.h"
#include "TCP.h"
#include "Robot.h"


void print(const char* msg)
{
	fprintf(stderr, msg);
	fprintf(stderr, "\n");
}

int main()
{
	print("\n\nRobo Core Oleg 2022");
	print("Program is starting...");
	
	// modules initialisation
	GPIOEntity* ge = new GPIOEntity();
	TCPEntity* te = new TCPEntity();
	Motor* ma = new Motor(ge->getHandle(), 6, 12, 13);
	Motor* mb = new Motor(ge->getHandle(), 26, 20, 21);

	Robot* Oleg = new Robot(te, ge, ma, mb); 
	
	print("General initialisation completed!");
	
	// General execution of the program
	Oleg->run();
	return 0;
	
	// Robot driving tests
	print("\nRobot test: forward");
	Oleg->forward(500);
	return 0;
	print("\nRobot test: left");
	Oleg->turn_left(200);
	
	print("\nRobot test: right");
	Oleg->turn_right(200);
	
	print("\nRobot test: backward");
	Oleg->backward(0);   	
    	

    	print("Program is shutting down!");

    	return EXIT_SUCCESS;
}
