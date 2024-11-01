#ifndef RELACIONAMISTAD_H
#define RELACIONAMISTAD_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
class enodo;
//------------------------------------------------------------------------------

//grafo vertice (emisor)
class vnodo{
private:
    string correo;
    vnodo *siguiente;
    enodo *destinos; //el primero de la lista de destinos

public:
    vnodo();
    ~vnodo();

    void insertarDestino(string);
    void graficarAristas(std::ofstream&);
    void graficarListaDestinos(std::ofstream&);


    string getCorreoE();
    vnodo* getSiguiente();
    enodo* getDestinos();
    void setCorreoE(string);
    void setSiguiente(vnodo*);
    void setDestinos(enodo*);
};

//------------------------------------------------------------------------------
// grafo destino (Receptor)
class enodo{
private:
    string correoDestino;
    enodo *siguiente;

public:
    enodo();

    string getDestino();
    enodo* getSiguiente();
    void setDestino(string);
    void setSiguiente(enodo*);
};


//------------------------------------------------------------------------------
// Lista de Adyacencia (Creacion de conexiones)
class listaAdyacencia{
private:
    vnodo *cabeza;

public:
    listaAdyacencia();
    ~listaAdyacencia();

    void insert(string);
    bool verificarAmistadGrafo(string);
    void eliminarAmigoGrafo(string);
    void crearConexion(string, string);
    bool crearGrafo();
    bool crearGrafoLista();
    vnodo* getprimero();
};
//------------------------------------------------------------------------------


#endif // RELACIONAMISTAD_H
