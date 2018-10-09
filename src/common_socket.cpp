#define _POSIX_C_SOURCE 200112L

#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <cstring>
#include <errno.h>

#include <string>
#include <iostream>

#include "common_socket.h"

Socket::Socket(const char* node, const std::string& serv, const int flags) :
	skt_fd(-1),
	address(nullptr) {
	struct addrinfo hints{};
	struct addrinfo* result;
	
	hints.ai_family = AF_INET;			// IPv4
	hints.ai_socktype = SOCK_STREAM;	// TCP
	hints.ai_flags = flags;				// Server: AI_PASSIVE | Client: 0

	int s = getaddrinfo(node, serv.c_str(), &hints, &result);
	if (s != 0) {
		throw Exception(gai_strerror(s));
	}

	this->address = result;

	struct addrinfo *ptr;
	for (ptr = result; ptr != nullptr; ptr = ptr->ai_next) {
		int domain = ptr->ai_family;
		int type = ptr->ai_socktype;
		int protocol = ptr->ai_protocol;
		this->skt_fd = socket(domain, type, protocol);
	}

	if (this->skt_fd == -1) {
		throw Exception("Socket error");
   	}
}

Socket::Socket(const int fd) :
	skt_fd(fd),
	address(nullptr) {}

/*Socket::Socket(Socket&& other) :
	skt_fd(other.skt_fd),
	address(other.address) {
	other.skt_fd = -1;
	other.address = nullptr;
}*/

Socket::~Socket() {
	if (this->address != nullptr) {
		freeaddrinfo(this->address);
	}
	if (this->skt_fd != -1) {
		// shutdown(this->skt_fd, SHUT_RDWR);
		// close(this->skt_fd);
	}
}

void Socket::bind() {
	int o = 1;	// one
	if (setsockopt(this->skt_fd, SOL_SOCKET,SO_REUSEADDR,&o,sizeof(o)) == -1) {
		throw Exception("reusing address error");
		// fprintf(stderr, "reusing address error: %s\n", strerror(errno));
	}

	struct sockaddr* address = this->address->ai_addr;
	socklen_t address_len = this->address->ai_addrlen;

	if (::bind(this->skt_fd, address, address_len) == -1) {
		std::string msg = "Binding error: " + std::string(strerror(errno));
		throw Exception(msg);
	}
}

void Socket::listen(const int max_request) {
	if (::listen(this->skt_fd, max_request) == -1) {
		std::string msg = "Listening error: " + std::string(strerror(errno));
		throw Exception(msg);
	}
}

int Socket::accept() {
	int peer_socket = ::accept(this->skt_fd, nullptr, nullptr);
	if (peer_socket == -1) {	// manejar error
		std::string msg = "Accepting error: " + std::string(strerror(errno));
		throw Exception(msg);
	}
	return peer_socket;
}

void Socket::connect() {
	struct sockaddr* address = this->address->ai_addr;
	socklen_t address_len = this->address->ai_addrlen;
	
	if (::connect(this->skt_fd, address, address_len) == -1) {
		std::string msg = "Connection error: " + std::string(strerror(errno));
		throw Exception(msg);
	}
}

// size_t Socket::_send(const char* buf, const size_t size) const {
void Socket::send(const std::vector<char>& buf) const {
	auto size = buf.size();
	size_t sent = 0;
	int length_sent = 0;
	bool open_socket = true;

	while ((sent < size) && open_socket) {
		size_t remaining = size - sent;
		length_sent = ::send(this->skt_fd, &buf[sent], remaining, MSG_NOSIGNAL);

		if (length_sent < 0) {	// Error al enviar
			std::string msg = "Sending error: " + std::string(strerror(errno));
			throw Exception(msg);
		} else if  (length_sent == 0) {
			open_socket = false;
		} else {
			sent += length_sent;
		}
	}
}

size_t Socket::receive(std::vector<char>& buf) const {
	auto size = buf.size();
	size_t received = 0;
	int len_recv = 0;
	bool open_socket = true;

	while ((received < size) && (open_socket)) {
		size_t remaining = size - received;
		len_recv = ::recv(this->skt_fd, &buf[received], remaining, MSG_NOSIGNAL);
		
		if (len_recv < 0) {	// Error al recibir
			std::string msg = "Receiving error: " + std::string(strerror(errno));
			throw Exception(msg);
		} else if (len_recv == 0) {	// Socket cerrado
			open_socket = false;
		} else {
			received += len_recv;
		}
	}
	return received;
}

void Socket::shutdown(const int how) {
	::shutdown(this->skt_fd, how);
}
