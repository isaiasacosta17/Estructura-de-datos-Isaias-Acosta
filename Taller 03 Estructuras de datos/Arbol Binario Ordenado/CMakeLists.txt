cmake_minimum_required(VERSION 3.27)
project(Arbol_Binario_Ordenado)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Arbol_Binario_Ordenado
        ArbolBinario.h
        ArbolBinario.hxx
        NodoBinario.h
        NodoBinario.hxx
        PruebaArbolBinarioOrdenado.cpp)
