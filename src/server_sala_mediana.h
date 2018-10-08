#ifndef __SERVER_SALA_MEDIANA_H__
#define __SERVER_SALA_MEDIANA_H__

#include "server_sala.h"

#define SALA_MEDIANA_FILAS 'K'
#define SALA_MEDIANA_COLUMNAS 10

class SalaMediana : public Sala {
public:
	SalaMediana(std::string& id, std::string& screen);

	~SalaMediana();

private:
	unsigned filas, columnas;
	//std::vector<Asiento> asientos;
};

#endif
