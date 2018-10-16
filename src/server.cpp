#define _POSIX_C_SOURCE 200112L

#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <string>
#include <vector>
#include <fcntl.h>

#include "server.h"
#include "server_command_parser.h"
#include "FailedAcceptException.h"

Server::Server(const char* service) :
	manualShutDown(false),
	acceptSkt(nullptr, service, AI_PASSIVE) {
	this->acceptSkt.bind();
	this->acceptSkt.listen(MAX_LISTEN);
}

Server::~Server() {
	if (!manualShutDown) {
		this->shutdown();
	}
}

Socket Server::accept() const {
	try {
		int peerSkt = this->acceptSkt.accept();
		if (peerSkt == -1) throw FailedAcceptException();
		return Socket(peerSkt);
	} catch (const std::runtime_error &error) {
		throw FailedAcceptException();
	}
}

bool Server::keepAccepting() {
	return (!(this->manualShutDown));
}

void Server::shutdown() {
	this->manualShutDown = true;
	this->acceptSkt.shutdown(SHUT_RDWR);
	this->acceptSkt.close();
}
