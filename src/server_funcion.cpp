#include <string>
#include <vector>
#include "server_funcion.h"

Funcion::Funcion(const unsigned id, Pelicula& pelicula,
				 const std::string& fecha, const std::string& hora) :
	idFuncion(id),
	pelicula(pelicula),
	fecha(fecha),
	hora(hora),
	asientos() {}

Funcion::~Funcion() {}

unsigned Funcion::get_id() const {
	return this->idFuncion;
}

std::string Funcion::get_fecha() const {
	return this->fecha;
}

std::string Funcion::get_title() const {
	return this->pelicula.get_title();
}

void Funcion::get_title_by_date(const std::string& date) const {
	if (this->fecha == date) {
		std::cout << this->pelicula.get_title() << std::endl;
	}
}

void Funcion::show_seats(const char maxFil, const unsigned maxCol) {
	for (unsigned i = 1; i <= maxCol; ++i)	{
		std::cout << "\t" << i;
	}
	std::cout << std::endl;

	for (char i = 'A'; i <= maxFil; ++i) {
		std::cout << i;
		for (unsigned j = 1; j <= maxCol; ++j)	{
			std::vector<Asiento>::iterator it_seat;
			it_seat = std::find_if(this->asientos.begin(), this->asientos.end(),
						find_by_position(i, j));
			if (it_seat == this->asientos.end()) { // El asiento no existe
				std::cout << "\tO";
			} else {//if (it_asiento->esta_reservado()) {
				std::cout << "\tX";
			}
		}
		std::cout << std::endl;
	}
}


void Funcion::reserve_seat(const char fila, const unsigned columna) {
	std::vector<Asiento>::iterator it_asiento;
	it_asiento = std::find_if(this->asientos.begin(), this->asientos.end(),
				find_by_position(fila, columna));
	
	if (it_asiento == this->asientos.end()) { // El asiento no existe
		this->asientos.push_back(Asiento(fila, columna));
	} else { // El asiento existe
	}
}
