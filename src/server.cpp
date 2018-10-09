#include <netdb.h>
#include <sys/socket.h>
#include <string>
#include <vector>

#include "server.h"
#include "server_command_parser.h"

#define NUM_ARGS 5

#define SUCCESS 0
#define USAGE_ERROR 1
#define FILE_ERROR 2

Server::Server(const std::string& service, const std::string& salasFile,
	const std::string& peliculasFile, const std::string& funcionesFile) : 
	cine(salasFile, peliculasFile, funcionesFile),
	buffer(BUF_SIZE),
	acceptSkt(nullptr, service, AI_PASSIVE),
	peerSkt(-1) {
		this->acceptSkt.bind();
		this->acceptSkt.listen(MAX_LISTEN);
		this->peerSkt = this->acceptSkt.accept();
	}

Server::~Server() {}

void Server::run() {
	bool running = true;
	while (running) {
		int received = this->peerSkt.receive(this->buffer);
		running = (received > 0);
		if (running) {
			this->send_response(std::string(this->buffer.begin(), this->buffer.end()));
		}
	}
}

void Server::send_response(const std::string& msg) {
	CommandParser commandParser(msg);
	const std::string cmd = commandParser.get_command();
	const std::string value = commandParser.get_value();
	if (cmd == "IDIOMA") {
		// std::string movies = 
		this->cine.filter_by_language(value);
		// this->peerSkt.send(std::vector<char>(movies.begin(),movies.end()));
	}
	if (cmd == "EDAD") {
		// std::string movies = 
		this->cine.filter_by_rating(value);
		// this->peerSkt.send(std::vector<char>(movies.begin(),movies.end()));
	}
	if (cmd == "GENERO") {
		// std::string movies = 
		this->cine.filter_by_genre(value);
		// this->peerSkt.send(std::vector<char>(movies.begin(),movies.end()));
	}
	if (cmd == "FECHA") {
		// std::string movies = 
		this->cine.filter_by_genre(value);
		// this->peerSkt.send(std::vector<char>(movies.begin(),movies.end()));
	}
	if (cmd == "ASIENTOS") {
		// std::string movies = 
		this->cine.view_seats(value);
		// this->peerSkt.send(std::vector<char>(movies.begin(),movies.end()));
	}
	if (cmd == "RESERVA") {
		// std::string movies = 
		this->cine.reserve_seat(value);
		// this->peerSkt.send(std::vector<char>(movies.begin(),movies.end()));
	}
}


int main(int argc, const char *argv[]) {
	if (argc != NUM_ARGS) {
		std::cerr << "Uso: " << argv[0]
				  << " <puerto> <salas.csv> <peliculas.csv> <funciones.csv>"
				  << std::endl;
		return USAGE_ERROR;
	} else {
		try {
		Server servidor(argv[1], argv[2], argv[3], argv[4]);
		servidor.run();
		} catch (Exception &e) {
			std::cerr << e.what();
			return FILE_ERROR;
		}
		// servidor.send_response("GENERO Terror");
		return SUCCESS;
	}
}
