#include "Parser.h"

void Parser::parse(vector<string> &lexer) {
    int index = 0;
    int jumpIndex = 0;
    while (index < lexer.size()) {
        string word = lexer.at(index);
        Command *c = commandMap[word];

        if (c != nullptr) {
            c->init(lexer, index);
            jumpIndex = c->execute();
        }
        index = index + jumpIndex;
    }
}