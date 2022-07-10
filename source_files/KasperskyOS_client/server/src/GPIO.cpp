#include "GPIO.h"

// GPIO controller
GPIOEntity::GPIOEntity()
{
	print("[GPIOEntity] Initialising...");
	#ifdef __arm__
    	{
		if (BspInit(NULL) != BSP_EOK)
		{
		    print("Failed to initialize BSP!");
		    exit(1);
		}

		if (BspSetConfig("gpio0", "raspberry_pi4b.default") != BSP_EOK)
		{
		    	print("Failed to set mux configuration for gpio0 module!");
		    	exit(1);
		}
   	}
	#endif

    	if (GpioInit())
    	{
		print("GpioInit failed!");
		exit(1);
    	}

    	/* initialize and setup gpio0 port */
    	handle = NULL;
    	if (GpioOpenPort("gpio0", &handle) || handle == GPIO_INVALID_HANDLE)
    	{
		print("GpioOpenPort failed");
		exit(1);
    	}
    	
    	print("[GPIOEntity] Initialisation completed!");
}

GpioHandle* GPIOEntity::getHandle()
{
	return &handle;
}

GPIOEntity::~GPIOEntity()
{
	print("[GPIOEntity] Destructing...");
	if(GpioClosePort(handle))
    	{
		print("[GPIOEntity] GpioClosePort failed");
    	}
}


// Motor controller class
Motor::Motor(GpioHandle* h, const unsigned int& pin_e, const unsigned int& pin_a, const unsigned int& pin_b) : 
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
	
void Motor::run(const int& direction)
{	
	int dir = direction % 2;
	
	GpioOut(*handle, PIN_A, dir);
	GpioOut(*handle, PIN_B, (dir + 1) % 2);
}

void Motor::stop()
{
	GpioOut(*handle, PIN_A, 0);
	GpioOut(*handle, PIN_B, 0);
}

Motor::~Motor()
{
	GpioOut(*handle, PIN_E, 0);
	GpioOut(*handle, PIN_E, 0);
}
