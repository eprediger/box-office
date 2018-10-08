#include "server_sala_mediana.h"

SalaMediana::SalaMediana(std::string& id, std::string& screen) : 
	Sala(id, screen, SALA_MEDIANA_FILAS, SALA_MEDIANA_COLUMNAS) {}

SalaMediana::~SalaMediana() {}
