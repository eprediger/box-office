#include "server_command_parser.h"

#include <string>
#include <vector>
#include <sstream>

CommandParser::CommandParser(const std::string& message) : 
	delim(' '),
	command(message.substr(0,message.find(delim))),
	value(message.substr(message.find(delim)+1)),
	values() {
	std::stringstream ss(this->value);
	std::string item;
	while (std::getline(ss, item, this->delim)) {
		this->values.push_back(item);
	}
}

CommandParser::~CommandParser() {}

std::string CommandParser::get_command() const {
	return this->command;
}

std::vector<std::string> CommandParser::get_values() const {
	return this->values;
}
