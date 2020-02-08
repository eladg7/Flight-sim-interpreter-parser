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
#include <mutex>

using namespace std;

class Client {
private:
    int clientSocket = -1;

    int port = 0;

    char ip[32] = {0};

    bool isRunning = true;

    mutex clientMutex;
public:

    void turnOffRunningMode();

    void turnOnRunningMode();

    bool getIsRunning() {
        clientMutex.lock();
        bool result = isRunning;
        clientMutex.unlock();
        return result;
    }

    int openSocket();

    int connectClient();

    int getClientSocket() {
        return this->clientSocket;
    }

    static void runningClientThread(Client &client);

    void setPort(int p) {
        port = p;
    }

    void setIP(char *x) {
        strcpy(ip, x);
    }

    void closeClientSocket() {
        this->clientSocket = -1;
    }

};

#endif //FLIGHT_SIM1_CLIENT_H
