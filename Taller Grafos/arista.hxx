//Isaías Acosta Herrera
//Taller Grafos
//Estructura de datos
//John Corredor
//16 de Octubre de 2024

// Arista.hxx

#include "arista.h"
// Constructor de la clase arista
template <typename T, typename W>
Arista<T, W>::Arista(Vertice<T>* orig, Vertice<T>* dest, W p) : origen(orig), destino(dest), peso(p) {}


