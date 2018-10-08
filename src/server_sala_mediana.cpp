#include <string>
#include "server_sala_mediana.h"

SalaMediana::SalaMediana(const std::string& id, const std::string& screen) : 
	Sala(id, screen, SALA_MEDIANA_FILAS, SALA_MEDIANA_COLUMNAS) {}

SalaMediana::~SalaMediana() {}
