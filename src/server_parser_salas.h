#ifndef __SERVER_PARSER_SALAS_H__
#define __SERVER_PARSER_SALAS_H__

#include <string>
#include <map>

#include "server_parser_file.h"
#include "server_sala_chica.h"
#include "server_sala_mediana.h"
#include "server_sala_grande.h"

class SalasParser : public CSVParser {
public:
	explicit SalasParser(const std::string& filename);

	~SalasParser();

	void parse_salas(std::map<std::string, Sala>& salas);

private:
	std::string id, screen, size;
};

#endif
