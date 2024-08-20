#include "listaEnlazada.h"

class gestionarSoli{

public:    
    static void enviarSolicitud(ListaEnlazada &usuarios,string correoEmisor, string correoReceptor);
    static void aceptarSolicitud(ListaEnlazada &usuarios,string correoEmisor,string correoReceptor);
    static void rechazarSolicitud(ListaEnlazada &usuarios,string correoEmisor,string correoReceptor);
    static void crearPublicacion(ListaEnlazada &usuarios, string correo, string contenido, string fecha, string hora);
    static void vermisPublicaciones(ListaEnlazada &usuarios, string correo);
    static void graficasSoliEnviadasyRecibidas(ListaEnlazada &usuarios, string micorreo); //graficos
    static void graficaListaAmigos(ListaEnlazada &usuario, string micorreo); //graficos
    static void graficarMatrizAmigos(ListaEnlazada &usuario, string micorreo); //graficos


};