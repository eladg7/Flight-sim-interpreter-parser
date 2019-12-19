//
// Created by elad on 18/12/2019.
//

#ifndef FLIGHT_SIM1_CONNECTCLIENTCOMMAND_H
#define FLIGHT_SIM1_CONNECTCLIENTCOMMAND_H

#include "Command.h"
#include "Client.h"
#include "../Lexer/Lexer.h"

class ConnectClientCommand : public Command {
private:
    Client *client{};
public:
    explicit ConnectClientCommand(Client &c) {
        numberOfParameters = 2;
        client = &c;
    }

    virtual void init(vector<string> &origLexer, int index);

    virtual void execute();

    virtual ~ConnectClientCommand() {}
};

#endif //FLIGHT_SIM1_CONNECTCLIENTCOMMAND_H
