#pragma once
#include <string.h>

// rapidjson
#include "../rapidjson/include/rapidjson/document.h"

void print(const char* msg);

class JSONCommand
{
private:
	rapidjson::Document command;
	
public:
	JSONCommand(const char* str_json);
	rapidjson::Document* getCommand();
	std::string getCommandType();
	std::string getMoveType();
	double getAngle();
	double getDistance();
};
