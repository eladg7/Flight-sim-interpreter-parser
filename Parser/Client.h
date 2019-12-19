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
public:
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
        if(x[0] == '\"'){
            x++;
        }
        if(x[strlen(x)- 1] == '\"'){
            x[strlen(x)- 1] = '\0';
        }
        strcat(ip,x);
    }

    void closeClientSocket() {
        this->clientSocket = -1;
    }
};

#endif //FLIGHT_SIM1_CLIENT_H
