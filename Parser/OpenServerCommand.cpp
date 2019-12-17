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

int OpenServerCommand::execute() {
    thread th(openServerThread, this);
    th.join();
    return numberOfParameters;
}

void OpenServerCommand::openServerThread(void *obj) {
    auto *myObj = (OpenServerCommand *) obj;
    myObj->openServerThreadExecution();
}

void OpenServerCommand::openServerThreadExecution() {
    int fd= server.openSocket();
    int clientSocket = server.bindListenSocket(fd);

    if (clientSocket < 0) {
        cerr << "server could not read data";
        return;
    }

    server.readFromClient(clientSocket);
//    close(socketFd); //closing the listening socket
}



