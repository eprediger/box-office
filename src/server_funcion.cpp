#include <string>
#include <vector>
#include "server_funcion.h"

Funcion::Funcion(const unsigned id, Sala& sala, Pelicula& pelicula,
				 const std::string& fecha, const std::string& hora) :
	idFuncion(id),
	sala(sala),
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

std::string Funcion::get_time() const {
	return this->hora;
}

std::string Funcion::get_title() const {
	return this->pelicula.get_title();
}

std::string Funcion::function_info() const {
	std::string msg = std::to_string(this->idFuncion) + ": <Funcion para \""
	+ this->pelicula.get_title() + "\" en la sala " + this->sala.get_ID()
	+ " con fecha " + this->fecha + " - " + this->hora + ">";

	if (this->asientos.size() == this->sala.size()) {	// sala llena
		msg += " AGOTADA";
	}

	msg += "\n";
	return msg;
}

std::string Funcion::show_seats() {
	std::string seats = "Asientos:\n";

	for (unsigned i = 1; i <= sala.get_ultimaColumna(); ++i)	{
		seats += "\t" + std::to_string(i);
	}
	seats += "\n";

	for (char i = 'A'; i <= sala.get_ultimaFila(); ++i) {
		seats += i;
		for (unsigned j = 1; j <= sala.get_ultimaColumna(); ++j)	{
			std::vector<Asiento>::iterator it_seat;
			it_seat = std::find_if(this->asientos.begin(), this->asientos.end(),
						find_by_position(i, j));
			if (it_seat == this->asientos.end()) { // El asiento no existe
				seats += "\tO";
			} else {	// asiento reservado
				seats += "\tX";
			}
		}
		seats += "\n";
	}
	return seats;
}

std::string Funcion::reserve_seat(const char fila, const unsigned columna) {
	std::string msg;
	std::vector<Asiento>::iterator it_asiento;
	it_asiento = std::find_if(this->asientos.begin(), this->asientos.end(),
				find_by_position(fila, columna));

	if (it_asiento == this->asientos.end()) { // El asiento no existe
		this->asientos.push_back(Asiento(fila, columna));
		msg = "OK\n";
	} else { // El asiento existe
		msg = "ERROR: El asiento ya está reservado\n";
	}
	return msg;
}
