#include "JSON.h"

JSONCommand::JSONCommand(const char* str_json)
{
	//validate JSON
	command.Parse(str_json);
}

rapidjson::Document* JSONCommand::getCommand()
{
	return &command;
}

std::string JSONCommand::getCommandType()
{
	return command["CommandType"].GetString();
}

std::string JSONCommand::getMoveType()
{
	return command["MoveType"].GetString();
}


double JSONCommand::getAngle()
{
	return command["Angle"].GetDouble();
}

double JSONCommand::getDistance()
{
	return command["Distance"].GetDouble();
}
