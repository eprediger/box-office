#include <string>
#include "server_parser_file.h"
#include "common_file_exception.h"

CSVParser::CSVParser(const std::string& filename) : 
	file(filename, std::ifstream::in),
	delim(',') {
	if (file.fail()) {
		std::string error = "El archivo " + filename + " no existe.";
		throw FileException(error);
	}
}

CSVParser::~CSVParser() {}
