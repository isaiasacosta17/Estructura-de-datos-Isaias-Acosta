cmake_minimum_required(VERSION 3.27)
project(Arbol_Binario)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Arbol_Binario
        ArbolBinario.h
        ArbolBinario.hxx
        NodoBinario.h
        NodoBinario.hxx
        PruebaArbolBinario.cpp)
