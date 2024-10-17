//Taller Grafos 
//Isaías Acosta Herrera
//Estructura de datos
//John Corredor

// Arista.h

#ifndef ARISTA_H
#define ARISTA_H

#include "vertice.h"

template <typename T, typename W>
class Arista {
public:
    Vertice<T>* origen;
    Vertice<T>* destino;
    W peso;

    Arista(Vertice<T>* orig, Vertice<T>* dest, W p);
};

#endif // ARISTA_H
