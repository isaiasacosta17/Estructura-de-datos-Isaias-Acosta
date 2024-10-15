//Isaías Acosta Herrera
//Estructura de datos
//Taller 03
//Arbol Binario 
//4 de octubre de 2024
//John Corredor

#include <iostream>
#include "ArbolBinario.h"
using namespace std;

int main() {
    ArbolBinario<int>* a = new ArbolBinario<int>();

    cout << "Arbol vacio" << endl;
    if (a->esVacio())
        cout << "El arbol esta vacio" << endl;

    int val;
    cout << "Introduce un valor para la raiz del arbol: ";
    cin >> val;
    a->insertar(val);

    cout << "Introduce mas valores para insertar en el arbol (termina con -1): " << endl;
    cin >> val;
    while (val != -1) {
        a->insertar(val);
        cin >> val;
    }

    cout << "Preorden:" << endl;
    a->preOrden();

    cout << "Inorden:" << endl;
    a->inOrden();

    cout << "Postorden:" << endl;
    a->posOrden();

    cout << "Nivel orden:" << endl;
    a->nivelOrden();

    return 0;
}
