#ifndef __SERVER_PARSER_FILE__
#define __SERVER_PARSER_FILE__

#include <fstream>
#include <string>

class CSVParser {
public:
	explicit CSVParser(const std::string& filename);
	
	virtual ~CSVParser();

protected:
	std::ifstream file;
	const char delim;
};

#endif
