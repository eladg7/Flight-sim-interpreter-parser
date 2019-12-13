//
// Created by yekaterina on 13/12/2019.
//

#ifndef FLIGHT_SIM1_LEXER_H
#define FLIGHT_SIM1_LEXER_H

#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

class lexer {
public:
    lexer() = default;

    vector<string> test(string);

    static vector<string> getLinesFromFile(string);
};


#endif //FLIGHT_SIM1_LEXER_H
