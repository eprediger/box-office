#ifndef __SERVER_SALA_H__
#define __SERVER_SALA_H__

#include <string>
#include <vector>
#include <algorithm>

#include <iostream>

#include "server_funcion.h"

class Sala {
protected:
	Sala(const std::string& id, const std::string& screen,
		   const char filas, const unsigned columnas);

public:	
	virtual ~Sala();

	std::string get_ID() const;

	void nueva_funcion(const Funcion& funcion);

	void get_title_by_date(const std::string& date);

	bool has_funcionID(const unsigned funcionID);

	void show_seats(const unsigned funcionID);

	void reserve_seat(const unsigned funcionID, const std::string& fila,
					  const std::string& columna);

private:
	bool valid_seat(const char fila, const unsigned columna);

private:
	const std::string salaID;
	const std::string pantalla;
	std::vector<Funcion> funciones;

protected:
	char ultimaFila;
	unsigned ultimaColumna;
};

#endif
