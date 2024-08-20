#include "PilaSoli_R.h"
#include <iostream>

//NodoPila.h
NodoPila::NodoPila(){correoUsuario = ""; siguiente = nullptr;}
NodoPila::NodoPila(string correoUsuario){this->correoUsuario = correoUsuario; this->siguiente = nullptr;}
string NodoPila::getCorreoUsuario(){return correoUsuario;}
NodoPila* NodoPila::getSiguiente(){return siguiente;}
void NodoPila::setSiguiente(NodoPila* sig){siguiente = sig;}




//PilaSolicitudesRecibidas.h
PilaSolicitudesRecibidas::PilaSolicitudesRecibidas(){head = nullptr; headGraficar = nullptr;}

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


  setGraficar(nuevo_nodo);
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

void PilaSolicitudesRecibidas::setGraficar(NodoPila* nuevonodo){
    

    if (headGraficar == nullptr){
        headGraficar = nuevonodo;
    
    }else{
        nuevonodo->setSiguiente(headGraficar);
        headGraficar = nuevonodo;
    }
    nuevonodo->setSiguiente(nullptr);
}

void PilaSolicitudesRecibidas::graficar(string micorreo){
    ofstream archivo("PilaDesolicitudesRecibidas.dot");
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
    nombreArchivo << "solicitudesRecibidas_" << micorreo << ".png";


    stringstream comando;
    comando << "dot -Tpng PilaDesolicitudesRecibidas.dot -o " << nombreArchivo.str();


    system(comando.str().c_str());

    cout << "La grafica de solicitudes recibidas se ha guardado como:  " << nombreArchivo.str() << endl;


}