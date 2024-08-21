#ifndef NODOPUBLICACIONCIRCULAR_H
#define NODOPUBLICACIONCIRCULAR_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include <conio.h> 
#include <fstream>
#include <sstream>
using namespace std;


class NodoCircular{
private:
    int id;
    string correo;
    string contenido;
    string fecha;
    string hora;
    NodoCircular *prev;
    NodoCircular *sig;

public:
    NodoCircular();
    NodoCircular(string correo,string contenido,string fecha,string hora,int id);

    void setSigPubl(NodoCircular *sig);
    void setPrevPub(NodoCircular *prev);

    string getCorreo();
    string getcontenido();
    string getfecha();
    string gethora();
    int getId();

    NodoCircular* getSigPub();
    NodoCircular* getPrevPub();

};

class listaCircular{
private:
    NodoCircular *primero;
    NodoCircular *ultimo;

public:
    listaCircular();
    ~listaCircular();

    void agregarListaPublicaciones(string correo,string contenido,string fecha,string hora,int contador);
    void verListasPublicaciones();
    void graficarCircular(string correo);
    NodoCircular* getprimero();
    bool verificarexiste(int contador, string correo);
    void actualizarLista(int contador,string correo);

};
#endif