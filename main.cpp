#include <iostream>
#include "Lexer/Lexer.h"
#include "Parser/OpenServerCommand.h"
#include "Parser/Parser.h"



int main() {
    char filename[64] = {0};
    strcpy(filename, "fly.txt");
    vector<string> *lexer = Lexer::getLexer(filename);

    map<string, Command *> mapCommand;

    Server server;
    OpenServerCommand serverCommand(server);
    mapCommand.insert(pair<string, Command *>("openDataServer", &serverCommand));

    thread serverTh(Server::runningServerThread, &server);
    thread clientTh;

    Parser parser(mapCommand);
    parser.parse(*lexer);

    server.closeSocketFD();
    serverTh.join();

    return 0;
}

