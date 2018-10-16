#ifndef __SERVER_H__
#define __SERVER_H__

#include <iostream>
#include <string>
#include <vector>

#include "common_socket.h"

#define MAX_LISTEN 10
#define BUF_SIZE 1024

class Server {
public:
	explicit Server(const char* service);
	
	~Server();

	Socket accept() const;

	bool keepAccepting();

	void shutdown();

private:
	bool manualShutDown;
	Socket acceptSkt;
};

#endif
