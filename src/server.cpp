#define _POSIX_C_SOURCE 200112L

#include <string>

#include "server.h"

#define NUM_ARGS 5

#define SUCCESS 0
#define USAGE_ERROR 1
#define FILE_ERROR 2

Server::Server(const std::string& service, const std::string& salasFile,
	const std::string& peliculasFile, const std::string& funcionesFile) : 
	cine(salasFile, peliculasFile, funcionesFile)
	// ,socket(nullptr, service, AI_PASSIVE) 
	{
}

Server::~Server() {}


int main(int argc, const char *argv[]) {
	if (argc != NUM_ARGS) {
		std::cerr << "Uso: " << argv[0]
				  << " <puerto> <salas.csv> <peliculas.csv> <funciones.csv>"
				  << std::endl;
		return USAGE_ERROR;
	} else {
		Server servidor(argv[1], argv[2], argv[3], argv[4]);

		return SUCCESS;
	}
}
