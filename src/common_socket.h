#ifndef __COMMON_SOCKET_H__
#define __COMMON_SOCKET_H__

#include <string>

#include "common_exception.h"

class Socket {
public:
	Socket(const char* node, const std::string& serv, const int flags);
	
	Socket(int fd);

	Socket(Socket&& other);
	
	~Socket();

	void _bind();

	void _listen(const int max_request);

	Socket _accept();

	// int _connect();

	// size_t _send(const int* buf, const size_t size);

	// size_t _receive(int* buf, size_t size);

	void _shutdown(const int how);

private:
	int skt_fd;
	struct addrinfo* address;
};

#endif
