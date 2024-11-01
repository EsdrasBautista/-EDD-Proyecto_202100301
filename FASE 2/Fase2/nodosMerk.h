#ifndef NODOSMERK_H
#define NODOSMERK_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

class nodoData{
private:
    int uid;
    std::string valor;

    std::string correo;
    std::string contenido;
    std::string fecha;
    std::string hora;
    int idpub;

    nodoData *sig;

public:
    nodoData();

    int getUid();
    int getIdPub();
    std::string getCorreoMerk();
    std::string getContenidoMerk();
    std::string getFechaMerk();
    std::string getHoraMerk();
    nodoData* getSig();

    void setUid(int);
    void setIdPub(int);
    void setCorreoMerk(std::string);
    void setContenidoMerk(std::string);
    void setHoraMerk(std::string);
    void setFechaMerk(std::string);
    void setSig(nodoData*);
};


class nodoHash{
private:
    int uid;
    std::string hash;
    nodoHash *drcha;
    nodoHash *izq;
    nodoData *data;

public:
    nodoHash();
    ~nodoHash();

    int getUid();
    std::string getHash();
    nodoHash* getDrcha();
    nodoHash* getIzq();
    nodoData* getData();

    void setUid(int);
    void setHash(std::string);
    void setDrcha(nodoHash*);
    void setIzq(nodoHash*);
    void setData(nodoData*);
};


#endif
