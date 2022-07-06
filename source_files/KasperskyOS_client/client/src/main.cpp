#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <gpio/gpio.h>
#include <stdbool.h>

#ifdef __arm__
#include <bsp/bsp.h>
#endif

// simple function for console output
void print(const char* msg)
{
	fprintf(stderr, msg);
	fprintf(stderr, "\n");
}

// GPIO controller
class GPIOEntity
{
private:
	GpioHandle handle;
public:
	GPIOEntity()
	{
		#ifdef __arm__
	    	{
			if (BspInit(NULL) != BSP_EOK)
			{
			    print("Failed to initialize BSP!");
			}

			if (BspSetConfig("gpio0", "raspberry_pi4b.default") != BSP_EOK)
			{
			    	print("Failed to set mux configuration for gpio0 module!");
			}
	   	}
		#endif

	    	if (GpioInit())
	    	{
			print("GpioInit failed!");
	    	}

	    	/* initialize and setup gpio0 port */
	    	handle = NULL;
	    	if (GpioOpenPort("gpio0", &handle) || handle == GPIO_INVALID_HANDLE)
	    	{
			print("GpioOpenPort failed");
	    	}
	}

	GpioHandle* getHandle()
	{
		return &handle;
	}

	~GPIOEntity()
	{
		if(GpioClosePort(handle))
	    	{
			print("GpioClosePort failed");
	    	}
	}

};


// Motor controller class
class Motor
{
private:
	GpioHandle* handle;
	const unsigned int PIN_E, PIN_A, PIN_B;
public:
	Motor(GpioHandle* h, const unsigned int& pin_e, const unsigned int& pin_a, const unsigned int& pin_b) : 
	PIN_E(pin_e), PIN_A(pin_a), PIN_B(pin_b)
	{
		handle = h;
		
		// set pins in the output mode
		GpioSetMode(*handle, PIN_E, GPIO_DIR_OUT);
		GpioSetMode(*handle, PIN_A, GPIO_DIR_OUT);
		GpioSetMode(*handle, PIN_B, GPIO_DIR_OUT);
		
		// enable motors
		GpioOut(*handle, PIN_E, 1);
		GpioOut(*handle, PIN_E, 1);
	}
	
	// doesn`t work currently, we can`t affect PWM
	void setSpeed(const int& speed)
	{
		GpioOut(*handle, PIN_E, speed);
	}
	
	void run(const int& direction)
	{	
		int dir = direction % 2;
		
		GpioOut(*handle, PIN_A, dir);
		GpioOut(*handle, PIN_B, (dir + 1) % 2);
	}
	
	void stop()
	{
		GpioOut(*handle, PIN_A, 0);
		GpioOut(*handle, PIN_B, 0);
	}
};


// Base robot class
class Robot
{
private:
	//TCPExchanger* cmdrcv;
	GPIOEntity* gpio_entity;
	Motor* motorA;
	Motor* motorB;
	
	const double wheel_value = 0.005;
	// set the real value (?)
	// via wheel radius and encoders thing
	// then update sleep in moving methods
public:
	Robot(GPIOEntity* ge, Motor* ma, Motor* mb, int spd = 50) : gpio_entity(ge), motorA(ma), motorB(mb)
	{}
	
	void forward(const int& val)
	{
		motorA->run(0);
		motorB->run(0);
		sleep(wheel_value*val);
		motorA->stop();
		motorB->stop();
	}
	
	void backward(const int& val)
	{
		motorA->run(1);
		motorB->run(1);
		sleep(wheel_value*val);
		motorA->stop();
		motorB->stop();
	}
	
	void turn_left(const int& val)
	{
		motorA->run(0);
		motorB->run(1);
		sleep(wheel_value*val);
		motorA->stop();
		motorB->stop();
	}
	
	void turn_right(const int& val)
	{
		motorA->run(1);
		motorB->run(0);
		sleep(wheel_value*val);
		motorA->stop();
		motorB->stop();
	}
};



int main(int argc, const char *argv[])
{
	print("\n\nRobo Core Oleg 2022");
	print("Program is starting...");
	
	// modules initialisation
	GPIOEntity* ge = new GPIOEntity();
	Motor* ma = new Motor(ge->getHandle(), 6, 12, 13);
	Motor* mb = new Motor(ge->getHandle(), 26, 20, 21);

	Robot* Oleg = new Robot(ge, ma, mb); 
	
	print("General initialisation completed!");
	
	// Robot driving tests
	print("\nRobot test: forward");
	Oleg->forward(400);
	
	print("\nRobot test: left");
	Oleg->turn_left(200);
	
	print("\nRobot test: right");
	Oleg->turn_right(200);
	
	print("\nRobot test: backward");
	Oleg->backward(200);   	
    	

    	print("Program is shutting down!");

    	return EXIT_SUCCESS;
}
