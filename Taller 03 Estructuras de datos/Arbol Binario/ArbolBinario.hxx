//Isaías Acosta Herrera
//Estructura de datos
//Taller 03
//Arbol Binario 
//4 de octubre de 2024
//John Corredor
#include "ArbolBinario.h"
#include "NodoBinario.h"

using namespace std;

template<class T>
ArbolBinario<T>::ArbolBinario() {
    this->raiz = NULL; // Inicializa la raíz como NULL, ya que es un árbol vacío.
}

template<class T>
bool ArbolBinario<T>::esVacio() {
    return this->raiz == NULL; // Verifica si el árbol está vacío.
}

template<class T>
T& ArbolBinario<T>::datoRaiz() {
    return this->raiz->obtenerDato(); // Devuelve el dato de la raíz.
}

template<class T>
int ArbolBinario<T>::altura() {
    return this->raiz->altura(); // Llama al método altura de NodoBinario.
}

template<class T>
int ArbolBinario<T>::tamano() {
    return this->raiz->tamano(); // Llama al método tamano de NodoBinario.
}

template<class T>
void ArbolBinario<T>::insertar(T& val) {
    if (this->raiz != NULL) {
        this->raiz->insertar(val); // Llama al método insertar de NodoBinario.
    } else {
        NodoBinario<T>* nuevo = new NodoBinario<T>(); // Crea un nuevo NodoBinario si la raíz está vacía.
        nuevo->fijarDato(val);
        this->raiz = nuevo;
    }
}

template<class T>
bool ArbolBinario<T>::eliminar(T& val) {
    NodoBinario<T>* borrar = this->buscar(val); // Busca el nodo a eliminar.
    if (borrar == NULL)
        return false;

    if (borrar->hijoIzq != NULL) {
        NodoBinario<T>* nuevo = borrar->hijoIzq->extremo_der(); // Encuentra el nodo más derecho del subárbol izquierdo.
        borrar->fijarDato(nuevo->obtenerDato());
        delete(nuevo); // Elimina el nodo más extremo.
    } else if (borrar->hijoDer != NULL) {
        NodoBinario<T>* nuevo = borrar->hijoDer->extremo_izq(); // Encuentra el nodo más izquierdo del subárbol derecho.
        borrar->fijarDato(nuevo->obtenerDato());
        delete(nuevo); // Elimina el nodo más extremo.
    }
    return true;
}

template<class T>
NodoBinario<T>* ArbolBinario<T>::buscar(T& val) {
    return this->raiz->buscar(val); // Llama al método buscar de NodoBinario.
}

template<class T>
void ArbolBinario<T>::preOrden() {
    this->raiz->preOrden(); // Llama al método preOrden de NodoBinario.
}

template<class T>
void ArbolBinario<T>::inOrden() {
    this->raiz->inOrden(); // Llama al método inOrden de NodoBinario.
}

template<class T>
void ArbolBinario<T>::posOrden() {
    this->raiz->posOrden(); // Llama al método posOrden de NodoBinario.
}

template<class T>
void ArbolBinario<T>::nivelOrden() {
    this->raiz->nivelOrden(); // Llama al método nivelOrden de NodoBinario.
}
