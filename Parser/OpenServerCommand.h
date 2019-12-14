//
// Created by yekaterina on 14/12/2019.
//

#ifndef FLIGHT_SIM1_OPENSERVERCOMMAND_H
#define FLIGHT_SIM1_OPENSERVERCOMMAND_H

#include <sys/socket.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include "Command.h"
#include <mutex>
#include <thread>

#define MAX_CONNECTED 10

class OpenServerCommand : public Command {
    unsigned int port = 0;
    vector<double> values;
    mutex mutex_lock;

    void addToMap(char * buffer,int size);

public:

    OpenServerCommand() {
        numberOfParameters = 1;
    }

    virtual void init(vector<string> &origLexer, int index);

    virtual int execute();

    virtual ~OpenServerCommand() {}

    int openSocket();

    int bindListenSocket(int socketFd);

    static void serverThread(void* obj);

    void threadWork();

    void readFromClient(int client_socket);

};


#endif //FLIGHT_SIM1_OPENSERVERCOMMAND_H
