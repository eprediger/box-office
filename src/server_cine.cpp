#include <string>
#include <exception>
#include "server_cine.h"

Cine::Cine(const std::string& salasFile, const std::string& peliculasFile,
	       const std::string& funcionesFile) :
	cartelera(),
	salas() {
	try {
		SalasParser salasParser(salasFile);
		PeliculasParser peliculasParser(peliculasFile);
		FuncionesParser funcionesParser(funcionesFile);
		salasParser.parse_salas(this->salas);
		peliculasParser.parse_peliculas(this->cartelera);
		funcionesParser.parse_funciones(this->cartelera, this->salas);
	} catch (const std::exception& e) {
		throw;
	}
}

Cine::~Cine() {}

std::string Cine::filter_by_language(const std::string& lang) {
	std::string movies;
	for (auto pelicula : this->cartelera) {
		if (pelicula.get_lang() == lang) {
			movies += pelicula.get_title() + '\n';
		}
	}
	if (movies.empty()) {
		movies = "Idioma no reconocido\n";
	}
	return movies;
}

std::string Cine::filter_by_rating(const std::string& rating) {
	std::string movies;
	for (auto pelicula : this->cartelera) {
		if (pelicula.get_rating() == rating) {
			movies += pelicula.get_title() + '\n';
		}
	}
	if (movies.empty()) {
		movies = "Edad no reconocida\n";
	}
	return movies;
}

std::string Cine::filter_by_genre(const std::string& genre) {
	std::string movies;
	for (auto pelicula : this->cartelera) {
		if (pelicula.get_genre() == genre) {
			movies += pelicula.get_title() + "\n";
		}
	}
	if (movies.empty()) {
		movies = "Genero no reconocido\n";
	}
	return movies;
}

std::string Cine::filter_by_date(const std::string& date) {
	Lock l(m);
	std::string movies;
	for (auto sala : this->salas) {
		movies += sala.second.get_title_by_date(date);
	}
	return movies;
}

std::string Cine::view_seats(const std::string& funcion) {
	Lock l(m);
	unsigned funcionID = (unsigned int) std::stoul(funcion, nullptr, 10);
	std::string movies;
	for (auto sala : this->salas) {
		if (sala.second.has_funcionID(funcionID)) {
			movies += sala.second.show_seats(funcionID);
		}
	}
	return movies;
}

std::string Cine::reserve_seat(const std::string& funcion,
			const std::string& fila, const std::string& columna) {
	Lock l(m);
	unsigned funcionID = (unsigned int) std::stoul(funcion, nullptr, 10);
	std::string response;
	for (auto& sala : this->salas) {
		if (sala.second.has_funcionID(funcionID)) {
			response += sala.second.reserve_seat(funcionID, fila, columna);
		}
	}
	return response;
}
