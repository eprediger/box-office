#ifndef __SERVER_PELICULA_H__
#define __SERVER_PELICULA_H__

#include <string>

/*enum class Idioma { ESP, SUB };
enum class Rating { ATP, MAYOR_TRECE, MAYOR_DIECIOCHO };
enum class Genero { Drama, Accion, Comedia, Animacion, Terror, Suspenso };*/

class Pelicula {
public:
	explicit Pelicula(const std::string& title, const std::string& lang,
			 		  const std::string& rating, const std::string& genre);

	~Pelicula();

	std::string get_title() const;

	std::string get_lang() const;

	std::string get_rating() const;

	std::string get_genre() const;

private:
	const std::string title;
	const std::string lang;
	const std::string rating;
	const std::string genre;
};

struct find_by_title {
	explicit find_by_title(const std::string& title) : title(title) {}
	bool operator()(const Pelicula& pelicula) const {
		return pelicula.get_title() == title;
	}
private:
	const std::string title;
};

#endif
