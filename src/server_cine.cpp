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
	// std::string movies;
	for (auto pelicula : this->cartelera) {
		if (pelicula.get_lang() == lang) {
			// movies += pelicula.get_title();// << std::endl;
			std::cout << pelicula.get_title() << std::endl;
		}
	}
	// return movies;
}

void Cine::filter_by_rating(const std::string& rating) {
	// std::string movies;
	for (auto pelicula : this->cartelera) {
		if (pelicula.get_rating() == rating) {
			// movies += pelicula.get_title();// << std::endl;
			std::cout << pelicula.get_title() << std::endl;
		}
	}
	// return movies;
}

// std::string Cine::filter_by_genre(const std::string& genre) {
void Cine::filter_by_genre(const std::string& genre) {
	// std::string movies;
	for (auto pelicula : this->cartelera) {
		if (pelicula.get_genre() == genre) {
			// movies += pelicula.get_title();// << std::endl;
			std::cout << pelicula.get_title() << std::endl;
		}
	}   
	// return movies;
}

void Cine::filter_by_date(const std::string& date) {
	for (auto sala : this->salas) {
	//(Id Funcion): <Funcion para "(Título)" en la sala (Id Sala) con fecha (DD/MM/AAAA) - (hh:mm)>
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
