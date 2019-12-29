//
// Created by elad on 18/12/2019.
//

#include "ConnectClientCommand.h"
#include "../ex1Expressions.h"


void ConnectClientCommand::init(vector<std::string> &origLexer, int index) {
    //put the needed params
    commandLexer.clear();
    for (int i = 1; i <= numberOfParameters; i++) {
        string parm = origLexer.at(index + i);
        if (Lexer::isCharInString(parm, '"')) {
            Lexer::eraseAllSubStr(parm, "\"");
        } else {//expression
            parm = to_string(Interpreter::getDoubleFromExpression(parm));
        }
        commandLexer.push_back(parm);
    }

    // init to all params
    double port = stoi(commandLexer.at(1));
    client->setPort(port);
    auto ip = commandLexer.at(0);
    client->setIP(&ip[0]);
}

void ConnectClientCommand::execute() {
    client->openSocket();
    client->connectClient();
}