#ifndef __CLIENT_H__
#define __CLIENT_H__

#include "common_socket.h"

#include <string>

class Client {
public:
	Client(const char* host, const char* service);

	~Client();

	void send_payload(const std::string& payload);

	void recv_payload();

private:
	Socket connectionSkt;
};

#endif
