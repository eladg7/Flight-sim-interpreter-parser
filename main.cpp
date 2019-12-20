#include "Lexer/Lexer.h"
#include "Parser/CommandDir/OpenServerCommand.h"
#include "Parser/Parser.h"
#include "Parser/Client.h"
#include "Parser/CommandDir/ConnectClientCommand.h"
#include "Parser/CommandDir/PrintCommand.h"
#include "Parser/CommandDir/SleepCommand.h"
#include "Parser/CommandDir/VarDefineCommand.h"

int main() {
    char filename[1024] = {0};
    strcpy(filename, "fly.txt");
    vector<string> *lexer = Lexer::getLexer(filename);

    map<string, Command *> mapCommand;

    Server server;
    OpenServerCommand serverCommand(server);
    mapCommand["openDataServer"]= &serverCommand;

    Client client;
    ConnectClientCommand clientCommand(client);
    mapCommand["connectControlClient"]= &clientCommand;

    VarDefineCommand varDefineCommand;
    mapCommand["var"]=&varDefineCommand;

    PrintCommand printCommand;
    mapCommand["Print"]= &printCommand;

    SleepCommand sleepCommand;
    mapCommand["Sleep"]= &sleepCommand;

    thread serverTh(Server::runningServerThread, ref(server));
    thread clientTh(Client::runningClientThread, ref(client));

    Parser parser(mapCommand);
    parser.parse(*lexer);

//    server.closeSocketFD();
//    client.closeClientSocket();
    serverTh.join();
    clientTh.join();

    return 0;
}

