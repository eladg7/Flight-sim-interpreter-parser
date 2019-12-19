//
// Created by elad on 18/12/2019.
//

#ifndef FLIGHT_SIM1_CONNECTCLIENTCOMMAND_H
#define FLIGHT_SIM1_CONNECTCLIENTCOMMAND_H

#include "Command.h"
#include "Client.h"

class ConnectClientCommand : public Command {
private:
    Client client{};
public:
    explicit ConnectClientCommand(Client &client) {
        numberOfParameters = 2;
        this->client = client;
    }

    virtual void init(vector<string> &origLexer, int index);

    virtual void execute();

    virtual ~ConnectClientCommand() {}
};

#endif //FLIGHT_SIM1_CONNECTCLIENTCOMMAND_H
