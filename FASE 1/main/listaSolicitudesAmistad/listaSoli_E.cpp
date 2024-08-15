#include "listaSoli_E.h"


//NodoLisaE
NodoLisaE::NodoLisaE(){correoUsuario = ""; estado = "" ;siguiente = nullptr;}
NodoLisaE::NodoLisaE(string correoUsuario,string estado){this->correoUsuario = correoUsuario;this->estado = estado ;siguiente = nullptr;}
string NodoLisaE::getCorreoUsuarioE(){return correoUsuario;}
string NodoLisaE::getEstadoSolicitudE(){return estado;}
NodoLisaE* NodoLisaE::getSiguiente(){return siguiente;}
void NodoLisaE::setSiguiente(NodoLisaE* sig){siguiente = sig;}


//ListaSolicitudesEnviadas
ListaSolicitudesEnviadas::ListaSolicitudesEnviadas(){head = nullptr; ultimo = nullptr;}
ListaSolicitudesEnviadas::~ListaSolicitudesEnviadas(){
    while (head != nullptr) {
        NodoLisaE* nodoAEliminar = head;
        head = head->getSiguiente();
        delete nodoAEliminar;
    }
}

void ListaSolicitudesEnviadas::agregar(string correoUsuario,string estado){
    NodoLisaE *nuevoNodo = new NodoLisaE(correoUsuario,estado);

    if(head == nullptr){
        head = nuevoNodo;
        ultimo = nuevoNodo;
    }else{
        NodoLisaE *tempo = head;
        while(tempo->getSiguiente() != nullptr){
            tempo = tempo->getSiguiente();
        }
        tempo->setSiguiente(nuevoNodo);
    }

}

void ListaSolicitudesEnviadas::eliminar(string correoUsuario){
    NodoLisaE* nodoActual = head;
    NodoLisaE* anterior = nullptr;

    while (nodoActual != nullptr && nodoActual->getCorreoUsuarioE() != correoUsuario) {
        anterior = nodoActual;
        nodoActual = nodoActual->getSiguiente();
    }

    if(nodoActual != nullptr){
        if(anterior == nullptr){
            head = nodoActual->getSiguiente();
        }else{
            anterior->setSiguiente(nodoActual->getSiguiente());
        }

        delete nodoActual;
    }
}
bool ListaSolicitudesEnviadas::existe(string correoUsuario){
    NodoLisaE* nodoActual = head;

    while(nodoActual != nullptr){
        if(nodoActual->getCorreoUsuarioE() == correoUsuario){
            //Ya se envio una solicitud a ese usuario

            return true;
        }
        nodoActual = nodoActual->getSiguiente();
    }
    return false; //No se ha enviado solicitud a ese usuario
}

bool ListaSolicitudesEnviadas::estaVacia(){
    return head == nullptr;
}

void ListaSolicitudesEnviadas::verListaSolEnviadas(){
    NodoLisaE* actual = head;

    while(actual != nullptr){
        cout << "Correo sol enviadas: " << actual->getCorreoUsuarioE() << endl;
        actual = actual->getSiguiente();
    }

}

string ListaSolicitudesEnviadas::getEstadosolicitud(string correo){
    NodoLisaE* actual = head;
    while (actual != nullptr) {
        if (actual->getCorreoUsuarioE() == correo) {
            return actual->getEstadoSolicitudE();
        }
        actual = actual->getSiguiente();
    }
    return ""; // Si no se encuentra, retornar nullptr
    
}

