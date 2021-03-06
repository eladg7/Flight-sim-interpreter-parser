#ifndef FLIGHT_SIM1_PRINTCOMMAND_H
#define FLIGHT_SIM1_PRINTCOMMAND_H

#include "FuncCommand.h"
#include "../Server.h"
#include "../Client.h"
#include <iostream>

using namespace std;

class PrintCommand : public FuncCommand {
private:
    Server *server;
    Client *client;

    string updateArgument();

public:
    PrintCommand(Server &s, Client &c) {
        numberOfParameters = 1;
        server = &s;
        client = &c;
    }

    virtual void execute();
};

#endif //FLIGHT_SIM1_PRINTCOMMAND_H
