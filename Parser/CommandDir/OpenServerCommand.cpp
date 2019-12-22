#include "OpenServerCommand.h"
#include "../SymbolTable.h"
// Server side C/C++ program to demonstrate Socket programming

void OpenServerCommand::init(vector<std::string> &origLexer, int index) {
    commandLexer.clear();
    for (int i = 1; i <= numberOfParameters; i++) {
        string parm = origLexer.at(index + i);
        if (Lexer::isCharInString(parm, '"')) {
            Lexer::eraseAllSubStr(parm, "\"");
        } else {
            parm = to_string(getDoubleFromExpression(parm));
        }
        commandLexer.push_back(parm);
    }

    double port = stoi(commandLexer.at(0));
    server->setPort(port);
}

void OpenServerCommand::execute() {
    server->openSocket();
    server->bindSocket();
    server->listenToClients();
    server->acceptClients();
}
