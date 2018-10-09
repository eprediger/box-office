#ifndef __CLIENT_H__
#define __CLIENT_H__

#include "common_socket.h"

class Client {
public:
	Client(const char* host, const char* service);

	~Client();

	void send(std::vector<char> v) const;

	void receive() const;

private:
	Socket connectionSkt;
};

#endif
