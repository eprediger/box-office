#ifndef __SERVER_ACCEPTED_CLIENT_H__
#define __SERVER_ACCEPTED_CLIENT_H__

#include <string>

#include "common_thread.h"
#include "server.h"
#include "server_cine.h"

class AcceptedClient : public Thread {
public:
	AcceptedClient(const Server& server, Cine& cine);
	// ~AcceptedClient();
	~AcceptedClient() override = default;

protected:
	void run() override;

private:
	void send_response(const std::string& msg);

private:
	const Socket peerSkt;
	Cine& cine;
	std::string buffer;
};

#endif
