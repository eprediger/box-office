#include "server_exit_thread.h"

#include <string>

ExitThread::ExitThread(Server& server) :
	server(server) {}

ExitThread::~ExitThread() {}

void ExitThread::run() {
	std::string instruction;
	while (instruction != "q") {
		std::cin >> instruction;
	}
	this->server.shutdown();
}
