#ifndef __SERVER_SALA_CHICA_H__
#define __SERVER_SALA_CHICA_H__

#include <string>

#include "server_sala.h"

#define SALA_CHICA_FILAS 'E'
#define SALA_CHICA_COLUMNAS 6

class SalaChica : public Sala {
public:
	SalaChica(const std::string& id, const std::string& screen);

	~SalaChica();
};

#endif
