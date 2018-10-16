#include <string>
#include "server_sala_grande.h"

SalaGrande::SalaGrande(const std::string& id, const std::string& screen) : 
	Sala(id, screen, SALA_GRANDE_FILAS, SALA_GRANDE_COLUMNAS) {}

SalaGrande::~SalaGrande() {}
