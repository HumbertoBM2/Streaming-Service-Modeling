// Humberto Barrera Martínez
// Isaac Saca Monroy
// 09/06/2023
// Clase Serie.h que tiene composición con Episodio.h

#ifndef Serie_h
#define Serie_h

#include "Episodio.h"

class Serie {

private:
  // Atributos privados
  int ID;
  string titulo;
  vector<Episodio *> episodios;

public:
  // Constructores

  // Default
  Serie();

  // Con parámetros
  Serie(string titulo);
  Serie(int ID, string titulo);
  Serie(int ID, string titulo, vector<Episodio *> episodios);

  // Setters
  void setID(int ID);
  void setTitulo(string titulo);
  void setEpisodios(vector<Episodio *> episodios);

  // Getters
  int getID();
  string getTitulo();
  vector<Episodio *> getEpisodios();

  // Métodos
  void mostrarEpisodios();
  void mostrarDatosSerie();
  void mostrarEpisodiosCalificacion(int calificacion);
  void agregarEpisodio(Episodio *episodio);
};

// Constructores
Serie::Serie() {

  ID = 0;
  titulo = "-";
  episodios = {};
}

Serie::Serie(string titulo) {

  ID = 0;
  this->titulo = titulo;
  episodios = {};
}

Serie::Serie(int ID, string titulo) {

  this->ID = ID;
  this->titulo = titulo;
  episodios = {};
}

Serie::Serie(int ID, string titulo, vector<Episodio *> episodios) {

  this->ID = ID;
  this->titulo = titulo;
  this->episodios = episodios;
}

// Setters

void Serie::setID(int ID) { this->ID = ID; }

void Serie::setTitulo(string titulo) { this->titulo = titulo; }

void Serie::setEpisodios(vector<Episodio *> episodios) {

  this->episodios = episodios;
}

// Getters

int Serie::getID() { return ID; }

string Serie::getTitulo() { return titulo; }

vector<Episodio *> Serie::getEpisodios() { return episodios; }

// Métodos

void Serie::mostrarEpisodios() {

  for (size_t i = 0; i < episodios.size(); i++) {

    episodios[i]->imprimirInfo();
  }
}

void Serie::mostrarDatosSerie() {

  cout << endl;
  cout << "Serie" << endl;
  cout << "ID: " << ID << endl;
  cout << "Titulo: " << titulo << endl;
  cout << "Episodios: " << endl;
}

void Serie::mostrarEpisodiosCalificacion(int calificacion) {

  for (size_t i = 0; i < episodios.size(); i++) {

    if (episodios[i]->getCalificacion() == calificacion) {

      episodios[i]->imprimirInfo();
    }
  }
}

void Serie::agregarEpisodio(Episodio *episodio) {

  episodios.push_back(episodio);
}

#endif