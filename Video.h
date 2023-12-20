// Humberto Barrera Martínez
// Isaac Saca Monroy
// 09/06/2023
// Clase abstracta Video.h

#ifndef Video_h
#define Video_h

#include <bits/stdc++.h>
using namespace std;

class Video {

protected:
    // Atributos protegidos
    int ID;
    string nombre;
    string genero;
    int duracion;
    int calificacion;

public:
    // Constructores
    Video(); // Default
    Video(int ID, string nombre, string genero, int duracion,
        int calificacion); // Con parámetros

    // Setters
    void setID(int ID);
    void setNombre(string nombre);
    void setGenero(string genero);
    void setDuracion(int duracion);
    void setCalificacion(int calificacion);

    // Getters
    int getID();
    string getNombre();
    string getGenero();
    int getDuracion();
    int getCalificacion();

    // Métodos
    virtual void imprimirInfo() = 0; // Método virtual puro
};

// Constructores

Video::Video() {
    ID = 0;
    nombre = "-";
    genero = "-";
    duracion = 0;
    calificacion = 0;
}

Video::Video(int ID, string nombre, string genero, int duracion,
    int calificacion) {
    this->ID = ID;
    this->nombre = nombre;
    this->genero = genero;
    this->duracion = duracion;
    this->calificacion = calificacion;
}

// Setters

void Video::setID(int ID) { this->ID = ID; }

void Video::setNombre(string nombre) { this->nombre = nombre; }

void Video::setGenero(string genero) { this->genero = genero; }

void Video::setDuracion(int duracion) { this->duracion = duracion; }

void Video::setCalificacion(int calificacion) {

    this->calificacion = calificacion;
}

// Getters

int Video::getID() { return ID; }

string Video::getNombre() { return nombre; }

string Video::getGenero() { return genero; }

int Video::getDuracion() { return duracion; }

int Video::getCalificacion() { return calificacion; }

#endif