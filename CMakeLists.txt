cmake_minimum_required(VERSION 3.15)
project(flight_sim1)

set(CMAKE_CXX_STANDARD 14)

add_executable(flight_sim1 main.cpp lexer_dir/lexer.cpp lexer_dir/lexer.h)