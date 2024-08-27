#ifndef GESTIONAR_ADMIN_H
#define GESTIONAR_ADMIN_H
#include "listaEnlazada.h"


class gestionaradmin{

public:
    static void gradicaListaUsuarios(ListaEnlazada &usuario);
    static void graficaPublicacionesTodas(listaPublicaciones &publicaciones);
    static void top5conMasPublicaciones(listaPublicaciones &publicaciones);
    static void eliminarUsuario(ListaEnlazada &usuario, string correoUser, listaPublicaciones &publicaciones, matriz &matrizG);
    static void graficaMatrizDispersaTodos(matriz &matrizT);

    




};

#endif