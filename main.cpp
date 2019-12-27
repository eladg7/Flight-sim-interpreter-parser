#include "ProgramRunner/ProgramExecute.h"

int main(int argc,char * argv[]) {

    char * filename=argv[1];
    ProgramExecute::run(filename);
    return 0;
}

