#ifndef GESTIONARSOLI_H
#define GESTIONARSOLI_H
#include "listaEnlazadaArbol.h"

#include <QWidget>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QLabel>
#include <QPushButton>
#include <QTableWidget>
#include <QScrollArea>
#include <QFileDialog>
#include <QPixmap>

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

    static void agregarComentario(listaEnlazadaArb &usuarios, string correoU,string fechaU,int id,string fecha,string hora,string contenido,string correoComento,QWidget *ventana);

    static int agregarPubDesdeAdmin(listaEnlazadaArb &usuarios, string correo, string contenido, string fecha, string hora, QWidget *ventana);
    static void agregarComentarioAdmin(listaEnlazadaArb &usuarios, string correoU,string fechaU,int id,string fecha,string hora,string contenido,string correoComento,QWidget *ventana);


    static void verComentarios(listaEnlazadaArb &usuarios, string correoU, string fechaU, int id, QPlainTextEdit* txtarea);
    static void mostrarArbolB(listaEnlazadaArb &usuarios, string correoU, string fechaU, int id,QLabel* img,QWidget *ventana);

    static void agregarComentarioDesdeAdmin(listaEnlazadaArb &usuarios, string correoU, string fechaU,string contenido);
};


#endif // GESTIONARSOLI_H
