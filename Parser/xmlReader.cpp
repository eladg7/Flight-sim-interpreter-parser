#include "xmlReader.h"

vector<string> xmlReader::readXmlFile(string dir) {
    vector<string> linesVector;

    ifstream in(dir);
    if (!in || !in.is_open()) {
        cout << "Could not read xml file: " << dir << endl;
        return linesVector;
    }

    string line;
    while (getline(in, line)) {
        Lexer::trim(line);
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
