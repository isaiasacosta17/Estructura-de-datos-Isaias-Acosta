//Isaías Acosta Herrera
//Estructura de datos
//Taller 03
//Arbol AVL
//4 de octubre de 2024
//John Corredor
#include "NodoBinarioAVL.h"

using namespace std;

template <typename T>
NodoBinarioAVL<T>::NodoBinarioAVL(const T& val){
    this->dato=val;
	this->hijoIzq=nullptr;
	this->hijoDer=nullptr;
}

template <typename T>
NodoBinarioAVL<T>::~NodoBinarioAVL(){
	delete hijoIzq;
	delete hijoDer;
}

template <typename T>
T& NodoBinarioAVL<T>::getDato(){
	return this->dato;
}

template <typename T>
void NodoBinarioAVL<T>::setDato(const T& val){
	this->dato=val;
	return;
}

template <typename T>
NodoBinarioAVL<T>* NodoBinarioAVL<T>::getHijoIzq(){
	return this->hijoIzq;
}

template <typename T>
NodoBinarioAVL<T>* NodoBinarioAVL<T>::getHijoDer(){
	return this->hijoDer;
}

template <typename T>
void NodoBinarioAVL<T>::setHijoIzq(NodoBinarioAVL<T>* izq){
	this->hijoIzq=izq;
	return;
}

template <typename T>
void NodoBinarioAVL<T>::setHijoDer(NodoBinarioAVL<T>* der){
	this->hijoDer=der;
	return;
}