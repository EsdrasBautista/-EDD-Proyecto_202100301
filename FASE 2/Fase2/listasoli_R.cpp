#include "./listasoli_R.h"

// NodoLisaR
NodoLisaR::NodoLisaR() {
    correoUsuario = "";
    estado = "";
    siguiente = nullptr;
}

NodoLisaR::NodoLisaR(string correoUsuario, string estado) {
    this->correoUsuario = correoUsuario;
    this->estado = estado;
    siguiente = nullptr;
}

string NodoLisaR::getCorreoUsuarioR() {
    return correoUsuario;
}

string NodoLisaR::getEstadoSolicitudR() {
    return estado;
}

NodoLisaR* NodoLisaR::getSiguiente() {
    return siguiente;
}

void NodoLisaR::setSiguiente(NodoLisaR* sig) {
    siguiente = sig;
}

// ListaSolicitudesRecibidas
ListaSolicitudesRecibidas::ListaSolicitudesRecibidas() {
    head = nullptr;
    ultimo = nullptr;
    headGraficar = nullptr;
}

ListaSolicitudesRecibidas::~ListaSolicitudesRecibidas() {
    while (head != nullptr) {
        NodoLisaR* nodoAEliminar = head;
        head = head->getSiguiente();
        delete nodoAEliminar;
    }

    while (headGraficar != nullptr) {
        NodoLisaR* nodoAEliminar = headGraficar;
        headGraficar = headGraficar->getSiguiente();
        delete nodoAEliminar;
    }

    head = nullptr;
    headGraficar = nullptr;
}

void ListaSolicitudesRecibidas::agregar(string correoUsuario, string estado) {
    NodoLisaR* nuevoNodo = new NodoLisaR(correoUsuario, estado);

    if (head == nullptr) {
        head = nuevoNodo;
        ultimo = nuevoNodo;
    } else {
        NodoLisaR* tempo = head;
        while (tempo->getSiguiente() != nullptr) {
            tempo = tempo->getSiguiente();
        }
        tempo->setSiguiente(nuevoNodo);
    }

    setGraficar(nuevoNodo);
}

void ListaSolicitudesRecibidas::eliminar(string correoUsuario) {
    NodoLisaR* nodoActual = head;
    NodoLisaR* anterior = nullptr;

    while (nodoActual != nullptr && nodoActual->getCorreoUsuarioR() != correoUsuario) {
        anterior = nodoActual;
        nodoActual = nodoActual->getSiguiente();
    }

    if (nodoActual != nullptr) {
        if (anterior == nullptr) {
            head = nodoActual->getSiguiente();
        } else {
            anterior->setSiguiente(nodoActual->getSiguiente());
        }
        delete nodoActual;
    }
}

bool ListaSolicitudesRecibidas::existe(string correoUsuario) {
    NodoLisaR* nodoActual = head;

    while (nodoActual != nullptr) {
        if (nodoActual->getCorreoUsuarioR() == correoUsuario) {
            return true;
        }
        nodoActual = nodoActual->getSiguiente();
    }
    return false;
}

bool ListaSolicitudesRecibidas::estaVacia() {
    return head == nullptr;
}

void ListaSolicitudesRecibidas::verListaSolRecibidas() {
    NodoLisaR* actual = head;

    while (actual != nullptr) {
        cout << "Correo solicitudes recibidas: " << actual->getCorreoUsuarioR() << endl;
        actual = actual->getSiguiente();
    }
}

string ListaSolicitudesRecibidas::getEstadosolicitud(string correo) {
    NodoLisaR* actual = head;
    while (actual != nullptr) {
        if (actual->getCorreoUsuarioR() == correo) {
            return actual->getEstadoSolicitudR();
        }
        actual = actual->getSiguiente();
    }
    return ""; // Retornar vacío si no se encuentra
}

void ListaSolicitudesRecibidas::setGraficar(NodoLisaR* nuevoNodo) {
    NodoLisaR* nuevoNodoGraficar = new NodoLisaR(nuevoNodo->getCorreoUsuarioR(), nuevoNodo->getEstadoSolicitudR());

    if (headGraficar == nullptr) {
        headGraficar = nuevoNodoGraficar;
        nuevoNodoGraficar->setSiguiente(nullptr);
    } else {
        NodoLisaR* temp = headGraficar;
        while (temp->getSiguiente() != nullptr) {
            temp = temp->getSiguiente();
        }
        temp->setSiguiente(nuevoNodoGraficar);
        nuevoNodoGraficar->setSiguiente(nullptr);
    }
}

void ListaSolicitudesRecibidas::graficar(string micorreo) {
    if (headGraficar == nullptr) {
        cout << "No has recibido ninguna solicitud aun!" << endl;
    } else {
        ofstream archivo("SolicitudesR.dot");
        if (!archivo.is_open()) {
            cout << "No se pudo crear el archivo" << endl;
            return;
        }

        archivo << "digraph G {" << endl;
        archivo << "    rankdir=LR;" << endl;
        archivo << "    node [shape=record];" << endl;

        NodoLisaR* nodoActual = headGraficar;

        while (nodoActual != nullptr) {
            archivo << "    \"" << nodoActual->getCorreoUsuarioR() << "\"";
            if (nodoActual->getSiguiente() != nullptr) {
                archivo << " -> \"" << nodoActual->getSiguiente()->getCorreoUsuarioR() << "\"";
            }
            archivo << ";" << endl;
            nodoActual = nodoActual->getSiguiente();
        }
        archivo << "}" << endl;
        archivo.close();

        stringstream nombreArchivo;
        nombreArchivo << "SolicitudesR_" << micorreo << ".png";

        stringstream comando;
        comando << "dot -Tpng SolicitudesR.dot -o " << nombreArchivo.str();

        system(comando.str().c_str());

        cout << "Las solicitudes recibidas han sido graficadas y guardadas en " << nombreArchivo.str() << endl;
    }
}
