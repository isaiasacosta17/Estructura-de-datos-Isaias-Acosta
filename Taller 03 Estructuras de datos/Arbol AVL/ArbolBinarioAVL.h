//Isaías Acosta Herrera
//Estructura de datos
//Taller 03
//Arbol AVL
//4 de octubre de 2024
//John Corredor
#ifndef ARBOL_BINARIO_AVL_H
#define ARBOL_BINARIO_AVL_H

#include "NodoBinarioAVL.h"
template <typename T>

class ArbolBinarioAVL{
	private:
		NodoBinarioAVL<T> *raiz;
	public:
		ArbolBinarioAVL();
		~ArbolBinarioAVL();
		void setRaiz(NodoBinarioAVL<T>* raiz);
		NodoBinarioAVL<T>* getRaiz();
		bool esVacio();
		T& datoRaiz();
		int altura(NodoBinarioAVL<T> *inicio);
		int tamano(NodoBinarioAVL<T> *inicio);
		NodoBinarioAVL<T>* giroDerecha(NodoBinarioAVL<T>*& inicio);
        NodoBinarioAVL<T>* giroIzquierda(NodoBinarioAVL<T>*& inicio);
        NodoBinarioAVL<T>* giroIzquierdaDerecha(NodoBinarioAVL<T>*& inicio);
		NodoBinarioAVL<T>* giroDerechaIzquierda(NodoBinarioAVL<T>*& inicio);
		bool insertar(const T& val);
		bool eliminar(const T& val);
		bool buscar(const T& val);
		void preOrden(NodoBinarioAVL<T> *inicio);
		void inOrden(NodoBinarioAVL<T> *inicio);
		void posOrden(NodoBinarioAVL<T> *inicio);
		void nivelOrden(NodoBinarioAVL<T> *inicio);
};
#include "ArbolBinarioAVL.hxx"

#endif //ARBOLBINARIOAVL_H
