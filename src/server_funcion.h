#ifndef __SERVER_FUNCION_H__
#define __SERVER_FUNCION_H__

#include "server_sala.h"
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
	Funcion(const unsigned id, Sala& sala, Pelicula& pelicula,
			const std::string& fecha, const std::string& hora);

	~Funcion();

	unsigned get_id() const;

	std::string get_fecha() const;
	
	std::string get_time() const;

	std::string get_title() const;

	std::string function_info() const;

	std::string show_seats();

	std::string reserve_seat(const char fila, const unsigned columna);

private:
	const unsigned idFuncion;
	Sala& sala;
	Pelicula& pelicula;
	const std::string fecha;
	const std::string hora;
	std::vector<Asiento> asientos;
};

struct find_by_date {
	explicit find_by_date(const std::string& fecha, std::string& msg) :
		fecha(fecha),
		msg(msg) {}
	void operator()(const std::pair<unsigned, Funcion>& funcPair) const {
		if (funcPair.second.get_fecha() == fecha) {
			msg += funcPair.second.function_info();
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
