#include "./SimplePublicacion.h"

nodoSimplePub::nodoSimplePub(string fecha,string correo,string contenido,string hora,string imagen,int id){
    this->fecha = fecha;
    this->correo = correo;
    this->contenido = contenido;
    this->hora = hora;
    this->id = id;
    this->imagen = imagen;
    this->siguiente = nullptr;
    this->anterior = nullptr;
    this->ArbolComentarios = new ArbolB();
}
nodoSimplePub::nodoSimplePub(){
    fecha = "";
    correo = "";
    contenido = "";
    hora = "";
    id = 0;
    imagen = "";
    siguiente = nullptr;
    anterior = nullptr;
}

nodoSimplePub::~nodoSimplePub(){
    delete ArbolComentarios;
}

void nodoSimplePub::setAnterior(nodoSimplePub* ant) {
    this->anterior = ant;
}
nodoSimplePub* nodoSimplePub::getAnterior() {
    return anterior;
}

void nodoSimplePub::setSiguiente(nodoSimplePub *sig){
    this->siguiente = sig;
}
nodoSimplePub* nodoSimplePub::getSiguiente(){
    return siguiente;
}

string nodoSimplePub::getFechaL(){
    return fecha;
}

string nodoSimplePub::getCorreoL(){
    return correo;
}
string nodoSimplePub::getContenidoL(){
    return contenido;
}
string nodoSimplePub::getImagen(){
    return imagen;
}
string nodoSimplePub::getHoraL(){
    return hora;
}
int nodoSimplePub::getIdL(){
    return id;
}

ArbolB* nodoSimplePub::getArbolComentarios(){
    return this->ArbolComentarios;
}

//-----------------------------------------------------------------

listaNodoPub::listaNodoPub(){
    this->cabeza = nullptr;
}

listaNodoPub::~listaNodoPub(){
    nodoSimplePub *temp = cabeza;
    nodoSimplePub *aux;
    while(temp != nullptr){
        aux = temp->getSiguiente();
        delete temp;
        temp = aux;
    }
}

void listaNodoPub::agregarPublicacionL(string fecha, string correo, string contenido, string hora, string imagen, int id){
    nodoSimplePub *nuevo = new nodoSimplePub(fecha,correo,contenido,hora,imagen,id);

    if(cabeza == nullptr){
        cabeza = nuevo;
    }else{
        nodoSimplePub *temp = cabeza;
        while(temp->getSiguiente() != nullptr){
            temp = temp->getSiguiente();
        }
        temp->setSiguiente(nuevo);
        nuevo->setAnterior(temp);
    }

}

void listaNodoPub::mostrarPublicacionesL(){
    nodoSimplePub *actual = cabeza;

    while(actual != nullptr){
        std::cout << "Correo: " << actual->getCorreoL() << " | Contenido: " << actual->getContenidoL()
        << " | Hora: " << actual->getHoraL()<< " | ID: " << actual->getIdL()<< std::endl;
        std::cout << " | Imagen: " << actual->getImagen() << std::endl;
        actual = actual->getSiguiente();
    }
}

nodoSimplePub* listaNodoPub::getCabeza(){
    nodoSimplePub* actual = cabeza;
    if(actual == nullptr){
        return nullptr;
    }else{
        return actual;
    }
}

bool listaNodoPub::verificarExistencia(string correo, int id){

    if(cabeza == nullptr){
        return false;
    }else{
        nodoSimplePub *actual = cabeza;
        while(actual != nullptr){
            if(actual->getCorreoL() == correo && actual->getIdL() == id){
                return true;
            }
            actual = actual->getSiguiente();
        }
    }

    return false;
}

void listaNodoPub::eliminarPub(string correo) {

    nodoSimplePub* actual = cabeza;

    while (actual != nullptr) {
        if (actual->getCorreoL() == correo) {
            if (actual->getAnterior() != nullptr) {
                actual->getAnterior()->setSiguiente(actual->getSiguiente());
            } else {
                cabeza = actual->getSiguiente();
            }

            if (actual->getSiguiente() != nullptr) {
                actual->getSiguiente()->setAnterior(actual->getAnterior());
            }

            delete actual;
            return;
        }
        actual = actual->getSiguiente();
    }

}


nodoSimplePub* listaNodoPub::buscarNodoporCorreoId(string correo, int id){
    nodoSimplePub* actual = cabeza;
    if(actual == nullptr){return nullptr;}

    while(actual != nullptr){
        if(actual->getCorreoL() == correo && actual->getIdL() == id){
            return actual;
        }
        actual = actual->getSiguiente();

    }

    return nullptr;
}

void listaNodoPub::graph(){
    if (cabeza == nullptr) {
        std::cout << "La lista está vacía, no hay nada que graficar." << std::endl;
        return;
    }
    std::ofstream archivo("lista_publicaciones.dot");
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo para escribir el gráfico." << std::endl;
        return;
    }
    // Escribir la cabecera del archivo DOT
    archivo << "digraph G {\n";
    archivo << "    rankdir=LR;\n";  // Orientación izquierda a derecha
    archivo << "    node [shape=record];\n";  // Usar nodos con forma de registro para mostrar los datos

    // Recorrer la lista y crear los nodos
    nodoSimplePub* actual = cabeza;
    int nodoID = 0;  // Un ID único para cada nodo
    while (actual != nullptr) {
        // Crear el nodo con sus atributos (correo, contenido, etc.)
        archivo << "    nodo" << nodoID << " [label=\"{ID: " << actual->getIdL()
                << " | Correo: " << actual->getCorreoL()
                << " | Contenido: " << actual->getContenidoL()
                << " | Fecha: " << actual->getFechaL()
                << " | Hora: " << actual->getHoraL() << "}\"];\n";

        // Si hay un nodo siguiente, crear la conexión bidireccional
        if (actual->getSiguiente() != nullptr) {
            archivo << "    nodo" << nodoID << " -> nodo" << nodoID + 1 << " [dir=both];\n";
        }

        // Pasar al siguiente nodo
        actual = actual->getSiguiente();
        nodoID++;
    }

    // Cerrar el archivo DOT
    archivo << "}\n";
    archivo.close();

    // Generar el gráfico usando el archivo .dot
    system("dot -Tpng lista_publicaciones.dot -o lista_publicaciones.png");

    std::cout << "Gráfico generado como 'lista_publicaciones.png'." << std::endl;
}

