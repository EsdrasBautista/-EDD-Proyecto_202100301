#ifndef LISTAENLAZADAARBOL_H
#define LISTAENLAZADAARBOL_H
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include "nodoMatriz.h"
#include "PilaSoli_R.h"
#include "listaSoli_E.h"
#include "listasoli_R.h"
#include "nodoPublicacion.h"
#include "listaAmistades.h"
#include "listaPublicaciones.h"
#include "SimplePublicacion.h"
#include "relacionAmistad.h"
#include "merkle.h"


using namespace std;



class nodoArbol{

private:
    string nombres;
    string apellidos;
    string correo;
    string contrasena;
    string fechaNacimiento;
    int altura;

    nodoArbol *derecha, *izquierda;
    PilaSolicitudesRecibidas* pilaSolicitudesRecibidas; // Pila de solicitudes recibidas
    ListaSolicitudesEnviadas* listadeSolicitudesEnviadasUsuario; //lista de solicitudes enviadas
    listaPublicaciones* listaPublicacionesU;
    listaAmistad* listaAmigos;
    ArbolBST* ArbolPublicacionesBST;
    listaNodoPub* listaTodasPubs;



    listaAdyacencia* listaAmistadGrafo;
    merkle* arbolMerkle;


public:
    nodoArbol(string n, string a, string c, string pwd, string fNac);
    nodoArbol();
    ~nodoArbol();
    int getAltura();
    void setAltura(int altura);
    string getNombres();
    string getApellidos();
    string getCorreo();
    string getContrasena();
    string getFechaNacimiento();

    void setNombres(string nombres);
    void setApellidos(string apellidos);
    void setCorreo(string correo);
    void setContrasena(string contrasena);
    void setFechaNacimiento(string fechaNacimiento);

    void setDerecha(nodoArbol *derecha);
    void setIzquierda(nodoArbol *izquierda);
    nodoArbol* getDerecha();
    nodoArbol* getIzquierda();
    PilaSolicitudesRecibidas* getPilaSolicitudesRecibidas(); // Getter para la pila de solicitudes
    ListaSolicitudesEnviadas* getListaDeSolicitudesEnviadas(); // Getter para la lista de solicitudes que el usuario ha enviado
    listaPublicaciones* getListapublicaionesU();
    listaAmistad* getListaAmigos();
    ArbolBST* getArbolPublicacionesBST();

    listaNodoPub* getListaTodasPubs();
    listaAdyacencia* getListaAmistadGrafo();
    merkle* getArbolMerkle();
};


class listaEnlazadaArb{

private:
    nodoArbol* raiz;
    nodoArbol* agregarUsuario(nodoArbol* raiz,string n, string a, string c, string pwd, string fNac);
    bool verificarCorreoArb(nodoArbol* raiz, string correo);

    int iniciodeSesionArb(nodoArbol* raiz,string contra,string correo);
    nodoArbol* buscarNodoPorCorreoArb(nodoArbol* raiz,string correo);
    string buscarNombreArb(nodoArbol* raiz,string correo);

    nodoArbol* rotacionIzquierda(nodoArbol *raiz);
    nodoArbol* rotacionDerecha(nodoArbol *raiz);
    int alturaMaxima(int izq, int drch);
    int obtenerAltura(nodoArbol *raiz);
    int obtenerBalance(nodoArbol *raiz);
    nodoArbol* eliminarUsuario(nodoArbol *raiz, string correo);

    void preOrden(nodoArbol *raiz);
    void postOrden(nodoArbol* raiz, bool estado);
    void inOrden(nodoArbol *raiz);
    void graph(nodoArbol *raiz, std::ofstream &f);




public:
    listaEnlazadaArb();
    ~listaEnlazadaArb();
    nodoArbol* obtenerMinimo(nodoArbol* raiz);
    void agregarUsuario (string n, string a, string c, string pwd, string fNac);
    void postOrden();
    void inOrden();
    void preOrden();
    void graph();
    nodoArbol* getRaiz();
    bool verificarCorreoArb(string correo);
    int iniciodeSesionArb(string contra,string correo);
    nodoArbol* buscarNodoPorCorreoArb(string correo);
    string buscarNombreArb(string correo);
    void actualizarArbol(string correo, bool decision); //para cunado se modificquen los datos, se tiene que actualizar el arbol
    nodoArbol *eliminarUsuario(string correo);

};







#endif // LISTAENLAZADAARBOL_H
