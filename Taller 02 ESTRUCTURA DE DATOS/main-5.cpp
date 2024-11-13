//Isaías Acosta
//Estructura de datos
//John Corredor


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;
// Estructura que representa un álbum musical
struct Album {
    string nombre;
    int año;
};
// Estructura que representa una canción, incluyendo el álbum al que pertenece
struct Cancion { 
    string nombre;
    string autor;
    string genero;
    Album album;
};

// Función que imprime una lista de canciones con sus detalles
void imprimirCanciones(const list<Cancion>& canciones) {
    for (const auto& cancion : canciones) {
        cout << "Canción: " << cancion.nombre << endl;
        cout << "Autor: " << cancion.autor << endl;
        cout << "Género: " << cancion.genero << endl;
        cout << "Álbum: " << cancion.album.nombre << endl;
        cout << "Año: " << cancion.album.año << endl;
        cout << "-----------------------------" << endl;
    }
}

int main() {
    list<Cancion> canciones; // Lista para almacenar las canciones leídas del archivo
    bool repetir = true;  // Variable para controlar el ciclo del menú

    while (repetir) {
        cout << "Bienvenido a javemusic, estas son sus canciones: " << endl;

        // Leer el archivo "archivo.txt" que contiene las canciones
        ifstream archivo("archivo.txt");
        if (archivo.is_open()) {
            string linea;
            while (getline(archivo, linea)) {
                istringstream ss(linea);
                Cancion cancion;
                string campo;
                
                // Leer y asignar los campos de la canción
                try {
                    // Leer los campos de la línea
                    getline(ss, cancion.nombre, '|');
                    getline(ss, cancion.autor, '|');
                    getline(ss, cancion.genero, '|');
                    getline(ss, campo, '|');
                    cancion.album.nombre = campo;
                    getline(ss, campo, '|');
                    if (!campo.empty()) {
                        cancion.album.año = stoi(campo); // Convertir el año a entero
                    } else {
                        throw invalid_argument("El campo del año está vacío");
                    }

                    canciones.push_back(cancion);
                } catch (const invalid_argument& e) {
                    cout << "Error al convertir el campo del año a entero: " << e.what() << endl;
                }
            }
            archivo.close();
        } else {
            cout << "Unable to open file" << endl;
        }

        int seleccion;
         // Menú de opciones
        cout << endl;
        cout << "1. Listar todos los autores." << endl;
        cout << "2. Listar las canciones de un artista ordenado alfabéticamente." << endl;
        cout << "3. Listar todos los álbumes, ordenados cronológicamente." << endl;
        cout << "4. Listar todas las canciones de un álbum, ordenadas alfabéticamente." << endl;
        cout << "5. Listar todas las canciones y su álbum, ordenados alfabéticamente por el álbum y después por la canción." << endl;
        cout << "Ingrese una opción: ";
        cin >> seleccion;

        // Ejecución de la opción seleccionada
        switch (seleccion) {
            case 1: {
                // Listar todos los autores sin duplicados y en orden alfabético
                
                list<string> autores;
                for (const auto& cancion : canciones) {
                    autores.push_back(cancion.autor);
                }
                autores.sort();
                autores.unique();
                cout << "Autores:" << endl;
                for (const auto& autor : autores) {
                    cout << autor << endl;
                }
                break;
            }
            case 2: {
                // Listar las canciones de un artista ordenado alfabéticamente
                string artista;
                cout << "Ingrese el nombre del artista: \n";
                cin>>artista;

                list<Cancion> cancionesArtista;
                for (const auto& cancion : canciones) {
                    if (cancion.autor == artista) {
                        cancionesArtista.push_back(cancion);
                    }
                }

                cancionesArtista.sort([](const Cancion& a, const Cancion& b) {
                    return a.nombre < b.nombre;
                });

                cout << "Canciones de " << artista << ":" << endl;
                imprimirCanciones(cancionesArtista);
                break;
            }
            case 3: {
            // Listar todos los álbumes ordenados cronológicamente y sin duplicados  
                vector<Album> albumes;
                for (const auto& cancion : canciones) {
                    albumes.push_back(cancion.album);
                }

               
                sort(albumes.begin(), albumes.end(), [](const Album& a, const Album& b) {
                    return a.año < b.año;
                });
                albumes.erase(unique(albumes.begin(), albumes.end(), [](const Album& a, const Album& b) {
                    return a.nombre == b.nombre && a.año == b.año;
                }), albumes.end());

                cout << "Álbumes por año:" << endl;
                for (const auto& album : albumes) {
                    cout << "Álbum: " << album.nombre << ", Año: " << album.año << endl;
                }
                break;
            }
            case 4: {
                // Listar todas las canciones de un álbum, ordenadas alfabéticamente
                string albumNombre;
                cout << "Ingrese el nombre del álbum: ";
                cin>>albumNombre;

                list<Cancion> cancionesAlbum;
                for (const auto& cancion : canciones) {
                    if (cancion.album.nombre == albumNombre) {
                        cancionesAlbum.push_back(cancion);
                    }
                }

                cancionesAlbum.sort([](const Cancion& a, const Cancion& b) {
                    return a.nombre < b.nombre;
                });

                cout << "Canciones en el álbum " << albumNombre << ":" << endl;
                imprimirCanciones(cancionesAlbum);
                break;
            }
            case 5: {
                // Listar todas las canciones y su álbum, ordenados alfabéticamente por el álbum y después por la canción
                list<Cancion> cancionesOrdenadas = canciones;

                cancionesOrdenadas.sort([](const Cancion& a, const Cancion& b) {
                    if (a.album.nombre == b.album.nombre) {
                        return a.nombre < b.nombre;
                    }
                    return a.album.nombre < b.album.nombre;
                });

                cout << "Canciones y álbumes:" << endl;
                imprimirCanciones(cancionesOrdenadas);
                break;
            }
            default:
                cout << "Opción no válida." << endl;
                break;
        }
         // Preguntar si el usuario quiere volver al menú principal
        cout << "¿Desea volver al menú principal? (1 para sí, 0 para no): ";
        cin >> repetir;
        if(repetir!=1 || repetir!=0){
            cout<<"Opcion erronea";
            return 0;
        }
    }

    return 0;
}

