#ifndef PILA_SOLI_H
#define PILA_SOLI_H  

#include <cstdlib>
#include <string>
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

public:
    PilaSolicitudesRecibidas();
    ~PilaSolicitudesRecibidas();

    void push(string correoUsuario);
    void pop();
    string peek() ;
    bool estaVacia() ;

    void verPila();
    bool existe(string correoEmisor);
};

#endif // PILA_SOLI_H  
