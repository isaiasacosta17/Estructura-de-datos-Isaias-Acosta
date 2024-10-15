//Isaías Acosta Herrera
//Estructura de datos
//Taller 03
//Arbol Binario Ordenado
//4 de octubre de 2024
//John Corredor
#ifndef NODO_BINARIO_HXX
#define NODO_BINARIO_HXX

template <typename T>
class NodoBinario {
private:
    T dato;
    NodoBinario<T>* hijoIzq;
    NodoBinario<T>* hijoDer;

public:
    // Constructor por defecto
    NodoBinario() : hijoIzq(nullptr), hijoDer(nullptr) {}

    // Constructor parametrizado
    NodoBinario(const T& dato) : dato(dato), hijoIzq(nullptr), hijoDer(nullptr) {}

    // Getters y setters
    T obtenerDato() const { return dato; }
    void fijarDato(const T& dato) { this->dato = dato; }

    NodoBinario<T>* obtenerHijoIzq() const { return hijoIzq; }
    void fijarHijoIzq(NodoBinario<T>* hijo) { this->hijoIzq = hijo; }

    NodoBinario<T>* obtenerHijoDer() const { return hijoDer; }
    void fijarHijoDer(NodoBinario<T>* hijo) { this->hijoDer = hijo; }
};

#endif // NODO_BINARIO_HXX
