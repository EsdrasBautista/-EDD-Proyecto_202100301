#ifndef SIMPLEPUBLICACION_H
#define SIMPLEPUBLICACION_H

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include "arbolB.h"

using namespace std;


class nodoSimplePub{
private:
    string fecha;
    string correo;
    string contenido;
    string hora;
    string imagen;
    int id;
    nodoSimplePub* siguiente;
    nodoSimplePub* anterior;
    ArbolB *ArbolComentarios;

public:
    nodoSimplePub(string fecha,string correo,string contenido,string hora,string imagen,int id);
    nodoSimplePub();
    ~nodoSimplePub();

    string getFechaL();
    string getCorreoL();
    string getContenidoL();
    string getHoraL();
    string getImagen();
    int getIdL();
    void setSiguiente(nodoSimplePub* sig);
    void setAnterior(nodoSimplePub* ant);
    nodoSimplePub* getSiguiente();
    nodoSimplePub* getAnterior();

    ArbolB* getArbolComentarios();

};


class listaNodoPub{
private:
    nodoSimplePub* cabeza;


public:
    listaNodoPub();
    ~listaNodoPub();

    void setCabeza(nodoSimplePub* nuevaCabeza) {
        this->cabeza = nuevaCabeza;
    }
    void agregarPublicacionL(string fecha,string correo,string contenido,string hora,string imagen,int id);
    void mostrarPublicacionesL();
    bool verificarExistencia(string correo,int id);
    nodoSimplePub* getCabeza();
    void eliminarPub(string correo);
    nodoSimplePub* buscarNodoporCorreoId(string correo,int id);
    void graph();

};






#endif // SIMPLEPUBLICACION_H
