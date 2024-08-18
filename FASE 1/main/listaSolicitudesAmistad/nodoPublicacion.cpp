#include "nodoPublicacion.h"


NodoPub::NodoPub(){
    correo = "";
    contenido = "";
    fecha = "";
    hora = "";
    contador = 0;
    sig = nullptr;
    prev = nullptr;
}
NodoPub::NodoPub(string correo,string contenido,string fecha,string hora){
    this->correo = correo;
    this->contenido = contenido;
    this->fecha = fecha;
    this->hora = hora;
    contador ++;
    this->sig = nullptr;
    this->prev = nullptr;
}

void NodoPub::setSigPubl(NodoPub *sig){
    this->sig = sig;
}
void NodoPub::setPrevPub(NodoPub *prev){
    this->prev = prev;
}

NodoPub* NodoPub::getPrevPub(){
    return prev;
}

NodoPub* NodoPub::getSigPub(){
    return sig;
}

string NodoPub::getcontenido(){
    return contenido;
}

string NodoPub::getCorreo(){
    return correo;
}

string NodoPub::getfecha(){
    return fecha;
}

string NodoPub::gethora(){
    return hora;
}

int NodoPub::getcontadorPublicaciones(){
    return contador;
}

//-------------------------------------------

listaPublicaciones::listaPublicaciones(){
    primero = nullptr;
    ultimo = nullptr;
}

listaPublicaciones::~listaPublicaciones(){
    NodoPub *temp = primero;
    NodoPub *aux;

    while(temp != nullptr){
        aux = temp->getSigPub();
        delete temp;
        temp = aux;
    }
}

void listaPublicaciones::agregarPub(string correo,string contenido,string fecha,string hora){
    NodoPub *nuevoNodo = new NodoPub(correo,contenido,fecha,hora);
    if(primero == nullptr){
        primero = nuevoNodo;
        ultimo = nuevoNodo;
    }else{
        nuevoNodo->setPrevPub(ultimo);
        ultimo->setSigPubl(nuevoNodo);
        ultimo = nuevoNodo;
    }
}

void listaPublicaciones::verMisPublicaciones(string correo){
    NodoPub *temp = primero;

    while(temp != nullptr ){
        if(temp->getCorreo() == correo){
            cout << temp->getCorreo() << endl;
            cout << temp->getcontenido() << endl;
            cout << temp->getfecha() << endl;
            cout << temp->gethora() << endl;
        }
         temp = temp->getSigPub();
    }

    cout << endl;
}