#include "listaEnlazadaArbol.h"
#include <QDebug>




nodoArbol::nodoArbol(string nom,string ape,string corr,string contr,string fechaNac){
    this->nombres = nom;
    this->apellidos = ape;
    this->correo = corr;
    this->contrasena = contr;
    this->fechaNacimiento = fechaNac;
    this->izquierda = nullptr;
    this->derecha = nullptr;
    this->altura = 1;
    this->pilaSolicitudesRecibidas = new PilaSolicitudesRecibidas(); // Inicializar la pila
    this->listadeSolicitudesEnviadasUsuario = new ListaSolicitudesEnviadas(); //Inicializar la lista
    this->listaPublicacionesU = new listaPublicaciones();
    this->listaAmigos = new listaAmistad();
    this->ArbolPublicacionesBST = new ArbolBST();

    this->listaTodasPubs = new listaNodoPub();
}



nodoArbol::nodoArbol(){
    nombres = "";
    apellidos = "";
    correo = "";
    contrasena = "";
    fechaNacimiento = "";
    derecha = nullptr;
    izquierda = nullptr;
}

listaNodoPub* nodoArbol::getListaTodasPubs(){
    return this->listaTodasPubs;
}
int nodoArbol::getAltura(){
    return altura;
}

void nodoArbol::setAltura(int altura){
    this->altura = altura;
}

string nodoArbol::getNombres(){
    return nombres;
}
string nodoArbol::getApellidos(){
    return apellidos;
}
string nodoArbol::getContrasena(){
    return contrasena;
}
string nodoArbol::getCorreo(){
    return correo;
}
string nodoArbol::getFechaNacimiento(){
    return fechaNacimiento;
}
nodoArbol* nodoArbol::getDerecha(){
    return derecha;
}
nodoArbol* nodoArbol::getIzquierda(){
    return izquierda;
}
void nodoArbol::setDerecha(nodoArbol* der){
    this->derecha = der;
}
void nodoArbol::setIzquierda(nodoArbol* izq){
    this->izquierda = izq;
}

PilaSolicitudesRecibidas* nodoArbol::getPilaSolicitudesRecibidas() {
    return this->pilaSolicitudesRecibidas;
}
ListaSolicitudesEnviadas* nodoArbol::getListaDeSolicitudesEnviadas(){
    return this->listadeSolicitudesEnviadasUsuario;
}

ArbolBST* nodoArbol::getArbolPublicacionesBST(){
    return this->ArbolPublicacionesBST;
}



listaAmistad* nodoArbol::getListaAmigos(){
    return this->listaAmigos;
}
listaPublicaciones* nodoArbol::getListapublicaionesU(){
    return this->listaPublicacionesU;
}


void nodoArbol::setNombres(string nombres) {
    this->nombres = nombres;
}

void nodoArbol::setApellidos(string apellidos) {
    this->apellidos = apellidos;
}

void nodoArbol::setCorreo(string correo) {
    this->correo = correo;
}

void nodoArbol::setContrasena(string contrasena) {
    this->contrasena = contrasena;
}

void nodoArbol::setFechaNacimiento(string fechaNacimiento) {
    this->fechaNacimiento = fechaNacimiento;
}


nodoArbol::~nodoArbol() {
    delete pilaSolicitudesRecibidas;  // Libera la pila de solicitudes recibidas
    delete listadeSolicitudesEnviadasUsuario;  // Libera la lista de solicitudes enviadas
    delete listaPublicacionesU;  // Libera la lista de publicaciones
    delete listaAmigos;  // Libera la lista de amigos
    delete ArbolPublicacionesBST;
    delete listaTodasPubs;
}


//----------------------------------------------------------------------------------------------

listaEnlazadaArb::listaEnlazadaArb(){
    this->raiz = nullptr;
}

listaEnlazadaArb::~listaEnlazadaArb(){
    postOrden(this->raiz,1);
}


void listaEnlazadaArb::agregarUsuario(string n, string a, string c, string pwd, string fNac){
    this->raiz = agregarUsuario(this->raiz,n,a,c,pwd,fNac);
}

nodoArbol* listaEnlazadaArb::agregarUsuario(nodoArbol* raiz,string n, string a, string c, string pwd, string fNac){
    if(raiz == nullptr){raiz = new nodoArbol(n,a,c,pwd,fNac);}
    else if(c < raiz->getCorreo()){raiz->setIzquierda(agregarUsuario(raiz->getIzquierda(),n,a,c,pwd,fNac));}
    else if(c > raiz->getCorreo()){raiz->setDerecha(agregarUsuario(raiz->getDerecha(),n,a,c,pwd,fNac));}

    raiz->setAltura(alturaMaxima(obtenerAltura(raiz->getIzquierda()), obtenerAltura(raiz->getDerecha())) + 1);

    if(obtenerBalance(raiz) > 1) {  // Desbalanceado a la derecha
        if(obtenerBalance(raiz->getDerecha()) < 0) {
            raiz->setDerecha(rotacionDerecha(raiz->getDerecha())); // Rotación derecha del subárbol derecho
        }
        raiz = rotacionIzquierda(raiz); // Rotación izquierda del nodo raíz
    }

    if(obtenerBalance(raiz) < -1) {  // Desbalanceado a la izquierda
        if(obtenerBalance(raiz->getIzquierda()) > 0) {
            raiz->setIzquierda(rotacionIzquierda(raiz->getIzquierda())); // Rotación izquierda del subárbol izquierdo
        }
        raiz = rotacionDerecha(raiz); // Rotación derecha del nodo raíz
    }

    return raiz;
}

void listaEnlazadaArb::postOrden(){
    postOrden(this->raiz,0);
}

void listaEnlazadaArb::postOrden(nodoArbol *raiz, bool estado){
    if(raiz != nullptr){
        postOrden(raiz->getIzquierda(), estado);
        postOrden(raiz->getDerecha(), estado);
        if(!estado){
            qDebug() << QString::fromStdString(raiz->getCorreo());

        }else{delete raiz;}
    }
}

bool listaEnlazadaArb::verificarCorreoArb(string correo){
    return verificarCorreoArb(this->raiz,correo);
}
bool listaEnlazadaArb::verificarCorreoArb(nodoArbol* raiz, string correo){
    if(raiz == nullptr){
        return true; //no existe el correo
    }

    if(raiz->getCorreo() == correo){
        return false; // si existe el correo y esta en la raiz
    }

    if(correo < raiz->getCorreo()){
        return verificarCorreoArb(raiz->getIzquierda(),correo);
    }

    if(correo > raiz->getCorreo()){
        return verificarCorreoArb(raiz->getDerecha(), correo);
    }

    return true;
}

int listaEnlazadaArb::iniciodeSesionArb(string contra,string correo){
    if (contra == "EDD2S2024" && correo == "admin@gmail.com") {
        cout << "Inicio de Sesion Exitosa! " << endl;
        cout << "Bienvenido: Admin" << endl;
        return 1;
    }
    return iniciodeSesionArb(this->raiz, contra,correo); //buscamos en nuestro arbol
}
int listaEnlazadaArb::iniciodeSesionArb(nodoArbol* raiz,string contra,string correo){

    if(raiz == nullptr){
        return 0;
    }

    if(raiz->getCorreo() == correo){
        if(raiz->getContrasena() == contra){
            //aqui se pone en el label el nombre
            return 2;
        }else{
            return 0;
        }
    }

    if(correo < raiz->getCorreo()){
        return iniciodeSesionArb(raiz->getIzquierda(),contra,correo);
    }

    if(correo > raiz->getCorreo()){
        return iniciodeSesionArb(raiz->getDerecha(),contra,correo);
    }

    return 0;

}

nodoArbol* listaEnlazadaArb::buscarNodoPorCorreoArb(string correo){
    return buscarNodoPorCorreoArb(this->raiz,correo);
}

nodoArbol* listaEnlazadaArb::buscarNodoPorCorreoArb(nodoArbol* raiz,string correo){
    if (raiz == nullptr) {
        return nullptr;
    }
    if (raiz->getCorreo() == correo) {
        return raiz;
    }
    if (correo < raiz->getCorreo()) {
        return buscarNodoPorCorreoArb(raiz->getIzquierda(), correo);
    }
    if(correo > raiz->getCorreo()){
        return buscarNodoPorCorreoArb(raiz->getDerecha(),correo);
    }

    return nullptr;

}

string listaEnlazadaArb::buscarNombreArb(string correo){
    return buscarNombreArb(this->raiz,correo);
}

string listaEnlazadaArb::buscarNombreArb(nodoArbol* raiz,string correo){
    if(raiz == nullptr){
        return "";
    }
    if(raiz->getCorreo() == correo){
        return raiz->getNombres() +" "+raiz->getApellidos();
    }

    if (correo < raiz->getCorreo()) {
        return buscarNombreArb(raiz->getIzquierda(), correo);
    }
    if(correo > raiz->getCorreo()){
        return buscarNombreArb(raiz->getDerecha(),correo);
    }

    return "";

}

nodoArbol* listaEnlazadaArb::getRaiz() {
    return raiz;
}

void listaEnlazadaArb::preOrden(){
    preOrden(this->raiz);
}

void listaEnlazadaArb::inOrden(){
    inOrden(this->raiz);
}

void listaEnlazadaArb::graph(){
    std::ofstream outfile ("AVL.dot");
    outfile << "digraph G {" << std::endl;

    if(raiz != nullptr){
        graph(this->raiz, outfile);
    }

    outfile << "}" << std::endl;
    outfile.close();

    int returnCode = system("dot -Tpng ./AVL.dot -o ./AVL.png");

    if(returnCode == 0){std::cout << "Command executed successfully." << std::endl; }
    else{std::cout << "Command execution failed or returned non-zero: " << returnCode << std::endl;}
}

void listaEnlazadaArb::graph(nodoArbol *raiz, std::ofstream &f){
    if(raiz != nullptr){
        std::stringstream oss;
        oss << raiz;
        std::string nombre = oss.str();

        f << "Nodo" + nombre + "[label = \"" + raiz->getCorreo() + "\"]" << std::endl;

        if(raiz->getIzquierda() != nullptr){
            oss.str("");
            oss << raiz->getIzquierda();
            std::string izquierda = oss.str();
            f << "Nodo" << nombre + "->Nodo" + izquierda << std::endl;

        }

        if(raiz->getDerecha() != nullptr){
            oss.str("");
            oss << raiz->getDerecha();
            std::string derecha = oss.str();
            f << "Nodo" << nombre + "->Nodo" + derecha << std::endl;

        }

        this->graph(raiz->getIzquierda(), f);
        this->graph(raiz->getDerecha(), f);
    }
}


void listaEnlazadaArb::preOrden(nodoArbol *raiz){
    if(raiz != nullptr){
        std::cout << raiz->getCorreo() << ", ";
        preOrden(raiz->getIzquierda());
        preOrden(raiz->getDerecha());
    }
}

void listaEnlazadaArb::inOrden(nodoArbol *raiz){
    if(raiz != nullptr){
        preOrden(raiz->getIzquierda());
        std::cout << raiz->getCorreo() << ", ";
        preOrden(raiz->getDerecha());
    }
}



nodoArbol* listaEnlazadaArb::rotacionIzquierda(nodoArbol *raiz){
    nodoArbol *raizDerecha = raiz->getDerecha();
    nodoArbol *temp = raizDerecha->getIzquierda();

    raizDerecha->setIzquierda(raiz);
    raiz->setDerecha(temp);

    raiz->setAltura(alturaMaxima(obtenerAltura(raiz->getIzquierda()), obtenerAltura(raiz->getDerecha())) + 1);
    raizDerecha->setAltura(alturaMaxima(obtenerAltura(raizDerecha->getIzquierda()), obtenerAltura(raizDerecha->getDerecha())) + 1);

    return raizDerecha;
}

nodoArbol* listaEnlazadaArb::rotacionDerecha(nodoArbol *raiz){
    nodoArbol *raizIzquierda = raiz->getIzquierda();
    nodoArbol *temp = raizIzquierda->getDerecha();

    raizIzquierda->setDerecha(raiz);
    raiz->setIzquierda(temp);

    raiz->setAltura(alturaMaxima(obtenerAltura(raiz->getIzquierda()), obtenerAltura(raiz->getDerecha())) + 1);
    raizIzquierda->setAltura(alturaMaxima(obtenerAltura(raizIzquierda->getIzquierda()), obtenerAltura(raizIzquierda->getDerecha())) + 1);

    return raizIzquierda;
}

int listaEnlazadaArb::obtenerAltura(nodoArbol *raiz){
    if(raiz == nullptr) return 0;
    return raiz->getAltura();
}

int listaEnlazadaArb::alturaMaxima(int izq, int drcha){
    if(izq >= drcha) return izq;
    return drcha;
}

int listaEnlazadaArb::obtenerBalance(nodoArbol *raiz){
    return obtenerAltura(raiz->getDerecha()) - obtenerAltura(raiz->getIzquierda());
}


void listaEnlazadaArb::actualizarArbol(string correo, bool decision){
    //se actualiza el arbol al eliminar o modificar datos
    // 1 para modificar y 0 para eliminar
}


nodoArbol* listaEnlazadaArb::eliminarUsuario(string correo) {
    this->raiz = eliminarUsuario(this->raiz, correo);
    return this->raiz;
}

nodoArbol* listaEnlazadaArb::eliminarUsuario(nodoArbol *raiz, string correo) {
    if (raiz == nullptr) {
        return raiz;  // El nodo no existe
    }

    // Buscar el nodo a eliminar
    if (correo < raiz->getCorreo()) {
        raiz->setIzquierda(eliminarUsuario(raiz->getIzquierda(), correo));
    } else if (correo > raiz->getCorreo()) {
        raiz->setDerecha(eliminarUsuario(raiz->getDerecha(), correo));
    } else {
        // Nodo encontrado

        // Caso 1: Nodo sin hijos
        if (raiz->getIzquierda() == nullptr && raiz->getDerecha() == nullptr) {
            delete raiz;
            return nullptr;
        }

        // Caso 2: Nodo con un solo hijo
        if (raiz->getIzquierda() == nullptr) {
            nodoArbol *temp = raiz->getDerecha();
            delete raiz;
            return temp;
        } else if (raiz->getDerecha() == nullptr) {
            nodoArbol *temp = raiz->getIzquierda();
            delete raiz;
            return temp;
        }

        // Caso 3: Nodo con dos hijos
        nodoArbol *temp = obtenerMinimo(raiz->getDerecha());  // Sucesor inorden
        raiz->setCorreo(temp->getCorreo());
        raiz->setContrasena(temp->getContrasena());
        raiz->setNombres(temp->getNombres());
        raiz->setApellidos(temp->getApellidos());
        raiz->setFechaNacimiento(temp->getFechaNacimiento());

        // Eliminar el sucesor
        raiz->setDerecha(eliminarUsuario(raiz->getDerecha(), temp->getCorreo()));
    }

    //DE ARRIBA PARA QUI ES PARA UN AVL Y UN BST
    //DE AQUI HACIA ABAJO ES LO ADICIONAL QUE DIFIERE DE LA ELIMINACION DE NODO DE UN AVL Y UN BST

    // Actualizar la altura del nodo actual
    raiz->setAltura(alturaMaxima(obtenerAltura(raiz->getIzquierda()), obtenerAltura(raiz->getDerecha())) + 1);

    // Verificar el balance del nodo
    int balance = obtenerBalance(raiz);

    // Caso de desbalance hacia la izquierda
    if (balance < -1) {
        if (obtenerBalance(raiz->getIzquierda()) > 0) {
            raiz->setIzquierda(rotacionIzquierda(raiz->getIzquierda()));
        }
        return rotacionDerecha(raiz);
    }

    // Caso de desbalance hacia la derecha
    if (balance > 1) {
        if (obtenerBalance(raiz->getDerecha()) < 0) {
            raiz->setDerecha(rotacionDerecha(raiz->getDerecha()));
        }
        return rotacionIzquierda(raiz);
    }

    return raiz;
}

nodoArbol* listaEnlazadaArb::obtenerMinimo(nodoArbol *raiz) {
    while (raiz->getIzquierda() != nullptr) {
        raiz = raiz->getIzquierda();
    }
    return raiz;
}
