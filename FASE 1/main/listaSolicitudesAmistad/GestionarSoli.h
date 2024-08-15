#include "listaEnlazada.h"

class gestionarSoli{

public:    
    static void enviarSolicitud(ListaEnlazada &usuarios,string correoEmisor, string correoReceptor);
    static void aceptarSolicitud(ListaEnlazada &usuarios,string correoEmisor,string correoReceptor);
    static void rechazarSolicitud(ListaEnlazada &usuarios,string correoEmisor,string correoReceptor);
    static void crearPublicacion(ListaEnlazada &usuarios, string correo, string contenido, string fecha, string hora);


};