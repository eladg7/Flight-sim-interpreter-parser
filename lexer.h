//
// Created by yekaterina on 13/12/2019.
//

#ifndef FLIGHT_SIM1_LEXER_H
#define FLIGHT_SIM1_LEXER_H

#include <vector>
#include <sstream>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <unistd.h>

using namespace std;

class lexer {
public:
    static vector<string> getLinesFromFile();

    static std::vector<std::string> split(const basic_string<char>& s, char delimiter);

    static bool isCharInString(const string &str, char c);

    static bool IsParentheses(char c);

    static bool isCondition(const string &str);

    static void insertToLexer(vector<string> *lexer, const vector<string> &buffer);

    static vector<string> *getLexer();

    static vector<string> splitByFirstChar(const string &str, char c);

    static vector<string> methodsOpenParethesis(const string &line);
};

#endif //FLIGHT_SIM1_LEXER_H
