#include "server_command_parser.h"

CommandParser::CommandParser(const std::string& message) : 
	delim(' '),
	command(message.substr(0,message.find(delim))),
	value(message.substr(message.find(delim)+1)) {}

CommandParser::~CommandParser() {}

std::string CommandParser::get_command() const {
	return this->command;
}

std::string CommandParser::get_value() const {
	return this->value;
}
