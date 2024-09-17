#ifndef LISTAPUBLICACIONES_H
#define LISTAPUBLICACIONES_H

#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include "nodoMatriz.h"
#include "PilaSoli_R.h"
#include "listaSoli_E.h"
#include "listasoli_R.h"

using namespace std;



class nodoBST{

private:
    string nombres;
    string apellidos;
    string correo;
    string contrasena;
    string fechaNacimiento;
    nodoBST *derecha, *izquierda;
    PilaSolicitudesRecibidas* pilaSolicitudesRecibidas; // Pila de solicitudes recibidas
    ListaSolicitudesEnviadas* listadeSolicitudesEnviadasUsuario; //lista de solicitudes enviadas
    ListaSolicitudesRecibidas* listadeSolicitudesRecibidasUsuario;


    matriz* miMatrizAmigos; //matriz dispersa



public:
    nodoBST(string n, string a, string c, string pwd, string fNac);
    nodoBST();


    string getNombres();
    string getApellidos();
    string getCorreo();
    string getContrasena();
    string getFechaNacimiento();

    void setDerecha(nodoBST *derecha);
    void setIzquierda(nodoBST *izquierda);
    nodoBST* getDerecha();
    nodoBST* getIzquierda();
    PilaSolicitudesRecibidas* getPilaSolicitudesRecibidas(); // Getter para la pila de solicitudes
    ListaSolicitudesEnviadas* getListaDeSolicitudesEnviadas(); // Getter para la lista de solicitudes que el usuario ha enviado
    ListaSolicitudesRecibidas* getListaSolicitudesRecibidas();
    matriz* getMimatrizAmigos();
};


class listaEnlazadaBST{

private:
    nodoBST* raiz;
    nodoBST* agregarUsuario(nodoBST* raiz,string n, string a, string c, string pwd, string fNac);
    bool verificarCorreoArb(nodoBST* raiz, string correo);
    void postOrden(nodoBST* raiz, bool estado);
    int iniciodeSesionArb(nodoBST* raiz,string contra,string correo);
    nodoBST* buscarNodoPorCorreoArb(nodoBST* raiz,string correo);
    string buscarNombreArb(nodoBST* raiz,string correo);

public:
    listaEnlazadaBST();
    ~listaEnlazadaBST();

    void agregarUsuario(string n, string a, string c, string pwd, string fNac);
    void postOrden();
    //void inOrder();
    //void postOrden();
    //void graph();
    nodoBST* getRaiz();
    bool verificarCorreoArb(string correo);
    int iniciodeSesionArb(string contra,string correo);
    nodoBST* buscarNodoPorCorreoArb(string correo);
    string buscarNombreArb(string correo);

};





#endif // LISTAPUBLICACIONES_H
