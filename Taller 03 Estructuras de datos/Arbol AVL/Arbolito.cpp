// Isaías Acosta Herrera
// Estructura de datos
// Taller 03
// Árbol AVL
// 4 de octubre de 2024
// John Corredor

#include <iostream>
#include "ArbolBinarioAVL.h"
#include "NodoBinarioAVL.h"

using namespace std;

int main(int argc, char* argv[]) {
    ArbolBinarioAVL<int> arbolito; 
    while (true) {
        int dato;
        char op;
        cout << "Ingrese una operación (A para agregar, E para eliminar, cualquier otra tecla para salir) seguido del dato: ";
        cin >> op >> dato;

        if (op == 'A') {
            arbolito.insertar(dato);
        } else if (op == 'E') {
            arbolito.eliminar(dato);
        } else {
            break;
        }
    }

    cout << endl << "Inorden: " << endl;
    arbolito.inOrden(arbolito.getRaiz());
    cout << endl << "Preorden: " << endl;
    arbolito.preOrden(arbolito.getRaiz());
    cout << endl << "Posorden: " << endl;
    arbolito.posOrden(arbolito.getRaiz());

    return 0;
}