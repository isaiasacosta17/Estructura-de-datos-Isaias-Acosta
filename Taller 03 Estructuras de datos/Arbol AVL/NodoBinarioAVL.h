//Isaías Acosta Herrera
//Estructura de datos
//Taller 03
//Arbol AVL
//4 de octubre de 2024
//John Corredor
#ifndef NODOBINARIOAVL_H
#define NODOBINARIOAVL_H

template <typename T>
class NodoBinarioAVL{
	public:
		T dato;
		NodoBinarioAVL<T> *hijoIzq;
		NodoBinarioAVL<T> *hijoDer;

		NodoBinarioAVL();
		NodoBinarioAVL(const T& val);
		~NodoBinarioAVL();
		T& getDato();
		void setDato(const T& val);
		NodoBinarioAVL<T>* getHijoIzq();
		NodoBinarioAVL<T>* getHijoDer();
		void setHijoIzq(NodoBinarioAVL<T>* izq);
		void setHijoDer(NodoBinarioAVL<T>* der);
};

#include "NodoBinarioAVL.hxx"

#endif //NODOBINARIOAVL_H
