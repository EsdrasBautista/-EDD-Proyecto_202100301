#include "nodoMatriz.h"

nodoMatriz::nodoMatriz(string correoEmisor, string correoReceptor) {
    this->correoEmisor = correoEmisor;
    this->correoReceptor = correoReceptor;
    this->data = false;
    this->arriba = nullptr;
    this->abajo = nullptr;
    this->izq = nullptr;
    this->der = nullptr;
}

nodoMatriz::nodoMatriz(string correoEmisor, string correoReceptor, bool data) {
    this->correoEmisor = correoEmisor;
    this->correoReceptor = correoReceptor;
    this->data = data;
    this->arriba = nullptr;
    this->abajo = nullptr;
    this->izq = nullptr;
    this->der = nullptr;
}

void nodoMatriz::setCorreoEmisor(string correo) {
    this->correoEmisor = correo;
}

void nodoMatriz::setCorreoReceptor(string correo) {
    this->correoReceptor = correo;
}

void nodoMatriz::setData(bool data) {
    this->data = data;
}

string nodoMatriz::getCorreoEmisor() {
    return correoEmisor;
}

string nodoMatriz::getCorreoReceptor() {
    return correoReceptor;
}

bool nodoMatriz::getData() {
    return data;
}

nodoMatriz *nodoMatriz::getArriba() {
    return arriba;
}

nodoMatriz *nodoMatriz::getAbajo() {
    return abajo;
}

nodoMatriz *nodoMatriz::getIzq() {
    return izq;
}

nodoMatriz *nodoMatriz::getDcha() {
    return der;
}

void nodoMatriz::setArriba(nodoMatriz *arriba) {
    this->arriba = arriba;
}

void nodoMatriz::setAbajo(nodoMatriz *abajo) {
    this->abajo = abajo;
}

void nodoMatriz::setIzq(nodoMatriz *izq) {
    this->izq = izq;
}

void nodoMatriz::setDcha(nodoMatriz *dcha) {
    this->der = dcha;
}

//-----------------------------------------------------------------------------------
matriz::matriz() {
    this->raiz = new nodoMatriz("", "");
}

matriz::~matriz() {
    nodoMatriz *temp = this->raiz;
    nodoMatriz *aux;

    while(temp != nullptr) {
        nodoMatriz *tempFila = temp;
        nodoMatriz *auxFila;

        aux = temp->getAbajo();

        while(tempFila != nullptr) {
            auxFila = tempFila->getDcha();
            delete tempFila;
            tempFila = auxFila;
        }

        temp = aux;
    }
}

nodoMatriz* matriz::buscarCol(string correoEmisor) {
    nodoMatriz *temp = this->raiz;

    while(temp != nullptr) {
        if(temp->getCorreoEmisor() == correoEmisor) {
            return temp;
        }
        temp = temp->getDcha();
    }
    return nullptr;
}

nodoMatriz* matriz::buscarFila(string correoReceptor) {
    nodoMatriz *temp = this->raiz;

    while(temp != nullptr) {
        if(temp->getCorreoReceptor() == correoReceptor) {
            return temp;
        }
        temp = temp->getAbajo();
    }

    return nullptr;
}

void matriz::agregar(string correoEmisor, string correoReceptor, bool data) {
    nodoMatriz *nuevo = new nodoMatriz(correoEmisor, correoReceptor, data);
    nodoMatriz *columna = buscarCol(correoEmisor);
    nodoMatriz *fila = buscarFila(correoReceptor);

    if(!this->existeNodo(nuevo)) {
        if(columna == nullptr) {
            columna = insertarEncabezadoC(correoEmisor);
        }
        if(fila == nullptr) {
            fila = insertarEncabezadoF(correoReceptor);
        }

        insertarEnFila(nuevo, columna);
        insertarEnCol(nuevo, fila);
    }
}

nodoMatriz* matriz::insertarEncabezadoF(string correoReceptor) {
    nodoMatriz *nuevoEncabezadoF = new nodoMatriz("", correoReceptor);
    this->insertarEnFila(nuevoEncabezadoF, this->raiz);
    return nuevoEncabezadoF;
}

nodoMatriz* matriz::insertarEncabezadoC(string correoEmisor) {
    nodoMatriz *nuevoEncabezadoCol = new nodoMatriz(correoEmisor, "");
    this->insertarEnCol(nuevoEncabezadoCol, this->raiz);
    return nuevoEncabezadoCol;
}

void matriz::insertarEnFila(nodoMatriz *nuevo, nodoMatriz *encabezadoCol) {
    nodoMatriz *temp = encabezadoCol;

    while(temp->getAbajo() != nullptr) {
        if(nuevo->getCorreoReceptor() < temp->getAbajo()->getCorreoReceptor()) {
            nuevo->setAbajo(temp->getAbajo());
            nuevo->setArriba(temp->getArriba());
            temp->getAbajo()->setArriba(nuevo);
            temp->setAbajo(nuevo);
            break;
        }
        temp = temp->getAbajo();
    }

    if(temp->getAbajo() == nullptr) {
        temp->setAbajo(nuevo);
        nuevo->setArriba(temp);
    }
}

void matriz::insertarEnCol(nodoMatriz *nuevo, nodoMatriz *encabezadoFila) {
    nodoMatriz *temp = encabezadoFila;

    while(temp->getDcha() != nullptr) {
        if(nuevo->getCorreoEmisor() < temp->getDcha()->getCorreoEmisor()) {
            nuevo->setDcha(temp->getDcha());
            nuevo->setIzq(temp);
            temp->getDcha()->setIzq(nuevo);
            temp->setDcha(nuevo);
            break;
        }
        temp = temp->getDcha();
    }

    if(temp->getDcha() == nullptr) {
        temp->setDcha(nuevo);
        nuevo->setIzq(temp);
    }
}

bool matriz::existeNodo(nodoMatriz *nuevo) {
    nodoMatriz *encabezadoF = this->raiz;

    while(encabezadoF != nullptr) {
        if(encabezadoF->getCorreoReceptor() == nuevo->getCorreoReceptor()) {
            nodoMatriz *columna = encabezadoF;
            while(columna != nullptr) {
                if(columna->getCorreoEmisor() == nuevo->getCorreoEmisor()) {
                    columna->setData(nuevo->getData());
                    delete nuevo;
                    return true;
                }
                columna = columna->getDcha();
            }
            return false;
        }
        encabezadoF = encabezadoF->getAbajo();
    }
    return false;
}

void matriz::imprimirEncabezadoCol() {
    nodoMatriz *temp = this->raiz;
    cout << " ";

    for(nodoMatriz* col = temp->getDcha(); col != nullptr; col = col->getDcha()) {
        cout << col->getCorreoEmisor() << " ";
    }
    cout << endl;
}

nodoMatriz* matriz::obtenerNodo(string correoEmisor, string correoReceptor) {
    nodoMatriz *encabezadoFila = this->raiz;

    while(encabezadoFila != nullptr) {
        if(encabezadoFila->getCorreoReceptor() == correoReceptor) {
            nodoMatriz *columna = encabezadoFila;
            while(columna != nullptr) {
                if(columna->getCorreoEmisor() == correoEmisor) {
                    return columna;
                }
                columna = columna->getDcha();
            }
            return nullptr;
        }
        encabezadoFila = encabezadoFila->getAbajo();
    }
    return nullptr;
}

void matriz::verMatriz() {
    nodoMatriz *temp;

    this->imprimirEncabezadoCol();

    for(nodoMatriz* fila = this->raiz->getAbajo(); fila != nullptr; fila = fila->getAbajo()) {
        cout << fila->getCorreoReceptor() << " ";
        for(nodoMatriz* col = this->raiz->getDcha(); col != nullptr; col = col->getDcha()) {
            temp = obtenerNodo(col->getCorreoEmisor(), fila->getCorreoReceptor());
            cout << (temp != nullptr ? (temp->getData() ? "V" : "F") : "0") << " ";
        }
        cout << endl;
    }
}


bool matriz::verificarAmistad(string emisor,string receptor){
    nodoMatriz *encabezadoF = this->raiz;

    while(encabezadoF != nullptr){
        if(encabezadoF->getCorreoReceptor() == receptor){
            nodoMatriz *columna = encabezadoF;
            while(columna != nullptr){
                if(columna->getCorreoEmisor() == emisor){
                    return true;
                }
                columna = columna->getDcha();
            }
            return false;
        }
        encabezadoF = encabezadoF->getAbajo();
    }
    return false;
}
void matriz::graficarMatriz(string micorreo) {
    ofstream archivo("MimatrizAmistades.dot");
    if (!archivo.is_open()) {
        cout << "No se pudo crear el archivo" << endl;
        return;
    }

    archivo << "digraph G {" << endl;
    archivo << "    rankdir=TB;" << endl; // Top-Bottom para la alineación vertical
    archivo << "    node [shape=box];" << endl;

    nodoMatriz* raiz = this->raiz;
    string inicio = "INICIO";
    archivo << "    \"" << inicio << "\" [label=\"Inicio\"];" << endl;

    // Conexión desde el nodo de inicio al primer nodo columna
    archivo << "    \"" << inicio << "\" -> \"" << raiz->getDcha()->getCorreoEmisor() << "\";" << endl;

    // Encabezados de columna en la misma fila
    archivo << "    { rank=same; ";
    for (nodoMatriz* col = raiz->getDcha(); col != nullptr; col = col->getDcha()) {
        archivo << "\"" << col->getCorreoEmisor() << "\" [label=\"" << col->getCorreoEmisor() << "\"]; ";
    }
    archivo << "}" << endl;

    // Conexión horizontal entre los nodos de la primera fila (columnas)
    for (nodoMatriz* col = raiz->getDcha(); col != nullptr; col = col->getDcha()) {
        if (col->getDcha() != nullptr) {
            archivo << "    \"" << col->getCorreoEmisor() << "\" -> \"" << col->getDcha()->getCorreoEmisor() << "\";" << endl;
        }
    }

    // Nodos y conexiones verticales de cada fila
    for (nodoMatriz* fila = raiz->getAbajo(); fila != nullptr; fila = fila->getAbajo()) {
        archivo << "\"" << fila->getCorreoReceptor() << "\" [label=\"" << fila->getCorreoReceptor() << "\"];" << endl;
        if (fila->getAbajo() != nullptr) {
            archivo << "\"" << fila->getCorreoReceptor() << "\" -> \"" << fila->getAbajo()->getCorreoReceptor() << "\";" << endl;
        }

        for (nodoMatriz* nodo = fila->getDcha(); nodo != nullptr; nodo = nodo->getDcha()) {
            archivo << "\"" << nodo->getCorreoEmisor() << nodo->getCorreoReceptor() << "\" [label=\"" << nodo->getCorreoEmisor() << "," << nodo->getCorreoReceptor() << "\"];" << endl;
            
            if (nodo->getDcha() != nullptr) {
                archivo << "\"" << nodo->getCorreoEmisor() << nodo->getCorreoReceptor() << "\" -> \"" << nodo->getDcha()->getCorreoEmisor() << nodo->getDcha()->getCorreoReceptor() << "\";" << endl;
            }
            if (nodo->getAbajo() != nullptr) {
                archivo << "\"" << nodo->getCorreoEmisor() << nodo->getCorreoReceptor() << "\" -> \"" << nodo->getAbajo()->getCorreoEmisor() << nodo->getAbajo()->getCorreoReceptor() << "\";" << endl;
            }
        }
    }

    archivo << "}" << endl;
    archivo.close();

    stringstream nombreArchivo;
    nombreArchivo << "MimatrizAmigos_" << micorreo << ".png";

    stringstream comando;
    comando << "dot -Tpng MimatrizAmistades.dot -o " << nombreArchivo.str();
    system(comando.str().c_str());

    cout << "La grafica de matriz de amistad ha sido guardada como: " << nombreArchivo.str() << endl;
}
