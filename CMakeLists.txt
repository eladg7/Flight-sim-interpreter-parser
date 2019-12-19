cmake_minimum_required(VERSION 3.15)
project(flight_sim1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)
add_executable(flight_sim1 main.cpp Parser/SymbolTable.cpp Parser/Server.h Parser/Server.h Parser/Server.cpp
        Parser/Parser.cpp Parser/Parser.h Parser/Command.h Parser/OpenServerCommand.cpp Parser/OpenServerCommand.h
        Lexer/Lexer.cpp Lexer/Lexer.h Parser/xmlReader.cpp Parser/xmlReader.h Parser/Client.cpp Parser/Client.h
        Parser/ConnectClientCommand.cpp Parser/ConnectClientCommand.h Parser/FuncCommand.cpp Parser/FuncCommand.h Parser/Expression.h
        Parser/Variable.cpp Parser/Variable.h Parser/ex1Expressions.h Parser/ex1Expressions.cpp)