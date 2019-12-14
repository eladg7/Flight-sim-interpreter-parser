//
// Created by elad on 13/12/2019.
//

#include <vector>
#include "string"

using namespace std;

class Command {
protected:
    int numberOfParameters;
    vector<string> commandLexer;

public:

    virtual void init(vector<string> &origLexer, int index) = 0;

    virtual int execute() = 0;

    virtual ~Command() {}
};

