#ifndef __SERVER_SALA_MEDIANA_H__
#define __SERVER_SALA_MEDIANA_H__

#include <string>

#include "server_sala.h"

#define SALA_MEDIANA_FILAS 'J'
#define SALA_MEDIANA_COLUMNAS 11

class SalaMediana : public Sala {
public:
	SalaMediana(const std::string& id, const std::string& screen);

	~SalaMediana();
};

#endif
