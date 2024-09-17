#ifndef LISTASOLI_R_H
#define LISTASOLI_R_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class NodoLisaR{
private:
    string correoUsuario;
    string estado;
    NodoLisaR *siguiente;

public:

    NodoLisaR(string correoUsuario, string estado);
    NodoLisaR();

    string getCorreoUsuarioR();
    string getEstadoSolicitudR();
    NodoLisaR* getSiguiente() ;
    void setSiguiente(NodoLisaR* nodo);
};


class ListaSolicitudesRecibidas{

private:
    NodoLisaR *head;
    NodoLisaR *ultimo;
    NodoLisaR *headGraficar;
public:
    ListaSolicitudesRecibidas();
    ~ListaSolicitudesRecibidas();

    void agregar(string correoUsuario,string estado);
    void eliminar(string correoUsuario);
    bool existe(string correoUsuario);
    bool estaVacia();
    void verListaSolRecibidas();
    string getEstadosolicitud(string correo);
    void setGraficar(NodoLisaR* nodo);
    void graficar(string micorreo);


};


#endif // LISTASOLI_R_H
