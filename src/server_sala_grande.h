#ifndef __SERVER_SALA_GRANDE_H__
#define __SERVER_SALA_GRANDE_H__

#include <string>
#include "server_sala.h"

#define SALA_GRANDE_FILAS 'O'
#define SALA_GRANDE_COLUMNAS 16

class SalaGrande : public Sala {
public:
	SalaGrande(const std::string& id, const std::string& screen);

	~SalaGrande();
};

#endif
