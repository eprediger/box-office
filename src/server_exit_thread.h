#ifndef __SERVER_EXIT_THREAD_H__
#define __SERVER_EXIT_THREAD_H__

#include "server.h"
#include "common_thread.h"

class ExitThread : public Thread {
public:
	explicit ExitThread(Server& server);

	~ExitThread();

protected:
	void run() override;

private:
	Server& server;
};

#endif
