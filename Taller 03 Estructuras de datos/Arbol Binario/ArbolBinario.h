//Isaías Acosta Herrera
//Estructura de datos
//Taller 03
//Arbol Binario 
//4 de octubre de 2024
//John Corredor
#ifndef __ARBOLBINARIO__H__
#define __ARBOLBINARIO__H__

#include "NodoBinario.h" // Se agregó esta línea para incluir el archivo de NodoBinario.

using namespace std;

template<class T>
class ArbolBinario {
protected:
    NodoBinario<T> *raiz; // El árbol ahora utiliza NodoBinario en lugar de Nodo.

public:
    ArbolBinario();
    bool esVacio();
    T& datoRaiz();
    int altura();
    int tamano();
    void insertar(T& val);
    bool eliminar(T& val);
    NodoBinario<T>* buscar(T& val);
    void preOrden();
    void inOrden();
    void posOrden();
    void nivelOrden(); // Método para recorrido en nivel orden añadido.
};

#include "ArbolBinario.hxx" // Se incluyó el archivo de implementación.
#endif
