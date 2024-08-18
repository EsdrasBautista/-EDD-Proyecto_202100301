
#include "ListaEnlazada.h"

Nodo::Nodo(){
    nombres = "";
    apellidos = "";
    correo = "";
    contrasena = "";
    fechaNacimiento = "";
    sig = nullptr;
    

}

Nodo::Nodo(string nom,string ape,string corr,string contr,string fechaNac){
    this->nombres = nom;
    this->apellidos = ape;
    this->correo = corr;
    this->contrasena = contr;
    this->fechaNacimiento = fechaNac;
    this->sig = nullptr;
    this->pilaSolicitudesRecibidas = new PilaSolicitudesRecibidas(); // Inicializar la pila
    this->listadeSolicitudesEnviadasUsuario = new ListaSolicitudesEnviadas(); //Inicializar la lista
    this->listaDePublicaciones = new listaPublicaciones();
    this->listaDeAmigos = new listaAmistad();
    this->miMatrizAmigos = new matriz();
}

Nodo::~Nodo(){
    delete this->pilaSolicitudesRecibidas;
    delete this->listadeSolicitudesEnviadasUsuario;
    delete this->listaDePublicaciones;
    delete this->listaDeAmigos;
    delete this->miMatrizAmigos;
}

//getters y setters
string Nodo::getNombres(){
    return nombres;
}
string Nodo::getApellidos(){
    return apellidos;
}
string Nodo::getContrasena(){
    return contrasena;
}
string Nodo::getCorreo(){
    return correo;
}
string Nodo::getFechaNacimiento(){
    return fechaNacimiento;
}

Nodo* Nodo::getSig(){
    return sig;
}

void Nodo::setSig(Nodo *sig){
    this->sig = sig;
}

PilaSolicitudesRecibidas* Nodo::getPilaSolicitudesRecibidas() {
    return this->pilaSolicitudesRecibidas;
}
ListaSolicitudesEnviadas* Nodo::getListaDeSolicitudesEnviadas(){
    return this->listadeSolicitudesEnviadasUsuario;
}

listaPublicaciones* Nodo::getlistaDepublicaciones(){
    return this->listaDePublicaciones;
}

listaAmistad* Nodo::getListaAmigos(){
    return this->listaDeAmigos;
}


matriz* Nodo::getMimatrizAmigos(){
    return this->miMatrizAmigos;
}








ListaEnlazada::ListaEnlazada(){
    head = nullptr;
}

ListaEnlazada::~ListaEnlazada() {
    Nodo *temp = head;
    Nodo *aux;

    while(temp != nullptr){
        aux = temp->getSig();
        delete temp;
        temp = aux;
    }
    
}

void ListaEnlazada::agregarUsuario(string nom,string ape,string corr,string contr,string fechaNac) {
    Nodo *nuevoNodo = new Nodo(nom,ape,corr,contr,fechaNac);
    
    if(head == nullptr){
        head = nuevoNodo;
    }else{
        Nodo *tempo = head;
        while(tempo->getSig() != nullptr){
            tempo = tempo->getSig();
        }
        tempo->setSig(nuevoNodo);
    }

    
}

void ListaEnlazada::verListadoUsuarios(){
    Nodo* actual = head;

    while(actual != nullptr){
        cout << "Nombres: " << actual->getNombres() << endl;
        cout << "Apellidos: " << actual->getApellidos() << endl;
        cout << "Correo: " << actual->getCorreo() << endl;
        cout << "Fecha Nacimiento: " << actual->getFechaNacimiento() << endl;
        cout << endl;
        actual = actual->getSig();
    }
}

bool ListaEnlazada::verificarCorreo(string correo) {
    Nodo* actual = head;

    while(actual != nullptr){
        if(actual->getCorreo() == correo){
            return false;
        }
        actual = actual->getSig();
    }
    return true;
    
}

int ListaEnlazada::iniciodeSesion(string contra,string correo){
    Nodo  *actual = head;
    
    if(contra == "EDD2S2024" && correo == "admin@gmail.com"){
        cout << "Inicio de Sesion Exitosa! "<<  endl;
        cout << "Bienvenido: "<< "Admin" << endl;
        return 1;
    }

    while(actual != nullptr){
        if(actual->getCorreo() == correo && actual->getContrasena() == contra){
            cout << "Inicio de Sesion Exitosa! "<<  endl;
            cout << "Bienvenido: "<< actual->getNombres() << " " << actual->getApellidos() << endl;
            return 2;
        }
        actual = actual->getSig();
    }
    return 0;
}

string ListaEnlazada::buscarNombre(string correo){
    Nodo* actual = head;

    while(actual != nullptr){
        if(actual->getCorreo() == correo){
            return actual->getNombres();
        }
        actual = actual->getSig();
    }
    return "";
}

bool ListaEnlazada::verificarExistenciaUsuario(string correoUsuario){
    Nodo* actual = head;

    while(actual != nullptr){
        if(actual->getCorreo() == correoUsuario){
            return true;
        }
        
        
        actual = actual->getSig();
    }
    return false;
}
Nodo* ListaEnlazada::buscarNodoPorCorreo(string correo) {
    Nodo* actual = head;
    while (actual != nullptr) {
        if (actual->getCorreo() == correo) {
            return actual;
        }
        actual = actual->getSig();
    }
    return nullptr; // Si no se encuentra, retornar nullptr
}

void ListaEnlazada::eliminarCuenta(string correo){

    Nodo *nodoActual = head;
    Nodo *anterior = nullptr;

    while (nodoActual != nullptr && nodoActual->getCorreo() != correo){
        anterior = nodoActual;
        nodoActual = nodoActual->getSig();
    }

    if (nodoActual != nullptr && nodoActual->getCorreo() == correo){
        if (anterior == nullptr){
            head = nodoActual->getSig();
        }
        else{
            anterior->setSig(nodoActual->getSig());
        }

        delete nodoActual;
    }else{
        cout << "No se encontró ninguna cuenta con el correo proporcionado." << endl;
    }
}