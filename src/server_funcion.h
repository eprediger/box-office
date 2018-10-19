#ifndef __SERVER_FUNCION_H__
#define __SERVER_FUNCION_H__

#include "server_pelicula.h"
#include "server_asiento.h"

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>

// typedef unsigned Funcion_ID;

class Funcion {
public:
	Funcion(const unsigned id, Pelicula& pelicula, const std::string& fecha,
			const std::string& hora);

	~Funcion();

	unsigned get_id() const;

	std::string get_fecha() const;
	
	std::string get_time() const;

	std::string get_title() const;

	std::string function_info(const std::string& sala) const;

	std::string show_seats(const char maxFil, const unsigned maxCol);

	std::string reserve_seat(const char fila, const unsigned columna);

private:
	const unsigned idFuncion;
	Pelicula& pelicula;
	const std::string fecha;
	const std::string hora;
	std::vector<Asiento> asientos;
};

struct find_by_date {
	explicit find_by_date(const std::string fecha,
		const std::string& sala, std::string& msg) :
		fecha(fecha),
		sala(sala),
		msg(msg) {}
	void operator()(const Funcion& func) const {
		if (func.get_fecha() == fecha) {
			msg += func.function_info(sala);
		}
	}
private:
	const std::string fecha;
	const std::string sala;
	std::string& msg;
};

struct find_by_id {
	explicit find_by_id(const unsigned id) : id(id) {}
	bool operator()(const Funcion& func) const {
		return func.get_id() == id;
	}
private:
	const unsigned id;
};

#endif
