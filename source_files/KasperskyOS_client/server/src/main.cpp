#include "GPIO.h"
#include "TCP.h"
#include "Robot.h"


void print(const char* msg)
{
	fprintf(stderr, "%s\n", msg);
}

void GPIO_Test(Robot* Oleg)
{
	print("[TEST] GPIO Test has ended!");
	print("\nRobot test: forward");
	Oleg->forward(500);
	
	print("\nRobot test: left");
	Oleg->turn_left(200);
	
	print("\nRobot test: right");
	Oleg->turn_right(200);
	
	print("\nRobot test: backward");
	Oleg->backward(500);   
	
	print("[TEST] GPIO Test has ended!");
	exit(0);
}

void TCP_Test(Robot* Oleg)
{
	print("[TEST] TCP Test has started!");
	Oleg->run();
	
	print("[TEST] TCP Test has ended!");
	exit(1);
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
	
	// Robot driving tests
	//GPIO_Test(Oleg);
	
	// Robot network tests
	TCP_Test(Oleg);
	
	// General execution of the program
	Oleg->run();  	

    	print("Program is shutting down!");
    	return EXIT_SUCCESS;
}
