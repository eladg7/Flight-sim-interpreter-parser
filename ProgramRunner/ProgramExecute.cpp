//
// Created by elad on 26/12/2019.
//

#include "ProgramExecute.h"

void ProgramExecute::run() {
    char filename[1024] = {0};
    strcpy(filename, "fly.txt");
    vector<string> *lexer = Lexer::getLexer(filename);

    map<string, Command *> mapCommand;

    Server server;
    OpenServerCommand serverCommand(server);
    mapCommand["openDataServer"] = &serverCommand;

    Client client;
    ConnectClientCommand clientCommand(client);
    mapCommand["connectControlClient"] = &clientCommand;

    VarDefineCommand varDefineCommand;
    mapCommand["var"] = &varDefineCommand;

    UpdateVarCommand updateVarCommand;
    mapCommand["="] = &updateVarCommand;

    PrintCommand printCommand(server, client);
    mapCommand["Print"] = &printCommand;

    SleepCommand sleepCommand;
    mapCommand["Sleep"] = &sleepCommand;

    IfConditionCommand ifConditionCommand(&mapCommand);
    mapCommand["if"] = &ifConditionCommand;

    WhileConditionCommand whileConditionCommand(&mapCommand);
    mapCommand["while"] = &whileConditionCommand;

    thread serverTh(Server::runningServerThread, ref(server));
    thread clientTh(Client::runningClientThread, ref(client));

    Parser parser(mapCommand);
    parser.parse(*lexer);

    serverTh.join();
    clientTh.join();
}