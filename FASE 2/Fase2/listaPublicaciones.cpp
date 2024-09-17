#include "listaPublicaciones.h"
#include <QDebug>

nodoBST::nodoBST(string nom,string ape,string corr,string contr,string fechaNac){
    this->nombres = nom;
    this->apellidos = ape;
    this->correo = corr;
    this->contrasena = contr;
    this->fechaNacimiento = fechaNac;
    this->izquierda = nullptr;
    this->derecha = nullptr;
    this->miMatrizAmigos = new matriz();
    this->pilaSolicitudesRecibidas = new PilaSolicitudesRecibidas(); // Inicializar la pila
    this->listadeSolicitudesEnviadasUsuario = new ListaSolicitudesEnviadas(); //Inicializar la lista
    this->listadeSolicitudesRecibidasUsuario = new ListaSolicitudesRecibidas();
}

nodoBST::nodoBST(){
    nombres = "";
    apellidos = "";
    correo = "";
    contrasena = "";
    fechaNacimiento = "";
    derecha = nullptr;
    izquierda = nullptr;
}

string nodoBST::getNombres(){
    return nombres;
}
string nodoBST::getApellidos(){
    return apellidos;
}
string nodoBST::getContrasena(){
    return contrasena;
}
string nodoBST::getCorreo(){
    return correo;
}
string nodoBST::getFechaNacimiento(){
    return fechaNacimiento;
}
nodoBST* nodoBST::getDerecha(){
    return derecha;
}
nodoBST* nodoBST::getIzquierda(){
    return izquierda;
}
void nodoBST::setDerecha(nodoBST* der){
    this->derecha = der;
}
void nodoBST::setIzquierda(nodoBST* izq){
    this->izquierda = izq;
}

PilaSolicitudesRecibidas* nodoBST::getPilaSolicitudesRecibidas() {
    return this->pilaSolicitudesRecibidas;
}
ListaSolicitudesEnviadas* nodoBST::getListaDeSolicitudesEnviadas(){
    return this->listadeSolicitudesEnviadasUsuario;
}

matriz* nodoBST::getMimatrizAmigos(){
    return this->miMatrizAmigos;
}
ListaSolicitudesRecibidas* nodoBST::getListaSolicitudesRecibidas(){
    return this->listadeSolicitudesRecibidasUsuario;
}


//----------------------------------------------------------------------------------------------

listaEnlazadaBST::listaEnlazadaBST(){
    this->raiz = nullptr;
}

listaEnlazadaBST::~listaEnlazadaBST(){
    postOrden(this->raiz,1);
}


void listaEnlazadaBST::agregarUsuario(string n, string a, string c, string pwd, string fNac){
    this->raiz = agregarUsuario(this->raiz,n,a,c,pwd,fNac);
}

nodoBST* listaEnlazadaBST::agregarUsuario(nodoBST* raiz,string n, string a, string c, string pwd, string fNac){
    if(raiz == nullptr){raiz = new nodoBST(n,a,c,pwd,fNac);}
    else if(c < raiz->getCorreo()){raiz->setIzquierda(agregarUsuario(raiz->getIzquierda(),n,a,c,pwd,fNac));}
    else if(c > raiz->getCorreo()){raiz->setDerecha(agregarUsuario(raiz->getDerecha(),n,a,c,pwd,fNac));}
    return raiz;
}

void listaEnlazadaBST::postOrden(){
    postOrden(this->raiz,0);
}

void listaEnlazadaBST::postOrden(nodoBST *raiz, bool estado){
    if(raiz != nullptr){
        postOrden(raiz->getIzquierda(), estado);
        postOrden(raiz->getDerecha(), estado);
        if(!estado){
            qDebug() << QString::fromStdString(raiz->getCorreo());

        }else{delete raiz;}
    }
}

bool listaEnlazadaBST::verificarCorreoArb(string correo){
    return verificarCorreoArb(this->raiz,correo);
}
bool listaEnlazadaBST::verificarCorreoArb(nodoBST* raiz, string correo){
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

int listaEnlazadaBST::iniciodeSesionArb(string contra,string correo){
    if (contra == "EDD2S2024" && correo == "admin@gmail.com") {
        cout << "Inicio de Sesion Exitosa! " << endl;
        cout << "Bienvenido: Admin" << endl;
        return 1;
    }
    return iniciodeSesionArb(this->raiz, contra,correo); //buscamos en nuestro arbol
}
int listaEnlazadaBST::iniciodeSesionArb(nodoBST* raiz,string contra,string correo){

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

nodoBST* listaEnlazadaBST::buscarNodoPorCorreoArb(string correo){
    return buscarNodoPorCorreoArb(this->raiz,correo);
}

nodoBST* listaEnlazadaBST::buscarNodoPorCorreoArb(nodoBST* raiz,string correo){
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

string listaEnlazadaBST::buscarNombreArb(string correo){
    return buscarNombreArb(this->raiz,correo);
}

string listaEnlazadaBST::buscarNombreArb(nodoBST* raiz,string correo){
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

nodoBST* listaEnlazadaBST::getRaiz() {
    return raiz;
}

