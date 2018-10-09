#include <iostream>

#define NUM_ARGS 5

#define SUCCESS 0
#define USAGE_ERROR 1
#define FILE_ERROR 2

void joinAndDelete(std::vector<ServerThread *> &threads,
									 WaitForQThread &waitForQThread) {
	std::for_each(threads.begin(), threads.end(),
								[](ServerThread *&serverThread) {
									serverThread->join();
									delete serverThread;
								});
	waitForQThread.join();
}

int main(int argc, const char *argv[]) {
	if (argc != NUM_ARGS) {
		std::cerr << "Uso: " << argv[0]
				  << " <puerto> <salas.csv> <peliculas.csv> <funciones.csv>"
				  << std::endl;
		return USAGE_ERROR;
	} else {
		ServerConnectionFactory connectionFactory(argv[1]);
		Cine cine;
		std::vector<ServerThread*> threads;
		WaitForQThread waitForQThread(connectionFactory);
		waitForQThread.start();

		while (connectionFactory.canAcceptConnection()) {
			try {
				threads.push_back(new ServerThread(connectionFactory, subeManager));
			} catch (AcceptFailedException &e) {
				joinAndDelete(threads, waitForQThread);
				return 0;
			}
			threads.back()->start();
		}

		joinAndDelete(threads, waitForQThread);
		return SUCCESS;
	}
}