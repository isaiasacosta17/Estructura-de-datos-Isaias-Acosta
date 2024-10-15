//Isaías Acosta Herrera
//Estructura de datos
//Taller 03
//Arbol K-d
//4 de octubre de 2024
//John Corredor
#include "kdtree.h"
#include "kdnodo.h"

using namespace std;


template<class T>
kdtree<T>::kdtree(){
	this->raiz=nullptr;
}


template<class T>
bool kdtree<T>::esVacio()
{
   if(this==NULL)
   {
      return true;
   }
   else
   {
     return false;
   }
}

template<class T>
T& kdtree<T>::datoRaiz()
{
   return this->raiz->obtenerDato();
}

template<class T>
int kdtree<T>::altura()
{
   return this->raiz->altura();
}

template<class T>
int kdtree<T>::tamano()
{
	return this->raiz->tamano() ;
}

template<class T>
void kdtree<T>::insertar(vector<T>& val)
{
	if(this->raiz!=NULL){
		this->raiz->insertar(val);
	}
	else{
		kdnodo<T>* nuevo= new kdnodo<T>();
		nuevo->fijarDato(val);
		this->raiz=nuevo;
	}


}



template<class T>
bool kdtree<T>::eliminar(vector<T>& val)
{

}

template<class T>
kdnodo<T>* kdtree<T>::buscar(vector<T>& val)
{
	return this->raiz->buscar(val);
}

template<class T>
void kdtree<T>::preOrden()
{
	this->raiz->preOrden();
}

template<class T>
void kdtree<T>::inOrden()
{
	this->raiz->inOrden();
}

template<class T>
void kdtree<T>::posOrden()
{
	this->raiz->posOrden();
}

template<class T>
void kdtree<T>::nivelOrden()
{
	this->raiz->nivelOrden();
}

template<class T>
void kdtree<T>::maximo(int &maxi)
{
	this->raiz->maximo(maxi);
}

template<class T>
void kdtree<T>::minimo(int &mini)
{
	this->raiz->minimo(mini);
}
