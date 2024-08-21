#ifndef LISTA_AMISTADES_H
#define LISTA_AMISTADES_H
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class nodoAmistad{

private:
    nodoAmistad *sig;
    string correo;
    int contador;


public:
    nodoAmistad(string correo);
    nodoAmistad();

    string getCorreoA();
    int getContadorAmigos();
    void setSiguiente(nodoAmistad* sig);
    void setContador(int contador);
    nodoAmistad* getsiguiente();
};


class listaAmistad{

private:
    nodoAmistad *head;
    nodoAmistad *ultimo;

    nodoAmistad* buscarAmigoporCorreo(string corre);

public:
    listaAmistad();
    ~listaAmistad();

    void agregarAmigo(string correo);
    void eliminarAmigo(string correo);
    void verLista();
    void graficar(string micorreo);
    nodoAmistad* getprimero();




};


#endif 