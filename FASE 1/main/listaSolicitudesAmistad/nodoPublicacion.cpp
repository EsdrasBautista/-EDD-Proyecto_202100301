#include "nodoPublicacion.h"


NodoPub::NodoPub(){
    correo = "";
    contenido = "";
    fecha = "";
    hora = "";
    contador = 0;
    sig = nullptr;
    prev = nullptr;
}
NodoPub::NodoPub(string correo,string contenido,string fecha,string hora, int contador){
    this->correo = correo;
    this->contenido = contenido;
    this->fecha = fecha;
    this->hora = hora;
    this->contador = contador;
    this->sig = nullptr;
    this->prev = nullptr;
}

void NodoPub::setSigPubl(NodoPub *sig){
    this->sig = sig;
}
void NodoPub::setPrevPub(NodoPub *prev){
    this->prev = prev;
}

NodoPub* NodoPub::getPrevPub(){
    return prev;
}

NodoPub* NodoPub::getSigPub(){
    return sig;
}

string NodoPub::getcontenido(){
    return contenido;
}

string NodoPub::getCorreo(){
    return correo;
}

string NodoPub::getfecha(){
    return fecha;
}

string NodoPub::gethora(){
    return hora;
}

int NodoPub::getcontadorPublicaciones(){
    return contador;
}

void NodoPub::setContador(int contador){
    this->contador = contador +1;
}
//-------------------------------------------

listaPublicaciones::listaPublicaciones(){
    primero = nullptr;
    ultimo = nullptr;
    contPublica = 0;
}

listaPublicaciones::~listaPublicaciones(){
    NodoPub *temp = primero;
    NodoPub *aux;

    while(temp != nullptr){
        aux = temp->getSigPub();
        delete temp;
        temp = aux;
    }
}

void listaPublicaciones::agregarPub(string correo,string contenido,string fecha,string hora){
    contPublica ++;

    NodoPub *nuevoNodo = new NodoPub(correo,contenido,fecha,hora,contPublica);
    if(primero == nullptr){
        primero = nuevoNodo;
        ultimo = nuevoNodo;
    }else{
        nuevoNodo->setPrevPub(ultimo);
        ultimo->setSigPubl(nuevoNodo);
        ultimo = nuevoNodo;
    }
    

}


void listaPublicaciones::verMisPublicaciones(string correo) {
    NodoPub *temp = primero;

    if(temp == nullptr){
        cout << "No hay publicaciones aun!" << endl;
    }else{

        while (temp != nullptr) {
            if (temp->getCorreo() == correo) {
                // Mostrar la publicación actual
                cout << endl;
                cout << "Correo: " << temp->getCorreo() << endl;
                cout << "Contenido: " << temp->getcontenido() << endl;
                cout << "Fecha: " << temp->getfecha() << endl;
                cout << "Hora: " << temp->gethora() << endl;
            }

            // Mostrar mensaje
            cout << "izquierda (<-) para Anterior, derecha (->) para Siguiente, o ESC para salir." << endl;


            int tecla = _getch(); // Captura la tecla
            if (tecla == 0 || tecla == 224) { 
                tecla = _getch(); // Obtener el código real de la tecla especial
                if (tecla == 75) { // Flecha izquierda (código ASCII 75)
                    if (temp->getPrevPub() != nullptr) {
                        temp = temp->getPrevPub(); // Ir a la publicación anterior
                    } else {
                        cout << "No hay mas publicaciones anteriores." << endl;
                    }
                } else if (tecla == 77) { // Flecha derecha (código ASCII 77)
                    if (temp->getSigPub() != nullptr) {
                        temp = temp->getSigPub(); // Ir a la siguiente publicación
                    } else {
                        cout << "No hay mas publicaciones siguientes." << endl;
                    }
                }
            }else if (tecla == 27) { // Tecla ESC (código ASCII 27)
                break; // Salir de la visualización
            }
        }
        cout << endl;
        cout << "Fin de la visualizacion de publicaciones." << endl;
    }
}

NodoPub* listaPublicaciones::getPrimero(){
    
    NodoPub* actual = primero;

    if(actual == nullptr){
        return nullptr;
    }else{
        return actual;
    }

    
    
}

int listaPublicaciones::eliminarPublicacion(string correo) {
    NodoPub *temp = primero;
    string opcionE;
    int id;
    int tecla;

    if (temp == nullptr) {
        cout << "No hay publicaciones aún!" << endl;
        return -1;
    }

    while (true) {
        if (temp->getCorreo() == correo) {
            // Mostrar la publicación actual
            cout << endl;
            cout << "ID: " << temp->getcontadorPublicaciones() << endl;
            cout << "Correo: " << temp->getCorreo() << endl;
            cout << "Contenido: " << temp->getcontenido() << endl;
            cout << "Fecha: " << temp->getfecha() << endl;
            cout << "Hora: " << temp->gethora() << endl;


            cout << "Ingrese el ID de la publicacion que desea eliminar, o presione ESC para cancelar:" << endl;
            cout << "O izquierda (<-) para Anterior, derecha (->) para Siguiente." << endl;
            

            tecla = _getch(); // Captura la tecla

            if (tecla == 0 || tecla == 224) { 
                tecla = _getch(); 
                if (tecla == 75) { // Flecha izquierda (código ASCII 75)
                    if (temp->getPrevPub() != nullptr) {
                        temp = temp->getPrevPub(); 
                    } else {
                        cout << "No hay mas publicaciones anteriores." << endl;
                    }
                }else if (tecla == 77) { // Flecha derecha (código ASCII 77)
                    if (temp->getSigPub() != nullptr) {
                        temp = temp->getSigPub(); 
                    } else {
                        cout << "No hay mas publicaciones siguientes." << endl;
                    }
                }
            } else if (tecla == 27) { // Tecla ESC (código ASCII 27)
                cout << "Operacion cancelada." << endl;
                return -1; 
            } else if (isdigit(tecla)) {
                // Captura de un número completo
                opcionE.clear();
                opcionE += tecla;
                while (_kbhit()) { 
                    tecla = _getch();
                    if (isdigit(tecla)) {
                        opcionE += tecla;
                    } else {
                        break; 
                    }
                }

                // Convertir la cadena a número entero
                id = stoi(opcionE);
                
                if (id == temp->getcontadorPublicaciones()) {

                    if (temp->getPrevPub() != nullptr) {
                        temp->getPrevPub()->setSigPubl(temp->getSigPub());
                    } else {
                        primero = temp->getSigPub();
                    }

                    if (temp->getSigPub() != nullptr) {
                        temp->getSigPub()->setPrevPub(temp->getPrevPub());
                    } else {
                        ultimo = temp->getPrevPub();
                    }

                    NodoPub *toDelete = temp;
                    if (temp->getSigPub() != nullptr) {
                        temp = temp->getSigPub();
                    } else {
                        temp = temp->getPrevPub();
                    }
                    int id = toDelete->getcontadorPublicaciones();
                    delete toDelete; 

                    cout << "Publicacion eliminada con exito!" << endl;
                    return id; 
                } else {
                    cout << "ID no coincide con la publicacion actual." << endl;
                }
            }
        } else {
            if (temp->getSigPub() != nullptr) {
                temp = temp->getSigPub(); // Ir a la siguiente publicación si la actual no coincide
            } else {
                cout << "No se encontro la publicacion con el correo especificado." << endl;
                return -1;
            }
        }
    }
}