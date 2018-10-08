#ifndef __SERVER_SALA_MEDIANA_H__
#define __SERVER_SALA_MEDIANA_H__

#include <string>

#include "server_sala.h"

#define SALA_MEDIANA_FILAS 'K'
#define SALA_MEDIANA_COLUMNAS 10

class SalaMediana : public Sala {
public:
	SalaMediana(const std::string& id, const std::string& screen);

	~SalaMediana();
};

#endif
