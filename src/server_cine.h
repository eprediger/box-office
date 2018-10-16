#ifndef __SERVER_CINE_H__
#define __SERVER_CINE_H__

#include <string>
#include <vector>
#include <map>
#include <mutex>

#include "server_parser_salas.h"
#include "server_parser_peliculas.h"
#include "server_parser_funciones.h"
#include "server_sala.h"
#include "server_pelicula.h"

class Cine {
public:
	Cine(const std::string& salasFile, const std::string& peliculasFile, 
		 const std::string& funcionesFile);

	~Cine();

	std::string filter_by_language(const std::string& lang);

	std::string filter_by_rating(const std::string& rating);

	std::string filter_by_genre(const std::string& genre);

	std::string filter_by_date(const std::string& date);

	std::string view_seats(const std::string& funcion);

	std::string reserve_seat(const std::string& funcion, 
				const std::string& fila, const std::string& columna);

private:
	std::vector<Pelicula> cartelera;
	std::map<std::string, Sala> salas;

	std::mutex m;
};

#endif
