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
#define NUMBER_OF_VALUES 1024

class Server {
private:
    double port;
    int socketFD;
    sockaddr_in address{};
    int clientSoc;
    bool isRunning = false;
    static vector<string> previousValues;

    static vector<string> getRelevantValuesVector(char buffer[NUMBER_OF_VALUES], vector<string> splittedByN);

public:
    Server() {
        port = 0;
        socketFD = -1;
        clientSoc = -1;
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

    void turnOffRunningMode();

    void turnOnRunningMode();

    bool getIsRunning() { return isRunning; }


};


#endif //FLIGHT_SIM1_SERVER_H
