#include "ProgramRunner/ProgramExecute.h"

int main(int argc,char * argv[]) {
    if(argc < 2){
        cout << "No parameters given to text file."<<endl;
        exit(1);
    }
    char * filename=argv[1];
    ProgramExecute::run(filename);
    return 0;
}

