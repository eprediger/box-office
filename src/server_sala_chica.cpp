#include "server_sala_chica.h"

SalaChica::SalaChica(std::string& id, std::string& screen) : 
	Sala(id, screen, SALA_CHICA_FILAS, SALA_CHICA_COLUMNAS) {}
	
SalaChica::~SalaChica() {}
