cmake_minimum_required(VERSION 3.17)
project(aula03 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(aula03
        matriz.c
        matriz.h
        progmat.c)
