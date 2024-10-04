#include "./nodoPublicacion.h"


NodoPub::NodoPub(){
    correo = "";
    contenido = "";
    fecha = "";
    hora = "";
    contador = 0;
    sig = nullptr;
    prev = nullptr;
    imagen = "";
}
NodoPub::NodoPub(string correo,string contenido,string fecha,string hora, int contador){
    this->correo = correo;
    this->contenido = contenido;
    this->fecha = fecha;
    this->hora = hora;
    this->contador = contador;
    this->sig = nullptr;
    this->prev = nullptr;
    this->imagen = "";
}


//constructor con imagen
NodoPub::NodoPub(string correo, string contenido, string fecha, string hora, int contador, string imagen){
    this->correo = correo;
    this->contenido = contenido;
    this->fecha = fecha;
    this->hora = hora;
    this->contador = contador;
    this->sig = nullptr;
    this->prev = nullptr;
    this->imagen = imagen;
}

void NodoPub::setImagen(string imagen){
    this->imagen = imagen;
}

string NodoPub::getImagen(){
    return imagen;
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

    primero = nullptr;
    ultimo = nullptr;
}

int listaPublicaciones::getContPublica(){
    return contPublica;
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


// Método agregar publicación con imagen
void listaPublicaciones::agregarPubConImagen(string correo, string contenido, string fecha, string hora, string imagen){
    contPublica++;

    NodoPub *nuevoNodo = new NodoPub(correo, contenido, fecha, hora, contPublica, imagen);
    if(primero == nullptr){
        primero = nuevoNodo;
        ultimo = nuevoNodo;
    } else {
        nuevoNodo->setPrevPub(ultimo);
        ultimo->setSigPubl(nuevoNodo);
        ultimo = nuevoNodo;
    }
}




//verMisPublicaciones para mostrar imagen si está disponible
void listaPublicaciones::verMisPublicaciones(string correo) {
    NodoPub *temp = primero;

    if(temp == nullptr){
        cout << "No hay publicaciones aún!" << endl;
    } else {
        while (temp != nullptr) {
            if (temp->getCorreo() == correo) {
                cout << endl;
                cout << "Correo: " << temp->getCorreo() << endl;
                cout << "Contenido: " << temp->getcontenido() << endl;
                cout << "Fecha: " << temp->getfecha() << endl;
                cout << "Hora: " << temp->gethora() << endl;

                // Mostrar la imagen si está disponible
                if (temp->getImagen() != "") {
                    cout << "Imagen: " << temp->getImagen() << endl;
                } else {
                    cout << "Imagen: No hay imagen disponible." << endl;
                }
            }

            // Navegación (sin cambios)
            cout << "Izquierda (<-) para Anterior, derecha (->) para Siguiente, o ESC para salir." << endl;

            int tecla = _getch();
            if (tecla == 0 || tecla == 224) {
                tecla = _getch();
                if (tecla == 75) {
                    if (temp->getPrevPub() != nullptr) {
                        temp = temp->getPrevPub();
                    } else {
                        cout << "No hay más publicaciones anteriores." << endl;
                    }
                } else if (tecla == 77) {
                    if (temp->getSigPub() != nullptr) {
                        temp = temp->getSigPub();
                    } else {
                        cout << "No hay más publicaciones siguientes." << endl;
                    }
                }
            } else if (tecla == 27) {
                break;
            }
        }
        cout << endl;
        cout << "Fin de la visualización de publicaciones." << endl;
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

void listaPublicaciones::eliminarTodaslasPublicaciones() {

    NodoPub* actual = primero;
    NodoPub* siguiente = nullptr;


    while (actual != nullptr) {
        siguiente = actual->getSigPub(); // Guardar el siguiente nodo
        delete actual;
        actual = siguiente;
    }


    primero = nullptr;
    ultimo = nullptr;

}

void listaPublicaciones::graficarListaP(){

        ofstream archivo("listaPublicacionesGeneral.dot");
        if(!archivo.is_open()){
            cout << "No se pudo crear el archivo" << endl;
            return;
        }

        archivo << "digraph G {" << endl;
        archivo << "    rankdir=LR;" << endl;
        archivo << "    node [shape=record];" << endl;

        NodoPub *nodoActual = primero;
        int contador = 1;

        while(nodoActual != nullptr) {
            archivo << "    nodo_" << contador << " [label=\"";
            archivo << "Correo: " << nodoActual->getCorreo() << "\\n";
            archivo << "Contenido: " << nodoActual->getcontenido() << "\\n";
            archivo << "Fecha: " << nodoActual->getfecha() << "\\n";
            archivo << "Hora: " << nodoActual->gethora() << "\\n";
            archivo << "\"];" << endl;

            if (nodoActual->getSigPub() != nullptr) {
                archivo << "    nodo_" << contador << " -> nodo_" << (contador + 1) << ";" << endl;
                archivo << "    nodo_" << (contador + 1) << " -> nodo_" << contador << ";" << endl;
            }

            nodoActual = nodoActual->getSigPub();
            contador++;
        }

        archivo << "}" << endl;
        archivo.close();

        stringstream nombreArchivo;
        nombreArchivo << "listaPublicacionesGeneral" << ".png";

        // Construir el comando Graphviz
        stringstream comando;
        comando << "dot -Tpng listaPublicacionesGeneral.dot -o " << nombreArchivo.str();

        // Ejecutar el comando
        system(comando.str().c_str());

        cout << "La lista de publicaciones ha sido graficada y guardada en " << nombreArchivo.str() << endl;

}


void listaPublicaciones::graficartop5() {
    if (primero == nullptr) {
        cout << "No hay publicaciones aún!" << endl;
        return;
    }

    NodoPub *temp = primero;
    NodoPub *top5 = nullptr;

    // Contar publicaciones por usuario
    while (temp != nullptr) {
        NodoPub *aux = top5;
        bool found = false;

        // Buscar si el usuario ya está en la lista top5
        while (aux != nullptr) {
            if (aux->getCorreo() == temp->getCorreo()) {
                aux->setContador(aux->getcontadorPublicaciones());
                found = true;
                break;
            }
            aux = aux->getSigPub();
        }

        // Si no se encontró el usuario en la lista top5, crear un nuevo nodo
        if (!found) {
            NodoPub *nuevo = new NodoPub(temp->getCorreo(), "", "", "", 1);

            // Inserción en lista ordenada por número de publicaciones (descendente)
            if (top5 == nullptr) {  // Lista vacía, insertar como primer nodo
                top5 = nuevo;
            } else {
                NodoPub *anterior = nullptr;
                aux = top5;

                while (aux != nullptr && aux->getcontadorPublicaciones() >= nuevo->getcontadorPublicaciones()) {
                    anterior = aux;
                    aux = aux->getSigPub();
                }

                if (anterior == nullptr) {  // Insertar al principio
                    nuevo->setSigPubl(top5);
                    top5 = nuevo;
                } else {  // Insertar en medio o al final
                    nuevo->setSigPubl(anterior->getSigPub());
                    anterior->setSigPubl(nuevo);
                }
            }
        }

        temp = temp->getSigPub();
    }

    // Graficar el top 5
    ofstream archivo("top5Publicaciones.dot");
    if (!archivo.is_open()) {
        cout << "No se pudo crear el archivo" << endl;
        return;
    }

    archivo << "digraph G {" << endl;
    archivo << "    rankdir=LR;" << endl;
    archivo << "    node [shape=record];" << endl;

    temp = top5;
    int contador = 1;

    while (temp != nullptr && contador <= 5) {
        archivo << "    nodo_" << contador << " [label=\"";
        archivo << "Usuario: " << temp->getCorreo() << "\\n";
        archivo << "Publicaciones: " << temp->getcontadorPublicaciones() << "\\n";
        archivo << "Fecha: " << temp->getfecha() << " \\n";
        archivo << "\"];" << endl;

        if (temp->getSigPub() != nullptr && contador < 5) {
            archivo << "    nodo_" << contador << " -> nodo_" << (contador + 1) << ";" << endl;
        }

        temp = temp->getSigPub();
        contador++;
    }

    archivo << "}" << endl;
    archivo.close();

    stringstream nombreArchivo;
    nombreArchivo << "top5Publicaciones.png";

    // Construir el comando Graphviz
    stringstream comando;
    comando << "dot -Tpng top5Publicaciones.dot -o " << nombreArchivo.str();

    // Ejecutar el comando
    system(comando.str().c_str());

    cout << "El top 5 de publicaciones ha sido graficado y guardado en " << nombreArchivo.str() << endl;

    // Liberar la lista auxiliar
    while (top5 != nullptr) {
        NodoPub *toDelete = top5;
        top5 = top5->getSigPub();
        delete toDelete;
    }
}

void listaPublicaciones::eliminarP(int id,string correo){
    if(primero == nullptr){
        cout << "No hay publicaciones aun!" << endl;
        return;
    }

    NodoPub *actual = primero;

    while(actual != nullptr){
        if(actual->getcontadorPublicaciones() == id && actual->getCorreo() == correo){

            if(actual == primero && actual == ultimo){
                delete actual;
                primero = nullptr;
                ultimo = nullptr;
            }else if(actual == primero){
                primero = actual->getSigPub();
                primero->setPrevPub(nullptr);
                delete actual;
            }else if(actual == ultimo){
                ultimo = actual->getPrevPub();
                ultimo->setSigPubl(nullptr);
                delete actual;
            }else{
                NodoPub *prev = actual->getPrevPub();
                NodoPub *sig = actual->getSigPub();
                prev->setSigPubl(sig);
                sig->setPrevPub(prev);
                delete actual;
            }

            return;

        }

        actual = actual->getSigPub();
    }



    cout << "No se encontró una publicación con el ID " << id << "." << endl;
}


void listaPublicaciones::eliminarP_porCorreo(string correo){
    if(primero == nullptr){

        return;
    }

    NodoPub* actual = primero;
    while(actual != nullptr){
        if(actual->getCorreo() == correo){
            NodoPub* nodoAEliminar = actual;
            actual = actual->getSigPub();

            if(nodoAEliminar == primero && nodoAEliminar == ultimo){

                primero = nullptr;
                ultimo = nullptr;
            } else if(nodoAEliminar == primero){
                // El nodo a eliminar es el primero
                primero = nodoAEliminar->getSigPub();
                if(primero != nullptr) {
                    primero->setPrevPub(nullptr);
                }
            } else if(nodoAEliminar == ultimo){
                // El nodo a eliminar es el último
                ultimo = nodoAEliminar->getPrevPub();
                if(ultimo != nullptr) {
                    ultimo->setSigPubl(nullptr);
                }
            } else {

                NodoPub* prev = nodoAEliminar->getPrevPub();
                NodoPub* sig = nodoAEliminar->getSigPub();
                prev->setSigPubl(sig);
                if(sig != nullptr) {
                    sig->setPrevPub(prev);
                }
            }

            delete nodoAEliminar;
        } else {

            actual = actual->getSigPub();
        }
    }


}
