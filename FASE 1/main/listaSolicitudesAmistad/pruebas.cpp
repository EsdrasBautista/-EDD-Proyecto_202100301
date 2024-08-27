/*#include <iostream>
#include "listaEnlazada.h"
#include "GestionarSoli.h"

int main() {
    ListaEnlazada usuarios;
    matriz matrizG;
    listaPublicaciones litap;

    usuarios.agregarUsuario("walter","walter","walter","12","kfdk");
    usuarios.agregarUsuario("arebalo","arebalo","arebalo","12","djssj");
    usuarios.agregarUsuario("qq","qq","qq","12","kfdk");
    

    gestionarSoli::enviarSolicitud(usuarios,"arebalo","walter");
    gestionarSoli::enviarSolicitud(usuarios,"qq","arebalo");

    gestionarSoli::aceptarSolicitud(usuarios,"arebalo","walter",matrizG);
    gestionarSoli::aceptarSolicitud(usuarios,"qq","arebalo",matrizG);

    gestionarSoli::graficarMatrizAmigos(usuarios,"walter");
    gestionarSoli::graficarMatrizAmigos(usuarios,"qq");
    gestionarSoli::graficarMatrizAmigos(usuarios,"arebalo");


    

    
    gestionarSoli::EliminarCuenta(usuarios,"arebalo");

    gestionarSoli::graficarMatrizAmigos(usuarios,"walter");
    gestionarSoli::graficarMatrizAmigos(usuarios,"qq");

    
    
    return 0;
}*/
/*
gestionarSoli::enviarSolicitud(usuarios,"qq","ee");
    gestionarSoli::aceptarSolicitud(usuarios,"qq","ee");
    gestionarSoli::graficarMatrizAmigos(usuarios,"ee");

gestionarSoli::crearPublicacion(usuarios,"ww","hola mundo","12/08", "12:59"); // 1 ww
    gestionarSoli::crearPublicacion(usuarios,"ee","adios mundo","11/08", "11:59"); // 1 ee
    gestionarSoli::crearPublicacion(usuarios,"ee","adiosX2 mundo","11/08", "11:59"); // 2 ee

    gestionarSoli::crearPublicacion(usuarios,"qq","que tal mundo","10/08", "10:59"); // 1 qq

    gestionarSoli::verPublicacionesAmigos(usuarios,"ee");

    gestionarSoli::crearPublicacion(usuarios,"qq","ESTA ES LA FINAAAAL","10/08", "10:59");

    gestionarSoli::verPublicacionesAmigos(usuarios,"ee");
    gestionarSoli::graficarListaCircularPublicaciones(usuarios,"ee");

*/