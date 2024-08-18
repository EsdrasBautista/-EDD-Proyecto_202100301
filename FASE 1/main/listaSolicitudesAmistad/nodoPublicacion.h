#ifndef NODO_PUBLICACION_H
#define NODO_PUBLICACION_H

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class NodoPub{

private:
    string correo;
    string contenido;
    string fecha;
    string hora;
    int contador;
    NodoPub *prev;
    NodoPub *sig;
public:
    NodoPub();
    NodoPub(string correo,string contenido,string fecha,string hora);

    void setSigPubl(NodoPub *sig);
    void setPrevPub(NodoPub *prev);

    string getCorreo();
    string getcontenido();
    string getfecha();
    string gethora();
    int getcontadorPublicaciones();

    NodoPub* getSigPub();
    NodoPub* getPrevPub();

};


class listaPublicaciones{

private:
    NodoPub *primero;
    NodoPub *ultimo;

public:
    listaPublicaciones();
    ~listaPublicaciones();

    void verMisPublicaciones(string correo);
    void agregarPub(string correo,string contenido, string fecha,string hora);

    


};
#endif