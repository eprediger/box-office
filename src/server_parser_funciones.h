#ifndef __SERVER_FUNCIONES_PARSER_H__
#define __SERVER_FUNCIONES_PARSER_H__

#include <string>
#include <vector>
#include <map>
#include <algorithm>
// #include <memory>

// #include <iostream>

#include "server_parser_file.h"
#include "server_funcion.h"
#include "server_pelicula.h"
#include "server_sala.h"

class FuncionesParser : public CSVParser {
public:
	FuncionesParser(const std::string& filename);

	~FuncionesParser();

	void parse_funciones(std::vector<Pelicula>& peliculas, std::map<std::string, Sala>& salas);

private:
	unsigned id;
	std::string sala, titulo, fecha, hora;
};

#endif
