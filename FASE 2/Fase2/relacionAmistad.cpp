#include "./relacionAmistad.h"


//-----------------------------------------------------------
enodo::enodo(){
    this->correoDestino = "";
    this->siguiente = nullptr;
}

string enodo::getDestino(){
    return correoDestino;
}

enodo* enodo::getSiguiente(){
    return siguiente;
}

void enodo::setDestino(string destino){
    this->correoDestino = destino;
}

void enodo::setSiguiente(enodo* siguiente){
    this->siguiente = siguiente;
}
//-----------------------------------------------------------

vnodo::vnodo(){
    this->correo = "";
    this->destinos = nullptr;
    this->siguiente = nullptr;
}

string vnodo::getCorreoE(){
    return this->correo;
}

enodo* vnodo::getDestinos(){
    return this->destinos;
}

vnodo* vnodo::getSiguiente(){
    return this->siguiente;
}

void vnodo::setCorreoE(string data){
    this->correo = data;
}

void vnodo::setDestinos(enodo *destinos){
    this->destinos = destinos;
}

void vnodo::setSiguiente(vnodo *siguiente){
    this->siguiente = siguiente;
}



vnodo::~vnodo(){
    enodo *aux = this->destinos;
    enodo *temp;

    while(aux != nullptr){
        temp = aux->getSiguiente();
        delete aux;
        aux = temp;
    }
}

void vnodo::insertarDestino(string destino){
    enodo *nuevo = new enodo();
    nuevo->setDestino(destino);


    if(this->destinos == nullptr){
        this->destinos = nuevo;

    }else{
        enodo *aux = this->destinos;
        while(aux->getSiguiente() != nullptr){
            if(aux->getDestino() == destino){
                return;
            }
            aux = aux->getSiguiente();
        }

        if(aux->getDestino() != destino){
            aux->setSiguiente(nuevo);
        }
    }
}


void vnodo::graficarAristas(std::ofstream &f){
    enodo *aux = this->destinos;

    std::string nombre_origen =  this->correo;
    while(aux != nullptr){
        if(this->correo < aux->getDestino()){
            std::string nombre_destino =  aux->getDestino();
            f << "\"" + nombre_origen + "\"->\"" + nombre_destino + "\" [dir = both];" << std::endl;
        }
        aux = aux->getSiguiente();
    }
}


void vnodo::graficarListaDestinos(std::ofstream &f){
    enodo  *aux = this->destinos;
    std::ostringstream oss;
    std::string valor = this->correo;
    std::string nombre_origen = "Nodo"+ valor;
    std::string rank = "{rank=same; \"" + nombre_origen + "\"";

    oss << this->destinos;
    std::string nombre = oss.str();

    f << "\"" + nombre_origen + "\"->\"Nodo" + nombre + "\";" << std::endl;

    while(aux != nullptr){
        oss.str("");
        oss << aux;
        std::string nombre = oss.str();

        std::string nombre_destino = "Nodo" + nombre;
        f << "\"" + nombre_destino + "\"[label = \"" + aux->getDestino() + "\" fillcolor = \"white\"];" << std::endl;
        rank+=";" + nombre_destino;

        if(aux->getSiguiente() != nullptr){
            oss.str("");
            oss << aux->getSiguiente();
            std::string nombre = oss.str();
            f << "\"" + nombre_destino + "\"->\"Nodo" + nombre + "\";" << std::endl;
        }
        aux = aux->getSiguiente();
    }
    rank+= "}";
    f << rank << std::endl;
}


//-----------------------------------------------------------


listaAdyacencia::listaAdyacencia(){
    this->cabeza = nullptr;
}

listaAdyacencia::~listaAdyacencia(){
    vnodo *aux = this->cabeza;
    vnodo *temp;

    while(aux != nullptr){
        temp = aux->getSiguiente();
        delete aux;
        aux = temp;
    }
}


void listaAdyacencia::insert(string vertice){
    if(this->cabeza == nullptr){
        this->cabeza = new vnodo();
        this->cabeza->setCorreoE(vertice);

    }else{
        vnodo *nuevo = new vnodo();
        nuevo->setCorreoE(vertice);

        if(vertice < this->cabeza->getCorreoE()){
            nuevo->setSiguiente(cabeza);
            this->cabeza = nuevo;

        }else{
            vnodo *aux = this->cabeza;
            while(aux->getSiguiente() != nullptr){
                if(vertice < aux->getSiguiente()->getCorreoE()){
                    nuevo->setSiguiente(aux->getSiguiente());
                    aux->setSiguiente(nuevo);
                    break;
                }
                aux = aux->getSiguiente();
            }

            if(aux->getSiguiente() == nullptr){
                aux->setSiguiente(nuevo);
            }
        }
    }
}

void listaAdyacencia::crearConexion(string origen, string destino){
    vnodo *aux = this->cabeza;
    while(aux != nullptr){
        if(aux->getCorreoE() == origen){
            aux->insertarDestino(destino);
            break;
        }
        aux = aux->getSiguiente();
    }
}
bool listaAdyacencia::crearGrafo(){
    std::ofstream outfile("grafo.dot");
    if (!outfile.is_open()) {
        std::cerr << "Error al abrir el archivo grafo.dot" << std::endl;
        return false;
    }

    outfile << "digraph G {" << std::endl;

    vnodo *aux = this->cabeza;
    while(aux != nullptr) {
        std::string valor = aux->getCorreoE();
        std::string dec_nodo = "\"" + valor + "\" [label = \"" + valor + "\"];";
        outfile << dec_nodo << std::endl;
        aux->graficarAristas(outfile);
        aux = aux->getSiguiente();
    }

    outfile << "}" << std::endl;
    outfile.close();

    int returnCode = system("dot -Tpng ./grafo.dot -o ./grafo.png");

    if (returnCode == 0) {
        std::cout << "Command executed successfully." << std::endl;
        return true;
    } else {
        std::cout << "Command execution failed or returned non-zero: " << returnCode << std::endl;
        return false;
    }
}


bool listaAdyacencia::crearGrafoLista(){
    std::ofstream outfile("grafoLista.dot");
    if (!outfile.is_open()) {
        std::cerr << "Error al abrir el archivo grafoLista.dot" << std::endl;
        return false;
    }

    outfile << "digraph G {" << std::endl;
    outfile << "node[shape = \"box\" style = \"filled\"]" << std::endl;

    vnodo *aux = this->cabeza;
    while(aux != nullptr) {
        std::string valor = aux->getCorreoE();
        std::string nombre = "\"Nodo" + valor + "\" [label = \"" + valor + "\" group = \"1\" fillcolor=\"lightgray\"];";
        outfile << nombre << std::endl;

        if(aux->getSiguiente() != nullptr) {
            outfile << "\"Nodo" + valor + "\"->\"Nodo" + aux->getSiguiente()->getCorreoE() + "\" [dir = none];" << std::endl;
        }

        aux->graficarListaDestinos(outfile);
        aux = aux->getSiguiente();
    }

    outfile << "}" << std::endl;
    outfile.close();

    int returnCode = system("dot -Tpng ./grafoLista.dot -o ./grafoLista.png");

    if (returnCode == 0) {
        std::cout << "Command executed successfully." << std::endl;
        return true;
    } else {
        std::cout << "Command execution failed or returned non-zero: " << returnCode << std::endl;
        return false;
    }
}



bool listaAdyacencia::verificarAmistadGrafo(string correoVerificar){
    if(cabeza == nullptr){
        return false;
    }

    vnodo* actual = cabeza;
    while(actual != nullptr){
        if(actual->getCorreoE() == correoVerificar){
            return true;
        }
        actual = actual->getSiguiente();
    }

    return false;
}

vnodo* listaAdyacencia::getprimero(){
    if(cabeza != nullptr){
        return cabeza;
    }else{
        return nullptr;
    }

}

void listaAdyacencia::eliminarAmigoGrafo(string correoEliminar) {
    if (cabeza == nullptr) {
        return;
    }

    // 1. Eliminar el vertice (vnodo) correspondiente al correoEliminar
    vnodo* actual = cabeza;
    vnodo* anterior = nullptr;

    while (actual != nullptr) {
        if (actual->getCorreoE() == correoEliminar) {

            if (anterior == nullptr) {
                // El nodo a eliminar es la cabeza
                cabeza = actual->getSiguiente();
            } else {
                // El nodo a eliminar esta en el medio o al final
                anterior->setSiguiente(actual->getSiguiente());
            }

            // Eliminar los destinos asociados a este vértice
            enodo* destinoActual = actual->getDestinos();
            while (destinoActual != nullptr) {
                enodo* siguienteDestino = destinoActual->getSiguiente();
                delete destinoActual;
                destinoActual = siguienteDestino;
            }

            delete actual;
            break;
        }
        anterior = actual;
        actual = actual->getSiguiente();
    }

    // 2. Eliminar cualquier referencia a correoEliminar en las listas de destinos de los otros vértices
    actual = cabeza;
    while (actual != nullptr) {
        enodo* destinoActual = actual->getDestinos();
        enodo* destinoAnterior = nullptr;

        while (destinoActual != nullptr) {
            if (destinoActual->getDestino() == correoEliminar) {
                // Encontramos una conexión que apunta al correo a eliminar
                if (destinoAnterior == nullptr) {
                    // El nodo a eliminar es el primero en la lista de destinos
                    actual->setDestinos(destinoActual->getSiguiente());
                } else {
                    // El nodo a eliminar esta en el medio o al final
                    destinoAnterior->setSiguiente(destinoActual->getSiguiente());
                }

                // Eliminar el nodo en la lista de destinos
                enodo* temp = destinoActual;
                destinoActual = destinoActual->getSiguiente();
                delete temp;
                continue; // Saltar a la siguiente iteración
            }

            destinoAnterior = destinoActual;
            destinoActual = destinoActual->getSiguiente();
        }

        actual = actual->getSiguiente();
    }
}


//-----------------------------------------------------------
