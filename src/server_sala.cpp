#include <string>
#include <vector>
#include "server_sala.h"

Sala::Sala(const std::string& id, const std::string& screen,
		   const char filas, const unsigned columnas) : 
	salaID(id),
	pantalla(screen),
	funciones(),
	ultimaFila(filas),
	ultimaColumna(columnas) {}

Sala::~Sala() {}

std::string Sala::get_ID() const {
	return this->salaID;
}

void Sala::nueva_funcion(const Funcion& funcion) {
	this->funciones.push_back(funcion);
}

std::string Sala::get_title_by_date(const std::string& date) {
	std::string msg;
	std::for_each(this->funciones.begin(), this->funciones.end(),
				  find_by_date(date, this->salaID, msg));
	return msg;
}

bool Sala::has_funcionID(const unsigned funcionID) {
	bool found = false;

	std::vector<Funcion>::iterator funcion_by_id;
	funcion_by_id = std::find_if(this->funciones.begin(), this->funciones.end(),
								find_by_id(funcionID));

	if (funcion_by_id != funciones.end()) {
		found = true;
	}

	return found;
}


std::string Sala::show_seats(const unsigned funcionID) {
	std::string seats;
	std::vector<Funcion>::iterator funcion_by_id;
	funcion_by_id = std::find_if(this->funciones.begin(), this->funciones.end(),
								find_by_id(funcionID));

	if (funcion_by_id != funciones.end()) {
		seats = funcion_by_id->function_info(this->salaID) + 
		funcion_by_id->show_seats(this->ultimaFila, this->ultimaColumna);
	} else {
		// return "";
	}
	return seats;
}

std::string Sala::reserve_seat(const unsigned funcionID, 
	const std::string& fila, const std::string& columna) {
	std::vector<Funcion>::iterator funcion_by_id;
	funcion_by_id = std::find_if(this->funciones.begin(), this->funciones.end(),
								find_by_id(funcionID));

	std::string response;
	if (funcion_by_id != funciones.end()) {	// existe funcionID
		char letraFila = fila[0];
		unsigned numColumna = (unsigned) std::stoul(columna, nullptr, 10);
		if (this->valid_seat(letraFila, numColumna)) {
			response = funcion_by_id->reserve_seat(letraFila, numColumna);
		} else {
		// parametros incorrectos
		}
	}
	return response;
}

bool Sala::valid_seat(const char fila, const unsigned columna) {
	return ((fila <= this->ultimaFila) && (columna <= this->ultimaColumna));
}
