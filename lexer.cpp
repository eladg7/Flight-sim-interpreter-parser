#include "lexer.h"

//stackoverflow
vector<string> split(const string &s, char delimiter) {
    vector<std::string> tokens;
    string token;
    istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

vector<string> *getLexer(vector<string> linesInFile) {
    vector<string> *lexer;
}

vector<string> lexer::getLinesFromFile(const string source) {
    ifstream input(source);

    if (!input || !input.is_open()) {
        throw invalid_argument("Could not open source file - Lexer");
    }

    vector<string> lines;

    for (string line; getline(input, line);) {
        lines.push_back(line);
    }

    input.close();

    return lines;
}

