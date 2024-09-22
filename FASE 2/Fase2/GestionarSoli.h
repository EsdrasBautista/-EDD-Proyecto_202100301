#ifndef GESTIONARSOLI_H
#define GESTIONARSOLI_H
#include "listaEnlazadaArbol.h"

#include <QWidget>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QLabel>
#include <QPushButton>
#include <QTableWidget>

class gestionarSoli{
public:
    static void enviarSolicitud(listaEnlazadaArb &usuarios,string correoEmisor, string correoReceptor,QWidget *ventSolicitudes);
    static void aceptarSolicitud(listaEnlazadaArb &usuarios,string correoEmisor,string correoReceptor,QWidget *ventSolicitudes);
    static void rechazarSolicitud(listaEnlazadaArb &usuarios,string correoEmisor,string correoReceptor,QWidget *ventSolicitudes);
    static void aceptarSolicitudD(listaEnlazadaArb &usuario, string correoE, string correoR,QWidget *ventAdmin); // cuando es carga desde admin
    static void cancelarSolicitud(listaEnlazadaArb &usuario, string micorreo, string elotrocorreo,QWidget *ventSolicitudes);

    static void EliminarCuenta(listaEnlazadaArb &usuario, string correo);
    static void verAmigos(listaEnlazadaArb &usuario, string correo);

    static void agregarPublicacionesAmigos(listaEnlazadaArb &usuarios, string correo);
    static void agregarPublicacionesArbol(listaEnlazadaArb &usuarios, string correo);
    static nodoSimplePub* mostrarPublicacionesArbol(listaEnlazadaArb &usuarios, string correo, QLineEdit* txtUsuario, QLineEdit* txtFecha, QPlainTextEdit* textoPub, QLabel* lblImagen,string fecha);
    static nodoSimplePub* OrdenarPublicacionespor(listaEnlazadaArb &usuarios, string correo, QLineEdit* txtUsuario, QLineEdit* txtFecha, QPlainTextEdit* textoPub, QLabel* lblImagen,int cantidad,string tipoOrden);

    static void agregarComentario(nodoSimplePub &publicaciones,string fecha,string hora,string contenido,string correoComento,QWidget *ventana);

    static void agregarPubDesdeAdmin(listaEnlazadaArb &usuarios,string correo,listaPublicaciones &listaPubs,string contenido,string fecha,string hora);

};


#endif // GESTIONARSOLI_H
