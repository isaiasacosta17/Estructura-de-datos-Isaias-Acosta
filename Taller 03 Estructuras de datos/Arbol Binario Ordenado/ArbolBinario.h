
//Isaías Acosta Herrera
//Estructura de datos
//Taller 03
//Arbol Binario Ordenado
//4 de octubre de 2024
//John Corredor
#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H

#include "NodoBinario.h"

template <class T>
class ArbolBinario {
protected:
    NodoBinario<T>* raiz;

public:
    ArbolBinario();
    ~ArbolBinario();
    bool esVacio();
    NodoBinario<T>* datoRaiz();  // Cambiado para devolver el puntero a la raíz
    int altura(NodoBinario<T>* inicio);
    int tamano(NodoBinario<T>* inicio);
    bool insertar(T& val, NodoBinario<T>* nodo);
    bool eliminar(T& val);
    bool buscar(T& val);
    void preOrden(NodoBinario<T>* inicio);
    void inOrden(NodoBinario<T>* inicio);
    void posOrden(NodoBinario<T>* inicio);
    void nivelOrden(NodoBinario<T>* inicio);
};

#endif // ARBOLBINARIO_H
