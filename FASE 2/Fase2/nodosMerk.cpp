#include "./nodosMerk.h"

//-------------------------------------------------------------------------------------------------
//NodoData
nodoData::nodoData(){
    uid = 0;
    valor = "";
    correo = "";
    contenido = "";
    fecha = "";
    hora = "";
    idpub = 0;
    sig = nullptr;
}

int nodoData::getUid(){
    return uid;
}

int nodoData::getIdPub(){
    return idpub;
}

std::string nodoData::getCorreoMerk(){
    return correo;
}
std::string nodoData::getContenidoMerk(){
    return contenido;
}

std::string nodoData::getFechaMerk(){
    return fecha;
}

std::string nodoData::getHoraMerk(){
    return hora;
}



nodoData* nodoData::getSig(){
    return sig;
}

void nodoData::setUid(int uid){
    this->uid = uid;
}



void nodoData::setSig(nodoData* sig){
    this->sig = sig;
}

void nodoData::setIdPub(int pub){
    this->idpub = pub;
}

void nodoData::setCorreoMerk(std::string correo){
    this->correo = correo;
}

void nodoData::setContenidoMerk(std::string conte){
    this->contenido = conte;
}

void nodoData::setHoraMerk(std::string hora){
    this->hora = hora;
}

void nodoData::setFechaMerk(std::string fecha){
    this->fecha = fecha;
}



//-------------------------------------------------------------------------------------------------
//NodoHash
nodoHash::nodoHash(){
    uid = 0;
    hash = "";
    drcha = nullptr;
    izq = nullptr;
    data = nullptr;
}

nodoHash::~nodoHash(){
    if(this->data != nullptr){
        delete this->data;
    }
}

int nodoHash::getUid(){
    return uid;
}

std::string nodoHash::getHash(){
    return hash;
}

nodoHash* nodoHash::getDrcha(){
    return drcha;
}

nodoHash* nodoHash::getIzq(){
    return izq;
}

nodoData* nodoHash::getData(){
    return data;
}

void nodoHash::setUid(int uid){
    this->uid = uid;
}

void nodoHash::setHash(std::string  hash){
    this->hash = hash;
}

void nodoHash::setIzq(nodoHash* izq){
    this->izq = izq;
}

void nodoHash::setDrcha(nodoHash* drcha){
    this->drcha = drcha;
}

void nodoHash::setData(nodoData*  data){
    this->data = data;
}
