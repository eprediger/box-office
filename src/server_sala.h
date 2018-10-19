#ifndef __SERVER_SALA_H__
#define __SERVER_SALA_H__

#include <string>
#include <vector>
#include <algorithm>

class Sala {
protected:
	Sala(const std::string& id, const std::string& screen,
		   const char filas, const unsigned columnas);

public:
	virtual ~Sala();

	std::string get_ID() const;

	char get_ultimaFila() const;

	unsigned get_ultimaColumna() const;

	unsigned size() const;

private:
	bool valid_seat(const char fila, const unsigned columna);

private:
	const std::string salaID;
	const std::string pantalla;

protected:
	char ultimaFila;
	unsigned ultimaColumna;
};

#endif
