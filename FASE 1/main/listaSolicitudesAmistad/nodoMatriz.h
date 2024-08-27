#ifndef NODO_MATRIZ_H
#define NODO_MATRIZ_H

#include <iostream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class nodoMatriz{

private:
    string correoEmisor;
    string correoReceptor;
    bool data = false;
    nodoMatriz *arriba, *abajo;
    nodoMatriz *izq, *der;
public:
    nodoMatriz(string correoEmisor, string correoReceptor);
    nodoMatriz(string correoEmisor, string correoReceptor, bool data);

    void setCorreoEmisor(string correo);
    void setCorreoReceptor(string correo);
    void setData(bool data);
    void setArriba(nodoMatriz *arriba);
    void setAbajo(nodoMatriz *abajo);
    void setIzq(nodoMatriz *izq);
    void setDcha(nodoMatriz *dcha);

    string getCorreoEmisor();
    string getCorreoReceptor();
    bool getData();
    nodoMatriz *getArriba();
    nodoMatriz *getAbajo();
    nodoMatriz *getIzq();
    nodoMatriz *getDcha();
};

class matriz{

private:
    nodoMatriz *raiz;

    
    nodoMatriz* insertarEncabezadoF(string correoReceptor);
    nodoMatriz* insertarEncabezadoC(string correoEmisor);
    void insertarEnFila(nodoMatriz *nuevo, nodoMatriz *encabezadoC);
    void insertarEnCol(nodoMatriz *nuevo, nodoMatriz *encabezadoF);
    void imprimirEncabezadoCol();
    nodoMatriz* obtenerNodo(string correoEmisor, string correoReceptor);



public:
    matriz();
    ~matriz();
    nodoMatriz* buscarFila(string correoReceptor);
    nodoMatriz* buscarCol(string correoEmisor);

    void agregar(string correoEmisor, string correoReceptor, bool data);
    bool existeNodo(nodoMatriz *nuevo);
    void verMatriz();
    bool verificarAmistad(string nombreU1, string nombreU2); 
    void graficarMatriz(string micorreo);

    void graficar();
    void actualizarMatriz(string correoAmigo);
    void eliminarNodo(nodoMatriz* nodo);


};

#endif