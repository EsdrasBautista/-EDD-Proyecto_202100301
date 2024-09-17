#ifndef GESTIONARSOLI_H
#define GESTIONARSOLI_H
#include "listaEnlazadaArbol.h"
#include <QWidget>

class gestionarSoli{
public:
    static void enviarSolicitud(listaEnlazadaArb &usuarios,string correoEmisor, string correoReceptor,QWidget *ventSolicitudes);
    static void aceptarSolicitud(listaEnlazadaArb &usuarios,string correoEmisor,string correoReceptor,QWidget *ventSolicitudes);
    static void rechazarSolicitud(listaEnlazadaArb &usuarios,string correoEmisor,string correoReceptor,QWidget *ventSolicitudes);
    static void aceptarSolicitudD(listaEnlazadaArb &usuario, string correoE, string correoR,QWidget *ventAdmin); // cuando es carga desde admin
    static void cancelarSolicitud(listaEnlazadaArb &usuario, string micorreo, string elotrocorreo,QWidget *ventSolicitudes);

    static void EliminarCuenta(listaEnlazadaArb &usuario, string correo);
    static void verAmigos(listaEnlazadaArb &usuario, string correo);


    static void verPublicacionesAmigos(listaEnlazadaArb &usuarios, string correo);

};


#endif // GESTIONARSOLI_H
