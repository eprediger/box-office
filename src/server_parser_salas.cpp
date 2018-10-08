#include <map>
#include <string>
#include "server_parser_salas.h"

SalasParser::SalasParser(const std::string& filename) :
	CSVParser(filename),
	id(),
	screen(),
	size() {}

SalasParser::~SalasParser() {}

void SalasParser::parse_salas(std::map<std::string, Sala>& salas) {
	while (std::getline(this->file, this->id, this->delim)) {
		std::getline(this->file, this->screen, this->delim);
		std::getline(this->file, this->size);
		if (this->size == "chica") {
			salas.emplace(this->id, SalaChica(this->id, this->screen));
		}
		if (this->size == "mediana") {
			salas.emplace(this->id, SalaMediana(this->id, this->screen));
		}
		if (this->size == "grande") {
			salas.emplace(this->id, SalaGrande(this->id, this->screen));
		}
	}
}
