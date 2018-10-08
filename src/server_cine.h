#ifndef __SERVER_CINE_H__
#define __SERVER_CINE_H__

#include <string>
#include <vector>
#include <map>

#include "server_parser_salas.h"
#include "server_parser_peliculas.h"
#include "server_parser_funciones.h"
#include "server_sala.h"
#include "server_pelicula.h"

#include <iostream> // test filters

class Cine {
public:
	Cine(const std::string& salasFile, const std::string& peliculasFile, 
		 const std::string& funcionesFile);
	
	~Cine();

	void filter_by_language(const std::string& lang);

	void filter_by_rating(const std::string& rating);

	void filter_by_genre(const std::string& genre);

	void filter_by_date(const std::string& date);

	void view_seats(const unsigned funcionID);

	void reserve_seat(const unsigned funcionID, const std::string& fila,
					  const std::string& columna);

private:
	std::vector<Pelicula> cartelera;
	std::map<std::string, Sala> salas;
};

#endif
