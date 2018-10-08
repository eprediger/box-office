#include "server_sala_grande.h"

SalaGrande::SalaGrande(std::string& id, std::string& screen) : 
	Sala(id, screen, SALA_GRANDE_FILAS, SALA_GRANDE_COLUMNAS) {}
	
SalaGrande::~SalaGrande() {}
