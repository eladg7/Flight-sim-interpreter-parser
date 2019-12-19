#include "Lexer/Lexer.h"
#include "Parser/CommandDir/OpenServerCommand.h"
#include "Parser/Parser.h"
#include "Parser/Client.h"
#include "Parser/CommandDir/ConnectClientCommand.h"
#include "Parser/CommandDir/FuncCommand.h"
#include "Parser/CommandDir/PrintCommand.h"
#include "Parser/CommandDir/SleepCommand.h"

int main() {
    char filename[1024] = {0};
    strcpy(filename, "fly.txt");
    vector<string> *lexer = Lexer::getLexer(filename);

    map<string, Command *> mapCommand;

    Server server;
    OpenServerCommand serverCommand(server);
    mapCommand.insert(pair<string, Command *>("openDataServer", &serverCommand));

    Client client;
    ConnectClientCommand clientCommand(client);
    mapCommand.insert(pair<string, Command *>("connectControlClient", &clientCommand));

    PrintCommand printCommand;
    mapCommand.insert(pair<string, Command *>("Print", &printCommand));

    SleepCommand sleepCommand;
    mapCommand.insert(pair<string, Command *>("Sleep", &sleepCommand));

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

