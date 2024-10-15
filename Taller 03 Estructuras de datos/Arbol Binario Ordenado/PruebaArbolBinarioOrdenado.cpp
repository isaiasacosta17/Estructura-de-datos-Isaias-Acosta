//Isaías Acosta Herrera
//Estructura de datos
//Taller 03
//Arbol Binario Ordenado
//4 de octubre de 2024
//John Corredor
#include "ArbolBinario.hxx"

int main() {
    ArbolBinario<int> arbol;

    // Insertar valores
    arbol.insertar(5);
    arbol.insertar(3);
    arbol.insertar(7);
    arbol.insertar(2);
    arbol.insertar(4);
    arbol.insertar(6);
    arbol.insertar(8);

    // Mostrar recorridos
    std::cout << "Recorrido inOrden: ";
    arbol.inOrden();

    std::cout << "Recorrido preOrden: ";
    arbol.preOrden();

    std::cout << "Recorrido posOrden: ";
    arbol.posOrden();

    // Comprobando tamaño y altura
    std::cout << "Tamaño del árbol: " << arbol.tamano() << std::endl;
    std::cout << "Altura del árbol: " << arbol.altura() << std::endl;

    // Buscar un valor
    int valorBuscado = 4;
    if (arbol.buscar(valorBuscado)) {
        std::cout << "Valor " << valorBuscado << " encontrado en el arbol." << std::endl;
    } else {
        std::cout << "Valor " << valorBuscado << " no encontrado en el arbol." << std::endl;
    }

    // Eliminar un valor
    arbol.eliminar(3);
    std::cout << "Recorrido inOrden tras eliminar 3: ";
    arbol.inOrden();

    return 0;
}
