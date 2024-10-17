//Isaías Acosta Herrera
//Taller Grafos
//Estructura de datos
//John Corredor
//16 de Octubre de 2024

// main

#include "grafo.h"
#include "grafo.hxx"
#include "vertice.hxx"
#include "arista.hxx"
#include <iostream>

int main() {
    Grafo<std::string, int> miGrafo;

    // Agregar vértices
    miGrafo.agregarVertice("A");
    miGrafo.agregarVertice("B");
    miGrafo.agregarVertice("C");

    // Agregar aristas
    miGrafo.agregarArista("A", "B", 5);
    miGrafo.agregarArista("A", "C", 10);

    // Imprimir el grafo actual
    miGrafo.imprimirGrafo();

    return 0;
}
