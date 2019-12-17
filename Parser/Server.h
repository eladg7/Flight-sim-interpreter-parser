//
// Created by yekaterina on 16/12/2019.
//

#ifndef FLIGHT_SIM1_SERVER_H
#define FLIGHT_SIM1_SERVER_H

#include <sys/socket.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <vector>
#include <thread>
#include "SymbolTable.h"


using namespace std;
#define MAX_CONNECTED 1

class Server {
    double port{};
    int socketFD{};

public:

    void setPort(double p) {
        port = p;
    }

    int openSocket();

    int bindListenSocket(int socketFd);

    void readFromClient(int client_socket);

};


#endif //FLIGHT_SIM1_SERVER_H
