#include "PilaSoli_R.h"
#include <iostream>

//NodoPila.h
NodoPila::NodoPila(){correoUsuario = ""; siguiente = nullptr;}
NodoPila::NodoPila(string correoUsuario){this->correoUsuario = correoUsuario; this->siguiente = nullptr;}
string NodoPila::getCorreoUsuario(){return correoUsuario;}
NodoPila* NodoPila::getSiguiente(){return siguiente;}
void NodoPila::setSiguiente(NodoPila* sig){siguiente = sig;}




//PilaSolicitudesRecibidas.h
PilaSolicitudesRecibidas::PilaSolicitudesRecibidas(){head = nullptr; headGraficar = nullptr; ultimo = nullptr;}

PilaSolicitudesRecibidas::~PilaSolicitudesRecibidas() {
    while (!estaVacia()) {
        pop();
    }
    
}

void PilaSolicitudesRecibidas::push(string correoUsuario){
    NodoPila* nuevo_nodo = new NodoPila(correoUsuario);
    if (head == nullptr) {
        head = nuevo_nodo;
        ultimo = nuevo_nodo;
    } else {
        nuevo_nodo->setSiguiente(head);
        head = nuevo_nodo;
    }

    
  setGraficar(nuevo_nodo);
}



void PilaSolicitudesRecibidas::pop(){
    if (head == nullptr) {
        return;
    }

    NodoPila *tempo = head;
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

void PilaSolicitudesRecibidas::setGraficar(NodoPila* nuevonodo){
    

    nuevonodo->setSiguiente(headGraficar);
    headGraficar = nuevonodo;
}

void PilaSolicitudesRecibidas::graficar(string micorreo){

    if(headGraficar == nullptr){
        cout << "No has recibido ni una solicitud aun!" << endl;
    }else{
        ofstream archivo("solicitudesR_.dot");
        if (!archivo.is_open()) {
            cout << "No se pudo crear el archivo" << endl;
            return;
        }

        archivo << "digraph G {" << endl;
        archivo << "    rankdir=LR;" << endl;
        archivo << "    node [shape=record];" << endl;

        NodoPila *nodoactual = headGraficar;

        while(nodoactual != nullptr){
            archivo << "    \"" << nodoactual->getCorreoUsuario() << "\"";
            if(nodoactual->getSiguiente() != nullptr){
                archivo << " -> \"" << nodoactual->getSiguiente()->getCorreoUsuario() << "\"";
            }
            archivo << ";" << endl;
            nodoactual = nodoactual->getSiguiente();
        }
        archivo << "}" << endl;
        archivo.close();


        stringstream nombreArchivo;
        nombreArchivo << "solicitudesR_" << micorreo << ".png";


        stringstream comando;
        comando << "dot -Tpng solicitudesR_.dot -o " << nombreArchivo.str();


        system(comando.str().c_str());

        cout << "La grafica de solicitudes recibidas se ha guardado como:  " << nombreArchivo.str() << endl;
    }

}

void PilaSolicitudesRecibidas::eliminarElemento(string correo){

    if(estaVacia()){
        return;
    }
    NodoPila* actual = head;
    NodoPila* anterior = nullptr;

    while(actual != nullptr && actual->getCorreoUsuario() != correo){
        anterior = actual;
        actual = actual->getSiguiente();
    }

    if(actual == nullptr) return;

    if(anterior == head){
        head = actual->getSiguiente();
    }else{
        anterior->setSiguiente(actual->getSiguiente());
    }

    if(actual == ultimo){
        ultimo = anterior;
    }

    delete actual;
}

