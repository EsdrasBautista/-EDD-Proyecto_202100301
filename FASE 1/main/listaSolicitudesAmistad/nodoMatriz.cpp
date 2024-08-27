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

    // Recorre hasta el final de la fila
    while (temp->getAbajo() != nullptr) {
        temp = temp->getAbajo();
    }

    // Inserta el nuevo nodo al final
    temp->setAbajo(nuevo);
    nuevo->setArriba(temp);
    nuevo->setAbajo(nullptr); // El nuevo nodo será el último en la fila
}


void matriz::insertarEnCol(nodoMatriz *nuevo, nodoMatriz *encabezadoFila) {
    nodoMatriz *temp = encabezadoFila;

    // Recorre hasta el final de la columna
    while (temp->getDcha() != nullptr) {
        temp = temp->getDcha();
    }

    // Inserta el nuevo nodo al final
    temp->setDcha(nuevo);
    nuevo->setIzq(temp);
    nuevo->setDcha(nullptr); // El nuevo nodo será el último en la columna
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

        ofstream archivo("MatrizA.dot");
        if (!archivo.is_open()) {
            cout << "No se pudo crear el archivo" << endl;
            return;
        }

        archivo << "digraph G {" << endl;
        archivo << "    rankdir=TB;" << endl; // Top-Bottom para la alineación vertical
        archivo << "    node [shape=box];" << endl;

        nodoMatriz* raiz = this->raiz;
        string inicio = "RAIZ";
        archivo << "    \"" << inicio << "\" [label=\"Raiz\", group = 1];" << endl;


        //-------------------------------------------------------------------------------------------------------------------------

        //estos son lo encabezados que van horizontal    
        archivo << "    { rank=same; ";
        
        int filaNodo = 1;
        for (nodoMatriz* fila = raiz->getDcha(); fila != nullptr; fila = fila->getDcha()) {
            archivo << "\"" << fila->getCorreoEmisor() << filaNodo << "\" [label=\"" << fila->getCorreoEmisor() << "\", group=" << fila->getCorreoEmisor() << "];" << endl;
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
            archivo << "\"" << col->getCorreoReceptor() << "C_" << columnaNodo << "\" [label=\"" << col->getCorreoReceptor() << "\", group=\"1\"]; ";
            columnaNodo ++;
        }
        archivo << endl;

        //Conexion entre los nodos que van vertical
        
        // Conexión entre los nodos que van verticalmente
        int colIndex = 1;
        archivo << "    \"" << inicio << "\" -> \"" << raiz->getAbajo()->getCorreoReceptor() <<"C_"<< colIndex <<"\";" << endl;
        archivo << "    \"" << raiz->getAbajo()->getCorreoReceptor() <<"C_"<< colIndex << "\" -> \"" << inicio <<"\";" << endl;

        for (nodoMatriz* col = raiz->getAbajo(); col != nullptr; col = col->getAbajo()) {
            if (col->getAbajo() != nullptr) {
                archivo << "    \"" << col->getCorreoReceptor() <<"C_"<< colIndex << "\" -> \"" << col->getAbajo()->getCorreoReceptor() <<"C_"<< (colIndex + 1) << "\";" << endl;
                archivo << "    \"" << col->getAbajo()->getCorreoReceptor() <<"C_"<< (colIndex + 1) << "\" -> \"" << col->getCorreoReceptor() <<"C_"<< colIndex << "\";" << endl;
            }
            colIndex++;  // Incrementar colIndex aquí
        }


        //-------------------------------------------------------------------------------------------------------------------------
        
        
        archivo << endl;
        
        // Posicionar nodos donde coincidan encabezados
        int filaN = 1;
        int colN = 1;
        for (nodoMatriz* fila = raiz->getDcha(); fila != nullptr; fila = fila->getDcha()) {
            int colN = 1; // Resetear colN para cada nueva fila
            for (nodoMatriz* col = raiz->getAbajo(); col != nullptr; col = col->getAbajo()) {
                nodoMatriz* nodoActual = obtenerNodo(fila->getCorreoEmisor(), col->getCorreoReceptor());
                if (nodoActual != nullptr) {
                    archivo << "\"" << fila->getCorreoEmisor() << "_" << col->getCorreoReceptor() << "\" [label=\"V\"];" << endl;

                    archivo << "\"" << fila->getCorreoEmisor() << filaN << "\" -> \"" << fila->getCorreoEmisor() << "_" << col->getCorreoReceptor() << "\";" << endl;
                    archivo << "\"" << col->getCorreoReceptor() << "C_" << colN << "\" -> \"" << fila->getCorreoEmisor() << "_" << col->getCorreoReceptor() << "\";" << endl;
                    archivo << "\"" << fila->getCorreoEmisor() << "_" << col->getCorreoReceptor() << "\" -> \"" << fila->getCorreoEmisor() << filaN << "\";" << endl;
                    archivo << "\"" << fila->getCorreoEmisor() << "_" << col->getCorreoReceptor() << "\" -> \"" << col->getCorreoReceptor() << "C_" << colN << "\";" << endl;
                    archivo << "    { rank=same; " << col->getCorreoReceptor() << "C_" << colN << ";" << fila->getCorreoEmisor() << "_" << col->getCorreoReceptor() << "};" << endl;
                }
                colN++;    
            }
            filaN++;
        }

        


        


        archivo << "}" << endl;
        archivo.close();

        stringstream nombreArchivo;
        nombreArchivo << "MatrizA_" << micorreo << ".png";

        stringstream comando;
        comando << "dot -Tpng MatrizA.dot -o " << nombreArchivo.str();
        system(comando.str().c_str());

        cout << "La grafica de matriz de amistad ha sido guardada como: " << nombreArchivo.str() << endl;
    }
}




void matriz::graficar(){

    if(this->raiz->getAbajo() == nullptr || this->raiz->getDcha() == nullptr){
        cout << "No tienes amigos con cuales relacionarte aun!" << endl;
    }else{

        ofstream archivo("MatrizGeneral.dot");
        if (!archivo.is_open()) {
            cout << "No se pudo crear el archivo" << endl;
            return;
        }

        archivo << "digraph G {" << endl;
        archivo << "    rankdir=TB;" << endl; // Top-Bottom para la alineación vertical
        archivo << "    node [shape=box];" << endl;

        nodoMatriz* raiz = this->raiz;
        string inicio = "RAIZ";
        archivo << "    \"" << inicio << "\" [label=\"Raiz\", group = 1];" << endl;


        //-------------------------------------------------------------------------------------------------------------------------

        //estos son lo encabezados que van horizontal    
        archivo << "    { rank=same; ";
        
        int filaNodo = 1;
        for (nodoMatriz* fila = raiz->getDcha(); fila != nullptr; fila = fila->getDcha()) {
            archivo << "\"" << fila->getCorreoEmisor() << filaNodo << "\" [label=\"" << fila->getCorreoEmisor() << "\", group=" << fila->getCorreoEmisor() << "];" << endl;
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
            archivo << "\"" << col->getCorreoReceptor() << "C_" << columnaNodo << "\" [label=\"" << col->getCorreoReceptor() << "\", group=\"1\"]; ";
            columnaNodo ++;
        }
        archivo << endl;

        //Conexion entre los nodos que van vertical
        
        // Conexión entre los nodos que van verticalmente
        int colIndex = 1;
        archivo << "    \"" << inicio << "\" -> \"" << raiz->getAbajo()->getCorreoReceptor() <<"C_"<< colIndex <<"\";" << endl;
        archivo << "    \"" << raiz->getAbajo()->getCorreoReceptor() <<"C_"<< colIndex << "\" -> \"" << inicio <<"\";" << endl;

        for (nodoMatriz* col = raiz->getAbajo(); col != nullptr; col = col->getAbajo()) {
            if (col->getAbajo() != nullptr) {
                archivo << "    \"" << col->getCorreoReceptor() <<"C_"<< colIndex << "\" -> \"" << col->getAbajo()->getCorreoReceptor() <<"C_"<< (colIndex + 1) << "\";" << endl;
                archivo << "    \"" << col->getAbajo()->getCorreoReceptor() <<"C_"<< (colIndex + 1) << "\" -> \"" << col->getCorreoReceptor() <<"C_"<< colIndex << "\";" << endl;
            }
            colIndex++;  // Incrementar colIndex aquí
        }


        //-------------------------------------------------------------------------------------------------------------------------
        
        
        archivo << endl;
        
        // Posicionar nodos donde coincidan encabezados
        int filaN = 1;
        int colN = 1;
        for (nodoMatriz* fila = raiz->getDcha(); fila != nullptr; fila = fila->getDcha()) {
            int colN = 1; // Resetear colN para cada nueva fila
            for (nodoMatriz* col = raiz->getAbajo(); col != nullptr; col = col->getAbajo()) {
                nodoMatriz* nodoActual = obtenerNodo(fila->getCorreoEmisor(), col->getCorreoReceptor());
                if (nodoActual != nullptr) {
                    archivo << "\"" << fila->getCorreoEmisor() << "_" << col->getCorreoReceptor() << "\" [label=\"V\"];" << endl;

                    archivo << "\"" << fila->getCorreoEmisor() << filaN << "\" -> \"" << fila->getCorreoEmisor() << "_" << col->getCorreoReceptor() << "\";" << endl;
                    archivo << "\"" << col->getCorreoReceptor() << "C_" << colN << "\" -> \"" << fila->getCorreoEmisor() << "_" << col->getCorreoReceptor() << "\";" << endl;
                    archivo << "\"" << fila->getCorreoEmisor() << "_" << col->getCorreoReceptor() << "\" -> \"" << fila->getCorreoEmisor() << filaN << "\";" << endl;
                    archivo << "\"" << fila->getCorreoEmisor() << "_" << col->getCorreoReceptor() << "\" -> \"" << col->getCorreoReceptor() << "C_" << colN << "\";" << endl;
                    archivo << "    { rank=same; " << col->getCorreoReceptor() << "C_" << colN << ";" << fila->getCorreoEmisor() << "_" << col->getCorreoReceptor() << "};" << endl;
                }
                colN++;    
            }
            filaN++;
        }

        


        


        archivo << "}" << endl;
        archivo.close();

        stringstream nombreArchivo;
        nombreArchivo << "MatrizGeneral"<< ".png";

        stringstream comando;
        comando << "dot -Tpng MatrizGeneral.dot -o " << nombreArchivo.str();
        system(comando.str().c_str());

        cout << "La grafica de matriz de ha sido guardada como: " << nombreArchivo.str() << endl;
    }


    
    
}


void matriz::actualizarMatriz(string correoAmigo) {
    // Eliminar columna
    nodoMatriz* col = buscarCol(correoAmigo);
    if (col != nullptr) {
        // Desconectar nodos en la columna
        nodoMatriz* actual = col->getAbajo();
        while (actual != nullptr) {
            nodoMatriz* siguienteNodo = actual->getAbajo();
            eliminarNodo(actual);
            actual = siguienteNodo;
        }

        // Eliminar la cabecera de la columna
        if (col->getIzq() != nullptr) {
            col->getIzq()->setDcha(col->getDcha());
        }
        if (col->getDcha() != nullptr) {
            col->getDcha()->setIzq(col->getIzq());
        }

        delete col;
    }



    // Eliminar fila
    nodoMatriz* fila = buscarFila(correoAmigo);
    if (fila != nullptr) {
        // Desconectar nodos en la fila

        nodoMatriz* actual = fila->getDcha();

        
        while (actual != nullptr) {
            nodoMatriz* siguienteNodo = actual->getDcha();

            eliminarNodo(actual);
            actual = siguienteNodo;

        }

        // Eliminar la cabecera de la fila
        if (fila->getArriba() != nullptr) {
            fila->getArriba()->setAbajo(fila->getAbajo());
        }
        if (fila->getAbajo() != nullptr) {
            fila->getAbajo()->setArriba(fila->getArriba());
        }

        delete fila;
    }


}

void matriz::eliminarNodo(nodoMatriz* nodo) {
    // Desconectar nodo de la fila
    if (nodo->getIzq() != nullptr) {
        nodo->getIzq()->setDcha(nodo->getDcha());
    }
    if (nodo->getDcha() != nullptr) {
        nodo->getDcha()->setIzq(nodo->getIzq());
    }

    // Desconectar nodo de la columna
    if (nodo->getArriba() != nullptr) {
        nodo->getArriba()->setAbajo(nodo->getAbajo());
    }
    if (nodo->getAbajo() != nullptr) {
        nodo->getAbajo()->setArriba(nodo->getArriba());
    }

    // Eliminar nodo
    delete nodo;
}


