#include <unistd.h>
#include "Parser.h"

void Parser::parse(vector<string> &lexer) {
    int index = 0;
    while (index < lexer.size()) {
        string word = lexer.at(index);
        Command *c = commandMap[word];

        if (c != nullptr) {
            c->init(lexer, index);
            c->execute();
            index += c->getNumberOfParam();
        }else{
            index++;
        }
        usleep(5000);
    }
}