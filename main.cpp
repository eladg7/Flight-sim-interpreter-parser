#include <iostream>
#include "Lexer/Lexer.h"
#include "Parser/OpenServerCommand.h"
#include "Parser/Parser.h"


int main() {
    char filename[64]={0};
    strcpy(filename, "fly.txt");
    thread serverTh;
    thread clientTh;
    vector<string> *lexer = Lexer::getLexer(filename);
    map<string, Command *> mapCommand;
    Server server;
    OpenServerCommand serverCommand(server);
    mapCommand.insert(pair<string, Command *>("openDataServer", &serverCommand));

    Parser parser(mapCommand);
    parser.parse(*lexer);

    return 0;
}