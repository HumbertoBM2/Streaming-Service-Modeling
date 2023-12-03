// Humberto Barrera Martínez
// Isaac Saca Monroy
// 09/06/2023
// Clase derivada Episodio.h (hija de Video.h)

#ifndef Episodio_h
#define Episodio_h

#include "Video.h"

class Episodio : public Video {

private:
  // Atributos privados
  string serie;
  string numEpisodio;
  string numTemporada;

public:
  // Constructores

  // Default
  Episodio();
  // Con parámetros
  Episodio(int ID, string nombre, string genero, int duracion, int calificacion,
           string serie, string numEpisodio, string numTemporada);

  // Setters
  void setSerie(string serie);
  void setNumEpisodio(string numEpisodio);
  void setNumTemporada(string numTemporada);

  // Getters
  string getSerie();
  string getNumEpisodio();
  string getNumTemporada();

  // Método redefinido
  void imprimirInfo();
};

// Constructores
Episodio::Episodio() : Video() {

  serie = "-";
  numEpisodio = "-";
  numTemporada = "-";
}

Episodio::Episodio(int ID, string nombre, string genero, int duracion,
                   int calificacion, string serie, string numEpisodio,
                   string numTemporada)
    : Video(ID, nombre, genero, duracion, calificacion) {

  this->serie = serie;
  this->numEpisodio = numEpisodio;
  this->numTemporada = numTemporada;
}

// Setters
void Episodio::setSerie(string serie) { this->serie = serie; }

void Episodio::setNumEpisodio(string numEpisodio) {

  this->numEpisodio = numEpisodio;
}

void Episodio::setNumTemporada(string numTemporada) {

  this->numTemporada = numTemporada;
}

// Getters
string Episodio::getSerie() { return serie; }

string Episodio::getNumEpisodio() { return numEpisodio; }

string Episodio::getNumTemporada() { return numTemporada; }

// Método redefinido
void Episodio::imprimirInfo() {

  cout << endl;
  cout << "Episodio" << endl;
  cout << "ID: " << ID << endl;
  cout << "Nombre: " << nombre << endl;
  cout << "Genero: " << genero << endl;
  cout << "Duracion: " << duracion << " minutos" << endl;
  cout << "Calificacion: " << calificacion << endl;
  cout << "Serie: " << serie << endl;
  cout << "Numero de episodio: " << numEpisodio << endl;
  cout << "Numero de temporada: " << numTemporada << endl;
  cout << endl;
}

#endif