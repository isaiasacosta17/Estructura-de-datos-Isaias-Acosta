//Isaías Acosta Herrera
//Estructura de datos
//Taller 03
//Arbol Binario 
//4 de octubre de 2024
//John Corredor
#ifndef __NODOBINARIO__H__
#define __NODOBINARIO__H__

using namespace std;

template<class T>
class NodoBinario {
protected:
    T dato; // Valor almacenado en el nodo.
    NodoBinario<T> *hijoIzq; // Puntero al hijo izquierdo.
    NodoBinario<T> *hijoDer; // Puntero al hijo derecho.

public:
    NodoBinario(); // Constructor.
    T& obtenerDato();
    void fijarDato(T& val);
    NodoBinario<T>* obtenerHijoIzq();
    NodoBinario<T>* obtenerHijoDer();
    void fijarHijoIzq(NodoBinario<T> *izq);
    void fijarHijoDer(NodoBinario<T> *der);
    int altura();
    int tamano();
    void insertar(T& val);
    NodoBinario<T>* buscar(T& val);
    void preOrden();
    void inOrden();
    void posOrden();
    void nivelOrden();
    NodoBinario<T>* extremo_izq();
    NodoBinario<T>* extremo_der();
};

#include "NodoBinario.hxx"
#endif
