#include "lexer.h"

vector<string> lexer::getLinesFromFile() {
    char buffer[4000];
    getcwd(buffer, sizeof(buffer));
    strcat(buffer, "/");
    ifstream input(strcat(buffer, "fly.txt"));

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
std::vector<std::string> lexer::split(const basic_string<char>& s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
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

bool lexer::isCharInString(const string &str, char c) {
    return (strchr(str.c_str(), c));
}

bool lexer::IsParentheses(char c) {
    switch (c) {
        case '(':
        case ')':
            return true;
        default:
            return false;
    }
}

bool lexer::isCondition(const string &str) {
    return str == "while" || str == "if";
}

vector<string> lexer::methodsOpenParethesis(const string &line) {
    // splits by open parenthesis
    vector<string> bufferByParenthesis = split(line, '(');
    string afterParenthesis = bufferByParenthesis.at(1);
    //erase closing parenthesis
    afterParenthesis.erase(std::remove_if(
            afterParenthesis.begin(), afterParenthesis.end(), &IsParentheses),
                           afterParenthesis.end());
    bufferByParenthesis.erase(bufferByParenthesis.end() - 1);

    vector<string> parameters = split(afterParenthesis, ',');
    for (const string &s:parameters) {
        bufferByParenthesis.push_back(s);
    }
    return bufferByParenthesis;
}

vector<string> lexer::splitByFirstChar(const string &str,char c){
    // split string by first char
    vector<string> newVector;
    newVector.push_back(str.substr(0,str.find(c)));
    newVector.push_back(str.substr(str.find(c) + 1, str.length()));
    return newVector;
}

void lexer::insertToLexer(vector<string>* lexer, const vector<string> &buffer) {
   //insert all words to lexer
    for (const string &str:buffer) {
        if (isCharInString(str, '(')) {
            vector<string> splitByParenthesis =
                    methodsOpenParethesis(str);
            for(const string &word:splitByParenthesis){
                lexer -> push_back(word);
            }
        } else {
            lexer -> push_back(str);
        }
    }
}

vector<string> *lexer::getLexer() {
    vector<string> linesInFile = getLinesFromFile();
    auto *lexer = new vector<string>;
    vector<string> buffer;
    for (const string &line:linesInFile) {
        if(line.rfind("//",0)==0){
            continue; //comment
        }
        if (isCondition(split(line, ' ').at(0))) { //conditions
            vector<string> condition=splitByFirstChar(line,' ');
            lexer->push_back(condition.at(0));
            lexer->push_back(condition.at(1));

        } else if (isCharInString(line, '=')) { //equal lines
            vector<string> equal = split(line, '=');
            lexer->push_back(trim(equal.at(0)));
            lexer->push_back(trim(equal.at(1)));
        } else {// can be split by spaces
            if(split(line, '(').at(0) != "Print"){//print can have spaces inside
                buffer = split(line, ' ');
            }else{
                buffer.push_back(line);
            }
            insertToLexer(lexer, buffer);
            buffer.clear();
        }
    }
    return lexer;
}
