// Isaías Acosta Herrera
//Algoritmo Dijkstra
//30 de octubre de 2024
//Estructura de datos
//John Corredor

#include <iostream>
#include <climits>
using namespace std;

// Función para encontrar el vértice con la distancia mínima que aún no ha sido procesado

int miniDist(int distance[], bool Tset[]) {
    int minimum = INT_MAX, ind;

    for (int k = 0; k < 6; k++) {
        if (!Tset[k] && distance[k] <= minimum) {
            minimum = distance[k];
            ind = k;
        }
    }
    return ind;
}

// Implementación del algoritmo de Dijkstra para encontrar rutas más cortas desde un vértice de origen
void DijkstraAlgo(int graph[7][7], int src) {
    int distance[7]; // Guarda las distancias mínimas desde el origen
    bool Tset[7];    // Indica si el vértice ha sido incluido en el camino más corto

    // Inicializar todos los elementos en "distancia" y "Tset"
    for (int k = 0; k < 7; k++) {
        distance[k] = INT_MAX;
        Tset[k] = false;
    }

    distance[src] = 0; // La distancia desde la fuente a sí misma es 0

    // Encuentra la ruta más corta para todos los vértices
    for (int i = 0; i < 7; i++) {
        int m = miniDist(distance, Tset);
        Tset[m] = true;

        for (int k = 0; k < 7; k++) {
            if (!Tset[k] && graph[m][k] && distance[m] != INT_MAX && distance[m] + graph[m][k] < distance[k])
                distance[k] = distance[m] + graph[m][k];
        }
    }

    // Imprimir la distancia de cada vértice desde la fuente
    cout << "Vertice\t\tDistancia desde la fuente al Vertice" << endl;
    for (int k = 0; k < 7; k++) {
        char str = 65 + k; // Convierte el índice en la letra correspondiente (A, B, C, ...)
        cout << str << "\t\t\t" << distance[k] << endl;
    }
}
// Matriz de adyacencia que representa el grafo con pesos en las aristas
int main() {
    int graph[7][7] = {
        {0, 2, 4, 0, 0, 0,0},
        {2, 0, 0, 5, 0, 0,0},
        {4, 0, 0, 8, 0, 0,0},
        {0, 5, 8, 0, 10, 15,0},
        {0, 0, 0, 10, 0, 6,2},
        {0, 0, 0, 15, 6, 0,6},
        {0, 0, 0, 0, 2, 6,0}
    };
    // Llama al algoritmo de Dijkstra tomando el vértice de origen como el primer vértice (índice 0)
    DijkstraAlgo(graph, 0);
    return 0;
}
