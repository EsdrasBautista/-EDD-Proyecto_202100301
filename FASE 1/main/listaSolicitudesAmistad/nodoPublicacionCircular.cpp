#include "nodoPublicacionCircular.h"


NodoCircular::NodoCircular(){
    correo = "";
    contenido = "";
    fecha = "";
    hora = "";
    sig = nullptr;
    prev = nullptr;
    id = 0;
}
NodoCircular::NodoCircular(string correo,string contenido,string fecha,string hora,int id){
    this->correo = correo;
    this->contenido = contenido;
    this->fecha = fecha;
    this->hora = hora;
    this->sig = nullptr;
    this->prev = nullptr;
    this->id = id;
}



void NodoCircular::setSigPubl(NodoCircular *sig){
    this->sig = sig;
}
void NodoCircular::setPrevPub(NodoCircular *prev){
    this->prev = prev;
}

NodoCircular* NodoCircular::getPrevPub(){
    return prev;
}

NodoCircular* NodoCircular::getSigPub(){
    return sig;
}

string NodoCircular::getcontenido(){
    return contenido;
}

string NodoCircular::getCorreo(){
    return correo;
}

string NodoCircular::getfecha(){
    return fecha;
}

string NodoCircular::gethora(){
    return hora;
}

int NodoCircular::getId(){
    return id;
}



//------------------------------------------------------------------------------------------



listaCircular::listaCircular(){
    primero = nullptr;
    ultimo = nullptr;

}

listaCircular::~listaCircular() {
    if (primero != nullptr) {
        NodoCircular *temp = primero;
        NodoCircular *aux;


        do {
            aux = temp->getSigPub(); // Guarda el siguiente nodo
            delete temp; // Libera el nodo actual
            temp = aux; // Avanza al siguiente nodo
        } while (temp != primero); 


        primero = nullptr;
        ultimo = nullptr;
    }
}


void listaCircular::agregarListaPublicaciones(string correo,string contenido,string fecha,string hora,int contador){

    NodoCircular *nuevoNodo = new NodoCircular(correo,contenido,fecha,hora,contador);
    if(primero == nullptr){
        primero = nuevoNodo;
        ultimo = nuevoNodo;
        primero->setSigPubl(primero);
        primero->setPrevPub(primero);
    }else{
        nuevoNodo->setPrevPub(ultimo);
        nuevoNodo->setSigPubl(primero);
        ultimo->setSigPubl(nuevoNodo);
        primero->setPrevPub(nuevoNodo);
        ultimo = nuevoNodo;
    }



}

void listaCircular::verListasPublicaciones() {
    NodoCircular *temp = primero;

    if(temp == nullptr){
        cout << "No hay publicaciones aun!" << endl;
    }else{

        while (temp != nullptr) {

                // Mostrar la publicación actual
                cout << endl;
                cout << "Correo: " << temp->getCorreo() << endl;
                cout << "Contenido: " << temp->getcontenido() << endl;
                cout << "Fecha: " << temp->getfecha() << endl;
                cout << "Hora: " << temp->gethora() << endl;
            

            // Mostrar mensaje
            cout << "izquierda (<-) para Anterior, derecha (->) para Siguiente, o ESC para salir." << endl;


            int tecla = _getch(); // Captura la tecla
            if (tecla == 0 || tecla == 224) { 
                tecla = _getch(); // Obtener el código real de la tecla especial
                if (tecla == 75) { // Flecha izquierda (código ASCII 75)
                    if (temp->getPrevPub() != nullptr) {
                        temp = temp->getPrevPub(); // Ir a la publicación anterior
                    } 
                } else if (tecla == 77) { // Flecha derecha (código ASCII 77)
                    if (temp->getSigPub() != nullptr) {
                        temp = temp->getSigPub(); // Ir a la siguiente publicación
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


void listaCircular::graficarCircular(string correo) {
    
    if (primero == nullptr) {
        cout << "No tienes publicaciones de tus amigos aun!" << endl;
    
    }else{

        ofstream archivo("AmistadesC.dot");
        if (!archivo.is_open()) {
            cout << "No se pudo crear el archivo" << endl;
            
        }else{

            archivo << "digraph G {" << endl;
            archivo << "    rankdir=LR;" << endl;
            archivo << "    node [shape=record];" << endl;

            NodoCircular *nodoactual = primero;
            int contador = 1;

            // Primero, crea todos los nodos
            do {
                archivo << "    nodo_" << contador << " [label=\"";
                archivo << "Correo: " << nodoactual->getCorreo() << "\\n";
                archivo << "Contenido: " << nodoactual->getcontenido() << "\\n";
                archivo << "Fecha: " << nodoactual->getfecha() << "\\n";
                archivo << "Hora: " << nodoactual->gethora() << "\\n";
                archivo << "\"];" << endl;

                nodoactual = nodoactual->getSigPub();
                contador++;
            } while (nodoactual != primero);

            // conectar todos los nodos en una lista circular
            
            int contador2 = 1;
            while(contador2 < (contador-1)){         
                archivo <<"nodo_"<< contador2 <<"-> " << "nodo_" << (contador2+1)  <<endl;
                archivo << "nodo_" << (contador2+1) << "-> " << "nodo_"<< contador2 << endl;
                contador2++;
            }

            archivo << "nodo_" << (contador2) << "->" << "nodo_1" <<endl;
            archivo << "nodo_1" << "->" << "nodo_" << (contador2) << endl;


            archivo << "}" << endl;
            archivo.close();

            stringstream nombreArchivo;
            nombreArchivo << "AmistadesC_" << correo << ".png";


            stringstream comando;
            comando << "dot -Tpng AmistadesC.dot -o " << nombreArchivo.str();


            system(comando.str().c_str());

            cout << "La lista de amistades ha sido graficada y guardada en " << nombreArchivo.str() << endl;
        }
    }
}


bool listaCircular::verificarexiste(int contador, string correo){
    if (primero == nullptr) {
        return false;
    }

    NodoCircular *actual = primero;

    do {


        if (actual->getId() == contador && actual->getCorreo() == correo) {

            return true;
        }
        actual = actual->getSigPub();
    } while (actual != primero);  

    return false;
}


void listaCircular::actualizarLista(int contador, string correo) {
    if (primero == nullptr) {
        return; // Lista vacía
    }

    NodoCircular *actual = primero;

    do {
        if (actual->getId() == contador && actual->getCorreo() == correo) {
            // Nodo a eliminar encontrado

            if (primero == ultimo && actual == primero) {
                // solo hay un nodo en la lista
                delete actual;
                primero = nullptr;
                ultimo = nullptr;

                return;
            } else if (actual == primero) {
                // Eliminar el primer nodo
                primero = actual->getSigPub();
                primero->setPrevPub(ultimo);
                ultimo->setSigPubl(primero);
            } else if (actual == ultimo) {
                // Eliminar el último nodo
                ultimo = actual->getPrevPub();
                ultimo->setSigPubl(primero);
                primero->setPrevPub(ultimo);
            } else {
                // Eliminar  nodo intermedio
                actual->getPrevPub()->setSigPubl(actual->getSigPub());
                actual->getSigPub()->setPrevPub(actual->getPrevPub());
            }

            // Eliminar el nodo
            NodoCircular *paraEliminar = actual;
            actual = actual->getSigPub(); 
            cout << paraEliminar->getCorreo() << " " << paraEliminar->getId() << endl;
            delete paraEliminar; 

            return;

        }

        actual = actual->getSigPub();
    } while (actual != primero); 
}


void listaCircular::eliminarPublicacionA(string correoAmigo) {
    if (primero == nullptr) {
        return; // Lista vacía
    }

    NodoCircular* actual = primero;
    NodoCircular* temp = nullptr;

    do {
        if (actual->getCorreo() == correoAmigo) {
            // Guardar el nodo a eliminar
            temp = actual;
            
            // Si es el único nodo en la lista
            if (primero == ultimo && actual == primero) {
                primero = nullptr;
                ultimo = nullptr;
                delete temp;
                return;
            }

            // Si el nodo a eliminar es el primero
            if (actual == primero) {
                primero = primero->getSigPub();
                ultimo->setPrevPub(primero);
                primero->setPrevPub(ultimo);
            }
            // Si el nodo a eliminar es el último
            else if (actual == ultimo) {
                ultimo = ultimo->getPrevPub();
                ultimo->setSigPubl(primero);
                primero->setSigPubl(ultimo);
            } 
            // Si el nodo a eliminar está en medio
            else {
                actual->getSigPub()->setSigPubl(actual->getSigPub());
                actual->getSigPub()->setPrevPub(actual->getPrevPub());
            }


            actual = actual->getSigPub();
            
            // Eliminar el nodo
            delete temp;
        } else {

            actual = actual->getSigPub();
        }
    } while (actual != primero);


}
