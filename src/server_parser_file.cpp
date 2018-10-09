#include <string>
#include "server_parser_file.h"
#include "common_exception.h"

CSVParser::CSVParser(const std::string& filename) : 
	file(filename, std::ifstream::in),
	delim(',') {
	if (!file) {
		std::string error = "El archivo " + filename + " no existe.";
		throw Exception(error);
	}
}

CSVParser::~CSVParser() {
	this->file.close();
}
