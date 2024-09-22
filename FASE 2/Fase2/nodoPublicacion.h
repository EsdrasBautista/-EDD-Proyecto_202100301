#ifndef NODOPUBLICACION_H
#define NODOPUBLICACION_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include <conio.h>
#include <fstream>
#include <sstream>

using namespace std;

class NodoPub {

private:
    string correo;
    string contenido;
    string fecha;
    string hora;
    string imagen;  // Nuevo atributo para almacenar la ruta o nombre de la imagen
    int contador;
    NodoPub *prev;
    NodoPub *sig;

public:
    NodoPub();  // Constructor por defecto
    NodoPub(string correo, string contenido, string fecha, string hora, int contador);  // Constructor original
    NodoPub(string correo, string contenido, string fecha, string hora, int contador, string imagen);  // Nuevo constructor con imagen

    // Métodos setters
    void setSigPubl(NodoPub *sig);
    void setPrevPub(NodoPub *prev);
    void setContador(int contador);
    void setImagen(string imagen);

    // Métodos getters
    string getCorreo();
    string getcontenido();
    string getfecha();
    string gethora();
    int getcontadorPublicaciones();
    string getImagen();
    NodoPub* getSigPub();
    NodoPub* getPrevPub();
};

class listaPublicaciones {

private:
    NodoPub *primero;
    NodoPub *ultimo;
    int contPublica;

public:
    listaPublicaciones();
    ~listaPublicaciones();

    void verMisPublicaciones(string correo);
    void agregarPub(string correo, string contenido, string fecha, string hora);
    void agregarPubConImagen(string correo, string contenido, string fecha, string hora, string imagen);  // Sobrecarga para agregar publicación con imagen
    NodoPub* getPrimero();
    int getContPublica();
    int eliminarPublicacion(string correo);

    void eliminarTodaslasPublicaciones();
    void graficarListaP();
    void graficartop5();
    void eliminarP(int id, string correo);
    void eliminarP_porCorreo(string correo);
};


#endif // NODOPUBLICACION_H
