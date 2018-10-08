#ifndef __SERVER_FUNCION_H__
#define __SERVER_FUNCION_H__

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>

#include "server_pelicula.h"
#include "server_asiento.h"

// typedef unsigned Funcion_ID;

class Funcion {
public:
	Funcion(const unsigned id, Pelicula& pelicula, const std::string& fecha, const std::string& hora);

	~Funcion();

	unsigned get_id() const;
	
	std::string get_fecha() const;

	std::string get_title() const;

	void get_title_by_date(const std::string& date) const;

	void show_seats(const char maxFil, const unsigned maxCol);

	void reserve_seat(const char fila, const unsigned columna);
	
private:
	const unsigned idFuncion;
	Pelicula& pelicula;
	const std::string fecha;
	const std::string hora;
	std::vector<Asiento> asientos;
};

struct find_by_id {
	find_by_id(const unsigned id) : id(id) {}
	bool operator()(const Funcion& func) const {
		return func.get_id() == id;
	}
private:
	const unsigned id;
};

#endif
