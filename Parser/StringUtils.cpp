//
// Created by elad on 19/12/2019.
//
#ifndef STRING_UTILS
#define STRING_UTILS

#include <string>
#include <cstring>

using namespace std;

static string removeApostrophes(char *str) {
    string x(str);
    if (x.at(0) == '\"') {
        x.erase(x.begin());
    }
    if (x.at(x.length() - 1) == '\"') {
        x.pop_back();
    }
    sprintf(str, "%s", x.c_str());
    return x;
}

#endif