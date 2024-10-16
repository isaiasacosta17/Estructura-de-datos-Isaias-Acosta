//Isaías Acosta Herrera
//Estructura de datos
//Taller 03
//Arbol Expresión
//4 de octubre de 2024
//John Corredor
#ifndef ARBOLEXPRESION_H
#define  ARBOLEXPRESION_H
#include "NodoExpresion.h"
#include <string>

using namespace std;

class ArbolExpresion {
  protected:
    NodoExpresion* raiz;
public:
    ArbolExpresion();
    ~ArbolExpresion();
    NodoExpresion* getRaiz();
    void setRaiz(NodoExpresion* nod);

    void llenarDesdePrefija(string &expresion);
    void llenarDesdePosfija (string &expresion);

    void  obtenerPrefija(NodoExpresion* inicio);
    void  obtenerInfija(NodoExpresion* inicio);
    void  obtenerPosfija(NodoExpresion* inicio);
    int evaluar(NodoExpresion* nodi);
    bool siOperando(char car);
};
#include "ArbolExpresion.hxx"

#endif

