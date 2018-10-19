#include <string>
#include <vector>
#include "server_sala.h"

Sala::Sala(const std::string& id, const std::string& screen,
		   const char filas, const unsigned columnas) : 
	salaID(id),
	pantalla(screen),
	ultimaFila(filas),
	ultimaColumna(columnas) {}

Sala::~Sala() {}

std::string Sala::get_ID() const {
	return this->salaID;
}

char Sala::get_ultimaFila() const {
	return this->ultimaFila;
}

unsigned Sala::get_ultimaColumna() const {
	return this->ultimaColumna;
}

bool Sala::valid_seat(const char fila, const unsigned columna) {
	return ((fila <= this->ultimaFila) && (columna <= this->ultimaColumna));
}

unsigned Sala::size() const {
	return ((this->ultimaFila - 'A' + 1) * this->ultimaColumna);
}
