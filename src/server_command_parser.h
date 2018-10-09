#ifndef __SERVER_COMMAND_PARSER_H__
#define __SERVER_COMMAND_PARSER_H__

#include <string>
#include <iostream>

class CommandParser {
public:
	explicit CommandParser(const std::string& message);
	
	~CommandParser();

	std::string get_command() const;

	std::string get_value() const;
	
private:
	const char delim;
	const std::string command;
	const std::string value;
};

#endif
