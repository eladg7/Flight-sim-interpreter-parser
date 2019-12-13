//
// Created by elad on 13/12/2019.
//

#include "string"

using namespace std;

class Command {
public:
    virtual int execute(string);

    virtual ~Command();
};
