//Isaías Acosta Herrera
//Estructura de datos
//Taller 03
//Arbol Quad Tree
//4 de octubre de 2024
//John Corredor
#include <bits/stdc++.h>
#include "quadtree.h"

using namespace std;

int main() {

    Arbol<int> quadtree;


    quadtree.insertar(make_pair(10, 20));
    quadtree.insertar(make_pair(30, 40));
    quadtree.insertar(make_pair(15, 25));
    quadtree.insertar(make_pair(35, 45));


    cout << "Pre-order traversal of the quadtree:" << endl;
    quadtree.preOrden();


    pair<int, int> searchValue = make_pair(15, 25);
    Nodo<int>* foundNode = quadtree.buscar(searchValue);

    if (foundNode) {
        cout << "Node found with value: (" << foundNode->obtenerDato().first
             << ", " << foundNode->obtenerDato().second << ")" << endl;
    } else {
        cout << "Node not found!" << endl;
    }

    return 0;
}