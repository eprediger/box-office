#include <iostream>

#define NUM_ARGS 3

#define SUCCESS 0
#define USAGE_ERROR 1

int main(int argc, const char *argv[]) {
	if (argc != NUM_ARGS) {
		std::cerr << "Uso: " << argv[0] << " <ip-servidor> <puerto-servidor>" << std::endl;
		return USAGE_ERROR;
	} else {
		
		return SUCCESS;
	}
}