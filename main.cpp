#include "Lexer/Lexer.h"
#include "Parser/CommandDir/OpenServerCommand.h"
#include "Parser/Parser.h"
#include "Parser/Client.h"
#include "Parser/CommandDir/ConnectClientCommand.h"
#include "Parser/CommandDir/PrintCommand.h"
#include "Parser/CommandDir/SleepCommand.h"
#include "Parser/CommandDir/VarDefineCommand.h"
#include "Parser/CommandDir/ConditionCommand.h"
#include "Parser/CommandDir/UpdateVarCommand.h"

int main() {
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
    mapCommand["="]=&updateVarCommand;

    PrintCommand printCommand(server,client);
    mapCommand["Print"]= &printCommand;

    SleepCommand sleepCommand;
    mapCommand["Sleep"] = &sleepCommand;

//    ConditionCommand conditionCommand;
//    mapCommand["while"] = &conditionCommand;


    thread serverTh(Server::runningServerThread, ref(server));
    thread clientTh(Client::runningClientThread,ref(client));

    Parser parser(mapCommand);
    parser.parse(*lexer);


    serverTh.join();
    clientTh.join();

    return 0;
}

