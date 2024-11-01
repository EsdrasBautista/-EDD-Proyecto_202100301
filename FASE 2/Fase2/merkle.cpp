#include "./merkle.h"
#include "./globalesV.h"
#include "./sha256.h"

merkle::merkle(){
    topHash = nullptr;
    primeroData = nullptr;
    ultimoData = nullptr;
    dot = "";
    pos = 0;
}

merkle::~merkle(){
    postOrder(this->topHash);
}

void merkle::agregar(std::string correo,std::string contenido,std::string fecha,std::string hora,int idpub){
    nodoData *nuevo = new nodoData();
    nuevo->setCorreoMerk(correo);
    nuevo->setContenidoMerk(contenido);
    nuevo->setFechaMerk(fecha);
    nuevo->setHoraMerk(hora);
    nuevo->setIdPub(idpub);

    nuevo->setUid(globalesV::uid);
    globalesV::uid++;

    if(primeroData == nullptr){
        primeroData = nuevo;
        ultimoData = nuevo;

    }else{
        ultimoData->setSig(nuevo);
        ultimoData = nuevo;
    }
}

void merkle::generar(){
    //std::string val = "-1";
    int expo = 1, i, pow;

    //Obtener un exponente X
    //tal que el resultado de 2^X sea mayor o igual que el largo de mi lista de data

    while(std::pow(2, expo) < this->largoListaData()){
        expo++;
    }

    pow = std::pow(2, expo);
    this->pos = pow;
    i = this->largoListaData();

    while(i < pow){
        this->agregar("","","","",-1);
        i++;
    }

    this->topHash = new nodoHash();
    this->crearArbol(this->topHash, expo);
    this->generarHash(this->topHash, pow);
}

void merkle::crearArbol(nodoHash* top, int expo){
    top->setUid(globalesV::uid);
    globalesV::uid++;

    if(expo > 0){
        top->setDrcha(new nodoHash());
        top->setIzq(new nodoHash());

        this->crearArbol(top->getIzq(), expo - 1);
        this->crearArbol(top->getDrcha(), expo - 1);
    }
}

void merkle::generarHash(nodoHash *top, int pow){
    if(top != nullptr){
        this->generarHash(top->getIzq(), pow);
        this->generarHash(top->getDrcha(), pow);

        if(top->getDrcha() == nullptr && top->getIzq() == nullptr){
            int temp = pow - this->pos;
            top->setData(this->obtenerData(temp));
            this->pos = this->pos - 1;
            std::string hash = top->getData()->getCorreoMerk();
            top->setHash(sha256(hash));

        }else{
            std::string hash = top->getIzq()->getHash() + top->getDrcha()->getHash();
            top->setHash(sha256(hash));
        }
    }
}

bool merkle::generarDot() {
    std::ofstream outfile("merkle.dot");

    if (!outfile.is_open()) {
        std::cout << "Error: No se pudo abrir el archivo merkle.dot." << std::endl;
        return false;  // Retorna false si no se pudo abrir el archivo
    }

    outfile << "graph {" << std::endl;
    this->generarDotRec(this->topHash, outfile);
    outfile << "}" << std::endl;
    outfile.close();

    int returnCode = system("dot -Tpng ./merkle.dot -o ./merkle.png");

    if (returnCode == 0) {
        std::cout << "El archivo PNG se generó correctamente." << std::endl;
        return true;  // Retorna true si el comando se ejecutó correctamente
    } else {
        std::cout << "Error: La ejecución del comando falló o devolvió un valor diferente de cero: " << returnCode << std::endl;
        return false;  // Retorna false si hubo un fallo en la ejecución del comando
    }
}


void merkle::generarDotRec(nodoHash *top, std::ofstream &f){
    if(top == nullptr) return;

    f << std::to_string(top->getUid()) + "[label = \"" + top->getHash() + "\"];" << std::endl;

    if(top->getIzq() != nullptr){
        f << std::to_string(top->getUid()) + " -- " + std::to_string(top->getIzq()->getUid()) + ";" << std::endl;
    }


    if(top->getDrcha() != nullptr){
        f << std::to_string(top->getUid()) + " -- " + std::to_string(top->getDrcha()->getUid()) + ";" << std::endl;
    }

    this->generarDotRec(top->getIzq(), f);
    this->generarDotRec(top->getDrcha(), f);

    if(top->getData() != nullptr){
        f << std::to_string(top->getData()->getUid()) + "[label = \"" + top->getData()->getCorreoMerk() + "\" shape=rect];" << std::endl;
        f << std::to_string(top->getUid()) + " -- " + std::to_string(top->getData()->getUid()) + ";" << std::endl;
    }
}


int merkle::largoListaData(){
    int len = 0;
    nodoData *aux = primeroData;

    while(aux != nullptr){
        len++;
        aux = aux->getSig();
    }
    return len;
}

nodoData* merkle::obtenerData(int pos){
    nodoData *aux = this->primeroData;

    while(aux != nullptr){
        if(pos == 0) return aux;
        pos = pos - 1;
        aux = aux->getSig();
    }
    return aux;
}

void merkle::postOrder(nodoHash *top){
    if(top != nullptr){
        postOrder(top->getIzq());
        postOrder(top->getDrcha());
        delete top;
    }
}
