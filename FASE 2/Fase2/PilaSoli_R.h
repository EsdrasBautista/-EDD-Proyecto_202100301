#ifndef PILA_SOLI_H
#define PILA_SOLI_H

#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;



class NodoPila {
private:
    string correoUsuario;
    NodoPila* siguiente;

public:

    NodoPila(string correoUsuario);
    NodoPila();

    string getCorreoUsuario() ;
    NodoPila* getSiguiente() ;
    void setSiguiente(NodoPila* nodo);

};


class PilaSolicitudesRecibidas {
private:
    NodoPila *head;
    NodoPila *ultimo;
    NodoPila *headGraficar;

public:
    PilaSolicitudesRecibidas();
    ~PilaSolicitudesRecibidas();

    void push(string correoUsuario);
    void pop();
    string peek() ;
    bool estaVacia() ;

    void verPila();
    bool existe(string correoEmisor);

    void setGraficar(NodoPila* nodo);
    void graficar(string micorreo);
    void eliminarElemento(string correo);

    NodoPila* getHead();

};

#endif // PILA_SOLI_H
