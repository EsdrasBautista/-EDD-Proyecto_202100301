#ifndef LISTAPUBLICACIONES_H
#define LISTAPUBLICACIONES_H

#include "SimplePublicacion.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <iomanip>
#include "nodoMatriz.h"
#include "PilaSoli_R.h"
#include "listaSoli_E.h"
#include "listasoli_R.h"

using namespace std;



class nodoBST{

private:
    string fecha;
    nodoBST *drcha, *izq;
    listaNodoPub *publicacionesBST;


public:
    nodoBST();
    nodoBST(string fecha);
    void setDrcha(nodoBST *der);
    void setgetIzq(nodoBST *izq);
    string getfecha();
    listaNodoPub* getPublicacionesBST();
    nodoBST* getDrcha();
    nodoBST* getIzq();
};


class ArbolBST{

private:
    nodoBST* raiz;
    nodoBST* agregarPublicacionBST(nodoBST* raiz,string correo,string contenido,string fecha,string hora,string imagen,int contador);
    bool verificarexisteFecha(nodoBST* raiz,int contador, string fecha,string correo);
    void eliminarPublicacionA(nodoBST* raiz,int contador, string fecha,string correo);
    nodoBST* buscarNodoporFecha(nodoBST* raiz,string fecha);

    void postOrden(nodoBST *raiz, bool accion);
    void preOrden(nodoBST *raiz);
    void inOrden(nodoBST *raiz);
    void graph(nodoBST *raiz, std::ofstream &f);

    std::tm convertirFecha(string fecha) {
        std::tm tm = {};
        std::istringstream ss(fecha);
        ss >> std::get_time(&tm, "%d/%m/%Y"); // Formato d/m/y
        if (ss.fail()) {
            throw std::runtime_error("Error al convertir la fecha");
        }
        return tm;
    }

    void Ordeninorden(nodoBST *raiz, nodoSimplePub* &cabeza, nodoSimplePub* &actual, int &contador, int cantidadMaxima);
    void OrdenPostorden(nodoBST *raiz, nodoSimplePub* &cabeza, nodoSimplePub* &actual, int &contador, int cantidadMaxima);
    void OrdenPreorden(nodoBST *raiz, nodoSimplePub* &cabeza, nodoSimplePub* &actual, int &contador, int cantidadMaxima);
public:
    ArbolBST();
    ~ArbolBST();
    void agregarPublicacionBST(string correo,string contenido,string fecha,string hora,string imagen,int contador);
    bool verificarexisteFecha(int contador, string fecha,string correo);
    void eliminarPublicacionA(int contador, string fecha,string correo);


    void preOrden();
    void inOrden();
    void postOrden();
    void graph();
    nodoBST* getRaiz();
    nodoBST* buscarNodoporFecha(string fecha);

    nodoSimplePub* Ordeninorden(int cantidadMax);
    nodoSimplePub* OrdenPostorden(int cantidadMax);
    nodoSimplePub* OrdenPreorden(int cantidadMax);

    bool compararFechas(const std::string& f1, const std::string& f2) {
        std::tm tm1 = convertirFecha(f1);
        std::tm tm2 = convertirFecha(f2);
        return std::difftime(std::mktime(&tm1), std::mktime(&tm2)) < 0;
    }

};





#endif // LISTAPUBLICACIONES_H
