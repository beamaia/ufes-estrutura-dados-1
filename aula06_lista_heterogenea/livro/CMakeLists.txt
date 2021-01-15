cmake_minimum_required(VERSION 3.17)
project(livro C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(livro
        formas.c
        formas.h
        listaHetFormas.c
        listaHetFormas.h
        mainFormas.c)
