#include <iostream>
#include "Lexer/Lexer.h"
#include "Parser/OpenServerCommand.h"

int main() {
    vector<string> *lexer = Lexer::getLexer("fly.txt");
//    OpenServerCommand serverCommand;
//    serverCommand.init(*lexer, 0);
//    serverCommand.execute();
    return 0;
}