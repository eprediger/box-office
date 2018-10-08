#include <netdb.h>
#include <sys/socket.h>
#include <string>

#include "server.h"

#define NUM_ARGS 5

#define SUCCESS 0
#define USAGE_ERROR 1
#define FILE_ERROR 2

#define MAX_LISTEN 1

Server::Server(const std::string& service, const std::string& salasFile,
	const std::string& peliculasFile, const std::string& funcionesFile) : 
	cine(salasFile, peliculasFile, funcionesFile),
	socket(nullptr, service, AI_PASSIVE) {
		this->socket._bind();
		this->socket._listen(MAX_LISTEN);
	}

Server::~Server() {
	this->socket._shutdown(SHUT_RDWR);
}


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
