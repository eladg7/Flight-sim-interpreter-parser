#include <iostream>
#include "Lexer/Lexer.h"
#include "Parser/OpenServerCommand.h"
#include "Parser/Parser.h"
#include "Parser/xmlReader.h"
#include "Parser/Client.h"
#include "Parser/ConnectClientCommand.h"

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

    thread serverTh(Server::runningServerThread, &server);
    thread clientTh(Client::runningClientThread, &client);

    Parser parser(mapCommand);
    parser.parse(*lexer);

    server.closeSocketFD();
    client.closeClientSocket();
    serverTh.join();
    clientTh.join();

    return 0;
}

