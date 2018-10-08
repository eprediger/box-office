#include "server_asiento.h"

Asiento::Asiento(const unsigned fila, const char columna) :
	fila(fila),
	columna(columna),
	ocupado(true) {}

Asiento::Asiento(const Asiento& other) : 
	fila(other.fila),
	columna(other.columna),
	ocupado(other.ocupado) {}

Asiento::~Asiento() {}

unsigned Asiento::get_fila() const {
	return this->fila;
}

char Asiento::get_columna() const {
	return this->columna;
}

bool Asiento::esta_reservado() const {
	return this->ocupado;
}
