#ifndef GESTIONAR_SOLI_H
#define GESTIONAR_SOLI_H
#include "listaEnlazada.h"

class gestionarSoli{

public:    
    static void enviarSolicitud(ListaEnlazada &usuarios,string correoEmisor, string correoReceptor);
    static void aceptarSolicitud(ListaEnlazada &usuarios,string correoEmisor,string correoReceptor, matriz &matrizG);
    static void rechazarSolicitud(ListaEnlazada &usuarios,string correoEmisor,string correoReceptor);
    static void crearPublicacion(ListaEnlazada &usuarios, string correo, string contenido, string fecha, string hora,listaPublicaciones &listapubli);

    static void vermisPublicaciones(ListaEnlazada &usuarios, string correo);
    static void verPublicacionesAmigos(ListaEnlazada &usuarios, string correo);
    static void graficasSoliEnviadasyRecibidas(ListaEnlazada &usuarios, string micorreo); //graficos
    static void graficaListaAmigos(ListaEnlazada &usuario, string micorreo); //graficos
    static void graficarMatrizAmigos(ListaEnlazada &usuario, string micorreo); //graficos
    static void graficarListaCircularPublicaciones(ListaEnlazada &usuario, string micorreo); //graficar lista circular publicaiones
    static void eliminarMiPublicacion(ListaEnlazada &usuario, string correo,listaPublicaciones &listapubli); 
    static void EliminarCuenta(ListaEnlazada &usuario, string correo);
    static void aceptarSolicitudD(ListaEnlazada &usuario, string correoE, string correoR, matriz &matrizG);



};
#endif