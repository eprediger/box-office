#ifndef __COMMON_SOCKET_H__
#define __COMMON_SOCKET_H__

#include <string>
#include <vector>

#include "common_exception.h"

class Socket {
public:
	Socket(const char* node, const std::string& serv, const int flags);
	
	Socket(int fd);

	// Socket(Socket&& other);
	
	~Socket();

	void bind();

	void listen(const int max_request);

	int accept();

	void connect();

	void send(const std::vector<char>& buf) const;

	size_t receive(std::vector<char>& buf) const;

	void shutdown(const int how);

private:
	int skt_fd;
	struct addrinfo* address;
};

#endif
