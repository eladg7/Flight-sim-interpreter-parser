//
// Created by elad on 18/12/2019.
//

#include "ConnectClientCommand.h"



void ConnectClientCommand::init(vector<std::string> &origLexer, int index) {
    for (int i = 1; i <= numberOfParameters; i++) {
        string parm= origLexer.at(index + i);
        if(Lexer::isCharInString(parm, '"')){
            Lexer::eraseAllSubStr(parm,"\"");
        }else {//expression
            Interpreter interpreter;
            Expression *e = interpreter.interpret(parm);
            double value = e->calculate();
            delete(e);
            parm = to_string(value);
        }
        commandLexer.push_back(parm);
    }

    double port = stoi(commandLexer.at(1));
    client->setPort(port);
    auto ip = commandLexer.at(0);
    client->setIP(&ip[0]);
}

void ConnectClientCommand::execute() {
    client->openSocket();
    client->connectClient();
}