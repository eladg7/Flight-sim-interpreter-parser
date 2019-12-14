cmake_minimum_required(VERSION 3.15)
project(flight_sim1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)
add_executable(flight_sim1 main.cpp Parser/Parser.cpp Parser/Parser.h Parser/Command.h Parser/OpenServerCommand.cpp Parser/OpenServerCommand.h Lexer/Lexer.cpp Lexer/Lexer.h)