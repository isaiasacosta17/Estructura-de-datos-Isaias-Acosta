//Estructuras de Datos
//21 de Octubre de 2024
//Santiago Hernandez, Isaias Acosta, Julian Diaz, Juan Carreño

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <fstream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <sstream>

using namespace std;

struct Objeto3D {
    string nombre;
    vector<vector<float>> vertices;
    vector<vector<int>> caras;
};

list<Objeto3D> objetosEnMemoria;

void mostrarAyuda();
void mostrarAyudaComando(const string& comando);
void cargarNombreArchivo(const string& nombre_archivo);
void listado();
void generarEnvolvente(const string& nombre_objeto);
void generarEnvolventeGlobal();
void descargarNombreObjeto(const string& nombre_objeto);
void guardarNombreObjeto(const string& nombre_objeto, const string& nombre_archivo);
void v_cercano(float px, float py, float pz, const string& nombre_objeto);
void v_cercano(float px, float py, float pz);
void v_cercanos_caja(const string& nombre_objeto);

list<Objeto3D>::iterator buscarObjeto(const string& nombre) {
    return find_if(objetosEnMemoria.begin(), objetosEnMemoria.end(),
    [&nombre](const Objeto3D& obj) {
        return obj.nombre == nombre;
    });
}

float calcularDistanciaEuclidiana(const vector<float>& punto1, const vector<float>& punto2) {
    return sqrt(pow(punto1[0] - punto2[0], 2) + pow(punto1[1] - punto2[1], 2) + pow(punto1[2] - punto2[2], 2));
}

int main() {
    string input, nombre_archivo, nombre_objeto;
    int opcion;
    float px, py, pz;

    size_t pos1, pos2;  // Declarar las variables fuera del switch

    cout << "Bienvenido al sistema de manipulacion de mallas 3D.\n Escribe 'ayuda' para ver los comandos disponibles." << endl;

    while (true) {
        cout << "\nOpciones disponibles: " << endl;
        cout << "  1. Cargar nombre archivo." << endl;
        cout << "  2. Listado." << endl;
        cout << "  3. Generar envolvente de un objeto." << endl;
        cout << "  4. Generar envolvente global." << endl;
        cout << "  5. Descargar nombre objeto." << endl;
        cout << "  6. Guardar objeto." << endl;
        cout << "  7. Salir." << endl;
        cout << "  8. Ayuda." << endl;
        cout << "  9. Vértice más cercano a un punto (por objeto)." << endl;
        cout << "  10. Vértice más cercano a un punto (todos los objetos)." << endl;
        cout << "  11. Vértices más cercanos a caja envolvente." << endl;
        cout << "Elige una opcion $ ";
        getline(cin, input);

        if (input == "ayuda") {
            mostrarAyuda();
            continue;
        } else if (input.find("ayuda") == 0) {
            string comando = input.substr(6);
            mostrarAyudaComando(comando);
            continue;
        }

        try {
            opcion = stoi(input);
        } catch (const invalid_argument&) {
            cout << "Opcion no valida." << endl;
            continue;
        }

        switch (opcion) {
            case 1:
                cout << "Introduce el nombre del archivo para cargar el objeto$ ";
                getline(cin, nombre_archivo);
                cargarNombreArchivo(nombre_archivo);
                break;
            case 2:
                listado();
                break;
            case 3:
                cout << "Introduce el nombre del objeto para generar su envolvente$ ";
                getline(cin, nombre_objeto);
                generarEnvolvente(nombre_objeto);
                break;
            case 4:
                generarEnvolventeGlobal();
                break;
            case 5:
                cout << "Introduce el nombre del objeto a descargar$ ";
                getline(cin, nombre_objeto);
                descargarNombreObjeto(nombre_objeto);
                break;
            case 6:
                cout << "Introduce el nombre del objeto a guardar$ ";
                getline(cin, nombre_objeto);
                cout << "Introduce el nombre del archivo de destino$ ";
                getline(cin, nombre_archivo);
                guardarNombreObjeto(nombre_objeto, nombre_archivo);
                break;
            case 7:
                cout << "Saliendo del programa." << endl;
                return 0;
            case 8:
                mostrarAyuda();
                break;
            case 9:
                cout << "Introduce el punto (px,py,pz) seguido del nombre del objeto$ ";
                getline(cin, input);

                // Remover espacios y dividir por comas
                input.erase(remove(input.begin(), input.end(), ' '), input.end());  // Eliminar espacios
                pos1 = input.find(',');
                pos2 = input.find(',', pos1 + 1);

                if (pos1 == string::npos || pos2 == string::npos) {
                    cout << "Formato incorrecto. Asegúrate de usar el formato x,y,z." << endl;
                    break;
                }

                try {
                    px = stof(input.substr(0, pos1));
                    py = stof(input.substr(pos1 + 1, pos2 - pos1 - 1));
                    pz = stof(input.substr(pos2 + 1));
                } catch (const invalid_argument&) {
                    cout << "Error: Formato de punto inválido." << endl;
                    break;
                }

                cout << "Introduce el nombre del objeto$ ";
                getline(cin, nombre_objeto);
                v_cercano(px, py, pz, nombre_objeto);
                break;
            case 10:
                cout << "Introduce el punto (px,py,pz) para buscar el vértice más cercano entre todos los objetos$ ";
                getline(cin, input);

                // Remover espacios y dividir por comas
                input.erase(remove(input.begin(), input.end(), ' '), input.end());  // Eliminar espacios
                pos1 = input.find(',');
                pos2 = input.find(',', pos1 + 1);

                if (pos1 == string::npos || pos2 == string::npos) {
                    cout << "Formato incorrecto. Asegúrate de usar el formato x,y,z." << endl;
                    break;
                }

                try {
                    px = stof(input.substr(0, pos1));
                    py = stof(input.substr(pos1 + 1, pos2 - pos1 - 1));
                    pz = stof(input.substr(pos2 + 1));
                } catch (const invalid_argument&) {
                    cout << "Error: Formato de punto inválido." << endl;
                    break;
                }

                v_cercano(px, py, pz);
                break;
            case 11:
                cout << "Introduce el nombre del objeto para buscar los vértices más cercanos a la caja envolvente$ ";
                getline(cin, nombre_objeto);
                v_cercanos_caja(nombre_objeto);
                break;
            default:
                cout << "Opcion no valida." << endl;
                break;
        }
    }

    return 0;
}

// Implementación de la función para encontrar el vértice más cercano a un punto en un objeto específico
void v_cercano(float px, float py, float pz, const string& nombre_objeto) {
    auto it = buscarObjeto(nombre_objeto);
    if (it == objetosEnMemoria.end()) {
        cout << "Error: El objeto " << nombre_objeto << " no ha sido cargado en memoria." << endl;
        return;
    }

    const auto& objeto = *it;
    float distancia_min = numeric_limits<float>::max();
    int vertice_mas_cercano = -1;

    for (size_t i = 0; i < objeto.vertices.size(); ++i) {
        float distancia = calcularDistanciaEuclidiana(objeto.vertices[i], {px, py, pz});
        if (distancia < distancia_min) {
            distancia_min = distancia;
            vertice_mas_cercano = i;
        }
    }

    const auto& vertice = objeto.vertices[vertice_mas_cercano];
    cout << "El vertice " << vertice_mas_cercano << " (" << vertice[0] << ", " << vertice[1] << ", " << vertice[2] << ") del objeto "
         << nombre_objeto << " es el más cercano al punto (" << px << ", " << py << ", " << pz << "), a una distancia de " << distancia_min << "." << endl;
}

// Implementación para buscar el vértice más cercano en todos los objetos cargados en memoria
void v_cercano(float px, float py, float pz) {
    if (objetosEnMemoria.empty()) {
        cout << "Memoria vacía: Ningún objeto ha sido cargado en memoria." << endl;
        return;
    }

    float distancia_min = numeric_limits<float>::max();
    string objeto_mas_cercano;
    int vertice_mas_cercano = -1;

    for (const auto& objeto : objetosEnMemoria) {
        for (size_t i = 0; i < objeto.vertices.size(); ++i) {
            float distancia = calcularDistanciaEuclidiana(objeto.vertices[i], {px, py, pz});
            if (distancia < distancia_min) {
                distancia_min = distancia;
                vertice_mas_cercano = i;
                objeto_mas_cercano = objeto.nombre;
            }
        }
    }

    // Verificar si se encontró un objeto más cercano
    auto it = buscarObjeto(objeto_mas_cercano);
    if (it == objetosEnMemoria.end()) {
        cout << "Error: No se encontró un objeto más cercano." << endl;
        return;
    }

    const auto& vertice = it->vertices[vertice_mas_cercano];
    cout << "El vertice " << vertice_mas_cercano << " (" << vertice[0] << ", " << vertice[1] << ", " << vertice[2] << ") del objeto "
         << objeto_mas_cercano << " es el más cercano al punto (" << px << ", " << py << ", " << pz << "), a una distancia de " << distancia_min << "." << endl;
}

// Implementación para encontrar los vértices más cercanos a las esquinas de la caja envolvente
void v_cercanos_caja(const string& nombre_objeto) {
    auto it = buscarObjeto(nombre_objeto);
    if (it == objetosEnMemoria.end()) {
        cout << "Error: El objeto " << nombre_objeto << " no ha sido cargado en memoria." << endl;
        return;
    }

    const auto& objeto = *it;
    Objeto3D cajaEnvolvente;

    // Primero generamos la caja envolvente del objeto
    vector<float> pmin(3, numeric_limits<float>::max());
    vector<float> pmax(3, numeric_limits<float>::lowest());

    for (const auto& vertice : objeto.vertices) {
        for (int i = 0; i < 3; ++i) {
            pmin[i] = min(pmin[i], vertice[i]);
            pmax[i] = max(pmax[i], vertice[i]);
        }
    }

    vector<vector<float>> esquinas_caja = {
        {pmin[0], pmin[1], pmin[2]}, {pmax[0], pmin[1], pmin[2]},
        {pmin[0], pmax[1], pmin[2]}, {pmax[0], pmax[1], pmin[2]},
        {pmin[0], pmin[1], pmax[2]}, {pmax[0], pmin[1], pmax[2]},
        {pmin[0], pmax[1], pmax[2]}, {pmax[0], pmax[1], pmax[2]}
    };

    cout << "Vertices más cercanos a las esquinas de la caja envolvente del objeto " << nombre_objeto << ":" << endl;
    for (size_t i = 0; i < esquinas_caja.size(); ++i) {
        float distancia_min = numeric_limits<float>::max();
        int vertice_mas_cercano = -1;

        for (size_t j = 0; j < objeto.vertices.size(); ++j) {
            float distancia = calcularDistanciaEuclidiana(objeto.vertices[j], esquinas_caja[i]);
            if (distancia < distancia_min) {
                distancia_min = distancia;
                vertice_mas_cercano = j;
            }
        }

        const auto& vertice = objeto.vertices[vertice_mas_cercano];
        cout << "Esquina " << i + 1 << " (" << esquinas_caja[i][0] << ", " << esquinas_caja[i][1] << ", " << esquinas_caja[i][2] << ") -> "
             << "Vertice " << vertice_mas_cercano << " (" << vertice[0] << ", " << vertice[1] << ", " << vertice[2] << ") a una distancia de " << distancia_min << endl;
    }
}

void cargarNombreArchivo(const string& nombre_archivo) {
    ifstream archivo(nombre_archivo);  // Abrir archivo

    if (!archivo.is_open()) {
        cout << "Error: No se pudo abrir el archivo " << nombre_archivo << ". Verifica si el archivo existe y tiene permisos de lectura." << endl;
        return;
    }

    string nombre_objeto;
    while (archivo >> nombre_objeto) {
        if (nombre_objeto == "-1") {
            // Fin de la lectura de un objeto
            break;
        }

        // Leer el número de vértices
        int n_vertices;
        archivo >> n_vertices;

        if (archivo.fail()) {
            cout << "Error al leer el número de vértices del objeto " << nombre_objeto << endl;
            archivo.close();
            return;
        }

        Objeto3D nuevoObjeto;
        nuevoObjeto.nombre = nombre_objeto;
        nuevoObjeto.vertices.resize(n_vertices, vector<float>(3));

        // Leer los vértices
        for (int i = 0; i < n_vertices; ++i) {
            archivo >> nuevoObjeto.vertices[i][0] >> nuevoObjeto.vertices[i][1] >> nuevoObjeto.vertices[i][2];
            if (archivo.fail()) {
                cout << "Error al leer los vértices del objeto " << nombre_objeto << endl;
                archivo.close();
                return;
            }
        }

        // Leer las caras (hasta encontrar un -1)
        vector<int> cara;
        while (true) {
            int n_caras;
            archivo >> n_caras;

            if (archivo.fail() || n_caras == -1) {
                // Terminamos de leer las caras del objeto
                break;
            }

            cara.resize(n_caras);
            for (int i = 0; i < n_caras; ++i) {
                archivo >> cara[i];
            }

            nuevoObjeto.caras.push_back(cara);
        }

        objetosEnMemoria.push_back(nuevoObjeto);
        cout << "Objeto " << nombre_objeto << " cargado exitosamente." << endl;
    }

    archivo.close();  // Cerrar el archivo
}


void listado() {
    if (objetosEnMemoria.empty()) {
        cout << "No hay objetos cargados en memoria." << endl;
    } else {
        cout << "Objetos en memoria: " << endl;
        for (const auto& obj : objetosEnMemoria) {
            cout << obj.nombre << " (vertices: " << obj.vertices.size()
                 << ", caras: " << obj.caras.size() << ")" << endl;
        }
    }
}

void generarEnvolvente(const string& nombre_objeto) {
    auto it = buscarObjeto(nombre_objeto);
    if (it == objetosEnMemoria.end()) {
        cout << "Error: El objeto no esta cargado en memoria." << endl;
        return;
    }

    const auto& objeto = *it;

    vector<float> pmin(3, numeric_limits<float>::max());
    vector<float> pmax(3, numeric_limits<float>::lowest());

    for (const auto& vertice : objeto.vertices) {
        for (int i = 0; i < 3; ++i) {
            pmin[i] = min(pmin[i], vertice[i]);
            pmax[i] = max(pmax[i], vertice[i]);
        }
    }

    Objeto3D cajaEnvolvente;
    cajaEnvolvente.nombre = "env_" + nombre_objeto;
    cajaEnvolvente.vertices = {
        {pmin[0], pmin[1], pmin[2]},
        {pmax[0], pmin[1], pmin[2]},
        {pmin[0], pmax[1], pmin[2]},
        {pmax[0], pmax[1], pmin[2]},
        {pmin[0], pmin[1], pmax[2]},
        {pmax[0], pmin[1], pmax[2]},
        {pmin[0], pmax[1], pmax[2]},
        {pmax[0], pmax[1], pmax[2]}
    };

    cajaEnvolvente.caras = {
        {0, 1, 3, 2},
        {4, 5, 7, 6},
        {0, 1, 5, 4},
        {2, 3, 7, 6},
        {0, 2, 6, 4},
        {1, 3, 7, 5}
    };

    objetosEnMemoria.push_back(cajaEnvolvente);
    cout << "Caja envolvente del objeto " << nombre_objeto << " generada exitosamente." << endl;
}

void generarEnvolventeGlobal() {
    if (objetosEnMemoria.empty()) {
        cout << "No hay objetos en memoria para generar una envolvente global." << endl;
        return;
    }

    vector<float> pmin(3, numeric_limits<float>::max());
    vector<float> pmax(3, numeric_limits<float>::lowest());

    for (const auto& objeto : objetosEnMemoria) {
        for (const auto& vertice : objeto.vertices) {
            for (int i = 0; i < 3; ++i) {
                pmin[i] = min(pmin[i], vertice[i]);
                pmax[i] = max(pmax[i], vertice[i]);
            }
        }
    }

    Objeto3D cajaEnvolventeGlobal;
    cajaEnvolventeGlobal.nombre = "envolvente_global";
    cajaEnvolventeGlobal.vertices = {
        {pmin[0], pmin[1], pmin[2]},
        {pmax[0], pmin[1], pmin[2]},
        {pmin[0], pmax[1], pmin[2]},
        {pmax[0], pmax[1], pmin[2]},
        {pmin[0], pmin[1], pmax[2]},
        {pmax[0], pmin[1], pmax[2]},
        {pmin[0], pmax[1], pmax[2]},
        {pmax[0], pmax[1], pmax[2]}
    };

    cajaEnvolventeGlobal.caras = {
        {0, 1, 3, 2},
        {4, 5, 7, 6},
        {0, 1, 5, 4},
        {2, 3, 7, 6},
        {0, 2, 6, 4},
        {1, 3, 7, 5}
    };

    objetosEnMemoria.push_back(cajaEnvolventeGlobal);
    cout << "Caja envolvente global generada exitosamente." << endl;
}

void descargarNombreObjeto(const string& nombre_objeto) {
    auto it = buscarObjeto(nombre_objeto);
    if (it == objetosEnMemoria.end()) {
        cout << "Error: El objeto no esta cargado en memoria." << endl;
        return;
    }

    objetosEnMemoria.erase(it);
    cout << "Objeto " << nombre_objeto << " descargado de la memoria." << endl;
}

void guardarNombreObjeto(const string& nombre_objeto, const string& nombre_archivo) {
    auto it = buscarObjeto(nombre_objeto);
    if (it == objetosEnMemoria.end()) {
        cout << "Error: El objeto no esta en memoria." << endl;
        return;
    }

    const auto& objeto = *it;

    ofstream archivo(nombre_archivo);
    if (!archivo.is_open()) {
        cout << "Error: No se pudo abrir el archivo de destino." << endl;
        return;
    }

    archivo << objeto.vertices.size() << endl;
    for (const auto& vertice : objeto.vertices) {
        archivo << vertice[0] << " " << vertice[1] << " " << vertice[2] << endl;
    }

    archivo << objeto.caras.size() << endl;
    for (const auto& cara : objeto.caras) {
        archivo << cara.size();
        for (int indice : cara) {
            archivo << " " << indice;
        }
        archivo << endl;
    }

    cout << "Objeto " << nombre_objeto << " guardado en " << nombre_archivo << "." << endl;
}

void mostrarAyudaComando(const string& comando) {
    if (comando == "cargar nombre archivo") {
        cout << "Cargar nombre archivo: Carga un objeto 3D desde un archivo. Usa el comando 'cargar nombre archivo'." << endl;
    } else if (comando == "listado") {
        cout << "Listado: Muestra una lista de los objetos 3D en memoria. Usa el comando 'listado'." << endl;
    } else if (comando == "generar envolvente de un objeto") {
        cout << "Generar envolvente de un objeto: Genera una caja envolvente para un objeto 3D específico. Usa el comando 'generar envolvente de un objeto'." << endl;
    } else if (comando == "generar envolvente global") {
        cout << "Generar envolvente global: Genera una caja envolvente para todos los objetos en memoria. Usa el comando 'generar envolvente global'." << endl;
    } else if (comando == "descargar nombre objeto") {
        cout << "Descargar nombre objeto: Elimina un objeto 3D de la memoria. Usa el comando 'descargar nombre objeto'." << endl;
    } else if (comando == "guardar objeto") {
        cout << "Guardar objeto: Guarda un objeto 3D en un archivo. Usa el comando 'guardar objeto'." << endl;
    } else if (comando == "salir") {
        cout << "Salir: Sale del programa. Usa el comando 'salir'." << endl;
    } else {
        cout << "Comando no reconocido. Usa 'ayuda' para ver la lista de comandos disponibles." << endl;
    }
}

void mostrarAyuda() {
    cout << "Lista de comandos disponibles:" << endl;
    cout << "  1. Cargar nombre archivo - Carga un objeto 3D desde un archivo." << endl;
    cout << "  2. Listado - Muestra una lista de los objetos 3D en memoria." << endl;
    cout << "  3. Generar envolvente de un objeto - Genera una caja envolvente para un objeto 3D específico." << endl;
    cout << "  4. Generar envolvente global - Genera una caja envolvente para todos los objetos en memoria." << endl;
    cout << "  5. Descargar nombre objeto - Elimina un objeto 3D de la memoria." << endl;
    cout << "  6. Guardar objeto - Guarda un objeto 3D en un archivo." << endl;
    cout << "  7. Salir - Sale del programa." << endl;
    cout << "  8. Ayuda - Muestra esta ayuda." << endl;
    cout << "  9. Vértice más cercano a un punto (por objeto)." << endl;
    cout << "  10. Vértice más cercano a un punto (todos los objetos)." << endl;
    cout << "  11. Vértices más cercanos a caja envolvente." << endl;
}