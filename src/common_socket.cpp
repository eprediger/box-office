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

Socket::Socket(Socket&& other) :
	skt_fd(other.skt_fd),
	address(other.address) {
	other.skt_fd = -1;
	other.address = nullptr;
}

Socket::~Socket() {
	if (this->address != nullptr) {
		freeaddrinfo(this->address);
	}
	if (this->skt_fd != -1) {
		close(this->skt_fd);
	}
}

void Socket::_bind() {
	int o = 1;	// one
	if (setsockopt(this->skt_fd, SOL_SOCKET,SO_REUSEADDR,&o,sizeof(o)) == -1) {
		throw Exception("reusing address error");
		// fprintf(stderr, "reusing address error: %s\n", strerror(errno));
	}

	struct sockaddr* address = this->address->ai_addr;
	socklen_t address_len = this->address->ai_addrlen;

	if (bind(this->skt_fd, address, address_len) == -1) {
		std::string msg = "Binding error: " + std::string(strerror(errno));
		throw Exception(msg);
		// fprintf(stderr, "binding error: %s\n", strerror(errno));
	}
}

void Socket::_listen(const int max_request) {
	if (listen(this->skt_fd, max_request) == -1) {
		std::string msg = "Listening error: " + std::string(strerror(errno));
		throw Exception(msg);
		// fprintf(stderr, "listening error: %s\n", strerror(errno));
	}
}

Socket Socket::_accept() {
	int client_socket = accept(this->skt_fd, nullptr, nullptr);
	if (client_socket == -1) {	// manejar error
	}
	return std::move(Socket(client_socket));
}
/*
int socket_connect(socket_t* self) {
	struct sockaddr* address = self->_address->ai_addr;
	socklen_t address_len = self->_address->ai_addrlen;
	
	int s = connect(self->_socket, address, address_len);
	if (s == -1) {
		fprintf(stderr, "connection error: %s\n", strerror(errno));
		socket_destroy(self);
		return -1;
	}

	return 0;
}

size_t Socket::_send(socket_t* self, const int* buf, const size_t size) {
	size_t sent = 0;
	int length_sent = 0;
	bool open_socket = true;
	bool valid_socket = true;

	while ((sent < size) && (valid_socket) && (open_socket)) {
		size_t remaining = size - sent;
		length_sent = send(self->_socket, &buf[sent], remaining, MSG_NOSIGNAL);

		if (length_sent < 0) {	// Error al enviar
			fprintf(stderr, "sending error: %s\n", strerror(errno));
			valid_socket = false;
		} else if (length_sent == 0) {	// Socket cerrado
			open_socket = false;
		} else {
			sent += length_sent;
		}
	}

	return sent;
}

size_t Socket::_receive(socket_t* self, int* buf, size_t size) {
	size_t received = 0;
	int len_recv = 0;
	bool open_socket = true;
	bool valid_socket = true;

	while ((received < size) && (valid_socket) && (open_socket)) {
		size_t remaining = size - received;
		len_recv = recv(self->_socket, &buf[received], remaining, MSG_NOSIGNAL);
		
		if (len_recv < 0) {	// Error al enviar
			fprintf(stderr, "receiving error: %s\n", strerror(errno));
			valid_socket = false;
		} else if (len_recv == 0) {	// Socket cerrado
			open_socket = false;
		} else {
			received += len_recv;
		}
	}
	return received;
}
*/
void Socket::_shutdown(const int how) {
	shutdown(this->skt_fd, how);	
}
