#include "server_parser_peliculas.h"

PeliculasParser::PeliculasParser(const std::string& filename) :
	CSVParser(filename),
	title(), 
	lang(), 
	rating(), 
	genre() {}

PeliculasParser::~PeliculasParser() {}

void PeliculasParser::parse_peliculas(std::vector<Pelicula>& peliculas) {
	// this->read_file();

	while (std::getline(this->file, this->title, this->delim)) {
		std::getline(this->file, this->lang, this->delim);
		std::getline(this->file, this->rating, this->delim);
		std::getline(this->file, this->genre);
		// std::cout << "Title: " << this->title << " | Lang: " << this->lang << " | Rating: " << this->rating <<" | Genre: " << this->genre << std::endl;
		peliculas.push_back(Pelicula(this->title, this->lang, this->rating, this->genre));
	}
	
	/*Idioma lang;
	if (this->lang == "ESP") {
		lang = Idioma::ESP;
	}
	if (this->lang == "SUB") {
		lang = Idioma::SUB;
	}
	
	Rating rating;
	if (this->rating == "ATP") {
		rating = Rating::ATP;
	}
	if (this->rating == "+13") {
		rating = Rating::MAYOR_TRECE;
	}
	if (this->rating == "+18") {
		rating = Rating::MAYOR_DIECIOCHO;
	}

	Genero genre;
	if (this->genre == "Drama") {
		genre = Genero::Drama;
	}
	if (this->genre == "Accion") {
		genre = Genero::Accion;
	}
	if (this->genre == "Comedia") {
		genre = Genero::Comedia;
	}
	if (this->genre == "Animacion") {
		genre = Genero::Animacion;
	}
	if (this->genre == "Terror") {
		genre = Genero::Terror;
	}
	if (this->genre == "Suspenso") {
		genre = Genero::Suspenso;
	}*/
}

/*int main(int argc, char const *argv[]) {
	PeliculasParser peliculas(argv[3]);
	
	while(peliculas.has_items()) {
		peliculas.get_pelicula();
	}
	return 0;
}*/
