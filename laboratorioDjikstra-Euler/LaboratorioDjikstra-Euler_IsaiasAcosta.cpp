// Isaías Acosta Herrera
//Algoritmo Dijkstra
//6 de noviembre de 2024
//Estructura de datos
//John Corredor

#include <iostream>
#include <climits>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

// Función para encontrar el vértice con la distancia mínima que aún no ha sido procesado
int miniDist(int distance[], bool Tset[], int V) {
    int minimum = INT_MAX, ind;

    for (int k = 0; k < V; k++) {
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
    int V = 7;
    int parent[7];   // Arreglo para almacenar el camino

    // Inicializar todos los elementos en "distancia" y "Tset"
    for (int k = 0; k < V; k++) {
        distance[k] = INT_MAX;
        Tset[k] = false;
        parent[k] = -1; // Inicializamos el padre como -1
    }

    distance[src] = 0; // La distancia desde la fuente a sí misma es 0

    // Encuentra la ruta más corta para todos los vértices
    for (int i = 0; i < V; i++) {
        int m = miniDist(distance, Tset, V);
        Tset[m] = true;

        for (int k = 0; k < V; k++) {
            if (!Tset[k] && graph[m][k] && distance[m] != INT_MAX && distance[m] + graph[m][k] < distance[k]) {
                distance[k] = distance[m] + graph[m][k];
                parent[k] = m; // Guarda el nodo anterior para reconstruir el camino
            }
        }
    }

    // Imprimir la distancia y el camino de cada vértice desde la fuente
    cout << "Vertice\tDistancia\tCamino" << endl;
    for (int k = 0; k < V; k++) {
        cout << src << " -> " << k << "\t" << distance[k] << "\t\t";
        
        // Imprimir el camino desde la fuente hasta el vértice k
        vector<int> path;
        for (int v = k; v != -1; v = parent[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());
        
        for (int v : path) {
            cout << v << " ";
        }
        cout << endl;
    }
}

// Función para encontrar un ciclo de Euler y mostrarlo
void encontrarCicloEuler(int graph[7][7], int start) {
    stack<int> pila;
    vector<int> ciclo;
    int tempGraph[7][7];
    int V = 7;

    // Copia el grafo original para modificarlo sin afectar el original
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            tempGraph[i][j] = graph[i][j];
        }
    }

    pila.push(start);
    while (!pila.empty()) {
        int v = pila.top();
        bool tieneArista = false;
        
        // Revisa aristas no visitadas
        for (int u = 0; u < V; u++) {
            if (tempGraph[v][u] > 0) {
                pila.push(u);
                tempGraph[v][u] = tempGraph[u][v] = 0; // Marca arista como visitada
                tieneArista = true;
                break;
            }
        }
        
        if (!tieneArista) {
            ciclo.push_back(v);
            pila.pop();
        }
    }

    // Imprimir el ciclo de Euler
    cout << "Ciclo de Euler: ";
    for (size_t i = 0; i < ciclo.size(); i++) {
        cout << ciclo[i];
        if (i != ciclo.size() - 1) cout << " -> ";
    }
    cout << endl;
}

// Matriz de adyacencia que representa el grafo con pesos en las aristas
int main() {
    int graph[7][7] = {
        {0, 1, 7, 6, 0, 0, 0},
        {1, 0, 9, 0, 0, 3, 0},
        {7, 9, 0, 0, 0, 0, 1},
        {6, 0, 0, 0, 2, 0, 0},
        {0, 0, 0, 2, 0, 0, 5},
        {0, 3, 0, 0, 0, 0, 3},
        {0, 0, 1, 0, 5, 3, 0}
    };

    // Ejecutar Dijkstra 
    DijkstraAlgo(graph, 0);
    
    // Ejecutar el ciclo de Euler 
    encontrarCicloEuler(graph, 0);
    
    return 0;
}