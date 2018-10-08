#ifndef __SERVER_H__
#define __SERVER_H__

#include <iostream>
#include <string>

#include "server_cine.h"

class Server {
public:
	Server(const std::string& service, const std::string& salasFile,
		   const std::string& peliculasFile, const std::string& funcionesFile);

	~Server();

private:
	Cine cine;
	// Socket socket;
};

#endif
