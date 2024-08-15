#ifndef LISTA_SOLI_E_H
#define LISTA_SOLI_E_H

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class NodoLisaE{
private:
    string correoUsuario;
    string estado;
    NodoLisaE *siguiente;

public:
    NodoLisaE(string correoUsuario, string estado);
    NodoLisaE();

    string getCorreoUsuarioE();
    string getEstadoSolicitudE();
    NodoLisaE* getSiguiente() ;
    void setSiguiente(NodoLisaE* nodo);
};


class ListaSolicitudesEnviadas{

private:
    NodoLisaE *head;
    NodoLisaE *ultimo;
public:
    ListaSolicitudesEnviadas();
    ~ListaSolicitudesEnviadas();

    void agregar(string correoUsuario,string estado);
    void eliminar(string correoUsuario);
    bool existe(string correoUsuario);
    bool estaVacia();
    void verListaSolEnviadas();
    string getEstadosolicitud(string correo);

};

#endif // LISTA_SOLI_E_H
