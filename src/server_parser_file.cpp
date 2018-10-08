#include "server_parser_file.h"

CSVParser::CSVParser(const std::string& filename) : 
	file(filename, std::ifstream::in),
	delim(',') {}

CSVParser::~CSVParser() {
	this->file.close();
}
