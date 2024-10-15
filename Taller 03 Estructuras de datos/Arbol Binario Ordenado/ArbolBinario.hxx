//Isaías Acosta Herrera
//Estructura de datos
//Taller 03
//Arbol Binario Ordenado
//4 de octubre de 2024
//John Corredor#ifndef ARBOL_BINARIO_HXX
#define ARBOL_BINARIO_HXX

#include "NodoBinario.hxx"
#include <iostream>

template <typename T>
class ArbolBinario {
private:
    NodoBinario<T>* raiz;

public:
    // Constructor
    ArbolBinario() : raiz(nullptr) {}

    // Obtener la raíz
    NodoBinario<T>* getRaiz() const { return raiz; }

    // Verificar si el árbol está vacío
    bool esVacio() const { return raiz == nullptr; }

    // Retornar el dato de la raíz
    T datoRaiz() const {
        if (!esVacio()) {
            return raiz->obtenerDato();
        }
        throw std::runtime_error("El árbol está vacío");
    }

    // Obtener la altura del árbol
    int altura() const {
        return alturaRecursivo(raiz);
    }

    // Obtener el tamaño del árbol
    int tamano() const {
        return tamanoRecursivo(raiz);
    }

    // Insertar un valor en el árbol
    void insertar(const T& dato) {
        raiz = insertarRecursivo(raiz, dato);
    }

    // Eliminar un valor en el árbol
    void eliminar(const T& dato) {
        raiz = eliminarRecursivo(raiz, dato);
    }

    // Buscar un valor en el árbol
    bool buscar(const T& dato) const {
        return buscarRecursivo(raiz, dato) != nullptr;
    }

    // Recorrido preOrden del árbol completo
    void preOrden() const {
        preOrdenRecursivo(raiz);
        std::cout << std::endl;
    }

    // Recorrido inOrden del árbol completo
    void inOrden() const {
        inOrdenRecursivo(raiz);
        std::cout << std::endl;
    }

    // Recorrido posOrden del árbol completo
    void posOrden() const {
        posOrdenRecursivo(raiz);
        std::cout << std::endl;
    }

    // Implementaciones de funciones recursivas
private:
    NodoBinario<T>* insertarRecursivo(NodoBinario<T>* nodo, const T& dato) {
        if (nodo == nullptr) {
            return new NodoBinario<T>(dato);
        }
        if (dato < nodo->obtenerDato()) {
            nodo->fijarHijoIzq(insertarRecursivo(nodo->obtenerHijoIzq(), dato));
        } else {
            nodo->fijarHijoDer(insertarRecursivo(nodo->obtenerHijoDer(), dato));
        }
        return nodo;
    }

    NodoBinario<T>* eliminarRecursivo(NodoBinario<T>* nodo, const T& dato) {
        if (nodo == nullptr) return nodo;
        if (dato < nodo->obtenerDato()) {
            nodo->fijarHijoIzq(eliminarRecursivo(nodo->obtenerHijoIzq(), dato));
        } else if (dato > nodo->obtenerDato()) {
            nodo->fijarHijoDer(eliminarRecursivo(nodo->obtenerHijoDer(), dato));
        } else {
            // Nodo encontrado
            if (nodo->obtenerHijoIzq() == nullptr) {
                NodoBinario<T>* temp = nodo->obtenerHijoDer();
                delete nodo;
                return temp;
            } else if (nodo->obtenerHijoDer() == nullptr) {
                NodoBinario<T>* temp = nodo->obtenerHijoIzq();
                delete nodo;
                return temp;
            }
            // Nodo con dos hijos
            NodoBinario<T>* temp = minimoNodo(nodo->obtenerHijoDer());
            nodo->fijarDato(temp->obtenerDato());
            nodo->fijarHijoDer(eliminarRecursivo(nodo->obtenerHijoDer(), temp->obtenerDato()));
        }
        return nodo;
    }

    NodoBinario<T>* minimoNodo(NodoBinario<T>* nodo) const {
        NodoBinario<T>* actual = nodo;
        while (actual && actual->obtenerHijoIzq() != nullptr) {
            actual = actual->obtenerHijoIzq();
        }
        return actual;
    }

    NodoBinario<T>* buscarRecursivo(NodoBinario<T>* nodo, const T& dato) const {
        if (nodo == nullptr || nodo->obtenerDato() == dato) {
            return nodo;
        }
        if (dato < nodo->obtenerDato()) {
            return buscarRecursivo(nodo->obtenerHijoIzq(), dato);
        }
        return buscarRecursivo(nodo->obtenerHijoDer(), dato);
    }

    int alturaRecursivo(NodoBinario<T>* nodo) const {
        if (nodo == nullptr) {
            return 0;
        }
        int alturaIzq = alturaRecursivo(nodo->obtenerHijoIzq());
        int alturaDer = alturaRecursivo(nodo->obtenerHijoDer());
        return std::max(alturaIzq, alturaDer) + 1;
    }

    int tamanoRecursivo(NodoBinario<T>* nodo) const {
        if (nodo == nullptr) {
            return 0;
        }
        return 1 + tamanoRecursivo(nodo->obtenerHijoIzq()) + tamanoRecursivo(nodo->obtenerHijoDer());
    }

    void preOrdenRecursivo(NodoBinario<T>* nodo) const {
        if (nodo != nullptr) {
            std::cout << nodo->obtenerDato() << " ";
            preOrdenRecursivo(nodo->obtenerHijoIzq());
            preOrdenRecursivo(nodo->obtenerHijoDer());
        }
    }

    void inOrdenRecursivo(NodoBinario<T>* nodo) const {
        if (nodo != nullptr) {
            inOrdenRecursivo(nodo->obtenerHijoIzq());
            std::cout << nodo->obtenerDato() << " ";
            inOrdenRecursivo(nodo->obtenerHijoDer());
        }
    }

    void posOrdenRecursivo(NodoBinario<T>* nodo) const {
        if (nodo != nullptr) {
            posOrdenRecursivo(nodo->obtenerHijoIzq());
            posOrdenRecursivo(nodo->obtenerHijoDer());
            std::cout << nodo->obtenerDato() << " ";
        }
    }
};

#endif // ARBOL_BINARIO_HXX
