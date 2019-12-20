cmake_minimum_required(VERSION 3.15)
project(flight_sim1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)
add_executable(flight_sim1 main.cpp Parser/SymbolTable.cpp Parser/Server.h
        Parser/Server.h Parser/Server.cpp
        Parser/Parser.cpp Parser/Parser.h Parser/CommandDir/Command.h
        Parser/CommandDir/OpenServerCommand.cpp
        Parser/CommandDir/OpenServerCommand.h Lexer/Lexer.cpp Lexer/Lexer.h
        Parser/xmlReader.cpp Parser/xmlReader.h Parser/Client.cpp
        Parser/Client.h Parser/CommandDir/ConnectClientCommand.cpp
        Parser/CommandDir/ConnectClientCommand.h
        Parser/CommandDir/FuncCommand.cpp Parser/CommandDir/FuncCommand.h
        Parser/CommandDir/PrintCommand.cpp
        Parser/CommandDir/PrintCommand.h Parser/CommandDir/SleepCommand.cpp
        Parser/CommandDir/SleepCommand.h Parser/Variable.h Parser/Variable.cpp
        Parser/ex1Expressions.cpp Parser/ex1Expressions.h
        Parser/CommandDir/VarDefineCommand.h Parser/CommandDir/VarDefineCommand.cpp
        Parser/CommandDir/LocalVarDefineCommand.cpp Parser/CommandDir/LocalVarDefineCommand.h
        Parser/CommandDir/SimVarDefineCommand.cpp Parser/CommandDir/SimVarDefineCommand.h
        Parser/CommandDir/ConditionCommand.cpp Parser/CommandDir/ConditionCommand.h
        Parser/CommandDir/IfConditionCommand.cpp Parser/CommandDir/IfConditionCommand.h)