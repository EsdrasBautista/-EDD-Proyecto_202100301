#include "./listasoli_e.h"


//NodoLisaE
NodoLisaE::NodoLisaE(){correoUsuario = ""; estado = "" ;siguiente = nullptr;}
NodoLisaE::NodoLisaE(string correoUsuario,string estado){this->correoUsuario = correoUsuario;this->estado = estado ;siguiente = nullptr;}
string NodoLisaE::getCorreoUsuarioE(){return correoUsuario;}
string NodoLisaE::getEstadoSolicitudE(){return estado;}
NodoLisaE* NodoLisaE::getSiguiente(){return siguiente;}
void NodoLisaE::setSiguiente(NodoLisaE* sig){siguiente = sig;}


//ListaSolicitudesEnviadas
ListaSolicitudesEnviadas::ListaSolicitudesEnviadas(){head = nullptr; ultimo = nullptr; headGraficar = nullptr;}
ListaSolicitudesEnviadas::~ListaSolicitudesEnviadas(){
    while (head != nullptr) {
        NodoLisaE* nodoAEliminar = head;
        head = head->getSiguiente();
        delete nodoAEliminar;
    }

    while (headGraficar != nullptr) {
        NodoLisaE* nodoAEliminar = headGraficar;
        headGraficar = headGraficar->getSiguiente();
        delete nodoAEliminar;
    }

    head = nullptr;
    headGraficar = nullptr;
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

    //setGraficar(nuevoNodo);
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

void ListaSolicitudesEnviadas::setGraficar(NodoLisaE* nuevonodo){
    NodoLisaE* nuevoNodoGraficar = new NodoLisaE(nuevonodo->getCorreoUsuarioE(), nuevonodo->getEstadoSolicitudE());

    if (headGraficar == nullptr) {
        headGraficar = nuevoNodoGraficar;
        nuevoNodoGraficar->setSiguiente(nullptr);
    } else {
        NodoLisaE* temp = headGraficar;
        while (temp->getSiguiente() != nullptr) {
            temp = temp->getSiguiente();
        }
        temp->setSiguiente(nuevoNodoGraficar);
        nuevoNodoGraficar->setSiguiente(nullptr);
    }
}


void ListaSolicitudesEnviadas::graficar(string micorreo){

    if(headGraficar == nullptr){
        cout << "No has enviado ni una solicitud aun!" << endl;
    }else{
        ofstream archivo("SolicitudesE.dot");
        if (!archivo.is_open()) {
            cout << "No se pudo crear el archivo" << endl;
            return;
        }

        archivo << "digraph G {" << endl;
        archivo << "    rankdir=LR;" << endl;
        archivo << "    node [shape=record];" << endl;

        NodoLisaE *nodoActual = headGraficar; // Empezamos con la lista de graficar

        while (nodoActual != nullptr) {
            archivo << "    \"" << nodoActual->getCorreoUsuarioE() << "\"";
            if (nodoActual->getSiguiente() != nullptr) {
                archivo << " -> \"" << nodoActual->getSiguiente()->getCorreoUsuarioE() << "\"";
            }
            archivo << ";" << endl;
            nodoActual = nodoActual->getSiguiente();
        }
        archivo << "}" << endl;
        archivo.close();


        stringstream nombreArchivo;
        nombreArchivo << "SolicitudesE_" << micorreo << ".png";


        stringstream comando;
        comando << "dot -Tpng SolicitudesE.dot -o " << nombreArchivo.str();


        system(comando.str().c_str());

        cout << "Las solicitudes enviadas han sido graficadas y guardadas en " << nombreArchivo.str() << endl;
    }
}

NodoLisaE* ListaSolicitudesEnviadas::getHead() {
    return head;
}
