#include "./GestionarSoli.h"
#include <unistd.h>

#include <QMessageBox>



void gestionarSoli::enviarSolicitud(listaEnlazadaArb &usuarios, string correoEmisor,string correoReceptor,QWidget *ventSolicitudes){
    try{

        nodoArbol* receptor = usuarios.buscarNodoPorCorreoArb(correoReceptor);
        nodoArbol* emisor = usuarios.buscarNodoPorCorreoArb(correoEmisor);
        listaAmistad* miamigo = emisor->getListaAmigos();

        if(miamigo->verificarAmistad(correoReceptor)){
            QString msg = QString::fromStdString("El usuario " + correoReceptor + " ya es tu amigo.");
            QMessageBox::warning(ventSolicitudes, "Error al enviar solicitud", msg);
        }else{

            if(receptor == nullptr ){
                QString msg = QString::fromStdString("El usuario "+correoReceptor+" No existe!");
                QMessageBox::warning(ventSolicitudes, "Error al enviar solicitud", msg);
                return;
            }
            if (correoEmisor == correoReceptor) {
                QMessageBox::warning(ventSolicitudes, "Error al enviar solicitud", "No puedes enviarte solicitud a ti mismo!");
            }else{
                PilaSolicitudesRecibidas* pilaReceptor = receptor->getPilaSolicitudesRecibidas();
                ListaSolicitudesEnviadas* listaEmisor = emisor->getListaDeSolicitudesEnviadas();
                PilaSolicitudesRecibidas* pilaEmisor = emisor->getPilaSolicitudesRecibidas();

                if(pilaEmisor->existe(correoReceptor)){
                    QString msg = QString::fromStdString("No se pudo enviar la solicitud, ya existe una solicitud pendiente de parte de: "+correoReceptor);
                    QMessageBox::warning(ventSolicitudes, "Error al enviar solicitud", msg);
                }else{
                    if(!pilaReceptor->existe(correoEmisor) && !listaEmisor->existe(correoReceptor)){
                        pilaReceptor->push(correoEmisor);
                        listaEmisor->agregar(correoReceptor,"PENDIENTE");
                        QString msg = QString::fromStdString("Solicitud enviada de: "+ correoEmisor + " para: "+correoReceptor);
                        QMessageBox::information(ventSolicitudes, "Solicitud Enviada con Exito!", msg);

                    }else{
                        QMessageBox::warning(ventSolicitudes, "Error al enviar solicitud", "No se pudo enviar la solicitud, ya existe una solicitud pendiente");
                    }
                }
            }
        }

    }catch(runtime_error& e){
        std::cerr << "Se ha producido una excepción: " << e.what() << std::endl;
    }



}

void gestionarSoli::aceptarSolicitud(listaEnlazadaArb &usuarios,string correoEmisor,string correoReceptor,QWidget *ventSolicitudes){
    try{

        nodoArbol* receptor = usuarios.buscarNodoPorCorreoArb(correoReceptor); //yo
        nodoArbol* emisor = usuarios.buscarNodoPorCorreoArb(correoEmisor); //el que me envio la sol
        if(receptor == nullptr){
            QMessageBox::warning(ventSolicitudes, "Error", "Uusario no encontrado!!");
            return;
        }

        PilaSolicitudesRecibidas* pilaReceptor = receptor->getPilaSolicitudesRecibidas();
        ListaSolicitudesEnviadas* listaEmisor = emisor->getListaDeSolicitudesEnviadas();

        listaAmistad* listaAmigosEmisor = emisor->getListaAmigos();
        listaAmistad* listaAmigosReceptor = receptor->getListaAmigos();

        if (!pilaReceptor->estaVacia()) {
            pilaReceptor->eliminarElemento(correoEmisor);
            listaEmisor->eliminar(correoReceptor);
            QString msg = QString::fromStdString( "Solicitud de: " +correoEmisor+ " Aceptada!");
            QMessageBox::information(ventSolicitudes, "Estado Solicitud",msg);

            //pilaReceptor->verPila();

            listaAmigosEmisor->agregarAmigo(correoReceptor);
            listaAmigosReceptor->agregarAmigo(correoEmisor);



        }
    }catch(runtime_error& e){
        std::cerr << "Se ha producido una excepción: " << e.what() << std::endl;
    }

}


void gestionarSoli::aceptarSolicitudD(listaEnlazadaArb &usuarios, string correoEmisor,string correoReceptor,QWidget *ventAdmin){
    nodoArbol* receptor = usuarios.buscarNodoPorCorreoArb(correoReceptor); //yo
    nodoArbol* emisor = usuarios.buscarNodoPorCorreoArb(correoEmisor); //el que me envio la sol
    if(receptor == nullptr){
        QMessageBox::warning(ventAdmin, "Error", "Uusario no encontrado!!");
        return;
    }
    listaAmistad* listaAmigosEmisor = emisor->getListaAmigos();
    listaAmistad* listaAmigosReceptor = receptor->getListaAmigos();
    //QString msg = QString::fromStdString( "Solicitud de: " +correoEmisor+ " Aceptada!");

    //QMessageBox::information(ventAdmin, "Estado Solicitud",msg);

    listaAmigosEmisor->agregarAmigo(correoReceptor);
    listaAmigosReceptor->agregarAmigo(correoEmisor);

}


void gestionarSoli::rechazarSolicitud(listaEnlazadaArb &usuarios,string correoEmisor,string correoReceptor,QWidget *ventSolicitudes){
    try{
        nodoArbol *receptor = usuarios.buscarNodoPorCorreoArb(correoReceptor);
        nodoArbol *emisor = usuarios.buscarNodoPorCorreoArb(correoEmisor);
        if (receptor == nullptr){
            QMessageBox::warning(ventSolicitudes, "Error", "Uusario no encontrado!!");
            return;
        }

        PilaSolicitudesRecibidas *pilaReceptor = receptor->getPilaSolicitudesRecibidas();
        ListaSolicitudesEnviadas *listaEmisor = emisor->getListaDeSolicitudesEnviadas();

        if (!pilaReceptor->estaVacia()){
            pilaReceptor->eliminarElemento(correoEmisor);
            listaEmisor->eliminar(correoReceptor);
            QString msg = QString::fromStdString( "Solicitud de: " +correoEmisor+ " Rechazada!");
            QMessageBox::information(ventSolicitudes, "Estado Solicitud", msg);
        }
    }catch(runtime_error& e){
        std::cerr << "Se ha producido una excepción: " << e.what() << std::endl;
    }

}

void gestionarSoli::cancelarSolicitud(listaEnlazadaArb &usuarios, string micorreo, string elotrocorreo, QWidget *ventSolicitudes) {
    try{
        nodoArbol *minodo = usuarios.buscarNodoPorCorreoArb(micorreo);
        nodoArbol *otroNodo = usuarios.buscarNodoPorCorreoArb(elotrocorreo);

        if (otroNodo == nullptr) {
            QMessageBox::warning(ventSolicitudes, "Error", "Uusario no encontrado!!");
            return;
        }

        ListaSolicitudesEnviadas *milista = minodo->getListaDeSolicitudesEnviadas();
        PilaSolicitudesRecibidas *otroPila = otroNodo->getPilaSolicitudesRecibidas();

        if (!otroPila->estaVacia()) {

            std::cout << "Antes: " << std::endl;
            otroPila->verPila(); // ee
            milista->verListaSolEnviadas(); //jj kk

            std::cout << "111111111: " << std::endl;
            otroPila->eliminarElemento(micorreo);
            std::cout << "2222222222: " << std::endl;
            milista->eliminar(elotrocorreo);


            std::cout << "Despues: " << std::endl;
            otroPila->verPila();
            milista->verListaSolEnviadas();

            QString msg = QString::fromStdString("La solicitud que enviaste a: " + elotrocorreo + " ha sido Cancelada!");
            QMessageBox::information(ventSolicitudes, "Estado Solicitud", msg);

        }
    }catch(runtime_error& e){
        std::cerr << "Se ha producido una excepción: " << e.what() << std::endl;
    }
}


void gestionarSoli::EliminarCuenta(listaEnlazadaArb &usuario, string correo){
    nodoArbol *minodo = usuario.buscarNodoPorCorreoArb(correo);

    if (minodo == nullptr) {
        return;
    }

    listaAmistad *misAmigos = minodo->getListaAmigos();
    nodoAmistad *amigos = misAmigos ? misAmigos->getprimero() : nullptr;

    if(amigos != nullptr){
        while(amigos != nullptr){

            nodoArbol *nodoamigos = usuario.buscarNodoPorCorreoArb(amigos->getCorreoA());
            if(nodoamigos != nullptr){
                listaAmistad *amigosnodo = nodoamigos->getListaAmigos();
                if(amigosnodo != nullptr){
                    std::cout << "Eliminando a " << correo << " de la lista de amigos de " << nodoamigos->getCorreo() << std::endl;
                    amigosnodo->eliminarAmigo(correo);
                    std::cout << "Amigo eliminado." << std::endl;
                }
            }
            amigos = amigos->getsiguiente();

        }
    }

    usuario.eliminarUsuario(correo);

}

void gestionarSoli::verAmigos(listaEnlazadaArb &usuario, string correo){
    nodoArbol *minodo = usuario.buscarNodoPorCorreoArb(correo);
    if (minodo == nullptr) {
        return;
    }

    listaAmistad *misamigos = minodo->getListaAmigos();
    misamigos->verLista();



}
