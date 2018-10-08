#include <string>
#include "server_cine.h"

Cine::Cine(const std::string& salasFile, const std::string& peliculasFile,
	       const std::string& funcionesFile) :
	cartelera(),
	salas() {
	SalasParser salasParser(salasFile);
	PeliculasParser peliculasParser(peliculasFile);
	FuncionesParser funcionesParser(funcionesFile);
	
	salasParser.parse_salas(this->salas);
	peliculasParser.parse_peliculas(this->cartelera);
	funcionesParser.parse_funciones(this->cartelera, this->salas);
}

Cine::~Cine() {}

void Cine::filter_by_language(const std::string& lang) {
	for (auto pelicula : this->cartelera) {
		if (pelicula.get_lang() == lang) {
			std::cout << pelicula.get_title() << std::endl;
		}
	}   
}

void Cine::filter_by_rating(const std::string& rating) {
	for (auto pelicula : this->cartelera) {
		if (pelicula.get_rating() == rating) {
			std::cout << pelicula.get_title() << std::endl;
		}
	}   
}

void Cine::filter_by_genre(const std::string& genre) {
	for (auto pelicula : this->cartelera) {
		if (pelicula.get_genre() == genre) {
			std::cout << pelicula.get_title() << std::endl;
		}
	}   
}

void Cine::filter_by_date(const std::string& date) {
	for (auto sala : this->salas) {
		sala.second.get_title_by_date(date);
	}
}

void Cine::view_seats(const unsigned funcionID) {
	for (auto sala : this->salas) {
		if (sala.second.has_funcionID(funcionID)) {
			sala.second.show_seats(funcionID);
		}
	}	
}

void Cine::reserve_seat(const unsigned funcionID, const std::string& fila,
	                    const std::string& columna) {
	for (auto& sala : this->salas) {
		if (sala.second.has_funcionID(funcionID)) {
			sala.second.reserve_seat(funcionID, fila, columna);
		}
	}	
}
