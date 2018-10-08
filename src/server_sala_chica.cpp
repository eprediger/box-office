#include <string>
#include "server_sala_chica.h"

SalaChica::SalaChica(const std::string& id, const std::string& screen) : 
	Sala(id, screen, SALA_CHICA_FILAS, SALA_CHICA_COLUMNAS) {}
	
SalaChica::~SalaChica() {}
