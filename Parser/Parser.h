//
// Created by yekaterina on 14/12/2019.
//

#ifndef FLIGHT_SIM1_PARSER_H
#define FLIGHT_SIM1_PARSER_H

#include <vector>
#include <string>
#include <map>
#include "CommandDir/Command.h"

using namespace std;


class Parser {
    map<string, Command *> commandMap;
public:
    explicit Parser(map<string, Command *> &map) {
        commandMap = map;
    }

    void parse(vector<string> &lexer);
};


#endif //FLIGHT_SIM1_PARSER_H
