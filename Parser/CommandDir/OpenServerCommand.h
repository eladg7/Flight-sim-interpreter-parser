//
// Created by yekaterina on 14/12/2019.
//

#ifndef FLIGHT_SIM1_OPENSERVERCOMMAND_H
#define FLIGHT_SIM1_OPENSERVERCOMMAND_H


#include "Command.h"
#include "../Server.h"
#include <thread>
#include "../ex1Expressions.h"

class OpenServerCommand : public Command {
    Server *server{};


public:

    explicit OpenServerCommand(Server &s) {
        numberOfParameters = 1;
        server = &s;
    }

    virtual void init(vector<string> &origLexer,unsigned int index);

    virtual void execute();

    virtual ~OpenServerCommand() {}

};


#endif //FLIGHT_SIM1_OPENSERVERCOMMAND_H
