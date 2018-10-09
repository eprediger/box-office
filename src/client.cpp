#include <netdb.h>
#include <sys/socket.h>
#include <iostream>
#include <vector>

#include "client.h"

#define BUF_SIZE 1024

Client::Client(const char* host, const char* service) : 
	connectionSkt(host, service, 0) {
	this->connectionSkt.connect();
	}

Client::~Client() {}

void Client::send(std::vector<char> v) const {
	this->connectionSkt.send(v);
}

void Client::receive() const {
	bool receiving = true;
	while (receiving) {
		std::vector<char> v(BUF_SIZE);
		int a = this->connectionSkt.receive(v);

		receiving = (a > 0);

		if (receiving) {
			std::cout << std::string(v.begin(), v.end()) << std::endl;
		}
	}
}

#define NUM_ARGS 3

#define SUCCESS 0
#define USAGE_ERROR 1

int main(int argc, const char *argv[]) {
	if (argc != NUM_ARGS) {
		std::cerr << "Uso: " << argv[0]
				  << " <ip-servidor> <puerto-servidor>" << std::endl;
		return USAGE_ERROR;
	} else {
		Client cliente(argv[1], argv[2]);
		std::string input;
		while (getline(std::cin, input)) {
			cliente.send(std::vector<char>(input.begin(),input.end()));
			// cliente.receive();
		}
		return SUCCESS;
	}
}
