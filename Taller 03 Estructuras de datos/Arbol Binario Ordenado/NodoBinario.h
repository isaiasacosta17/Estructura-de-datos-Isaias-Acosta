//Isaías Acosta Herrera
//Estructura de datos
//Taller 03
//Arbol Binario Ordenado
//4 de octubre de 2024
//John Corredor
#ifndef NODOBINARIO_H
#define NODOBINARIO_H

template <class T>
class NodoBinario {
protected:
    T dato;
    NodoBinario<T>* hijoIzq;
    NodoBinario<T>* hijoDer;

public:
    NodoBinario();  // Constructor
    ~NodoBinario();  // Destructor
    T& getDato();  // Obtiene el dato del nodo
    void setDato(T& val);  // Establece el dato del nodo
    NodoBinario<T>* getHijoIzq();  // Retorna el hijo izquierdo
    NodoBinario<T>* getHijoDer();  // Retorna el hijo derecho
    void setHijoIzq(NodoBinario<T>* izq);  // Establece el hijo izquierdo
    void setHijoDer(NodoBinario<T>* der);  // Establece el hijo derecho
};

#endif // NODOBINARIO_H
