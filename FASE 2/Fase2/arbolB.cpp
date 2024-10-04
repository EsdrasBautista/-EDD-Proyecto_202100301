#include "./arbolB.h"
#include <iostream>

Nodo::Nodo(){
    this->hoja = true;
    this->primero = nullptr;
    this->numeroLlaves = 0;
}

Nodo::~Nodo(){
    Llave *temp = primero;
    Llave *aux;

    while(temp != nullptr){
        aux = temp->getSig();
        delete temp;
        temp = aux;
    }
}

void Nodo::insertarLlave(Llave *llave){
    Llave *puntero = this->primero;

    if(this->primero == nullptr){
        this->primero = llave;
        this->numeroLlaves++;

    }else if(compararFechas(llave->getFecha(),primero->getFecha()) == 1 && compararHoras(llave->getHora(),primero->getHora()) == 1){ //caso meno llave < primero
        llave->setSig(primero);
        primero->setIzq(llave->getDrcha());
        primero->setPrev(llave);
        primero = llave;
        numeroLlaves++;

    }else{
        while(puntero != nullptr){
            if(compararFechas(llave->getFecha(),puntero->getFecha()) == 0 && compararHoras(llave->getHora(),puntero->getHora()) == 0){ //caso igual
                std::cout << "El valor " << llave->getFecha() << " y " << llave->getFecha() << "ya se encuentra en el arbol. " << std::endl;
                std::cout << llave->getHora() <<" "<< puntero->getHora() << std::endl;
                break;

            }else if(compararFechas(llave->getFecha(),puntero->getFecha()) == 1 && compararHoras(llave->getHora(),puntero->getHora()) == 1){ //caso menor llave < puntero
                puntero->setIzq(llave->getDrcha());
                puntero->getPrev()->setDrcha(llave->getIzq());

                llave->setSig(puntero);
                llave->setPrev(puntero->getPrev());
                puntero->getPrev()->setSig(llave);
                puntero->setPrev(llave);

                numeroLlaves++;
                break;

            }else if(puntero->getSig() == nullptr){
                puntero->setSig(llave);
                llave->setPrev(puntero);
                puntero->setDrcha(llave->getIzq());

                numeroLlaves++;
                break;
            }
            puntero = puntero->getSig();
        }
    }
}

bool Nodo::esHoja(){
    return hoja;
}

Llave* Nodo::getPrimero(){
    return primero;
}

int Nodo::getNumeroLlaves(){
    return numeroLlaves;
}

void Nodo::setHoja(bool hoja){
    this->hoja = hoja;
}

void Nodo::setPrimero(Llave *primero){
    this->primero = primero;
}

void Nodo::setNumeroLlaves(int numeroLlaves){
    this->numeroLlaves = numeroLlaves;
}




//--------------------------------------------------------------------


Llave::Llave(string fecha, string hora,string correo,string contenido){
    this->fecha = fecha;
    this->hora = hora;
    this->contenido = contenido;
    this->correo = correo;
    prev = nullptr;
    sig = nullptr;
    drcha = nullptr;
    izq = nullptr;
}

Llave::~Llave(){
    delete drcha;
    delete izq;
    delete sig;
    delete prev;
}

bool Llave::tieneHijos(){
    return this->drcha != nullptr && this->izq != nullptr;
}

string Llave::getFecha(){
    return fecha;
}

Nodo* Llave::getIzq(){
    return izq;
}

Llave* Llave::getSig(){
    return sig;
}

Llave* Llave::getPrev(){
    return prev;
}

Nodo* Llave::getDrcha(){
    return drcha;
}

void Llave::setFecha(string fecha){
    this->fecha = fecha;
}

void Llave::setIzq(Nodo* izq){
    this->izq = izq;
}

void Llave::setSig(Llave *sig){
    this->sig = sig;
}

void Llave::setPrev(Llave *prev){
    this->prev = prev;
}

void Llave::setDrcha(Nodo *drcha){
    this->drcha = drcha;
}

void Llave::setHora(string hora){
    this->hora = hora;
}
string Llave::getHora(){
    return this->hora;
}
string Llave::getContenido(){
    return this->contenido;
}
string Llave::getCorreo(){
    return this->correo;
}

void Llave::setCorreo(string correo){
    this->correo = correo;
}
void Llave::setContenido(string contenido){
    this->contenido = contenido;
}



//-------------------------ARBOL B-----------------------------

ArbolB::ArbolB(){
    this->raiz = new Nodo();
    this->orden = 5;
}

ArbolB::~ArbolB(){
    delete this->raiz;
}

void ArbolB::insert(string fecha,string hora,string correo,string contenido){
    Llave *nueva_raiz = insertarEnHoja(fecha,hora,correo,contenido, this->raiz);
    if(nueva_raiz != nullptr){
        this->raiz = new Nodo();
        raiz->insertarLlave(nueva_raiz);
        raiz->setHoja(false);
    }
}


Llave* ArbolB::insertarEnHoja(string fecha,string hora,string correo,string contenido,Nodo *raiz){
    if(raiz->esHoja()){
        raiz->insertarLlave(new Llave(fecha,hora,correo,contenido));
        return (raiz->getNumeroLlaves() == this->orden) ? dividir(raiz) : nullptr;

    }else{
        Llave *puntero = raiz->getPrimero();
        if(compararFechas(fecha,puntero->getFecha()) == 0 && compararHoras(hora,puntero->getHora()) == 0) return nullptr;
        else if(compararFechas(fecha,puntero->getFecha()) == 1 && compararHoras(hora,puntero->getHora()) == 1){ // si es menor fecha < puntero.fecha
            Llave *llaveRaiz = insertarEnHoja(fecha,hora,correo,contenido, puntero->getIzq());
            if(llaveRaiz != nullptr){
                raiz->insertarLlave(llaveRaiz);
                return (raiz->getNumeroLlaves() == this->orden) ? dividir(raiz) : nullptr;
            }

            return nullptr;

        }else{
            do{
                if(compararFechas(fecha,puntero->getFecha()) == 0 && compararHoras(hora,puntero->getHora()) == 0) return nullptr;
                else if(compararFechas(fecha,puntero->getFecha()) == 1 && compararHoras(hora,puntero->getHora()) == 1){
                    Llave *llaveRaiz = insertarEnHoja(fecha,hora, correo,contenido,puntero->getIzq());
                    if(llaveRaiz != nullptr){
                        raiz->insertarLlave(llaveRaiz);
                        return (raiz->getNumeroLlaves() == this->orden) ? dividir(raiz) : nullptr;
                    }
                    return nullptr;

                }else if(puntero->getSig() == nullptr){
                    Llave *llaveRaiz = insertarEnHoja(fecha,hora,correo,contenido, puntero->getDrcha());
                    if(llaveRaiz != nullptr){
                        raiz->insertarLlave(llaveRaiz);
                        return (raiz->getNumeroLlaves() == this->orden) ? dividir(raiz) : nullptr;
                    }
                    return nullptr;
                }

                puntero = puntero->getSig();
            } while(puntero != nullptr);
        }
    }
    return nullptr;
}


Llave* ArbolB::dividir(Nodo *nodo){
    int contador = 1;
    string valorClaveRaizF = ""; //fecha
    string valorClaveRaizH = ""; //hora
    string valorCorreo = "";
    string valorConte = "";

    Llave *temp = nodo->getPrimero();
    Nodo *izquierda = new Nodo();
    Nodo *derecha = new Nodo();

    while(temp != nullptr){
        if(contador < 3){ //primeros elementos izquierda
            Llave *nueva_llave = new Llave(temp->getFecha(),temp->getHora(),temp->getCorreo(),temp->getContenido());
            nueva_llave->setDrcha(temp->getDrcha());
            nueva_llave->setIzq(temp->getIzq());
            izquierda->insertarLlave(nueva_llave);

            if(nueva_llave->tieneHijos()){
                izquierda->setHoja(false);
            }

        }else if(contador == 3){ //elemeto de enmedio
            valorClaveRaizF = temp->getFecha();
            valorClaveRaizH = temp->getHora();
            valorCorreo = temp->getCorreo();
            valorConte = temp->getContenido();

        }else{ //elementos derecha
            Llave *nueva_llave = new Llave(temp->getFecha(),temp->getHora(),temp->getCorreo(),temp->getContenido());
            nueva_llave->setDrcha(temp->getDrcha());
            nueva_llave->setIzq(temp->getIzq());
            derecha->insertarLlave(nueva_llave);

            if(nueva_llave->tieneHijos()){
                derecha->setHoja(false);
            }
        }
        contador++;
        temp = temp->getSig();
    }

    Llave *llaveRaiz = new Llave(valorClaveRaizF,valorClaveRaizH,valorCorreo,valorConte);
    llaveRaiz->setDrcha(derecha);
    llaveRaiz->setIzq(izquierda);
    return llaveRaiz;
}



void ArbolB::eliminarComentarios(string fecha, string correo){
    eliminarComentarios(fecha,correo,this->raiz);
}

void ArbolB::eliminarComentarios(string fecha, string correo, Nodo *nodo){
    if(raiz == nullptr){return;}


    Llave *llave = nodo->getPrimero();
    Llave *anterior = nullptr;


    //iteramos las llaves
    while(llave != nullptr){
        if(compararFechas(fecha, llave->getFecha()) == 0 && llave->getCorreo() == correo){
            if (anterior == nullptr) {
                nodo->setPrimero(llave->getSig());
                if (llave->getSig() != nullptr) {
                    llave->getSig()->setPrev(nullptr);
                }
            } else {
                anterior->setSig(llave->getSig());
                if (llave->getSig() != nullptr) {
                    llave->getSig()->setPrev(anterior);
                }
            }
            Llave *temp = llave;
            llave = llave->getSig(); // Mover al siguiente antes de eliminar
            delete temp;
            nodo->setNumeroLlaves(nodo->getNumeroLlaves() - 1);
        } else {
            anterior = llave;
            llave = llave->getSig();
        }
    }


    //verificar si no es una hoja
    if (!nodo->esHoja()) {
        llave = nodo->getPrimero();
        while (llave != nullptr) {
            eliminarComentarios(fecha, correo, llave->getIzq());
            llave = llave->getSig();
        }
        //ultimo hijo derecho
        eliminarComentarios(fecha, correo, nodo->getPrimero()->getDrcha());
    }
}

void ArbolB::recorrer(QPlainTextEdit *txtarea){

    recorrer(this->raiz, txtarea);
}

void ArbolB::recorrer(Nodo* nodo, QPlainTextEdit *textEdit){
    if(nodo == nullptr){return;}

    Llave* llave = nodo->getPrimero();

    while(llave != nullptr){
        if(!nodo->esHoja()){
            recorrer(llave->getIzq(),textEdit);
        }

        std::cout << llave->getContenido() << std::endl;

        QString infoLlave = QString("Fecha: %1\nHora: %2\nCorreo: %3\nContenido: %4\n")
                                .arg(QString::fromStdString(llave->getFecha()))
                                .arg(QString::fromStdString(llave->getHora()))
                                .arg(QString::fromStdString(llave->getCorreo()))
                                .arg(QString::fromStdString(llave->getContenido()));

        textEdit->insertPlainText(infoLlave);
        textEdit->insertPlainText("--------------------------------------------\n");

        llave = llave->getSig();
    }

    if(!nodo->esHoja() && nodo->getPrimero() != nullptr){
        recorrer(nodo->getPrimero()->getDrcha(),textEdit);
    }

}

string ArbolB::verArbol(){
    std::ofstream outfile ("arbolB.dot");
    outfile << "digraph G {" << std::endl;
    if(raiz != nullptr){
        verArbol(this->raiz,outfile);
    }else{
        return "";
    }
    outfile << "}" << std::endl;
    outfile.close();

    int returnCode = system("dot -Tpng ./arbolB.dot -o ./arbolB.png");

    if (returnCode == 0) {
        std::cout << "Command executed successfully." << std::endl;

        return "\\arbolB.png";
    } else {
        std::cout << "Command execution failed or returned non-zero: " << returnCode << std::endl;
        return "";
    }

}

void ArbolB::verArbol(Nodo *nodo, ofstream &archivoDot) {
    if (nodo == nullptr) { return; }

    // Crear el nodo principal (el contenedor de las llaves)
    std::ostringstream nodoStream;
    nodoStream << "nodo" << nodo;


    Llave *llave = nodo->getPrimero();
    int contador = 0;


    while (llave != nullptr) {
        std::ostringstream llaveStream;
        llaveStream << "llave" << llave;
        archivoDot << llaveStream.str() << " [label=\""
                   << llave->getFecha() << "\\n"
                   << llave->getHora() << "\\n"
                   << llave->getContenido() << "\"];\n";

        if (contador == 0) {
            archivoDot << nodoStream.str() << " -> " << llaveStream.str() << ";\n";
        } else {
            std::ostringstream prevLlaveStream;
            prevLlaveStream << "llave" << llave->getPrev();  // Nodo anterior
            archivoDot << prevLlaveStream.str() << " -> " << llaveStream.str() << ";\n";
        }

        if (llave->getIzq() != nullptr) {
            archivoDot << llaveStream.str() << " -> nodo" << llave->getIzq() << ";\n";
            verArbol(llave->getIzq(), archivoDot);  // Llamada recursiva para el subárbol izquierdo
        }

        llave = llave->getSig();
        contador++;
    }

    if (nodo->getPrimero() != nullptr && nodo->getPrimero()->getDrcha() != nullptr) {
        archivoDot << nodoStream.str() << " -> nodo" << nodo->getPrimero()->getDrcha() << ";\n";
        verArbol(nodo->getPrimero()->getDrcha(), archivoDot);  // Llamada recursiva para subárbol derecho
    }
}
