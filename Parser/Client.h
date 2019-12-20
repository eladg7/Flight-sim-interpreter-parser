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

    char ip[64] = {0};
    bool isRunning=false;
public:

    void turnOffRunningMode();

    void turnOnRunningMode();

    bool getIsRunning(){return isRunning;}

    int openSocket();

    int connectClient();

    int sendMessage(const char *msg);

    int getClientSocket() {
        return this->clientSocket;
    }

    static void runningClientThread(Client &client);

    void setPort(int p) {
       port = p;
    }

    void setIP(char *x) {
        strcat(ip, x);
    }

    void closeClientSocket() {
        this->clientSocket = -1;
    }

};

#endif //FLIGHT_SIM1_CLIENT_H
