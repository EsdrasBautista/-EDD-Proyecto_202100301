#ifndef LISTA_ENLAZADA_H
#define LISTA_ENLAZADA_H

#include "PilaSoli_R.h"
#include "listaSoli_E.h"
#include "nodoPublicacion.h"
#include "listaAmistades.h"
#include "nodoMatriz.h"
#include "nodoPublicacionCircular.h"

class Nodo {
private:
    string nombres;
    string apellidos;
    string correo;
    string contrasena;
    string fechaNacimiento;
    Nodo *sig;
    PilaSolicitudesRecibidas* pilaSolicitudesRecibidas; // Pila de solicitudes recibidas
    ListaSolicitudesEnviadas* listadeSolicitudesEnviadasUsuario; //lista de solicitudes enviadas
    listaPublicaciones* listaDePublicaciones; //lista de mis publicaciones
    listaAmistad* listaDeAmigos;  // lista de amistades
    matriz* miMatrizAmigos; //matriz dispersa
    listaCircular* listaCircularAmigos;



public:
    Nodo(string n, string a, string c, string pwd, string fNac);
    Nodo();
    ~Nodo();

    string getNombres();

    string getApellidos();

    string getCorreo();

    string getContrasena();

    string getFechaNacimiento();

    Nodo* getSig();
    void setSig(Nodo* sig);
    PilaSolicitudesRecibidas* getPilaSolicitudesRecibidas(); // Getter para la pila de solicitudes
    ListaSolicitudesEnviadas* getListaDeSolicitudesEnviadas(); // Getter para la lista de solicitudes que el usuario ha enviado
    listaPublicaciones* getlistaDepublicaciones(); //doblemente enlazada
    listaAmistad* getListaAmigos();
    matriz* getMimatrizAmigos();
    listaCircular* getListaCircular();
    

};



class ListaEnlazada {
private:
    Nodo* head;

public:
    ListaEnlazada();
    ~ListaEnlazada();

    Nodo* buscarNodoPorCorreo(string correo);
    void eliminarCuenta(string correo);
    void verListadoUsuarios();
    void agregarUsuario(string nom,string ape,string corr,string contr,string fechaNac);
    bool verificarCorreo(string correo);
    int iniciodeSesion(string contra,string correo);
    string buscarNombre(string correo);
    bool verificarExistenciaUsuario(string correoUsuario); 
};

#endif // LISTA_ENLAZADA_H
