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
        } else if ((index + 1 < lexer.size()) && isGenericFunction(lexer.at(index + 1))) {
            auto *tempCommand = new GenericFunctionCommand(&commandMap);
            commandMap[word] = tempCommand;
            tempCommand->init(lexer, index);
            tempCommand->execute();
            index += tempCommand->getNumberOfParam();
        } else {
            index++;
        }
    }
    usleep(5000);
}

bool Parser::isGenericFunction(const string &comm) {
    return (comm.find("var") != string::npos) && (comm.find('{') != string::npos);
}