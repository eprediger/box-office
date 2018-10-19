#include <netdb.h>
#include <sys/socket.h>
#include <iostream>
#include <vector>
#include <string>

#include "client.h"

#define BUF_SIZE 1024

Client::Client(const char* host, const char* service) : 
	connectionSkt(host, service, 0) {
	this->connectionSkt.connect();
}

Client::~Client() {}

void Client::send_payload(const std::string& payload) {
	this->connectionSkt.send_length(payload.length());
	this->connectionSkt.send(payload.c_str(), payload.length());
}

void Client::recv_payload() {
	uint32_t length = 0;
	this->connectionSkt.receive_number(&length);
	char* buffer = new char[length+1]();
	this->connectionSkt.receive(&buffer[0], length);
	std::cout << buffer;
	delete[] buffer;
}
