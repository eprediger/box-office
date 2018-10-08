#include <iostream>

#include "server_parser_salas.h"
#include "server_parser_peliculas.h"
#include "server_parser_funciones.h"

#include "server_cine.h"

#define NUM_ARGS 5

#define SUCCESS 0
#define USAGE_ERROR 1
#define FILE_ERROR 2

int main(int argc, const char *argv[]) {
	if (argc != NUM_ARGS) {
		const std::string args = " <puerto> <salas.csv> <peliculas.csv> <funciones.csv>";
		std::cerr << "Uso: " << argv[0] << args << std::endl;
		return USAGE_ERROR;
	} else {
		SalasParser salas(argv[2]);
		PeliculasParser peliculas(argv[3]);
		FuncionesParser funciones(argv[4]);
		Cine cine(salas, peliculas, funciones);

		/*const std::string lang= "ESP";
		std::cout << "Filtrando por idioma... " << lang << std::endl;
		cine.filter_by_language(lang);
		
		const std::string rating = "+13";
		std::cout << std::endl << "Filtrando por rating... " << rating << std::endl;
		cine.filter_by_rating(rating);
		
		const std::string genero = "Terror";
		std::cout << std::endl << "Filtrando por genero..." << genero <<std::endl;
		cine.filter_by_genre(genero);

		const std::string fecha = "25/09/2018";
		std::cout << std::endl << "Filtro por fecha... " << fecha << std::endl;
		cine.filter_by_date(fecha);*/

		unsigned idFuncion = 2;
		std::cout << std::endl << "Consulta asientos ID función... \'" << idFuncion << "\'" << std::endl;
		cine.view_seats(idFuncion);

		std::string fila = "A";
		std::string columna = "1";
		std::cout << std::endl << "Reserva asiento... " << "Fila: " << fila << " Columna: " << columna << std::endl;
		cine.reserve_seat(idFuncion, fila, columna);

		std::cout << std::endl << "Consulta asientos ID función... \'" << idFuncion << "\'" << std::endl;
		cine.view_seats(idFuncion);

		fila = "B";
		columna = "2";
		std::cout << std::endl << "Reserva asiento... " << "Fila: " << fila << " Columna: " << columna << std::endl;
		cine.reserve_seat(idFuncion, fila, columna);

		idFuncion = 3;
		std::cout << std::endl << "Consulta asientos ID función... \'" << idFuncion << "\'" << std::endl;
		cine.view_seats(idFuncion);

		fila = "C";
		columna = "3";
		std::cout << std::endl << "Reserva asiento... " << "Fila: " << fila << " Columna: " << columna << std::endl;
		cine.reserve_seat(idFuncion, fila, columna);

		std::cout << std::endl << "Consulta asientos ID función... \'" << idFuncion << "\'" << std::endl;
		cine.view_seats(idFuncion);

		fila = "D";
		columna = "4";
		std::cout << std::endl << "Reserva asiento... " << "Fila: " << fila << " Columna: " << columna << std::endl;
		cine.reserve_seat(idFuncion, fila, columna);

		std::cout << std::endl << "Consulta asientos ID función... \'" << idFuncion << "\'" << std::endl;
		cine.view_seats(idFuncion);

		return SUCCESS;
	}
}
