#include <iostream>
#include <vector>

#include "common_exception.h"
#include "common_file_exception.h"
#include "server.h"
#include "server_cine.h"
#include "server_exit_thread.h"
#include "server_accepted_client.h"

#define SRV_ARGS 5

#define SUCCESS 0
#define PARAM_ERROR 1
#define USAGE_ERROR 2

void joinAndDelete(std::vector<AcceptedClient*> &threads,
				   ExitThread &exitThread) {
	std::for_each(threads.begin(), threads.end(),
				  [](AcceptedClient *&AcceptedClient) {
				  AcceptedClient->join();
				  delete AcceptedClient;
				});
  exitThread.join();
}

int main(int argc, const char *argv[]) {
	if (argc != SRV_ARGS) {
		std::cerr << "Uso: " << argv[0]
				  << " <puerto> <salas.csv> <peliculas.csv> <funciones.csv>"
				  << std::endl;
		return PARAM_ERROR;
	} else {
		try {
			Server servidor(argv[1]);
			Cine cine(argv[2], argv[3], argv[4]);
			std::vector<AcceptedClient*> clientes;
			ExitThread exitThread(servidor);
			exitThread.start();
			
			while(servidor.keepAccepting()) {
				try {
					clientes.push_back(new AcceptedClient(servidor, cine));
				} catch (const Exception& error) {
					error.what();
					joinAndDelete(clientes, exitThread);
					return SUCCESS;
				}
				clientes.back()->start();
			}
			joinAndDelete(clientes, exitThread);
			return SUCCESS;
		} catch (const FileException& fe) {
			std::cerr << fe.what() << std::endl;
			return PARAM_ERROR;
		} catch (const Exception& e) {
			std::cerr << e.what() << std::endl;
			return USAGE_ERROR;
		}
	}
}
