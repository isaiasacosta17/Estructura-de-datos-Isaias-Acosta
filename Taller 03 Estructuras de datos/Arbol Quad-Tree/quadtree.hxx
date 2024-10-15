//Isaías Acosta Herrera
//Estructura de datos
//Taller 03
//Arbol Quad Tree
//4 de octubre de 2024
//John Corredor
#include <bits/stdc++.h>
#include "quadtree.h"

using namespace std;

template<class T>
Arbol<T>::Arbol()
{
    Nodo<T>* root = NULL;
}

template<class T>
Arbol<T>::Arbol(pair<T,T> val)
{
    Nodo<T>* root =new  Nodo<T>(val);
    this->raiz=root;
}
/*
template<class T>
Arbol<T>::~Arbol()
{
    delete(this->raiz);
}
*/
template<class T>
bool Arbol<T>:: esVacio()
{
    if(this->raiz==NULL)
        return true;
    return false;
}

template<class T>
pair<T,T> Arbol<T>:: obtenerRaiz()
{
    return this->raiz;
}

template<class T>
void Arbol<T>::fijarRaiz(Nodo<T>* root)
{
    this->raiz = root;
}

template<class T>
int Arbol<T>:: altura()
{
    return this->raiz->altura();
}

template<class T>
int Arbol<T>:: tamano()
{
    return this->raiz->tamano();
}

template<class T>
void Arbol<T>:: insertar(pair<T,T> val)
{
    this->raiz->insertar(val);
}

/*
template<class T>
bool Arbol<T>:: eliminar(T val)
{
    return this->raiz->eliminar(val);
}
*/
template<class T>
Nodo<T>* Arbol<T>::  buscar(pair<T,T> val)
{
    return this->raiz->buscar(val);
}

template<class T>
void Arbol<T>:: preOrden()
{
    this->raiz->preOrden();
}


template<class T>
void Arbol<T>:: posOrden()
{
    this->raiz->posOrden();
}

