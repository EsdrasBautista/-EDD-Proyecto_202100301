#ifndef GESTIONAR_ADMIN_H
#define GESTIONAR_ADMIN_H
#include "listaEnlazada.h"


class gestionaradmin{

public:
    static void gradicaListaUsuarios(ListaEnlazada &usuario);
    static void graficaPublicacionesTodas(listaPublicaciones &publicaciones);
    static void top5conMasPublicaciones(listaPublicaciones &publicaciones);
    static void graficaMatrizDispersaTodos(matriz &matrizT);

    
    static void eliminarUsuario(ListaEnlazada &usuario, string correoUser);
    static void top5conMenosAmigos(ListaEnlazada &usuario);



};

#endif