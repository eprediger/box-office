#include <string>
#include <vector>

#include "server_accepted_client.h"
#include "server_command_parser.h"

AcceptedClient::AcceptedClient(const Server& server, Cine& cine) : 
	peerSkt(server.accept()),
	cine(cine),
	buffer() {}

AcceptedClient::~AcceptedClient() {}

void AcceptedClient::run() {
	bool running = true;
	while (running) {
		uint32_t length = 0;
		size_t received = this->peerSkt.receive_number(&length);
		std::unique_ptr<char[]> buffer(new char[length]());
		this->peerSkt.receive(&buffer[0], length);
		this->buffer = std::string(&buffer[0], length);
		running = (received > 0);
		if (running) {
			this->send_response(this->buffer);
		}
		this->buffer.clear();
	}
}

void AcceptedClient::send_response(const std::string& msg) {
	CommandParser commandParser(msg);
	const std::string cmd = commandParser.get_command();
	const std::vector<std::string> values = commandParser.get_values();
	std::string message;
	if (cmd == "IDIOMA") {
		message = this->cine.filter_by_language(values[0]);
	}
	if (cmd == "EDAD") {
		message = this->cine.filter_by_rating(values[0]);
	}
	if (cmd == "GENERO") {
		message = this->cine.filter_by_genre(values[0]);
	}
	if (cmd == "FECHA") {
		message = this->cine.filter_by_date(values[0]);
	}
	if (cmd == "ASIENTOS") {
		message = this->cine.view_seats(values[0]);
	}
	if (cmd == "RESERVA") {
		message = this->cine.reserve_seat(values[0], values[1], values[2]);
	}
	this->peerSkt.send_length(message.length()+1);
	this->peerSkt.send(message.c_str(), message.length()+1);
}
