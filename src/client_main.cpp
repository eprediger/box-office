#include <iostream>
#include <string>

#include "client.h"

#define CLT_ARGS 3

#define SUCCESS 0
#define USAGE_ERROR 1

int main(int argc, const char *argv[]) {
	if (argc != CLT_ARGS) {
		std::cerr << "Uso: " << argv[0]
				  << " <ip-servidor> <puerto-servidor>" << std::endl;
		return USAGE_ERROR;
	} else {
		try {
			Client cliente(argv[1], argv[2]);
			std::string input;
			while (getline(std::cin, input)) {
				cliente.send_payload(input);
				cliente.recv_payload();
			}
		} catch (const Exception& error) {
			error.what();
			return USAGE_ERROR;
		}
		return SUCCESS;
	}
}
