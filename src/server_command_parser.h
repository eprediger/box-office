#ifndef __SERVER_COMMAND_PARSER_H__
#define __SERVER_COMMAND_PARSER_H__

#include <string>
#include <iostream>
#include <vector>

class CommandParser {
public:
	explicit CommandParser(const std::string& message);

	~CommandParser();

	std::string get_command() const;

	std::vector<std::string> get_values() const;

private:
	const char delim;
	const std::string command;
	std::string value;
	std::vector<std::string> values;
};

#endif
