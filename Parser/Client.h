//
// Created by elad on 18/12/2019.
//

#ifndef FLIGHT_SIM1_CLIENT_H
#define FLIGHT_SIM1_CLIENT_H

#include <sys/socket.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>

using namespace std;

class Client {
private:
    int clientSocket = -1;

    int port = 0;

    char *ip = nullptr;
public:
    int openSocket();

    int connectClient();

    int sendMessage(const char *msg);

    void closeSocket() {
        this->clientSocket = -1;
    }

    int getClientSocket() {
        return this->clientSocket;
    }

    static void runningClientThread(void *obj);

    void setPort(int port) {
        this->port = port;
    }

    void setIP(char *ip) {
        this->ip = ip;
    }

    void closeClientSocket() {
        this->clientSocket = -1;
    }
};

#endif //FLIGHT_SIM1_CLIENT_H
