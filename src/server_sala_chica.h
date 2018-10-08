#ifndef __SERVER_SALA_CHICA_H__
#define __SERVER_SALA_CHICA_H__

#include "server_sala.h"

#define SALA_CHICA_FILAS 'F'
#define SALA_CHICA_COLUMNAS 5

class SalaChica : public Sala {
public:
	SalaChica(std::string& id, std::string& screen);

	~SalaChica();
};

#endif
