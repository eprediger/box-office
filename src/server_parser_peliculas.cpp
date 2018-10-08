#include <string>
#include <vector>
#include "server_parser_peliculas.h"

PeliculasParser::PeliculasParser(const std::string& filename) :
	CSVParser(filename),
	title(), 
	lang(), 
	rating(), 
	genre() {}

PeliculasParser::~PeliculasParser() {}

void PeliculasParser::parse_peliculas(std::vector<Pelicula>& peliculas) {
	while (std::getline(this->file, this->title, this->delim)) {
		std::getline(this->file, this->lang, this->delim);
		std::getline(this->file, this->rating, this->delim);
		std::getline(this->file, this->genre);
		peliculas.push_back(Pelicula(this->title, this->lang, 
									 this->rating, this->genre));
	}
}
