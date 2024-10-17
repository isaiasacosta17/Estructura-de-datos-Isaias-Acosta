//Isaías Acosta Herrera
//Taller Grafos
//Estructura de datos
//John Corredor
//16 de Octubre de 2024

// Grafo.hxx

#include "grafo.h"
#include <iostream>

// Metodo para agregar un vertice al grafo
template <typename T, typename W>
void Grafo<T, W>::agregarVertice(T valor) {
    Vertice<T>* nuevoVertice = new Vertice<T>(valor);
    vertices.push_back(nuevoVertice);
}

// Metodo para agregar una arista al grafo
template <typename T, typename W>
void Grafo<T, W>::agregarArista(T valorOrigen, T valorDestino, W peso) {
    Vertice<T>* origen = nullptr;
    Vertice<T>* destino = nullptr;

    for (auto v : vertices) {
        if (v->dato == valorOrigen) {
            origen = v;
        }
        if (v->dato == valorDestino) {
            destino = v;
        }
    }

    if (origen && destino) {
        Arista<T, W>* nuevaArista = new Arista<T, W>(origen, destino, peso);
        aristas.push_back(nuevaArista);
    } else {
        std::cout << "Uno o ambos vertices no existen.\n";
    }
}

// Metodo para imprimir el grafo
template <typename T, typename W>
void Grafo<T, W>::imprimirGrafo() const {
    for (const auto& arista : aristas) {
        std::cout << arista->origen->dato << " --(" << arista->peso << ")--> " << arista->destino->dato << std::endl;
    }
}

