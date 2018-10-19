#include <map>
#include <string>
#include <vector>
#include "common_exception.h"
#include "server_parser_funciones.h"

FuncionesParser::FuncionesParser(const std::string& filename) :
	CSVParser(filename),
	id(0),
	sala(),
	titulo(),
	fecha(),
	hora() {}

FuncionesParser::~FuncionesParser() {}

void FuncionesParser::parse_funciones(std::vector<Pelicula>& peliculas, 
									std::map<std::string, Sala>& salas) {
	while (std::getline(this->file, this->sala, delim)) {
		std::getline(this->file, this->titulo, delim);
		std::getline(this->file, this->fecha, delim);
		std::getline(this->file, this->hora);
		this->id++;

		std::vector<Pelicula>::iterator peli_by_title;
		peli_by_title = std::find_if(peliculas.begin(), peliculas.end(),
										find_by_title(this->titulo));

		if (peli_by_title != peliculas.end()) {
			std::map<std::string, Sala>::iterator sala_by_id;
			sala_by_id = salas.find(this->sala);
			if (sala_by_id != salas.end()) {
				sala_by_id->second.nueva_funcion(
				Funcion(this->id, *peli_by_title, this->fecha, this->hora));
			} else {
				std::string error = "La sala " + this->sala;
				error += " no existe en el sistema.";
				throw Exception(error);
			}
		} else {
			std::string error = "La película " + this->titulo;
			error += " no existe en el sistema.";
			throw Exception(error);
		}
	}
}
