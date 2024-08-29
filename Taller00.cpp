#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <stack>
#include <vector>  // Añadir esta línea para usar std::vector

using namespace std;

struct cliente {
    string nombre;
    string nombre_producto;
    int cedula;
    int costo_producto;
    int cantidad;
};

void rellenarArreglo(int arreglo[]) {
    for (int i = 0; i < 10; i++) {
        arreglo[i] = rand() % 25;
    }
}

void mostrarArreglo(int arreglo[], int* puntero) {
    for (int i = 0; i < 10; i++) {
        cout << "posicion " << i + 1 << " :" << *(puntero + i) << endl;
    }

    for (int i = 0; i < 10; i++) {
        cout << puntero + i << endl;
    }
}

int main() {
    srand(time(NULL));
    int arreglo[10];
    int* puntero = arreglo;
    rellenarArreglo(arreglo);
    mostrarArreglo(arreglo, puntero);

    bool repetir = true;
    int numeroRepetir;
    vector<cliente> clientes;  // Se debe usar std::vector

    cout << "Bienvenido a la empresa." << endl;
    while (repetir) {
        cliente nuevoCliente;
        cout << "Por favor ingrese el nombre del cliente: ";
        cin >> nuevoCliente.nombre;
        cout << "Por favor ingrese el nombre del producto: ";
        cin >> nuevoCliente.nombre_producto;
        cout << "Por favor ingrese la cedula del cliente: ";
        cin >> nuevoCliente.cedula;
        cout << "Por favor ingrese el precio del producto: ";
        cin >> nuevoCliente.costo_producto;
        cout << "Por favor ingrese la cantidad de productos: ";
        cin >> nuevoCliente.cantidad;
        clientes.push_back(nuevoCliente);
        cout << "¿Desea ingresar otro cliente?" << endl;
        cout << "Ingrese 1 para sí, 2 para no: ";
        cin >> numeroRepetir;
        repetir = (numeroRepetir == 1);
    }

    int valortotal;
    for (int i = 0; i < clientes.size(); i++) {
        cout << "Nombre: " << clientes[i].nombre << endl;
        cout << "Nombre producto: " << clientes[i].nombre_producto << endl;
        cout << "Cédula: " << clientes[i].cedula << " ";
        cout << "Valor producto: " << clientes[i].costo_producto << endl;
        cout << "Cantidad producto: " << clientes[i].cantidad << endl;
        valortotal = clientes[i].cantidad * clientes[i].costo_producto;
        cout << "Valor total: " << valortotal << endl;
    }

    ofstream archivo("clientes.txt");  // Abre el archivo para escritura

    if (archivo.is_open()) {
        for (int i = 0; i < clientes.size(); i++) {
            archivo << "Nombre: " << clientes[i].nombre << endl;
            archivo << "Nombre producto: " << clientes[i].nombre_producto << endl;
            archivo << "Cédula: " << clientes[i].cedula << " ";
            archivo << "Valor producto: " << clientes[i].costo_producto << endl;
            archivo << "Cantidad producto: " << clientes[i].cantidad << endl;
            valortotal = clientes[i].cantidad * clientes[i].costo_producto;
            archivo << "Valor total: " << valortotal << endl;
        }
        archivo.close();
    }
}
