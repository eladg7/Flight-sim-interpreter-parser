//
// Created by elad on 18/12/2019.
//

#ifndef FLIGHT_SIM1_XMLREADER_H
#define FLIGHT_SIM1_XMLREADER_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#define NODE_STARTER "<node>"
#define NODE_END "</node>"

using namespace std;

class xmlReader {
private:
    static void removeNodeString(string &);

    static inline void ltrim(std::string &s);

    static inline void rtrim(std::string &s);

    static inline void trim(std::string &s);

public:
    static vector<string> readFile(string);
};

#endif //FLIGHT_SIM1_XMLREADER_H
