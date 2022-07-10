#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <gpio/gpio.h>
#include <stdbool.h>

#ifdef __arm__
#include <bsp/bsp.h>
#endif

void print(const char* msg);

class GPIOEntity
{
private:
	GpioHandle handle;
public:
	GPIOEntity();
	GpioHandle* getHandle();
	~GPIOEntity();
};

class Motor
{
private:
	GpioHandle* handle;
	const unsigned int PIN_E, PIN_A, PIN_B;
public:
	Motor(GpioHandle* h, const unsigned int& pin_e, const unsigned int& pin_a, const unsigned int& pin_b);
	void run(const int& direction);
	void stop();
	~Motor();
};

