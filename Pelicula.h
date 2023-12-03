// Humberto Barrera Martínez
// Isaac Saca Monroy
// 09/06/2023
// Clase derivada Pelicula.h (hija de Video.h)

#ifndef Pelicula_h
#define Pelicula_h

#include "Video.h"

class Pelicula : public Video {

public:
  // Constructores
  Pelicula(); // Default
  Pelicula(int ID, string nombre, string genero, int duracion,
           int calificacion); // Con parámetros

  // Método redefinido
  void imprimirInfo();
};

// Constructores
Pelicula::Pelicula() : Video() {}

Pelicula::Pelicula(int ID, string nombre, string genero, int duracion,
                   int calificacion)
    : Video(ID, nombre, genero, duracion, calificacion) {}

// Método redefinido
void Pelicula::imprimirInfo() {
  cout << endl;
  cout << "Pelicula" << endl;
  cout << "ID: " << ID << endl;
  cout << "Nombre: " << nombre << endl;
  cout << "Genero: " << genero << endl;
  cout << "Duracion: " << duracion << " minutos" << endl;
  cout << "Calificacion: " << calificacion << endl;
  cout << endl;
}

#endif