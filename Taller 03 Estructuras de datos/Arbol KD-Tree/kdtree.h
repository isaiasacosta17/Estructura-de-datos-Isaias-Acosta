//Isaías Acosta Herrera
//Estructura de datos
//Taller 03
//Arbol K-d
//4 de octubre de 2024
//John Corredor
#ifndef __KDTREE__H__
#define __KDTREE__H__

#include "kdnodo.h"

using namespace std;

template<class T>
class kdtree {
  private:
    kdnodo<T> *raiz;
public:
	kdtree();
    bool esVacio();
    T& datoRaiz();
    int altura();
    int tamano();
    void insertar(vector<T>& val);
    bool eliminar(vector<T>& val);
    kdnodo<T>*  buscar(vector<T>& val);
    void preOrden();
    void inOrden();
    void posOrden();
    void nivelOrden();
    void maximo(int &maxi);
    void minimo(int &mini);
};

#include "kdtree.hxx"
#endif
