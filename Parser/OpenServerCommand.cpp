#include "OpenServerCommand.h"
#include "SymbolTable.h"
// Server side C/C++ program to demonstrate Socket programming

void OpenServerCommand::init(vector<std::string> &origLexer, int index) {
    for (int i = 1; i <= numberOfParameters; i++) {
        commandLexer.push_back(origLexer.at(index + i));
    }

    double port = stoi(commandLexer.at(0));
    server.setPort(port);
}

void OpenServerCommand::execute() {
    server.openSocket();
    server.bindSocket();
    server.listenToClients();
    server.acceptClients();
}




