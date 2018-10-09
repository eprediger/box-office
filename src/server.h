#ifndef __SERVER_H__
#define __SERVER_H__

#include <iostream>
#include <string>
#include <vector>

#include "server_cine.h"
#include "common_socket.h"

#define MAX_LISTEN 1
#define BUF_SIZE 1024

class Server {
public:
	Server(const std::string& service, const std::string& salasFile,
		   const std::string& peliculasFile, const std::string& funcionesFile);

	~Server();

	void run();
	
	void send_response(const std::string& msg);

private:
	Cine cine;
	std::vector<char> buffer;
	Socket acceptSkt, peerSkt;
};

#endif
