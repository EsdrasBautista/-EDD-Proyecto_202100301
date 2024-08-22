#include "GestionarSoli.h"
#include <unistd.h>


void gestionarSoli::enviarSolicitud(ListaEnlazada &usuarios, string correoEmisor,string correoReceptor){
    try{
        Nodo* receptor = usuarios.buscarNodoPorCorreo(correoReceptor);
        Nodo* emisor = usuarios.buscarNodoPorCorreo(correoEmisor);
        matriz* miamigo = emisor->getMimatrizAmigos();

        if(miamigo->verificarAmistad(correoEmisor,correoReceptor)){
            cout << "Ustedes ya son amigos, no puedes enviarle nuevamente solicitud!" << endl;
        }else{


            if(receptor == nullptr ){
                cout << "Este usuario: "<< correoReceptor << " no existe!" << endl;
                return;
            }
            if (correoEmisor == correoReceptor) {
                cout << "No puedes enviarte solicitudes de amistad a ti mismo!" << endl;
            }else{
                PilaSolicitudesRecibidas* pilaReceptor = receptor->getPilaSolicitudesRecibidas();
                ListaSolicitudesEnviadas* listaEmisor = emisor->getListaDeSolicitudesEnviadas();
                PilaSolicitudesRecibidas* pilaEmisor = emisor->getPilaSolicitudesRecibidas();

                if(pilaEmisor->existe(correoReceptor)){
                    cout << "No se pudo enviar la solicitud, ya existe una solicitud pendiente de parte de: " << correoReceptor <<endl;
                }else{
                    if(!pilaReceptor->existe(correoEmisor) && !listaEmisor->existe(correoReceptor)){
                        pilaReceptor->push(correoEmisor);
                        listaEmisor->agregar(correoReceptor,"PENDIENTE");
                        cout << "Solicitud enviada con exito a: " << correoReceptor << " de parte de: " << correoEmisor << endl;

                    }else{
                        cout << "No se pudo enviar la solicitud, ya existe una solicitud pendiente!" << endl;
                    }
                }
            }
        }
        
    }catch(runtime_error& e){
        std::cerr << "Se ha producido una excepción: " << e.what() << std::endl;
    }

    
    
}

void gestionarSoli::aceptarSolicitud(ListaEnlazada &usuarios,string correoEmisor,string correoReceptor){
    try{
        Nodo* receptor = usuarios.buscarNodoPorCorreo(correoReceptor); //yo
        Nodo* emisor = usuarios.buscarNodoPorCorreo(correoEmisor); //el que me envio la sol
        if(receptor == nullptr){
            cout << "Usuario no encontrado!" << endl;
            return;
        }
        
        PilaSolicitudesRecibidas* pilaReceptor = receptor->getPilaSolicitudesRecibidas();
        ListaSolicitudesEnviadas* listaEmisor = emisor->getListaDeSolicitudesEnviadas();
        listaAmistad* listaAmigosEmisor = emisor->getListaAmigos();
        listaAmistad* listaAmigosReceptor = receptor->getListaAmigos();

        if (!pilaReceptor->estaVacia()) {
            string correoEmisor = pilaReceptor->peek();
            pilaReceptor->pop();
            listaEmisor->eliminar(correoReceptor);
            cout << "Solicitud de " << correoEmisor << " Aceptada." << endl;

            listaAmigosEmisor->agregarAmigo(correoReceptor);
            listaAmigosReceptor->agregarAmigo(correoEmisor);

            
            //agregar la lógica para actualizar la matriz de amistad
            matriz* matrizDreceptor = receptor->getMimatrizAmigos();
            matriz* matrizDemisor = emisor->getMimatrizAmigos();

            matrizDreceptor->agregar(correoEmisor,correoReceptor,true);
            matrizDreceptor->agregar(correoReceptor,correoEmisor,true);

            matrizDemisor->agregar(correoEmisor,correoReceptor,true);
            matrizDemisor->agregar(correoReceptor,correoEmisor,true);
            cout << "Matriz de amistad actualizada con exito!" << endl; 
           
           
        }
    }catch(runtime_error& e){
        std::cerr << "Se ha producido una excepción: " << e.what() << std::endl;
    }

}


void gestionarSoli::aceptarSolicitudD(ListaEnlazada &usuarios, string correoEmisor,string correoReceptor){
    Nodo* receptor = usuarios.buscarNodoPorCorreo(correoReceptor); //yo
    Nodo* emisor = usuarios.buscarNodoPorCorreo(correoEmisor); //el que me envio la sol
    if(receptor == nullptr){
            cout << "Usuario no encontrado!" << endl;
            return;
    }
    listaAmistad* listaAmigosEmisor = emisor->getListaAmigos();
    listaAmistad* listaAmigosReceptor = receptor->getListaAmigos();

    cout << "Solicitud de " << correoEmisor << " Aceptada." << endl;

    listaAmigosEmisor->agregarAmigo(correoReceptor);
    listaAmigosReceptor->agregarAmigo(correoEmisor);

    // agregar la lógica para actualizar la matriz de amistad
    matriz *matrizDreceptor = receptor->getMimatrizAmigos();
    matriz *matrizDemisor = emisor->getMimatrizAmigos();

    matrizDreceptor->agregar(correoEmisor, correoReceptor, true);
    matrizDreceptor->agregar(correoReceptor, correoEmisor, true);

    matrizDemisor->agregar(correoEmisor, correoReceptor, true);
    matrizDemisor->agregar(correoReceptor, correoEmisor, true);
    cout << "Matriz de amistad actualizada con exito!" << endl;
}


void gestionarSoli::rechazarSolicitud(ListaEnlazada &usuarios,string correoEmisor,string correoReceptor){
    try{
        Nodo *receptor = usuarios.buscarNodoPorCorreo(correoReceptor);
        Nodo *emisor = usuarios.buscarNodoPorCorreo(correoEmisor);
        if (receptor == nullptr){
            cout << "Usuario no encontrado!" << endl;
            return;
        }

        PilaSolicitudesRecibidas *pilaReceptor = receptor->getPilaSolicitudesRecibidas();
        ListaSolicitudesEnviadas *listaEmisor = emisor->getListaDeSolicitudesEnviadas();

        if (!pilaReceptor->estaVacia()){
            string correoEmisor = pilaReceptor->peek();
            pilaReceptor->pop();
            listaEmisor->eliminar(correoReceptor);
            cout << "Solicitud de " << correoEmisor << " Rechazada." << endl;
        }
    }catch(runtime_error& e){
        std::cerr << "Se ha producido una excepción: " << e.what() << std::endl;
    }
    


}

void gestionarSoli::crearPublicacion(ListaEnlazada &usuarios, string correo, string contenido, string fecha, string hora,listaPublicaciones &listapubli){
    
    try{
        Nodo* correoYo = usuarios.buscarNodoPorCorreo(correo);
        listaPublicaciones* milista = correoYo->getlistaDepublicaciones();
    
        
        milista->agregarPub(correo,contenido,fecha,hora);
        listapubli.agregarPub(correo,contenido,fecha,hora);
        cout << "Creando Publicacion..." << endl;
        sleep(1);
        cout << "Publicacion creada con Exito!" << endl;
        
    }catch(runtime_error& e){
        std::cerr << "Se ha producido una excepción: " << e.what() << std::endl;
    }
    
}
void gestionarSoli::vermisPublicaciones(ListaEnlazada &usuarios,string correo){
    try{
        Nodo* micorreo = usuarios.buscarNodoPorCorreo(correo);
        listaPublicaciones* milista = micorreo->getlistaDepublicaciones();

        milista->verMisPublicaciones(correo);

    }catch(runtime_error& e){
        std::cerr << "Se ha producido una excepción: " << e.what() << std::endl;
    }
}



void gestionarSoli::verPublicacionesAmigos(ListaEnlazada &usuarios, string micorreo) {
    try {
        Nodo* nodoUsuario = usuarios.buscarNodoPorCorreo(micorreo);

        // Obtener lista de publicaciones del usuario
        listaPublicaciones* publicacionesUsuario = nodoUsuario->getlistaDepublicaciones();
        listaCircular* listac = nodoUsuario->getListaCircular();
        

        // Agregar publicaciones del usuario a la lista combinada
        NodoPub* pubActual = publicacionesUsuario->getPrimero();
        
        while (pubActual != nullptr) {
            if(!listac->verificarexiste(pubActual->getcontadorPublicaciones(),pubActual->getCorreo()) ){
                listac->agregarListaPublicaciones(pubActual->getCorreo(), pubActual->getcontenido(), pubActual->getfecha(), pubActual->gethora(),pubActual->getcontadorPublicaciones());
            }
            pubActual = pubActual->getSigPub();
        }

        // Obtener lista de amigos del usuario
        listaAmistad* listaAmigos = nodoUsuario->getListaAmigos();
        nodoAmistad* amigoActual = listaAmigos->getprimero();

        // Agregar publicaciones de cada amigo a la lista combinada
        while (amigoActual != nullptr) {
            Nodo* nodoAmigo = usuarios.buscarNodoPorCorreo(amigoActual->getCorreoA());

            if (nodoAmigo != nullptr) {
                listaPublicaciones* publicacionesAmigo = nodoAmigo->getlistaDepublicaciones();
                NodoPub* pubAmigoActual = publicacionesAmigo->getPrimero();
                
                while (pubAmigoActual != nullptr) {

                    if(!listac->verificarexiste(pubAmigoActual->getcontadorPublicaciones(),pubAmigoActual->getCorreo()) ){

                        listac->agregarListaPublicaciones(pubAmigoActual->getCorreo(), pubAmigoActual->getcontenido(), pubAmigoActual->getfecha(), pubAmigoActual->gethora(),pubAmigoActual->getcontadorPublicaciones());
                    }
                    pubAmigoActual = pubAmigoActual->getSigPub();
                }
            }
            amigoActual = amigoActual->getsiguiente();
        }

        listac->verListasPublicaciones();

    } catch (runtime_error& e) {
        std::cerr << "Se ha producido una excepción: " << e.what() << std::endl;
    }
}



void gestionarSoli::eliminarMiPublicacion(ListaEnlazada &usuario,string micorreo,listaPublicaciones &listapubli){
    Nodo* minodo = usuario.buscarNodoPorCorreo(micorreo);
    listaPublicaciones* milista = minodo->getlistaDepublicaciones();
    listaCircular* milistC = minodo->getListaCircular();
    int pos = milista->eliminarPublicacion(micorreo);
    if(pos >= 0){
        milistC->actualizarLista(pos,micorreo);
        listapubli.eliminarP(pos,micorreo);
    }
    
}

//-------------------------------GRAFICOS------------------------------------------------------------------------------------------------


void gestionarSoli::graficasSoliEnviadasyRecibidas(ListaEnlazada &usuarios, string micorreo){
    
    Nodo* miNodo = usuarios.buscarNodoPorCorreo(micorreo);
    ListaSolicitudesEnviadas* misEnvios = miNodo->getListaDeSolicitudesEnviadas();
    PilaSolicitudesRecibidas* misRecibidos = miNodo->getPilaSolicitudesRecibidas();
    misEnvios->graficar(micorreo);
    misRecibidos->graficar(micorreo);
    
}

void gestionarSoli::graficaListaAmigos(ListaEnlazada &usuario, string micorreo){
    Nodo* miNodo = usuario.buscarNodoPorCorreo(micorreo);

    listaAmistad* misamigos = miNodo->getListaAmigos();

    misamigos->graficar(micorreo);
}

void gestionarSoli::graficarMatrizAmigos(ListaEnlazada &usuario, string micorreo){
    Nodo* miNodo = usuario.buscarNodoPorCorreo(micorreo);
    matriz* mimatriz = miNodo->getMimatrizAmigos();
    mimatriz->graficarMatriz(micorreo);
}


void gestionarSoli::graficarListaCircularPublicaciones(ListaEnlazada &usuario, string micorreo){
    Nodo* minodo = usuario.buscarNodoPorCorreo(micorreo);
    listaCircular* milista = minodo->getListaCircular();

    milista->graficarCircular(micorreo);
}


//-------------------------ELIMINACION DE CUENTA -- ELIMINAR TODO --------------------------------------

void gestionarSoli::EliminarCuenta(ListaEnlazada &usuario,string micorreo){
    
    usuario.eliminarCuenta(micorreo); //eliminar de mi lista de usuarios
    
    cout << "Usuario: " << micorreo << " Eliminado con Exito!" << endl;

}



