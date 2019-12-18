//
// Created by elad on 18/12/2019.
//

#include "xmlReader.h"

vector<string> xmlReader::readFile(string dir) {
    vector<string> linesVector;

    ifstream in(dir);
    if (!in || !in.is_open()) {
        cerr << "Could not read xml file: " << dir << endl;
        return linesVector;
    }

    string line;
    while (getline(in, line)) {
        trim(line);
        if (line.find("<node>") == string::npos) {
            continue;
        }
        removeNodeString(line);
        linesVector.push_back(line);
    }

}

void xmlReader::removeNodeString(string &removeFrom) {
    int pos = removeFrom.find(NODE_STARTER);
    int nodeStarterLength = 6;
    int nodeEndLength = 7;
    if (pos >= 0) {
        removeFrom.erase(pos, nodeStarterLength);
    }
    pos = removeFrom.find(NODE_END, nodeEndLength);
    if (pos >= 0) {
        removeFrom.erase(pos);
    }
}

inline void xmlReader::ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
        return !std::isspace(ch);
    }));
}

// trim from end (in place)
inline void xmlReader::rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
inline void xmlReader::trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}
