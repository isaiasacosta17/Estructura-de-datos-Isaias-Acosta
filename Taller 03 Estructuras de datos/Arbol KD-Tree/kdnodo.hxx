//Isaías Acosta Herrera
//Estructura de datos
//Taller 03
//Arbol K-d
//4 de octubre de 2024
//John Corredor
#include "kdnodo.h"
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

template<class T>
kdnodo<T>::kdnodo()
{
    this->hijoIzq = nullptr;
    this->hijoDer = nullptr;
    this->tag = 0;
}

template<class T>
T& kdnodo<T>::obtenerDato()
{
    return this->datos;
}

template<class T>
void kdnodo<T>::fijarDato(vector<T>& val)
{
    this->datos = val;
}

template<class T>
void kdnodo<T>::fijarTag(int value)
{
    this->tag = value;
}

template<class T>
kdnodo<T>* kdnodo<T>::obtenerHijoIzq()
{
    return this->hijoIzq;
}

template<class T>
kdnodo<T>* kdnodo<T>::obtenerHijoDer()
{
    return this->hijoDer;
}

template<class T>
void kdnodo<T>::fijarHijoIzq(kdnodo<T>* izq)
{
    this->hijoIzq = izq;
}

template<class T>
void kdnodo<T>::fijarHijoDer(kdnodo<T>* der)
{
    this->hijoDer = der;
}

template<class T>
int kdnodo<T>::altura()
{
    int alturaIzq = this->hijoIzq ? this->hijoIzq->altura() : 0;
    int alturaDer = this->hijoDer ? this->hijoDer->altura() : 0;

    return max(alturaIzq, alturaDer) + 1;
}

template<class T>
int kdnodo<T>::tamano()
{
    int tamIzq = this->hijoIzq ? this->hijoIzq->tamano() : 0;
    int tamDer = this->hijoDer ? this->hijoDer->tamano() : 0;

    return tamIzq + tamDer + 1;
}

template<class T>
void kdnodo<T>::insertar(vector<T>& val)
{
    if (val[this->tag] > this->datos[this->tag])
    {
        if (this->hijoDer == nullptr)
        {
            kdnodo<T>* nuevo = new kdnodo<T>();
            nuevo->fijarTag((this->tag + 1) % val.size());
            nuevo->fijarDato(val);
            this->fijarHijoDer(nuevo);
        }
        else
        {
            this->hijoDer->insertar(val);
        }
    }
    else if (val[this->tag] < this->datos[this->tag])
    {
        if (this->hijoIzq == nullptr)
        {
            kdnodo<T>* nuevo = new kdnodo<T>();
            nuevo->fijarTag((this->tag + 1) % val.size());
            nuevo->fijarDato(val);
            this->fijarHijoIzq(nuevo);
        }
        else
        {
            this->hijoIzq->insertar(val);
        }
    }
}

template<class T>
kdnodo<T>* kdnodo<T>::buscar(vector<T>& val)
{
    if (this->iguales(val))
    {
        return this;
    }

    if (val[this->tag] < this->datos[this->tag] && this->hijoIzq != nullptr)
    {
        return this->hijoIzq->buscar(val);
    }
    else if (val[this->tag] >= this->datos[this->tag] && this->hijoDer != nullptr)
    {
        return this->hijoDer->buscar(val);
    }

    return nullptr; // Si no se encuentra el valor
}

template<class T>
bool kdnodo<T>::iguales(vector<T>& val)
{
    for (int i = 0; i < val.size(); ++i)
    {
        if (this->datos[i] != val[i])
        {
            return false;
        }
    }
    return true;
}

template<class T>
void kdnodo<T>::preOrden()
{
    this->imprimir();
    if (this->hijoIzq != nullptr)
        this->hijoIzq->preOrden();
    if (this->hijoDer != nullptr)
        this->hijoDer->preOrden();
}

template<class T>
void kdnodo<T>::inOrden()
{
    if (this->hijoIzq != nullptr)
        this->hijoIzq->inOrden();

    this->imprimir();

    if (this->hijoDer != nullptr)
        this->hijoDer->inOrden();
}

template<class T>
void kdnodo<T>::posOrden()
{
    if (this->hijoIzq != nullptr)
        this->hijoIzq->posOrden();

    if (this->hijoDer != nullptr)
        this->hijoDer->posOrden();

    this->imprimir();
}

template<class T>
void kdnodo<T>::nivelOrden()
{
    queue<kdnodo<T>*> cola;
    cola.push(this);
    while (!cola.empty())
    {
        kdnodo<T>* actual = cola.front();
        cola.pop();
        actual->imprimir();

        if (actual->hijoIzq != nullptr)
            cola.push(actual->hijoIzq);
        if (actual->hijoDer != nullptr)
            cola.push(actual->hijoDer);
    }
}

template<class T>
void kdnodo<T>::maximo(int& maxi)
{
    if (maxi < this->datos[this->tag])
    {
        maxi = this->datos[this->tag];
    }
    if (this->hijoIzq != nullptr)
        this->hijoIzq->maximo(maxi);

    if (this->hijoDer != nullptr)
        this->hijoDer->maximo(maxi);
}

template<class T>
void kdnodo<T>::minimo(int& mini)
{
    if (mini > this->datos[this->tag])
    {
        mini = this->datos[this->tag];
    }
    if (this->hijoIzq != nullptr)
        this->hijoIzq->minimo(mini);

    if (this->hijoDer != nullptr)
        this->hijoDer->minimo(mini);
}

template<class T>
void kdnodo<T>::imprimir()
{
    cout << "( ";
    for (int i = 0; i < this->datos.size(); ++i)
    {
        cout << this->datos[i];
        if (i != this->datos.size() - 1)
            cout << ", ";
    }
    cout << " )\n";
}
