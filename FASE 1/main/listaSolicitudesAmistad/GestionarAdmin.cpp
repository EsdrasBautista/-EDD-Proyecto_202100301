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

void gestionaradmin::eliminarUsuario(ListaEnlazada &usuario,string micorreo,listaPublicaciones &publicaciones, matriz &matrizG){



    Nodo* minodo = usuario.buscarNodoPorCorreo(micorreo);
    if (minodo == nullptr) {
        cout << "Usuario no encontrado" << endl;
        return;
    }

    matriz* mimatriz = minodo->getMimatrizAmigos();

    listaCircular* milista;
    listaAmistad* milistaA;
    matriz* matrizA;
    ListaSolicitudesEnviadas* enviadas;
    PilaSolicitudesRecibidas* recibidas;
    listaPublicaciones* listapub;

    nodoMatriz* fila = mimatriz->buscarFila(micorreo);

    if (fila == nullptr) {
        cout << "No tienes amistades" << endl;
        usuario.eliminarCuenta(micorreo);
        cout << "Usuario: " << micorreo << " Eliminado con Exito!" << endl;
        return;
    }


    nodoMatriz* nodoactual = fila;
    while (nodoactual->getArriba() != nullptr) {
        nodoactual = nodoactual->getArriba();
    }

    // Recorrer hacia adelante (hacia abajo)
    while (nodoactual != nullptr) {
        nodoMatriz* nodoDerecho = nodoactual->getDcha();
        while (nodoDerecho != nullptr) {
            string correoAmigo = nodoDerecho->getCorreoEmisor();
            Nodo* nodoAmigo = usuario.buscarNodoPorCorreo(correoAmigo);

            if (nodoAmigo != nullptr && nodoAmigo->getCorreo() != micorreo) {
                milista = nodoAmigo->getListaCircular();
                milistaA = nodoAmigo->getListaAmigos();
                matrizA = nodoAmigo->getMimatrizAmigos();
                enviadas = nodoAmigo->getListaDeSolicitudesEnviadas();
                recibidas = nodoAmigo->getPilaSolicitudesRecibidas();
                listapub = nodoAmigo->getlistaDepublicaciones();

                milista->eliminarPublicacionA(micorreo);

                milistaA->eliminarAmigo(micorreo);

                matrizA->actualizarMatriz(micorreo);

                enviadas->eliminar(micorreo);

                recibidas->eliminarElemento(micorreo);

                listapub->eliminarP_porCorreo(micorreo);

            }

            nodoDerecho = nodoDerecho->getDcha();
        }
        nodoactual = nodoactual->getAbajo();
    }


    matrizG.actualizarMatriz(micorreo);
    publicaciones.eliminarP_porCorreo(micorreo);
    usuario.eliminarCuenta(micorreo);

}

void gestionaradmin::graficaMatrizDispersaTodos(matriz &matrizG){
    matrizG.graficar();
}