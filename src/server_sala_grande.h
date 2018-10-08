#ifndef __SERVER_SALA_GRANDE_H__
#define __SERVER_SALA_GRANDE_H__

#include "server_sala.h"

#define SALA_GRANDE_FILAS 'P'
#define SALA_GRANDE_COLUMNAS 15

class SalaGrande : public Sala {
public:
	SalaGrande(std::string& id, std::string& screen);

	~SalaGrande();
	
private:
	unsigned filas, columnas;
	//std::vector<Asiento> asientos;
};

#endif
