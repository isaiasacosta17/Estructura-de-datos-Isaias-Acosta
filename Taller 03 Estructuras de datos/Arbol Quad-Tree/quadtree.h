//Isaías Acosta Herrera
//Estructura de datos
//Taller 03
//Arbol Quad Tree
//4 de octubre de 2024
//John Corredor
#ifndef __QUADTREE__H__
#define __QUADTREE__H__

#include "Nodo.h"

using namespace std;

template<class T>
class Arbol {
  protected:
    Nodo<T> *raiz;
  public:
	Arbol();
	Arbol(pair<T,T> val);
    bool esVacio();
    pair<T,T> obtenerRaiz();
    void fijarRaiz(Nodo<T>* root);
    void insertar(pair<T,T>);
    int altura();
    int tamano();
    void insertar(T& val);
    bool eliminar(T& val);
    Nodo<T>*  buscar(pair<T,T> val);
    void preOrden();
    void posOrden();
};

#include "quadtree.hxx"
#endif
