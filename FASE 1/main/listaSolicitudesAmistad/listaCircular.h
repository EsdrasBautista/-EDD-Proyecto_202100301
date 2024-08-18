#include <iostream>
#include <fstream>
#include "nodoPublicacion.h"


class nodoCircular{
private:
    nodoCircular   *sig;
    listaPublicaciones* publicaciones;

public:
    nodoCircular();
    void setSig(nodoCircular* sig);
    nodoCircular* getsig();
    listaPublicaciones* getlistapublicacionesG();




};


class listaCircular{

};