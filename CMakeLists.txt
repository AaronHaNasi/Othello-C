# cmake_minimum_required(VERSION <specify CMake version here>)
project(Othello_C C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Test_C
        CuTest.c
        tests.c
        othello.c
        othello.h)
