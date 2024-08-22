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
    nodoMatriz *temp = raiz;
    nodoMatriz *aux;

    while(temp != nullptr){
        nodoMatriz *tempFila = temp;
        nodoMatriz *auxFila;

        aux = temp->getAbajo();

        while(tempFila != nullptr){
            auxFila = tempFila->getDcha();
            delete tempFila;
            tempFila = auxFila;
        }

        temp = aux;
    }
    this->raiz = nullptr;
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

    if(this->raiz->getAbajo() == nullptr || this->raiz->getDcha() == nullptr){
        cout << "No tienes amigos con cuales relacionarte aun!" << endl;
    }else{

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


        //-------------------------------------------------------------------------------------------------------------------------
        // Encabezados de columna en la misma fila
        //estos son lo encabezados que van horizontal    
        archivo << "    { rank=same; ";
        
        int filaNodo = 1;
        for (nodoMatriz* fila = raiz->getDcha(); fila != nullptr; fila = fila->getDcha()) {
            archivo << "\"" << fila->getCorreoEmisor() << filaNodo << "\" [label=\"" << fila->getCorreoEmisor() << "\"]; ";
            filaNodo ++;
        }
        archivo << endl;
        int filaIndex = 1;
        archivo << "    \"" << inicio << "\" -> \"" << raiz->getDcha()->getCorreoEmisor() << filaIndex <<"\";" << endl;
        archivo << "    \"" << raiz->getDcha()->getCorreoEmisor() << filaIndex << "\" -> \"" << inicio <<"\";" << endl;
        
        // Conectar nodos de encabezado de columna horizontalmente
        for (nodoMatriz* fila = raiz->getDcha(); fila != nullptr; fila = fila->getDcha()) {
            if (fila->getDcha() != nullptr) {
                archivo << "    \"" << fila->getCorreoEmisor() << filaIndex << "\" -> \"" << fila->getDcha()->getCorreoEmisor() << (filaIndex + 1) << "\";" << endl;
                archivo << "    \"" << fila->getDcha()->getCorreoEmisor() << (filaIndex + 1) << "\" -> \"" << fila->getCorreoEmisor() << filaIndex << "\";" << endl;
            }
            filaIndex++;
        }
        archivo << "}" << endl;
        //-------------------------------------------------------------------------------------------------------------------------
        //creacion de nodos verticales
        int columnaNodo = 1;
        for (nodoMatriz* col = raiz->getAbajo(); col != nullptr; col = col->getAbajo()) {
            archivo << "\"" << col->getCorreoReceptor() << "C_"<< columnaNodo << "\" [label=\"" << col->getCorreoReceptor() << "\"]; ";
            columnaNodo ++;
        }
        archivo << endl;

        //Conexion entre los nodos que van vertical
        int colIndex = 1;
        archivo << "    \"" << inicio << "\" -> \"" << raiz->getAbajo()->getCorreoReceptor() <<"C_"<< colIndex <<"\";" << endl;
        archivo << "    \"" << raiz->getAbajo()->getCorreoReceptor() <<"C_"<< colIndex << "\" -> \"" << inicio <<"\";" << endl;

        for (nodoMatriz* col = raiz->getAbajo(); col != nullptr; col = col->getAbajo()) {
            if (col->getAbajo() != nullptr) {
                archivo << "    \"" << col->getCorreoReceptor() <<"C_"<< colIndex << "\" -> \"" << col->getAbajo()->getCorreoReceptor() <<"C_"<< (colIndex +1)<< "\";" << endl;
                archivo << "    \"" << col->getAbajo()->getCorreoReceptor() <<"C_"<< (colIndex +1) << "\" -> \"" << col->getCorreoReceptor() <<"C_"<< colIndex << "\";" << endl;        
                }
        }

        //-------------------------------------------------------------------------------------------------------------------------
        //aqui se deben de meter los nodos donde coincidan

        // Posicionar nodos donde coincidan encabezados
        int filaN = 1;
        int colN = 1;
        for (nodoMatriz* fila = raiz->getDcha(); fila != nullptr; fila = fila->getDcha()) {
            int colN = 1; // Resetear colN para cada nueva fila
            for (nodoMatriz* col = raiz->getAbajo(); col != nullptr; col = col->getAbajo()) {
                nodoMatriz* nodoActual = obtenerNodo(fila->getCorreoEmisor(), col->getCorreoReceptor());
                if (nodoActual != nullptr) {
                    archivo << "\"" << fila->getCorreoEmisor() << "_" << col->getCorreoReceptor() << "\" [label=\"v\"];" << endl;
                    archivo << "\"" << fila->getCorreoEmisor() << filaN << "\" -> \"" << fila->getCorreoEmisor() << "_" << col->getCorreoReceptor() << "\";" << endl;
                    archivo << "\"" << col->getCorreoReceptor() << "C_" << colN << "\" -> \"" << fila->getCorreoEmisor() << "_" << col->getCorreoReceptor() << "\";" << endl;
                    archivo << "\"" << fila->getCorreoEmisor() << "_" << col->getCorreoReceptor() << "\" -> \"" << fila->getCorreoEmisor() << filaN << "\";" << endl;
                    archivo << "\"" << fila->getCorreoEmisor() << "_" << col->getCorreoReceptor() << "\" -> \"" << col->getCorreoReceptor() << "C_" << colN << "\";" << endl;
                }
                colN++;    
            }
            filaN++;
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
}




void matriz::eliminarMatriz() {

    nodoMatriz *actualFila = this->raiz;
    nodoMatriz *siguienteFila = nullptr;

    if(this->raiz == nullptr){
        return;
    }

    while (actualFila != nullptr) {
        nodoMatriz *actualColumna = actualFila;
        nodoMatriz *siguienteColumna = nullptr;

        // Eliminar todos los nodos en la fila actual
        while (actualColumna != nullptr) {
            siguienteColumna = actualColumna->getDcha(); // Guardar el siguiente nodo en la fila
            delete actualColumna; 
            actualColumna = siguienteColumna; // Avanzar al siguiente nodo en la fila
        }

        // Avanzar a la siguiente fila
        siguienteFila = actualFila->getAbajo();
        delete actualFila; // Eliminar el nodo de encabezado de la fila
        actualFila = siguienteFila; // Avanzar a la siguiente fila
    }


    this->raiz = nullptr;
}
