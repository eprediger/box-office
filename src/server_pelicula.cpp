#include "server_pelicula.h"

Pelicula::Pelicula(const std::string& title, const std::string& lang, const std::string& rating, const std::string& genre) : 
	title(title), 
	lang(lang), 
	rating(rating), 
	genre(genre) {}

Pelicula::~Pelicula() {}

std::string Pelicula::get_title() const {
	return this->title;
}

std::string Pelicula::get_lang() const {
	return this->lang;
}

std::string Pelicula::get_rating() const {
	return this->rating;
}

std::string Pelicula::get_genre() const {
	return this->genre;
}
