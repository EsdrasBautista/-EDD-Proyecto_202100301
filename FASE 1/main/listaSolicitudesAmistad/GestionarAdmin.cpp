#include "GestionarAdmin.h"


void gestionaradmin::gradicaListaUsuarios(ListaEnlazada &usuario){
    usuario.graficar();
}

void gestionaradmin::graficaPublicacionesTodas(listaPublicaciones &publicaciones){
    publicaciones.graficarListaP();
}

void gestionaradmin::top5conMasPublicaciones(listaPublicaciones &publicaciones){
    publicaciones.graficartop5();
}