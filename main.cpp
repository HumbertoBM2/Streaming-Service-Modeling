// Humberto Barrera Martínez
// Isaac Saca Monroy
// 09/06/2023
// Programa main.cpp donde se programa el menú del servicio de streaming junto
// con sus respectivas funciones Se incluye el sistema de clase creadao para el
// proyecto

#include "Episodio.h"
#include "Pelicula.h"
#include "Serie.h"
#include <bits/stdc++.h>

using namespace std;

// Función para cargar los datos desde un archivo
void cargarDatos(vector<Video*>& videos, vector<Serie*>& series) {
    // Se leen los archivos con las series y los videos
    string seriesFile = "datosSeries.txt";
    string videosFile = "datosVideos.txt";
    ifstream archivoSeries(seriesFile);
    ifstream archivoVideos(videosFile);
    // Se válida que la lectura de los archivos haya sido correcta
    if (archivoSeries.is_open()) {
        string lineaLeida;
        int numeroSerie;
        string nombreSerie;
        // Se lee el archivo de series
        while (getline(archivoSeries, lineaLeida)) {
            stringstream ss(lineaLeida); // Se lee cada palabra del renglón
            ss >> numeroSerie >> nombreSerie;
            series.push_back(new Serie(
                numeroSerie, nombreSerie)); // se crea un nuevo objeto de tipo Serie y
            // se agrega a un vector de apuntadores
        }
        archivoSeries.close();
        cout << "Los datos de las series se cargaron correctamente" << endl;
    }
    else {
        cout << "No se pudo abrir el archivo de series" << endl;
    }

    // Se lee la lista de videos
    if (archivoVideos.is_open()) {
        string lineaLeida;
        char tipo;
        // Se lee el archivo de videos hasta encontrar un renglón vacío
        while (getline(archivoVideos, lineaLeida)) {
            stringstream ss(lineaLeida);
            ss >> tipo;
            int ID;
            int calificacion;
            int duracion;
            string nombre, genero;
            // Se revisa la primera letra de cada renglón
            // Si la primera letra es p, se agrega un nuevo objeto de tipo película al
            // vector de videos Si la primera letra es e, se agrag un nuevo objeto de
            // tipo episodio al vector de videos Adicionalmente, se agrega cada
            // episodio a la serie que le corresponde Se verifica si ya existe una
            // serie para acomodar el episodio y si no, se crea una nueva
            if (tipo == 'p') {
                ss >> ID >> nombre >> genero >> duracion >> calificacion;
                videos.push_back(
                    new Pelicula(ID, nombre, genero, duracion, calificacion));
            }
            else if (tipo == 'e') {
                string nombreSerie, EpisodioS, TemporadaS;
                int numEpisodio = 0, numTemporada = 0;
                ss >> ID >> nombre >> genero >> duracion >> calificacion >>
                    nombreSerie >> EpisodioS >> TemporadaS;
                numEpisodio = stoi(EpisodioS.substr(1, EpisodioS.length()));
                numTemporada = stoi(TemporadaS.substr(1, TemporadaS.length()));
                videos.push_back(new Episodio(ID, nombre, genero, duracion,
                    calificacion, nombreSerie, EpisodioS,
                    TemporadaS));
                for (int i = 0; i < series.size(); i++) {
                    if (series[i]->getTitulo() == nombreSerie) {
                        // Se verifica si el episodio ya existe en la serie por su ID
                        bool episodioExistente = false;
                        for (Episodio* episodio : series[i]->getEpisodios()) {
                            if (episodio->getID() == ID) {
                                episodioExistente = true;
                                break;
                            }
                        }
                        if (!episodioExistente) {
                            series[i]->agregarEpisodio((Episodio*)videos[videos.size() - 1]);
                        }
                        break;
                    }
                    else if (i == series.size() - 1) {
                        // Si la serie no existe se crea una nueva y se agrega el episodio
                        series.push_back(new Serie(nombreSerie));
                        series.back()->agregarEpisodio(
                            (Episodio*)videos[videos.size() - 1]);
                    }
                }
            }
        }

        archivoVideos.close();
        cout << "Los datos de los videos se cargaron correctamente" << endl;
    }
    else {
        cout << "No se pudo abrir el archivo de videos" << endl;
    }
}

// Función para mostrar la lista de películas
void mostrarPeliculas(vector<Video*>& listaVideos) {
    cout << "Lista de Peliculas:" << endl;
    for (Video* video : listaVideos) {
        Pelicula* pelicula = dynamic_cast<Pelicula*>(video);
        if (pelicula != nullptr) {
            pelicula->imprimirInfo();
        }
    }
}

// Función para mostrar la lista de series con sus episodios
void mostrarSeries(vector<Serie*>& series) {
    cout << "Lista de Series:" << endl;
    for (Serie* serie : series) {
        if (serie != nullptr) {
            serie->mostrarDatosSerie();
            serie->mostrarEpisodios();
        }
    }
}

// Función para mostrar los videos en general con una cierta calificación o de
// un cierto género
void mostrarVideosCalificacionGenero(vector<Video*>& listaVideos,
    int calificacion, string genero) {
    cout << "Lista de Videos con Calificacion " << calificacion << " y Genero "
        << genero << ":" << endl;
    for (Video* video : listaVideos) {
        if (video->getCalificacion() == calificacion &&
            video->getGenero() == genero) {
            video->imprimirInfo();
        }
    }
}

// Función para mostrar los episodios de una determinada serie con una
// calificación determinada
void mostrarEpisodiosSerie(vector<Serie*>& series, string titulo,
    int calificacion) {
    cout << "Episodios de la Serie " << titulo << " con Calificacion "
        << calificacion << ":" << endl;
    for (Serie* serie : series) {
        if (serie != nullptr && serie->getTitulo() == titulo) {
            serie->mostrarEpisodiosCalificacion(calificacion);
        }
    }
}

// Función para mostrar las películas con cierta calificación
void mostrarPeliculasCalificacion(vector<Video*>& listaVideos,
    int calificacion) {
    cout << "Peliculas con Calificacion " << calificacion << ":" << endl;
    for (Video* video : listaVideos) {
        Pelicula* pelicula = dynamic_cast<Pelicula*>(video);
        if (pelicula != nullptr && pelicula->getCalificacion() == calificacion) {
            pelicula->imprimirInfo();
        }
    }
}

// Función para calificar un video
void calificarVideo(vector<Video*>& listaVideos, string titulo, int valor) {
    for (Video* video : listaVideos) {
        if (video->getNombre() == titulo) {
            video->setCalificacion(valor);
            cout << "Se ha calificado el video \"" << titulo << "\" con valor "
                << valor << endl;
            return;
        }
    }
    cout << "No se encontro el video \"" << titulo << "\"" << endl;
}

// Main donde se despliega el menu interactivo con las opciones a ejecutar
int main() {

    // Vectores de apuntadores de tipo video y series
    vector<Video*> videos;
    vector<Serie*> series;

    cout << "Los archivos de trabajo disponibles son: " << endl;
    cout << "datosSeries.txt" << endl;
    cout << "datosVideos.txt" << endl;
    cout << endl;

    int opcion;

    // Estatuto do while que mantiene el menú ciclado hasta que se ingresa un 0
    do {
        cout << "----- Menu -----" << endl;
        cout << "1. Cargar archivos de datos" << endl;
        cout << "2. Mostrar la lista de peliculas" << endl;
        cout << "3. Mostrar la lista de series con sus episodios" << endl;
        cout << "4. Mostrar los videos en general con una cierta calificacion o de "
            "un cierto genero"
            << endl;
        cout << "5. Mostrar los episodios de una determinada serie con una "
            "calificacion determinada"
            << endl;
        cout << "6. Mostrar las peliculas con cierta calificacion" << endl;
        cout << "7. Calificar un video" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        // Switch case que manda llamar a la funcion correspondiente según la
        // elección del usuario
        switch (opcion) {
        case 1: {
            cargarDatos(videos, series);
            break;
        }
        case 2: {
            mostrarPeliculas(videos);
            break;
        }
        case 3: {

            mostrarSeries(series);
            break;
        }
        case 4: {

            int calificacion;
            string genero;
            cout << "Ingrese la calificacion: ";
            cin >> calificacion;
            cout << "Ingrese el genero: ";
            cin >> genero;
            mostrarVideosCalificacionGenero(videos, calificacion, genero);
            break;
        }
        case 5: {
            string serie;
            int calificacion;
            cout << "Ingrese el nombre de la serie: ";
            cin >> serie;
            cout << "Ingrese la calificacion: ";
            cin >> calificacion;
            mostrarEpisodiosSerie(series, serie, calificacion);
            break;
        }
        case 6: {
            int calificacion;
            cout << "Ingrese la calificacion: ";
            cin >> calificacion;
            mostrarPeliculasCalificacion(videos, calificacion);
            break;
        }
        case 7: {
            string titulo;
            int valor;
            cout << "Ingrese el titulo a calificar: ";
            cin >> titulo;
            cout << "Ingrese el valor otorgado: ";
            cin >> valor;
            calificarVideo(videos, titulo, valor);
            break;
        }
        case 0: {
            cout << "Saliendo..." << endl;
            break;
        }
        default: {
            cout << "Opcion invalida. Intente nuevamente." << endl;
            break;
        }
        }
        cout << endl;
    } while (opcion != 0);
    // Liberar la memoria de las variables dinámicas de tipo Video
    for (Video* video : videos) {
        delete video;
    }
    videos.clear();
    // Liberar la memoria de las variables dinámicas de tipo Serie
    for (Serie* serie : series) {
        delete serie;
    }
    series.clear();
    return 0;
}
