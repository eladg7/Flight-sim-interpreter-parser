#ifndef FLIGHT_SIM1_PROGRAMEXECUTE_H
#define FLIGHT_SIM1_PROGRAMEXECUTE_H

#include "../Lexer/Lexer.h"
#include "../Parser/CommandDir/OpenServerCommand.h"
#include "../Parser/Parser.h"
#include "../Parser/Client.h"
#include "../Parser/CommandDir/ConnectClientCommand.h"
#include "../Parser/CommandDir/PrintCommand.h"
#include "../Parser/CommandDir/SleepCommand.h"
#include "../Parser/CommandDir/VarDefineCommand.h"
#include "../Parser/CommandDir/ConditionCommand.h"
#include "../Parser/CommandDir/UpdateVarCommand.h"
#include "../Parser/CommandDir/IfConditionCommand.h"
#include "../Parser/CommandDir/WhileConditionCommand.h"
#include "../Parser/CommandDir/GenericFunctionCommand.h"

class ProgramExecute {
private:

public:
    static void run();
};

#endif //FLIGHT_SIM1_PROGRAMEXECUTE_H
