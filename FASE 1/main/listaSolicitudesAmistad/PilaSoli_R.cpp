#include "PilaSoli_R.h"
#include <iostream>

//NodoPila.h
NodoPila::NodoPila(){correoUsuario = ""; siguiente = nullptr;}
NodoPila::NodoPila(string correoUsuario){this->correoUsuario = correoUsuario; this->siguiente = nullptr;}
string NodoPila::getCorreoUsuario(){return correoUsuario;}
NodoPila* NodoPila::getSiguiente(){return siguiente;}
void NodoPila::setSiguiente(NodoPila* sig){siguiente = sig;}




//PilaSolicitudesRecibidas.h
PilaSolicitudesRecibidas::PilaSolicitudesRecibidas(){head = nullptr;}

PilaSolicitudesRecibidas::~PilaSolicitudesRecibidas() {
    while (!estaVacia()) {
        pop();
    }
}

void PilaSolicitudesRecibidas::push(string correoUsuario){
    NodoPila* nuevo_nodo = new NodoPila(correoUsuario);
    if (head == nullptr){
        head = nuevo_nodo;
    
    }else{
        nuevo_nodo->setSiguiente(head);
        head = nuevo_nodo;
    }
  
}



void PilaSolicitudesRecibidas::pop(){
    NodoPila *tempo;
    int ret;
    if(head == nullptr){return;}

    tempo = head;
    head = head->getSiguiente();

    delete tempo;
}


string PilaSolicitudesRecibidas::peek(){
    if(!estaVacia()){
        return head->getCorreoUsuario();
    }
    return "";
}

bool PilaSolicitudesRecibidas::estaVacia(){
    return head == nullptr;
}

void PilaSolicitudesRecibidas::verPila(){
    NodoPila *nodoactual = head;

    while(nodoactual != nullptr){
        cout << "correo: " << nodoactual->getCorreoUsuario() << endl;
        nodoactual = nodoactual->getSiguiente();
    }

    cout << endl;

}

bool PilaSolicitudesRecibidas::existe(string correoEmisor){
    NodoPila* nodoActual = head;

    while(nodoActual != nullptr){
        if(nodoActual->getCorreoUsuario() == correoEmisor){
            //Ya se envio una solicitud a ese usuario
            return true;
        }
        nodoActual = nodoActual->getSiguiente();
    }

    return false; //No se ha enviado solicitud a ese usuario
}