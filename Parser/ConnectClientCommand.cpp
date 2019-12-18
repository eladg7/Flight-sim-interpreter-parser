//
// Created by elad on 18/12/2019.
//

#include "ConnectClientCommand.h"

void ConnectClientCommand::init(vector<std::string> &origLexer, int index) {
    for (int i = 1; i <= numberOfParameters; i++) {
        commandLexer.push_back(origLexer.at(index + i));
    }

    double port = stoi(commandLexer.at(1));
    client.setPort(port);
    auto ip = commandLexer.at(0);
    client.setIP(&ip[0]);
}

void ConnectClientCommand::execute() {
    this->client.openSocket();
    this->client.connectClient();
}