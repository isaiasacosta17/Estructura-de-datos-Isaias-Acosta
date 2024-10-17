//Taller Grafos 
//Isaías Acosta Herrera
//Estructura de datos
//John Corredor

// Grafo.h

#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include "vertice.h"
#include "arista.h"

template <typename T, typename W>
class Grafo {
private:
    std::vector<Vertice<T>*> vertices;
    std::vector<Arista<T, W>*> aristas;

public:
    void agregarVertice(T valor);
    void agregarArista(T valorOrigen, T valorDestino, W peso);
    void imprimirGrafo() const;
};

#endif // GRAFO_H
