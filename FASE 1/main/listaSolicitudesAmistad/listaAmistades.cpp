#include "listaAmistades.h"

nodoAmistad::nodoAmistad(){
    contador = 0;
    correo = "";
    sig = nullptr;
}


nodoAmistad::nodoAmistad(string correo){
    this->correo = correo;
    this->contador = 0;
    this->sig = nullptr;
}

string nodoAmistad::getCorreoA(){
    return this->correo;
}

int nodoAmistad::getContadorAmigos(){
    return this->contador;
}

void nodoAmistad::setSiguiente(nodoAmistad* sig){
    this->sig = sig;
}

nodoAmistad* nodoAmistad::getsiguiente(){
    return this->sig;
}

void nodoAmistad::setContador(int contador){
    this->contador += contador;
}
//-------------------------------------------------------------------

listaAmistad::listaAmistad(){
    head = nullptr;
    ultimo = nullptr;
}

listaAmistad::~listaAmistad() {
    nodoAmistad *temp = head;
    nodoAmistad *aux;

    while (temp != nullptr) {
        aux = temp->getsiguiente(); // Guarda el siguiente nodo
        delete temp; // Libera el nodo actual
        temp = aux; // Avanza al siguiente nodo
    }

    head = nullptr;
    ultimo = nullptr;
}


void listaAmistad::agregarAmigo(string correo){

    nodoAmistad *nuevoNodo = new nodoAmistad(correo);

    if(head == nullptr){
        head = nuevoNodo;

    }else{
        nodoAmistad *tempo = head;
        while(tempo->getsiguiente() != nullptr){
            tempo = tempo->getsiguiente();
        }
        tempo->setSiguiente(nuevoNodo);
        tempo->setContador(1);
        
    }
}

void listaAmistad::verLista(){
    nodoAmistad *nodoActual = head;

    while(nodoActual != nullptr){
        cout << nodoActual->getCorreoA() << endl;
        nodoActual = nodoActual->getsiguiente();
    }
}

void listaAmistad::eliminarAmigo(string correo){
    nodoAmistad* nodoActual = head;
    nodoAmistad* anterior = nullptr;

    while (nodoActual != nullptr && nodoActual->getCorreoA() != correo) {
        anterior = nodoActual;
        nodoActual = nodoActual->getsiguiente();
    }

    if(nodoActual != nullptr){
        if(anterior == nullptr){
            head = nodoActual->getsiguiente();
        }else{
            anterior->setSiguiente(nodoActual->getsiguiente());
        }

        delete nodoActual;
    }

}

void listaAmistad::graficar(string micorreo){

    if(head == nullptr){
        cout << "No tienes amigos aun!" << endl;
    }else{
        ofstream archivo("listaDeAmistades.dot");
        if(!archivo.is_open()){
            cout << "No se pudo crear el archivo" << endl;
        }

        archivo << "digraph G {" << endl;
        archivo << "    rankdir=LR;" << endl;
        archivo << "    node [shape=record];" << endl;

        nodoAmistad *nodoActual = head;
        while(nodoActual != nullptr){
            archivo << "    \"" << nodoActual->getCorreoA() << "\"";
            if (nodoActual->getsiguiente() != nullptr) {
                archivo << " -> \"" << nodoActual->getsiguiente()->getCorreoA() << "\"";
            }
            archivo << ";" << endl;
            nodoActual = nodoActual->getsiguiente();
        }
        archivo << "}" << endl;
        archivo.close();

        stringstream nombreArchivo;
        nombreArchivo << "listaAmistades_" << micorreo << ".png";

        // Construir el comando Graphviz
        stringstream comando;
        comando << "dot -Tpng listaDeAmistades.dot -o " << nombreArchivo.str();

        // Ejecutar el comando
        system(comando.str().c_str());

        cout << "La lista de amistades ha sido graficada y guardada en " << nombreArchivo.str() << endl;
    }
}

nodoAmistad* listaAmistad::buscarAmigoporCorreo(string correo){
    nodoAmistad* actual = head;
    while (actual != nullptr) {
        if (actual->getCorreoA() == correo) {
            return actual;
        }
        actual = actual->getsiguiente();
    }
    return nullptr; // Si no se encuentra, retornar nullptr
}

nodoAmistad* listaAmistad::getprimero(){
    nodoAmistad* actual = head;
    if(head == nullptr){
        return nullptr;
    }else{
        return actual;
    }
}

void listaAmistad::eliminarLista() {
    nodoAmistad* actual = head;

    while (actual != nullptr) {
        nodoAmistad* paraEliminar = actual; // Guardar el nodo actual para eliminarlo
        actual = actual->getsiguiente();    
        delete paraEliminar;              
    }

    head = nullptr; // Asegurarse de que la lista este vacia
}