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
private:
    double port;
    int socketFD ;
    sockaddr_in address{};
    int clientSoc;

public:
    Server(){
        port=0;
        socketFD=-1;
        clientSoc=-1;

    }


    void setPort(double p) {
        port = p;
    }

    int getSocketFD() {
        return socketFD;
    }

    int getClientSoc() { return clientSoc; }

    int openSocket();

    int bindSocket();

    int listenToClients();

    int acceptClients();

    void closeSocketFD() {
        socketFD = -1;
    }

    static vector<double> valuesInDouble(char *buffer);

    static void runningServerThread(Server &server);


};


#endif //FLIGHT_SIM1_SERVER_H
