//Isaías Acosta Herrera
//Estructura de datos
//Taller 03
//Arbol K-d
//4 de octubre de 2024
//John Corredor
#include<iostream>
#include<vector>
#include "kdtree.h"
#include "kdnodo.h"

using namespace std;

int main(int argc, char* argv[])
{
    cout<<"ARBOL BINARIO ORDENADO"<<endl;
    cout<<"****************************************************************"<<endl;
    kdtree<int> arbolito;
	for(int i=0; i<15; i++)
	{
	    cout<<"Inserte dato: ";
		int dato;
		cin>>dato;vector<int> datos ={dato};
		arbolito.insertar(datos);
	}

	cout<<endl;
	cout<<"Pre Orden:"<<endl;
	arbolito.preOrden();
	cout<<endl;
	cout<<"Pos Orden: "<<endl;
	arbolito.posOrden();
	cout<<endl;

	return 0;
}
