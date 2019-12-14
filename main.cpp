#include <iostream>
#include "Lexer/Lexer.h"
#include "Parser/OpenServerCommand.h"
#include "Parser/Parser.h"

int main() {
    char *filename = "fly.txt";
    vector<string> *lexer = Lexer::getLexer(filename);

    map<string, Command *> mapCommand;
    OpenServerCommand serverCommand;
    mapCommand.insert(pair<string, Command *>("openDataServer", &serverCommand));

    Parser parser(mapCommand);
    parser.parse(*lexer);

    return 0;
}