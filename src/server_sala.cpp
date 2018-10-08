#include "server_sala.h"

Sala::Sala(std::string& id, std::string& screen, char filas, unsigned columnas) : 
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

void Sala::get_title_by_date(const std::string& date) {
	for (auto funcion : this->funciones) {
		funcion.get_title_by_date(date);
	}
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


void Sala::show_seats(const unsigned funcionID) {
	std::vector<Funcion>::iterator funcion_by_id;
	funcion_by_id = std::find_if(this->funciones.begin(), this->funciones.end(),
								find_by_id(funcionID));

	if (funcion_by_id != funciones.end()) {
		funcion_by_id->show_seats(this->ultimaFila, this->ultimaColumna);
	}
}

void Sala::reserve_seat(const unsigned funcionID, const std::string& fila, const std::string& columna) {
	std::vector<Funcion>::iterator funcion_by_id;
	funcion_by_id = std::find_if(this->funciones.begin(), this->funciones.end(),
								find_by_id(funcionID));

	if (funcion_by_id != funciones.end()) {	// existe funcionID
		char letraFila = fila[0];
		unsigned numColumna = (unsigned) std::stoul(columna, nullptr, 10);
		if (this->valid_seat(letraFila, numColumna)) {	// fila y columna validas
			funcion_by_id->reserve_seat(letraFila, numColumna);	
		} else {	// parametros incorrectos

		}
	}
}

bool Sala::valid_seat(const char fila, const unsigned columna) {
	return ((fila <= this->ultimaFila) && (columna <= this->ultimaColumna));
}
