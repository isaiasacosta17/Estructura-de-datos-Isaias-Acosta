//Isaías Acosta Herrera
//Estructura de datos
//Taller 03
//Arbol AVL
//4 de octubre de 2024
//John Corredor
#include "ArbolBinarioAVL.h"
#include <queue>

using namespace std;

template <typename T>
ArbolBinarioAVL<T>::ArbolBinarioAVL(){
	this->raiz=NULL;
}

template <typename T>
ArbolBinarioAVL<T>::~ArbolBinarioAVL(){
}

template <typename T>
void ArbolBinarioAVL<T>::setRaiz(NodoBinarioAVL<T>* raiz){
	this->raiz=raiz;
}

template <typename T>
NodoBinarioAVL<T>* ArbolBinarioAVL<T>::getRaiz(){
	return this->raiz;
}

template <typename T>
bool ArbolBinarioAVL<T>::esVacio(){
	return this->raiz==NULL;
}

template <typename T>
T& ArbolBinarioAVL<T>::datoRaiz(){
	if(this->raiz){
	return (this->raiz)->getDato();
	}
	throw std::runtime_error("La raiz es nula");
}

template <typename T>
int ArbolBinarioAVL<T>::altura(NodoBinarioAVL<T> *inicio){
if (inicio == NULL) {
        return -1;
    }
    int alturaIzq = altura(inicio->getHijoIzq());
    int alturaDer = altura(inicio->getHijoDer());
    return 1 + std::max(alturaIzq, alturaDer);
}

template <typename T>
int ArbolBinarioAVL<T>::tamano(NodoBinarioAVL<T> *inicio){
	if (inicio == NULL) {
        return 0;
    }
    return 1 + tamano(inicio->getHijoIzq()) + tamano(inicio->getHijoDer());
}
	

template <typename T>
NodoBinarioAVL<T>* ArbolBinarioAVL<T>::giroDerecha(NodoBinarioAVL<T>*& padre) {
    NodoBinarioAVL<T> *n_padre = padre->getHijoIzq();
    padre->setHijoIzq(n_padre->getHijoDer());
    n_padre->setHijoDer(padre);
    return n_padre;
}

template <typename T>
NodoBinarioAVL<T>* ArbolBinarioAVL<T>::giroIzquierda(NodoBinarioAVL<T>*& padre) {
    NodoBinarioAVL<T> *n_padre = padre->getHijoDer();
    padre->setHijoDer(n_padre->getHijoIzq());
    n_padre->setHijoIzq(padre);
    return n_padre;
}

template <typename T>
NodoBinarioAVL<T>* ArbolBinarioAVL<T>::giroIzquierdaDerecha(NodoBinarioAVL<T>*& padre) {
    NodoBinarioAVL<T>* hijoIzq = padre->getHijoIzq();
    padre->setHijoIzq(giroIzquierda(hijoIzq));
    return giroDerecha(padre);
}

template <typename T>
NodoBinarioAVL<T>* ArbolBinarioAVL<T>::giroDerechaIzquierda(NodoBinarioAVL<T>*& padre) {
    NodoBinarioAVL<T>* hijoDer = padre->getHijoDer();
    padre->setHijoDer(giroDerecha(hijoDer));
    return giroIzquierda(padre);
}


template <typename T>
bool ArbolBinarioAVL<T>::insertar(const T& val){
	NodoBinarioAVL<T> *nodoActual=this->raiz;
	NodoBinarioAVL<T> *nNodo=new NodoBinarioAVL<T>(val);
	NodoBinarioAVL<T> *n_padre = nullptr;
	while (nodoActual != NULL) {
        n_padre = nodoActual;
        if (val < nodoActual->getDato()) {
            nodoActual = nodoActual->getHijoIzq();
        } else if (val > nodoActual->getDato()) {
            nodoActual = nodoActual->getHijoDer();
        } else {
            // El valor ya existe en el árbol.
            delete nNodo; // Liberar memoria si no se inserta.
            return false;
        }
    }

    if (n_padre == NULL) {
        // El árbol estaba vacío, el nuevo nodo se convierte en la raíz.
        this->raiz = nNodo;
    } else if (val < n_padre->getDato()) {
        n_padre->setHijoIzq(nNodo);
    } else {
        n_padre->setHijoDer(nNodo);
    }

    return true;
}

template <typename T>
bool ArbolBinarioAVL<T>::eliminar(const T& val){
	NodoBinarioAVL<T> *buscaNodo=this->raiz;
	if(this->raiz==NULL){
		return false;
	}else{
		while(buscaNodo->getHijoDer()!=NULL || buscaNodo->getHijoIzq()!=NULL || buscaNodo->getDato()==val){
			if(buscaNodo->getDato()==val){
				if(buscaNodo->getHijoDer()==NULL && buscaNodo->getHijoIzq()==NULL){
					NodoBinarioAVL<T> *buscaNodo3=this->raiz;
					if(this->raiz==buscaNodo){
						this->raiz=NULL;
					}
					else{
						while(buscaNodo3->getHijoIzq()!=NULL || buscaNodo3->getHijoDer()!=NULL){
							if(buscaNodo3->getHijoIzq()!=NULL){
								if((buscaNodo3->getHijoIzq())->getDato()==buscaNodo->getDato()){
									buscaNodo3->setHijoIzq(NULL);
									break;
								}
							}
							if(buscaNodo3->getHijoDer()!=NULL){
								if((buscaNodo3->getHijoDer())->getDato()==buscaNodo->getDato()){
									buscaNodo3->setHijoDer(NULL);
									break;
								}
							}
							if(buscaNodo->getDato()>buscaNodo3->getDato()){
								buscaNodo3=buscaNodo3->getHijoDer();
							}else{
								buscaNodo3=buscaNodo3->getHijoIzq();
							}
						}
					}
					delete(buscaNodo);
				}else if(buscaNodo->getHijoDer()==NULL){
					*(buscaNodo)=*(buscaNodo->getHijoIzq());
				}else if(buscaNodo->getHijoIzq()==NULL){
					*(buscaNodo)=*(buscaNodo->getHijoDer());
				}else{
					NodoBinarioAVL<T> *buscaNodo2=buscaNodo->getHijoIzq();
					while(buscaNodo2->getHijoDer()!=NULL){
						buscaNodo2=buscaNodo2->getHijoDer();
					}
					buscaNodo->setDato(buscaNodo2->getDato());
					if(buscaNodo2->getHijoIzq()==NULL){
						if((buscaNodo->getHijoIzq())->getHijoDer()!=NULL){
							NodoBinarioAVL<T> *buscaNodo3=buscaNodo->getHijoIzq();
							while((buscaNodo3->getHijoDer())->getDato()!=buscaNodo2->getDato()){
								buscaNodo3=buscaNodo3->getHijoDer();
							}
							buscaNodo3->setHijoDer(NULL);
						}else{
							buscaNodo->setHijoIzq(NULL);
						}
						delete(buscaNodo2);
					}else{
						*(buscaNodo2)=*(buscaNodo2->getHijoIzq());
					}
				}
				NodoBinarioAVL<T> **nBalanceo=&(this->raiz);
				while((*nBalanceo)!=NULL){
					if(altura((*nBalanceo)->getHijoIzq())-altura((*nBalanceo)->getHijoDer())>1 && altura(((*nBalanceo)->getHijoIzq())->getHijoIzq())>altura(((*nBalanceo)->getHijoIzq())->getHijoDer())){
						*nBalanceo=giroDerecha(*nBalanceo);
					}else if(altura((*nBalanceo)->getHijoIzq())-altura((*nBalanceo)->getHijoDer())>1 && altura(((*nBalanceo)->getHijoIzq())->getHijoIzq())<altura(((*nBalanceo)->getHijoIzq())->getHijoDer())){
						*nBalanceo=giroIzquierdaDerecha(*nBalanceo);
					}else if(altura((*nBalanceo)->getHijoDer())-altura((*nBalanceo)->getHijoIzq())>1 && altura(((*nBalanceo)->getHijoDer())->getHijoDer())>altura(((*nBalanceo)->getHijoDer())->getHijoIzq())){
						*nBalanceo=giroIzquierda(*nBalanceo);
					}else if(altura((*nBalanceo)->getHijoDer())-altura((*nBalanceo)->getHijoIzq())>1 && altura(((*nBalanceo)->getHijoDer())->getHijoDer())<altura(((*nBalanceo)->getHijoDer())->getHijoIzq())){
						*nBalanceo=giroDerechaIzquierda(*nBalanceo);
					}
			
					if((*nBalanceo)->getDato()<val){
						nBalanceo=&((*nBalanceo)->hijoDer);
					}else{
						nBalanceo=&((*nBalanceo)->hijoIzq);
					}
				} 
				return true;
			}else if(val<buscaNodo->getDato() && buscaNodo->getHijoIzq()!=NULL){
				buscaNodo=buscaNodo->getHijoIzq();
			}else if(val>buscaNodo->getDato() && buscaNodo->getHijoDer()!=NULL){
				buscaNodo=buscaNodo->getHijoDer();
			}else if(val<buscaNodo->getDato() && buscaNodo->getHijoIzq()==NULL){
				return false;
			}else if(val>buscaNodo->getDato() && buscaNodo->getHijoDer()==NULL){
				return false;
			}
		}
	}
	return false;
}

template <typename T>
bool ArbolBinarioAVL<T>::buscar(const T& val){
NodoBinarioAVL<T>* buscaNodo = this->raiz;
    while (buscaNodo != NULL) {
        if (buscaNodo->getDato() == val) {
            return true;
        }
        buscaNodo = (val < buscaNodo->getDato()) ? buscaNodo->getHijoIzq() : buscaNodo->getHijoDer();
    }
    return false;
}

template <typename T>
void ArbolBinarioAVL<T>::preOrden(NodoBinarioAVL<T>* inicio) {
    if (inicio) {
        cout << inicio->getDato() << " ";
        preOrden(inicio->getHijoIzq());
        preOrden(inicio->getHijoDer());
    }
}

template <typename T>
void ArbolBinarioAVL<T>::inOrden(NodoBinarioAVL<T>* inicio) {
    if (inicio) {
        inOrden(inicio->getHijoIzq());
        cout << inicio->getDato() << " ";
        inOrden(inicio->getHijoDer());
    }
}

template <typename T>
void ArbolBinarioAVL<T>::posOrden(NodoBinarioAVL<T>* inicio) {
    if (inicio) {
        posOrden(inicio->getHijoIzq());
        posOrden(inicio->getHijoDer());
        cout << inicio->getDato() << " ";
    }
}

template <typename T>
void ArbolBinarioAVL<T>::nivelOrden(NodoBinarioAVL<T>* inicio) {
    if (inicio == NULL) return;

    queue<NodoBinarioAVL<T>*> colaNivel; // Usar punteros
    colaNivel.push(inicio);
    while (!colaNivel.empty()) {
        NodoBinarioAVL<T>* nodo = colaNivel.front();
        colaNivel.pop();
        cout << nodo->getDato() << " ";
        if (nodo->getHijoIzq() != NULL) {
            colaNivel.push(nodo->getHijoIzq());
        }
        if (nodo->getHijoDer() != NULL) {
            colaNivel.push(nodo->getHijoDer());
        }
    }
}