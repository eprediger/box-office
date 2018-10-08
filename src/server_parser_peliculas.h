#ifndef __SERVER_PARSER_PELICULAS_H__
#define __SERVER_PARSER_PELICULAS_H__

#include <string>
#include <vector>

#include "server_parser_file.h"
#include "server_pelicula.h"

class PeliculasParser : public CSVParser {
public:
	explicit PeliculasParser(const std::string& filename);

	~PeliculasParser();

	void parse_peliculas(std::vector<Pelicula>& peliculas);

private:
	std::string title, lang, rating, genre;
};

#endif
