//
// Created by yekaterina on 14/12/2019.
//

#ifndef FLIGHT_SIM1_OPENSERVERCOMMAND_H
#define FLIGHT_SIM1_OPENSERVERCOMMAND_H


#include "Command.h"
#include "Server.h"
#include <thread>


class OpenServerCommand : public Command {
    Server server{};


public:

    explicit OpenServerCommand(Server &s) {
        numberOfParameters = 1;
        server=s;
    }

    virtual void init(vector<string> &origLexer, int index);

    virtual int execute();

    virtual ~OpenServerCommand() {}

    static void openServerThread(void* obj);

    void openServerThreadExecution();

};


#endif //FLIGHT_SIM1_OPENSERVERCOMMAND_H
