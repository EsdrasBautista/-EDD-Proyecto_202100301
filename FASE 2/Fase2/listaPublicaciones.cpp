#include "listaPublicaciones.h"
#include <QDebug>

nodoBST::nodoBST(string fecha){
    this->fecha = fecha;
    this->izq = nullptr;
    this->drcha = nullptr;
    this->publicacionesBST = new listaNodoPub();
}

nodoBST::nodoBST(){
    fecha = "";
    izq = nullptr;
    drcha = nullptr;
}



void nodoBST::setDrcha(nodoBST *der){
    this->drcha = der;
}
void nodoBST::setgetIzq(nodoBST *izq){
    this->izq = izq;
}

nodoBST* nodoBST::getDrcha(){
    return drcha;
}

nodoBST* nodoBST::getIzq(){
    return izq;
}

string nodoBST::getfecha(){
    return fecha;
}

listaNodoPub* nodoBST::getPublicacionesBST(){
    return this->publicacionesBST;
}

//------------------------------------------------------------------------------------------



ArbolBST::ArbolBST(){
    this->raiz = nullptr;
}


ArbolBST::~ArbolBST(){
    postOrden(this->raiz,1);
}


void ArbolBST::agregarPublicacionBST(string correo,string contenido,string fecha,string hora,string imagen,int id){
    this->raiz = agregarPublicacionBST(this->raiz,correo,contenido,fecha,hora,imagen,id);
}

nodoBST* ArbolBST::agregarPublicacionBST(nodoBST* raiz,string correo,string contenido,string fecha,string hora,string imagen,int id){

    if(raiz == nullptr){
        raiz = new nodoBST(fecha);
        raiz->getPublicacionesBST()->agregarPublicacionL(fecha,correo, contenido, hora,imagen,id);
        raiz->getPublicacionesBST()->mostrarPublicacionesL();
    }
    else if(compararFechas(fecha, raiz->getfecha())){
        raiz->setgetIzq(agregarPublicacionBST(raiz->getIzq(),correo,contenido,fecha,hora,imagen,id));
    }
    else if(compararFechas(raiz->getfecha(), fecha)){
        raiz->setDrcha(agregarPublicacionBST(raiz->getDrcha(),correo,contenido,fecha,hora,imagen,id));
    }else{
        // Si la fecha es igual, agregar la publicación en la lista del nodo existente
        raiz->getPublicacionesBST()->agregarPublicacionL(fecha,correo, contenido, hora,imagen,id);
        raiz->getPublicacionesBST()->mostrarPublicacionesL();
    }
    return raiz;
}



void ArbolBST::postOrden(){
    return postOrden(this->raiz,0);
}

void ArbolBST::postOrden(nodoBST *raiz, bool estado){
    if(raiz != nullptr){
        postOrden(raiz->getIzq(), estado);
        postOrden(raiz->getDrcha(), estado);
        if(!estado){
            qDebug() << QString::fromStdString(raiz->getfecha());
        }else{
            delete raiz;
        }
    }
}



void ArbolBST::preOrden(){
    preOrden(this->raiz);
}

void ArbolBST::inOrden(){
    inOrden(this->raiz);
}

void ArbolBST::preOrden(nodoBST *raiz){
    if(raiz != nullptr){
        std::cout << raiz->getfecha() << ", ";
        preOrden(raiz->getIzq());
        preOrden(raiz->getDrcha());
    }
}

void ArbolBST::inOrden(nodoBST *raiz){
    if(raiz != nullptr){
        preOrden(raiz->getIzq());
        std::cout << raiz->getfecha() << ", ";
        preOrden(raiz->getDrcha());
    }
}

nodoBST* ArbolBST::getRaiz() {
    return raiz;
}

bool ArbolBST::verificarexisteFecha(int contador, string fecha, string correo){
    return verificarexisteFecha(this->raiz,contador,fecha,correo);
}
bool ArbolBST::verificarexisteFecha(nodoBST *raiz, int contador, string fecha, string correo){
    if (raiz == nullptr) {
        return false;
    }

    // Verifica en la lista de publicaciones del nodo actual
    nodoSimplePub* actual = raiz->getPublicacionesBST()->getCabeza();
    while (actual != nullptr) {
        if (actual->getIdL() == contador && actual->getFechaL() == fecha && actual->getCorreoL() == correo) {
            return true;
        }
        actual = actual->getSiguiente();  // Avanza en la lista de publicaciones
    }

    if (verificarexisteFecha(raiz->getIzq(), contador, fecha, correo)) {
        return true;
    }
    if (verificarexisteFecha(raiz->getDrcha(), contador, fecha, correo)) {
        return true;
    }

    return false;
}


nodoBST* ArbolBST::buscarNodoporFecha(string fecha){
    return buscarNodoporFecha(this->raiz,fecha);
}

nodoBST* ArbolBST::buscarNodoporFecha(nodoBST* raiz,string fecha){
    if (raiz == nullptr) {
        return nullptr;
    }
    if (raiz->getfecha() == fecha) {
        return raiz;
    }
    if (compararFechas(fecha, raiz->getfecha())) {
        return buscarNodoporFecha(raiz->getIzq(), fecha);
    }
    if(compararFechas(raiz->getfecha(), fecha)){
        return buscarNodoporFecha(raiz->getDrcha(),fecha);
    }

    return nullptr;

}



nodoSimplePub* ArbolBST::Ordeninorden(int cantidadMaxima) {
    nodoSimplePub* cabeza = nullptr;
    nodoSimplePub* actual = nullptr;
    int contador = 0;
    Ordeninorden(this->raiz, cabeza, actual, contador, cantidadMaxima);
    return cabeza;
}

void ArbolBST::Ordeninorden(nodoBST *raiz, nodoSimplePub* &cabeza, nodoSimplePub* &actual, int &contador, int cantidadMaxima) {
    if (raiz != nullptr && contador < cantidadMaxima) {

        Ordeninorden(raiz->getIzq(), cabeza, actual, contador, cantidadMaxima);

        if(contador == cantidadMaxima){return;}

        listaNodoPub* publicaciones = raiz->getPublicacionesBST();  // Obtén la lista de publicaciones de la fecha
        if (publicaciones != nullptr) {
            nodoSimplePub* nodoPub = publicaciones->getCabeza();  // Empieza desde la cabeza de la lista de publicaciones
            while (nodoPub != nullptr && contador < cantidadMaxima) {

                nodoSimplePub* nuevoNodo = new nodoSimplePub(nodoPub->getFechaL(), nodoPub->getCorreoL(), nodoPub->getContenidoL(), nodoPub->getHoraL(), nodoPub->getImagen(), nodoPub->getIdL());

                if (cabeza == nullptr) {
                    cabeza = nuevoNodo;
                    actual = cabeza;
                } else {
                    actual->setSiguiente(nuevoNodo);
                    actual = nuevoNodo;
                }

                contador++;
                nodoPub = nodoPub->getSiguiente();
            }
        }

        Ordeninorden(raiz->getDrcha(), cabeza, actual, contador, cantidadMaxima);
    }
}



nodoSimplePub* ArbolBST::OrdenPreorden(int cantidadMaxima) {
    nodoSimplePub* cabeza = nullptr;
    nodoSimplePub* actual = nullptr;
    int contador = 0;
    OrdenPreorden(this->raiz, cabeza, actual, contador, cantidadMaxima);
    return cabeza;
}

void ArbolBST::OrdenPreorden(nodoBST *raiz, nodoSimplePub* &cabeza, nodoSimplePub* &actual, int &contador, int cantidadMaxima) {
    if (raiz != nullptr && contador < cantidadMaxima) {

        listaNodoPub* publicaciones = raiz->getPublicacionesBST();
        if (publicaciones != nullptr) {
            nodoSimplePub* nodoPub = publicaciones->getCabeza();
            while (nodoPub != nullptr && contador < cantidadMaxima) {
                nodoSimplePub* nuevoNodo = new nodoSimplePub(nodoPub->getFechaL(), nodoPub->getCorreoL(), nodoPub->getContenidoL(), nodoPub->getHoraL(), nodoPub->getImagen(), nodoPub->getIdL());

                if (cabeza == nullptr) {
                    cabeza = nuevoNodo;
                    actual = cabeza;
                } else {
                    actual->setSiguiente(nuevoNodo);
                    actual = nuevoNodo;
                }
                contador++;
                nodoPub = nodoPub->getSiguiente();
            }
        }

        OrdenPreorden(raiz->getIzq(), cabeza, actual, contador, cantidadMaxima);
        OrdenPreorden(raiz->getDrcha(), cabeza, actual, contador, cantidadMaxima);
    }
}

nodoSimplePub* ArbolBST::OrdenPostorden(int cantidadMaxima) {
    nodoSimplePub* cabeza = nullptr;
    nodoSimplePub* actual = nullptr;
    int contador = 0;
    OrdenPostorden(this->raiz, cabeza, actual, contador, cantidadMaxima);
    return cabeza;
}

void ArbolBST::OrdenPostorden(nodoBST *raiz, nodoSimplePub* &cabeza, nodoSimplePub* &actual, int &contador, int cantidadMaxima) {
    if (raiz != nullptr && contador < cantidadMaxima) {

        OrdenPostorden(raiz->getIzq(), cabeza, actual, contador, cantidadMaxima);
        OrdenPostorden(raiz->getDrcha(), cabeza, actual, contador, cantidadMaxima);


        listaNodoPub* publicaciones = raiz->getPublicacionesBST();
        if (publicaciones != nullptr) {
            nodoSimplePub* nodoPub = publicaciones->getCabeza();
            while (nodoPub != nullptr && contador < cantidadMaxima) {
                nodoSimplePub* nuevoNodo = new nodoSimplePub(nodoPub->getFechaL(), nodoPub->getCorreoL(), nodoPub->getContenidoL(), nodoPub->getHoraL(), nodoPub->getImagen(), nodoPub->getIdL());

                if (cabeza == nullptr) {
                    cabeza = nuevoNodo;
                    actual = cabeza;
                } else {
                    actual->setSiguiente(nuevoNodo);
                    actual = nuevoNodo;
                }
                contador++;
                nodoPub = nodoPub->getSiguiente();
            }
        }
    }
}

nodoBST* ArbolBST::graficarNodoporFecha(string fecha){
    std::ofstream outfile("AVLFecha.dot");
    outfile << "digraph G {" << std::endl;

    // Buscar el nodo con la fecha proporcionada
    nodoBST* nodoInicio = buscarNodoporFecha(fecha);
    if (nodoInicio != nullptr) {
        graficarNodoporFecha(nodoInicio, outfile);
    } else {
        std::cout << "No se encontró un nodo con la fecha especificada." << std::endl;
    }

    outfile << "}" << std::endl;
    outfile.close();

    int returnCode = system("dot -Tpng ./AVLFecha.dot -o ./AVLFecha.png");
    if (returnCode == 0) {
        std::cout << "Comando ejecutado con éxito." << std::endl;
    } else {
        std::cout << "Error al ejecutar el comando: " << returnCode << std::endl;
    }

    return nodoInicio;
}

void ArbolBST::graficarNodoporFecha(nodoBST *raiz, ofstream &f){
    if(raiz != nullptr){
        std::stringstream oss;
        oss << raiz;
        std::string nombre = oss.str();

        // Graficar el nodo del árbol BST (fecha)
        f << "Nodo" + nombre + "[label = \"" + raiz->getfecha() + "\"]" << std::endl;


        // Graficar el hijo izquierdo si existe
        if(raiz->getIzq() != nullptr){
            oss.str("");
            oss << raiz->getIzq();
            std::string izquierda = oss.str();
            f << "Nodo" << nombre + "->Nodo" + izquierda << std::endl;
        }

        // Graficar el hijo derecho si existe
        if(raiz->getDrcha() != nullptr){
            oss.str("");
            oss << raiz->getDrcha();
            std::string derecha = oss.str();
            f << "Nodo" << nombre + "->Nodo" + derecha << std::endl;
        }

        // Graficar la lista doblemente enlazada de publicaciones asociada al nodo
        if(raiz->getPublicacionesBST() != nullptr){
            graficarListaPublicaciones(raiz->getPublicacionesBST(), f, nombre);
        }

        // Recursión para graficar subárbol izquierdo y derecho
        this->graficarNodoporFecha(raiz->getIzq(), f);
        this->graficarNodoporFecha(raiz->getDrcha(), f);
    }
}

void ArbolBST::graficarListaPublicaciones(listaNodoPub* lista, ofstream &f, const std::string &nombreNodoBST) {
    if (lista == nullptr || lista->getCabeza() == nullptr) {
        return;
    }

    nodoSimplePub* actual = lista->getCabeza();
    std::string nodoAnterior = "";
    std::string nodoPublicacion;

    // Subgrafo para la lista doblemente enlazada
    f << "subgraph cluster_" << nombreNodoBST << " {" << std::endl;
    f << "label = \"Publicaciones\";" << std::endl;

    while (actual != nullptr) {
        std::stringstream oss;
        oss << actual;
        nodoPublicacion = "Pub" + oss.str();

        // Graficar el nodo de la publicación
        f << nodoPublicacion + "[label = \"ID: " + std::to_string(actual->getIdL()) + "\\nCorreo: " + actual->getCorreoL() + "\\nContenido: " + actual->getContenidoL() + "\"];" << std::endl;

        // Conectar con el nodo anterior (lista doblemente enlazada)
        if (!nodoAnterior.empty()) {
            f << nodoAnterior + "->" + nodoPublicacion << " [dir=both];" << std::endl;  // Doble enlace
        }

        nodoAnterior = nodoPublicacion;
        actual = actual->getSiguiente();
    }

    f << "}" << std::endl;

    // Conectar el nodo del árbol con la cabeza de la lista de publicaciones
    nodoSimplePub* cabeza = lista->getCabeza();
    if (cabeza != nullptr) {
        std::stringstream oss;
        oss << cabeza;
        std::string nodoCabeza = "Pub" + oss.str();
        f << "Nodo" << nombreNodoBST + "->" + nodoCabeza << std::endl;
    }
}
