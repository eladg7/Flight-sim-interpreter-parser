#include "Lexer.h"

vector<string> Lexer::getLinesFromFile(char *fileName) {
    char buffer[4000];
    getcwd(buffer, sizeof(buffer));
    strcat(buffer, "/");
    ifstream input(strcat(buffer, fileName));

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


//stackoverflow
std::vector<std::string> Lexer::split(basic_string<char> s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

/*
 * Erase all Occurrences of given substring from main string.
 */
void Lexer::eraseAllSubStr(std::string &mainStr, const std::string &toErase) {
    size_t pos = std::string::npos;

    // Search for the substring in string in a loop untill nothing is found
    while ((pos = mainStr.find(toErase)) != std::string::npos) {
        // If found then erase it from string
        mainStr.erase(pos, toErase.length());
    }
}


std::string &ltrim(std::string &str, const std::string &chars = "\t\n\v\f\r ") {
    str.erase(0, str.find_first_not_of(chars));
    return str;
}

std::string &rtrim(std::string &str, const std::string &chars = "\t\n\v\f\r ") {
    str.erase(str.find_last_not_of(chars) + 1);
    return str;
}

std::string &trim(std::string &str, const std::string &chars = "\t\n\v\f\r ") {
    return ltrim(rtrim(str, chars), chars);
}

bool Lexer::isCharInString(const string &str, char c) {
    return (strchr(str.c_str(), c));
}

bool Lexer::IsParentheses(char c) {
    switch (c) {
        case '(':
        case ')':
            return true;
        default:
            return false;
    }
}

bool Lexer::isCondition(const string &str) {
    return str == "while" || str == "if";
}

vector<string> Lexer::methodsOpenParethesis(const string &line) {
    // splits by open parenthesis
    vector<string> bufferByParenthesis = split(line, '(');
    string afterParenthesis = bufferByParenthesis.at(1);
    //erase closing parenthesis
    afterParenthesis.erase(std::remove_if(
            afterParenthesis.begin(), afterParenthesis.end(), &IsParentheses),
                           afterParenthesis.end());
    bufferByParenthesis.erase(bufferByParenthesis.end() - 1);

    vector<string> parameters = split(afterParenthesis, ',');
    for (string s:parameters) {
        bufferByParenthesis.push_back(s);
    }
    return bufferByParenthesis;
}

vector<string> Lexer::splitByFirstChar(const string &str, char c) {
    // split string by first char
    vector<string> newVector;
    newVector.push_back(str.substr(0, str.find(c)));
    newVector.push_back(str.substr(str.find(c) + 1, str.length()));
    return newVector;
}

void Lexer::insertToLexer(vector<string> *lexer, const vector<string> &buffer) {
    //insert all words to Lexer
    for (string str:buffer) {
        if (isCharInString(str, '(')) {
            vector<string> splitByParenthesis =
                    methodsOpenParethesis(str);
            for (string word:splitByParenthesis) {
                eraseAllSubStr(word, "\t");
                lexer->push_back(trim(word));
            }
        } else {
            eraseAllSubStr(str, "\t");
            lexer->push_back(trim(str));
        }
    }
}

vector<string> *Lexer::getLexer(char *fileName) {
    vector<string> linesInFile = getLinesFromFile(fileName);
    auto *lexer = new vector<string>;
    vector<string> buffer;
    for (string line:linesInFile) {
        if (line.empty() || line.rfind("//", 0) == 0) {
            continue; //comment.
        }
        if (isCondition(split(trim(line), ' ').at(0))) { //conditions
            line = trim(line);
            vector<string> condition = splitByFirstChar(line, ' ');
            lexer->push_back(trim(condition.at(0)));
            lexer->push_back(trim(condition.at(1)));

        } else if (line.find("var") != string::npos) { // func
            vector<string> func = splitByFirstChar(line, '(');
            lexer->push_back(trim(func.at(0)));
            string variablesToFunc = func.at(1);
            Lexer::eraseAllSubStr(variablesToFunc, ")");
            lexer->push_back(trim(variablesToFunc));

        } else if (isCharInString(line, '=')) { //equal lines
            if (line.find("var") == string::npos) { // there isn't a Var x =...
                vector<string> equal = split(line, '=');
                lexer->push_back("=");
                lexer->push_back(trim(equal.at(0)));
                lexer->push_back(trim(equal.at(1)));
            } else {// var x = ...
                line = trim(line);
                buffer = splitByFirstChar(line, ' ');
                lexer->push_back(buffer.at(0));// var
                buffer = split(buffer.at(1), '=');
                lexer->push_back("=");
                insertToLexer(lexer, buffer);
            }
        } else {// can be split by spaces
            string splitByP = split(line, '(').at(0);
            if (splitByP.find("Print")
                == string::npos) {
                //print can have spaces inside
                buffer = split(line, ' ');
            } else {
                buffer.push_back(line);
            }
            insertToLexer(lexer, buffer);
        }
        buffer.clear();
    }
    return lexer;
}
