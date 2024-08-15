#include "GestionarSoli.h"
#include <unistd.h>


void gestionarSoli::enviarSolicitud(ListaEnlazada &usuarios, string correoEmisor,string correoReceptor){
    try{
        Nodo* receptor = usuarios.buscarNodoPorCorreo(correoReceptor);
        Nodo* emisor = usuarios.buscarNodoPorCorreo(correoEmisor);
        if(receptor == nullptr ){
            cout << "Este usuario: "<< correoReceptor << " no existe!" << endl;
            return;
        }
        if (correoEmisor == correoReceptor) {
            cout << "No puedes enviarte solicitudes de amistad a ti mismo!" << endl;
        }else{
            PilaSolicitudesRecibidas* pilaReceptor = receptor->getPilaSolicitudesRecibidas();
            ListaSolicitudesEnviadas* listaEmisor = emisor->getListaDeSolicitudesEnviadas();
            if(!pilaReceptor->existe(correoEmisor) && !listaEmisor->existe(correoReceptor)){
                cout << "Solicitud enviada con exito a: " << correoReceptor << " de parte de: " << correoEmisor << endl;
                
                pilaReceptor->push(correoEmisor);
                listaEmisor->agregar(correoReceptor,"PENDIENTE");
                

            }else {
                cout << "No se pudo enviar la solicitud, ya existe una solicitud pendiente!" << endl;
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

        if (!pilaReceptor->estaVacia()) {
            string correoEmisor = pilaReceptor->peek();
            pilaReceptor->pop();
            listaEmisor->eliminar(correoReceptor);
            cout << "Solicitud de " << correoEmisor << " Aceptada." << endl;

            // Aquí puedes agregar la lógica para actualizar la matriz de amistad




        }
    }catch(runtime_error& e){
        std::cerr << "Se ha producido una excepción: " << e.what() << std::endl;
    }

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

void gestionarSoli::crearPublicacion(ListaEnlazada &usuarios, string correo, string contenido, string fecha, string hora){
    
    try{
        Nodo* correoYo = usuarios.buscarNodoPorCorreo(correo);
        listaPublicaciones *milista = correoYo->getlistaDepublicaciones();
    
        milista->agregarPub(correo,contenido,fecha,hora);
        cout << "Creando Publicacion..." << endl;
        sleep(2);
        cout << "Publicacion creada con Exito!" << endl;
    }catch(runtime_error& e){
        std::cerr << "Se ha producido una excepción: " << e.what() << std::endl;
    }
    
}