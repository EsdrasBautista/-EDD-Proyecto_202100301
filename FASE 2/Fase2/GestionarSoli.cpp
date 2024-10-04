#include "./GestionarSoli.h"
#include <unistd.h>

#include <QMessageBox>



void gestionarSoli::enviarSolicitud(listaEnlazadaArb &usuarios, string correoEmisor,string correoReceptor,QWidget *ventSolicitudes){
    try{

        nodoArbol* receptor = usuarios.buscarNodoPorCorreoArb(correoReceptor);
        nodoArbol* emisor = usuarios.buscarNodoPorCorreoArb(correoEmisor);
        listaAmistad* miamigo = emisor->getListaAmigos();

        if(miamigo->verificarAmistad(correoReceptor)){
            QString msg = QString::fromStdString("El usuario " + correoReceptor + " ya es tu amigo.");
            QMessageBox::warning(ventSolicitudes, "Error al enviar solicitud", msg);
        }else{

            if(receptor == nullptr ){
                QString msg = QString::fromStdString("El usuario "+correoReceptor+" No existe!");
                QMessageBox::warning(ventSolicitudes, "Error al enviar solicitud", msg);
                return;
            }
            if (correoEmisor == correoReceptor) {
                QMessageBox::warning(ventSolicitudes, "Error al enviar solicitud", "No puedes enviarte solicitud a ti mismo!");
            }else{
                PilaSolicitudesRecibidas* pilaReceptor = receptor->getPilaSolicitudesRecibidas();
                ListaSolicitudesEnviadas* listaEmisor = emisor->getListaDeSolicitudesEnviadas();
                PilaSolicitudesRecibidas* pilaEmisor = emisor->getPilaSolicitudesRecibidas();

                if(pilaEmisor->existe(correoReceptor)){
                    QString msg = QString::fromStdString("No se pudo enviar la solicitud, ya existe una solicitud pendiente de parte de: "+correoReceptor);
                    QMessageBox::warning(ventSolicitudes, "Error al enviar solicitud", msg);
                }else{
                    if(!pilaReceptor->existe(correoEmisor) && !listaEmisor->existe(correoReceptor)){
                        pilaReceptor->push(correoEmisor);
                        listaEmisor->agregar(correoReceptor,"PENDIENTE");
                        QString msg = QString::fromStdString("Solicitud enviada de: "+ correoEmisor + " para: "+correoReceptor);
                        QMessageBox::information(ventSolicitudes, "Solicitud Enviada con Exito!", msg);

                    }else{
                        QMessageBox::warning(ventSolicitudes, "Error al enviar solicitud", "No se pudo enviar la solicitud, ya existe una solicitud pendiente");
                    }
                }
            }
        }

    }catch(runtime_error& e){
        std::cerr << "Se ha producido una excepción: " << e.what() << std::endl;
    }



}

void gestionarSoli::aceptarSolicitud(listaEnlazadaArb &usuarios,string correoEmisor,string correoReceptor,QWidget *ventSolicitudes){
    try{

        nodoArbol* receptor = usuarios.buscarNodoPorCorreoArb(correoReceptor); //yo
        nodoArbol* emisor = usuarios.buscarNodoPorCorreoArb(correoEmisor); //el que me envio la sol
        if(receptor == nullptr){
            QMessageBox::warning(ventSolicitudes, "Error", "Uusario no encontrado!!");
            return;
        }

        PilaSolicitudesRecibidas* pilaReceptor = receptor->getPilaSolicitudesRecibidas();
        ListaSolicitudesEnviadas* listaEmisor = emisor->getListaDeSolicitudesEnviadas();

        listaAmistad* listaAmigosEmisor = emisor->getListaAmigos();
        listaAmistad* listaAmigosReceptor = receptor->getListaAmigos();

        if (!pilaReceptor->estaVacia()) {
            pilaReceptor->eliminarElemento(correoEmisor);
            listaEmisor->eliminar(correoReceptor);
            QString msg = QString::fromStdString( "Solicitud de: " +correoEmisor+ " Aceptada!");
            QMessageBox::information(ventSolicitudes, "Estado Solicitud",msg);

            //pilaReceptor->verPila();

            listaAmigosEmisor->agregarAmigo(correoReceptor);
            listaAmigosReceptor->agregarAmigo(correoEmisor);



        }
    }catch(runtime_error& e){
        std::cerr << "Se ha producido una excepción: " << e.what() << std::endl;
    }

}


void gestionarSoli::aceptarSolicitudD(listaEnlazadaArb &usuarios, string correoEmisor,string correoReceptor,QWidget *ventAdmin){
    nodoArbol* receptor = usuarios.buscarNodoPorCorreoArb(correoReceptor); //yo
    nodoArbol* emisor = usuarios.buscarNodoPorCorreoArb(correoEmisor); //el que me envio la sol
    if(receptor == nullptr){
        QMessageBox::warning(ventAdmin, "Error", "Uusario no encontrado!!");
        return;
    }
    listaAmistad* listaAmigosEmisor = emisor->getListaAmigos();
    listaAmistad* listaAmigosReceptor = receptor->getListaAmigos();
    //QString msg = QString::fromStdString( "Solicitud de: " +correoEmisor+ " Aceptada!");

    //QMessageBox::information(ventAdmin, "Estado Solicitud",msg);

    listaAmigosEmisor->agregarAmigo(correoReceptor);
    listaAmigosReceptor->agregarAmigo(correoEmisor);

}


void gestionarSoli::rechazarSolicitud(listaEnlazadaArb &usuarios,string correoEmisor,string correoReceptor,QWidget *ventSolicitudes){
    try{
        nodoArbol *receptor = usuarios.buscarNodoPorCorreoArb(correoReceptor);
        nodoArbol *emisor = usuarios.buscarNodoPorCorreoArb(correoEmisor);
        if (receptor == nullptr){
            QMessageBox::warning(ventSolicitudes, "Error", "Uusario no encontrado!!");
            return;
        }

        PilaSolicitudesRecibidas *pilaReceptor = receptor->getPilaSolicitudesRecibidas();
        ListaSolicitudesEnviadas *listaEmisor = emisor->getListaDeSolicitudesEnviadas();

        if (!pilaReceptor->estaVacia()){
            pilaReceptor->eliminarElemento(correoEmisor);
            listaEmisor->eliminar(correoReceptor);
            QString msg = QString::fromStdString( "Solicitud de: " +correoEmisor+ " Rechazada!");
            QMessageBox::information(ventSolicitudes, "Estado Solicitud", msg);
        }
    }catch(runtime_error& e){
        std::cerr << "Se ha producido una excepción: " << e.what() << std::endl;
    }

}

void gestionarSoli::cancelarSolicitud(listaEnlazadaArb &usuarios, string micorreo, string elotrocorreo, QWidget *ventSolicitudes) {
    try{
        nodoArbol *minodo = usuarios.buscarNodoPorCorreoArb(micorreo);
        nodoArbol *otroNodo = usuarios.buscarNodoPorCorreoArb(elotrocorreo);

        if (otroNodo == nullptr) {
            QMessageBox::warning(ventSolicitudes, "Error", "Uusario no encontrado!!");
            return;
        }

        ListaSolicitudesEnviadas *milista = minodo->getListaDeSolicitudesEnviadas();
        PilaSolicitudesRecibidas *otroPila = otroNodo->getPilaSolicitudesRecibidas();

        if (!otroPila->estaVacia()) {

            std::cout << "Antes: " << std::endl;
            otroPila->verPila(); // ee
            milista->verListaSolEnviadas(); //jj kk

            std::cout << "111111111: " << std::endl;
            otroPila->eliminarElemento(micorreo);
            std::cout << "2222222222: " << std::endl;
            milista->eliminar(elotrocorreo);


            std::cout << "Despues: " << std::endl;
            otroPila->verPila();
            milista->verListaSolEnviadas();

            QString msg = QString::fromStdString("La solicitud que enviaste a: " + elotrocorreo + " ha sido Cancelada!");
            QMessageBox::information(ventSolicitudes, "Estado Solicitud", msg);

        }
    }catch(runtime_error& e){
        std::cerr << "Se ha producido una excepción: " << e.what() << std::endl;
    }
}


void gestionarSoli::EliminarCuenta(listaEnlazadaArb &usuario, string correo){
    nodoArbol *minodo = usuario.buscarNodoPorCorreoArb(correo);

    if (minodo == nullptr) {
        return;
    }

    listaAmistad *misAmigos = minodo->getListaAmigos();
    nodoAmistad *amigos = misAmigos ? misAmigos->getprimero() : nullptr;

    if(amigos != nullptr){
        while(amigos != nullptr){

            nodoArbol *nodoamigos = usuario.buscarNodoPorCorreoArb(amigos->getCorreoA());
            //falta eliminar las publicacaiones mias en listas de mis amigos
            if(nodoamigos != nullptr){
                listaAmistad *amigosnodo = nodoamigos->getListaAmigos();
                ArbolBST *BSTamigo = nodoamigos->getArbolPublicacionesBST();
                listaNodoPub *todasPubs = nodoamigos->getListaTodasPubs();

                if(amigosnodo != nullptr){
                    amigosnodo->eliminarAmigo(correo);
                }

                if(todasPubs != nullptr){
                    nodoSimplePub *actual = todasPubs->getCabeza();
                    nodoSimplePub* anterior = nullptr;
                    if(actual != nullptr){
                        while(actual != nullptr){
                            string fecha="";

                            if (actual->getCorreoL() == correo) {
                                if (anterior == nullptr) {
                                    todasPubs->setCabeza(actual->getSiguiente());
                                } else {
                                    anterior->setSiguiente(actual->getSiguiente());
                                }

                                // Eliminar el nodo actual
                                nodoSimplePub* nodoAEliminar = actual;
                                actual = actual->getSiguiente();
                                fecha = actual->getFechaL();

                                if(BSTamigo != nullptr && BSTamigo->buscarNodoporFecha(fecha) != nullptr){
                                    nodoBST *nodo = BSTamigo->buscarNodoporFecha(fecha);
                                    listaNodoPub *nodop = nodo->getPublicacionesBST();
                                    if(nodop != nullptr){
                                        nodoSimplePub *nodoSpub = nodop->buscarNodoporCorreoId(actual->getCorreoL(),actual->getIdL());
                                        if(nodoSpub != nullptr){
                                            ArbolB *arbolP = nodoSpub->getArbolComentarios();
                                            if(arbolP != nullptr){
                                                arbolP->eliminarComentarios(fecha,correo);
                                            }

                                        }
                                        nodop->eliminarPub(correo);
                                    }
                                }
                                delete nodoAEliminar;

                            } else {
                                anterior = actual;
                                actual = actual->getSiguiente();
                            }

                        }
                    }

                }

            }
            amigos = amigos->getsiguiente();

        }
    }

    usuario.eliminarUsuario(correo);

}

void gestionarSoli::verAmigos(listaEnlazadaArb &usuario, string correo){
    nodoArbol *minodo = usuario.buscarNodoPorCorreoArb(correo);
    if (minodo == nullptr) {
        return;
    }

    listaAmistad *misamigos = minodo->getListaAmigos();
    misamigos->verLista();

}

void gestionarSoli::agregarPublicacionesArbol(listaEnlazadaArb &usuarios, string correo){
    try{
        nodoArbol *minodo = usuarios.buscarNodoPorCorreoArb(correo);
        listaPublicaciones *misPubs = minodo->getListapublicaionesU();
        ArbolBST *arbolBST = minodo->getArbolPublicacionesBST();

        NodoPub* pubActual = misPubs->getPrimero();

        //llenar mi arbolBST con mis publicaciones
        while(pubActual != nullptr){
            if(!arbolBST->verificarexisteFecha(pubActual->getcontadorPublicaciones(),pubActual->getfecha(),pubActual->getCorreo())){
                arbolBST->agregarPublicacionBST(pubActual->getCorreo(), pubActual->getcontenido(), pubActual->getfecha(), pubActual->gethora(),pubActual->getImagen(),pubActual->getcontadorPublicaciones());
            }
            pubActual = pubActual->getSigPub();
        }


        //llenar el arbolBST con publicaciones de mis amigos
        listaAmistad *misamigos = minodo->getListaAmigos();
        nodoAmistad* amigoActual = misamigos->getprimero();

        while(amigoActual != nullptr){
            nodoArbol *nodoAmigo = usuarios.buscarNodoPorCorreoArb(amigoActual->getCorreoA());
            if(nodoAmigo != nullptr){
                listaPublicaciones *publicacionesAmigo = nodoAmigo->getListapublicaionesU();
                NodoPub* pubAmigoActual = publicacionesAmigo->getPrimero();
                while(pubAmigoActual != nullptr){
                    if(!arbolBST->verificarexisteFecha(pubAmigoActual->getcontadorPublicaciones(),pubAmigoActual->getfecha(),pubAmigoActual->getCorreo())){
                        arbolBST->agregarPublicacionBST(pubAmigoActual->getCorreo(), pubAmigoActual->getcontenido(), pubAmigoActual->getfecha(), pubAmigoActual->gethora(),pubAmigoActual->getImagen(),pubAmigoActual->getcontadorPublicaciones());
                    }
                    pubAmigoActual = pubAmigoActual->getSigPub();
                }
            }
            amigoActual = amigoActual->getsiguiente();
        }


    }catch (runtime_error& e) {
        std::cerr << "Se ha producido una excepción: " << e.what() << std::endl;
    }
}


void gestionarSoli::agregarPublicacionesAmigos(listaEnlazadaArb &usuarios, string correo){
    try{
        nodoArbol *minodo = usuarios.buscarNodoPorCorreoArb(correo);
        listaNodoPub *milista = minodo->getListaTodasPubs();
        listaAmistad *misamigos = minodo->getListaAmigos();
        if(misamigos != nullptr){
            nodoAmistad *amigos = misamigos->getprimero();
            while(amigos != nullptr){
                nodoArbol *nodoAmigo = usuarios.buscarNodoPorCorreoArb(amigos->getCorreoA());
                if(nodoAmigo != nullptr){
                    listaNodoPub *pubAmigos = nodoAmigo->getListaTodasPubs();
                    if(pubAmigos != nullptr){
                        nodoSimplePub* nodo = pubAmigos->getCabeza();
                        while(nodo != nullptr){
                            if(!milista->verificarExistencia(nodo->getCorreoL(),nodo->getIdL())){
                                milista->agregarPublicacionL(nodo->getFechaL(),nodo->getCorreoL(),nodo->getContenidoL(),nodo->getHoraL(),nodo->getImagen(),nodo->getIdL());
                            }
                            nodo = nodo->getSiguiente();
                        }

                    }
                }
                amigos = amigos->getsiguiente();
            }
        }

    }catch (runtime_error& e) {
        std::cerr << "Se ha producido una excepción: mostrarARBOL " << e.what() << std::endl;
    }
}


nodoSimplePub* gestionarSoli::mostrarPublicacionesArbol(listaEnlazadaArb &usuarios, string correo, QLineEdit *txtUsuario, QLineEdit *txtFecha, QPlainTextEdit *textoPub, QLabel *lblImagen, string fecha){
    try{
        nodoArbol *minodo = usuarios.buscarNodoPorCorreoArb(correo);
        if(minodo != nullptr){
            ArbolBST *miarbolBST = minodo->getArbolPublicacionesBST();
            if(miarbolBST != nullptr){
                if(fecha == "TODO"){
                    listaNodoPub *listaPubs = minodo->getListaTodasPubs();
                    if(listaPubs != nullptr){
                        nodoSimplePub *actual = listaPubs->getCabeza();
                        if(actual != nullptr){
                            txtUsuario->setText(QString::fromStdString(actual->getCorreoL()));
                            txtFecha->setText(QString::fromStdString(actual->getFechaL()));
                            textoPub->setPlainText(QString::fromStdString(actual->getContenidoL()));

                            if (actual->getImagen() != "") {
                                QPixmap pixmap(QString::fromStdString(actual->getImagen()));
                                lblImagen->setPixmap(pixmap.scaled(lblImagen->width(), lblImagen->height(), Qt::KeepAspectRatio));
                            } else {
                                lblImagen->clear();
                            }
                            return actual;
                        }else{
                            return nullptr;
                        }

                    }

                }else{
                    nodoBST *minodoBST = miarbolBST->buscarNodoporFecha(fecha);
                    if(minodoBST != nullptr){
                        listaNodoPub *listaPub = minodoBST->getPublicacionesBST();
                        if(listaPub != nullptr){
                            nodoSimplePub *pub = listaPub->getCabeza();
                            txtUsuario->setText(QString::fromStdString(pub->getCorreoL()));
                            txtFecha->setText(QString::fromStdString(pub->getFechaL()));
                            textoPub->setPlainText(QString::fromStdString(pub->getContenidoL()));

                            if (pub->getImagen() != "") {
                                QPixmap pixmap(QString::fromStdString(pub->getImagen()));
                                lblImagen->setPixmap(pixmap.scaled(lblImagen->width(), lblImagen->height(), Qt::KeepAspectRatio));
                            } else {
                                lblImagen->clear();
                            }
                            return pub;
                        }else{
                            return nullptr;
                        }
                    }
                }
            }
        }else{
            return nullptr;
        }

    }catch (runtime_error& e) {
        std::cerr << "Se ha producido una excepción: mostrarARBOL " << e.what() << std::endl;
    }
    return nullptr;
}

nodoSimplePub* gestionarSoli::OrdenarPublicacionespor(listaEnlazadaArb &usuarios, string correo, QLineEdit *txtUsuario, QLineEdit *txtFecha, QPlainTextEdit *textoPub, QLabel *lblImagen, int cantidad, string tipoOrden){
    try{
        nodoArbol *minodo = usuarios.buscarNodoPorCorreoArb(correo);
        ArbolBST *miBST = minodo->getArbolPublicacionesBST();
        if(miBST != nullptr){
            nodoSimplePub *pub = nullptr;

            if(tipoOrden == "PreOrden"){
                pub = miBST->OrdenPreorden(cantidad);

                if(pub != nullptr){
                    txtUsuario->setText(QString::fromStdString(pub->getCorreoL()));
                    txtFecha->setText(QString::fromStdString(pub->getFechaL()));
                    textoPub->setPlainText(QString::fromStdString(pub->getContenidoL()));

                    if (pub->getImagen() != "") {
                        QPixmap pixmap(QString::fromStdString(pub->getImagen()));
                        lblImagen->setPixmap(pixmap.scaled(lblImagen->width(), lblImagen->height(), Qt::KeepAspectRatio));
                    } else {
                        lblImagen->clear();
                    }
                    return pub;
                }else{
                    return nullptr;
                }

            }else if(tipoOrden == "PosOrden"){
                pub = miBST->OrdenPostorden(cantidad);

                if(pub != nullptr){
                    txtUsuario->setText(QString::fromStdString(pub->getCorreoL()));
                    txtFecha->setText(QString::fromStdString(pub->getFechaL()));
                    textoPub->setPlainText(QString::fromStdString(pub->getContenidoL()));

                    if (pub->getImagen() != "") {
                        QPixmap pixmap(QString::fromStdString(pub->getImagen()));
                        lblImagen->setPixmap(pixmap.scaled(lblImagen->width(), lblImagen->height(), Qt::KeepAspectRatio));
                    } else {
                        lblImagen->clear();
                    }
                    return pub;
                }else{
                    return nullptr;
                }

            }else if(tipoOrden == "InOrden"){
                pub = miBST->Ordeninorden(cantidad);

                if(pub != nullptr){
                    txtUsuario->setText(QString::fromStdString(pub->getCorreoL()));
                    txtFecha->setText(QString::fromStdString(pub->getFechaL()));
                    textoPub->setPlainText(QString::fromStdString(pub->getContenidoL()));

                    if (pub->getImagen() != "") {
                        QPixmap pixmap(QString::fromStdString(pub->getImagen()));
                        lblImagen->setPixmap(pixmap.scaled(lblImagen->width(), lblImagen->height(), Qt::KeepAspectRatio));
                    } else {
                        lblImagen->clear();
                    }
                    return pub;
                }else{
                    return nullptr;
                }

            }
        }else{
            return nullptr;
        }

    }catch (runtime_error& e) {
        std::cerr << "Se ha producido una excepción: mostrarARBOL " << e.what() << std::endl;
    }
    return nullptr;
}


void gestionarSoli::agregarComentario(listaEnlazadaArb &usuarios, string correoU,string fechaU ,int id,string fecha, string hora, string contenido, string correoComento,QWidget *ventana){
    try{
        nodoArbol *minodo = usuarios.buscarNodoPorCorreoArb(correoU);

        if(minodo != nullptr){
            ArbolBST *miarbolBst = minodo->getArbolPublicacionesBST();
            if(miarbolBst != nullptr){
                nodoBST* nodo = miarbolBst->buscarNodoporFecha(fechaU);
                if(nodo != nullptr){
                    listaNodoPub* lista = nodo->getPublicacionesBST();
                    if(lista != nullptr){
                        nodoSimplePub* nodoS = lista->buscarNodoporCorreoId(correoU,id);
                        if(nodoS != nullptr){
                            ArbolB* arbolB = nodoS->getArbolComentarios();
                            if(arbolB != nullptr){
                                arbolB->insert(fecha,hora,correoComento,contenido);
                                QMessageBox::information(ventana,"Comentario","Se ha comentado la publicacion con exito!");
                            }
                        }
                    }
                }
            }
        }
    }catch (runtime_error& e) {
        std::cerr << "Se ha producido una excepción: mostrarARBOL " << e.what() << std::endl;
        QMessageBox::information(ventana,"Advertencia","Error al agregar comentario!");
    }
}


int gestionarSoli::agregarPubDesdeAdmin(listaEnlazadaArb &usuarios,string correoU,string contenido,string fecha,string hora,QWidget *ventana){

    try{
        nodoArbol *minodo = usuarios.buscarNodoPorCorreoArb(correoU);

        if(minodo != nullptr){
            listaPublicaciones* milistapub = minodo->getListapublicaionesU();
            ArbolBST* arbolPub = minodo->getArbolPublicacionesBST();
            listaNodoPub *todosPubs = minodo->getListaTodasPubs();
            string correo = minodo->getCorreo();
            if(milistapub != nullptr || arbolPub != nullptr || todosPubs != nullptr){

                milistapub->agregarPub(correo,contenido,fecha,hora);
                int cont = milistapub->getContPublica();
                arbolPub->agregarPublicacionBST(correo,contenido,fecha,hora,"",cont);
                todosPubs->agregarPublicacionL(fecha,correo,contenido,hora,"",cont);

                QMessageBox::information(ventana,"Exito","Publicacion creada!");
                std::cout << cont << " cont" <<std::endl;
                return cont;
            }
        }

        QMessageBox::information(ventana,"Advertencia","Error al crear publicacion!");
        return -1;


    }catch (runtime_error& e) {
        std::cerr << "Se ha producido una excepción: mostrarARBOL " << e.what() << std::endl;
        QMessageBox::information(ventana,"Advertencia","Error al crear publicacion!");
    }
}

void gestionarSoli::verComentarios(listaEnlazadaArb &usuarios, string correoU,string fechaU ,int id, QPlainTextEdit *txtarea){

    try{
        nodoArbol *minodo = usuarios.buscarNodoPorCorreoArb(correoU);
        ArbolBST *miarbolBst = minodo->getArbolPublicacionesBST();
        if(miarbolBst != nullptr){
            nodoBST* nodo = miarbolBst->buscarNodoporFecha(fechaU);
            if(nodo != nullptr){
                listaNodoPub* lista = nodo->getPublicacionesBST();
                if(lista != nullptr){
                    nodoSimplePub* nodoS = lista->buscarNodoporCorreoId(correoU,id);
                    if(nodoS != nullptr){
                        ArbolB* arbolB = nodoS->getArbolComentarios();
                        if(arbolB != nullptr){
                            arbolB->recorrer(txtarea);
                        }
                    }
                }
            }
        }

    }catch (runtime_error& e) {
        std::cerr << "Se ha producido una excepción: recorrerArbolB " << e.what() << std::endl;
    }

}

void gestionarSoli::mostrarArbolB(listaEnlazadaArb &usuarios, string correoU, string fechaU, int id, QLabel *img,QWidget *ventana){
    try{
        nodoArbol *minodo = usuarios.buscarNodoPorCorreoArb(correoU);
        ArbolBST *miarbolBst = minodo->getArbolPublicacionesBST();
        if(miarbolBst != nullptr){
            nodoBST* nodo = miarbolBst->buscarNodoporFecha(fechaU);
            if(nodo != nullptr){
                listaNodoPub* lista = nodo->getPublicacionesBST();
                if(lista != nullptr){
                    nodoSimplePub* nodoS = lista->buscarNodoporCorreoId(correoU,id);
                    if(nodoS != nullptr){
                        ArbolB* arbolB = nodoS->getArbolComentarios();
                        if(arbolB != nullptr){
                            string ruta = "C:\\Users\\bauti\\Desktop\\USAC\\2024\\SEMESTRE 2\\EDD\\LAB\\PROYECTO\\FASE 2\\Fase2\\build\\Desktop_Qt_6_7_2_MinGW_64_bit-Debug";
                            ruta += arbolB->verArbol();
                            if (ruta != "") {
                                QPixmap pixmap(QString::fromStdString(ruta));
                                img->setPixmap(pixmap.scaled(img->width(), img->height(), Qt::KeepAspectRatio));
                            }else{
                                QMessageBox::warning(ventana,"Advertencia","No hay comentarios aun!");
                                std::cout << "ruta: "<<ruta << std::endl;
                            }

                        }
                    }
                }
            }
        }

    }catch (runtime_error& e) {
        std::cerr << "Se ha producido una excepción: recorrerArbolB " << e.what() << std::endl;
    }
}




void gestionarSoli::agregarComentarioAdmin(listaEnlazadaArb &usuarios, string correoU,string fechaU ,int id,string fecha, string hora, string contenido, string correoComento,QWidget *ventana){

    try{
        nodoArbol *minodo = usuarios.buscarNodoPorCorreoArb(correoU);
        listaAmistad *misamigos = minodo->getListaAmigos();
        if(minodo != nullptr){
            if(misamigos->verificarAmistad(correoComento)){
                ArbolBST *miarbolBst = minodo->getArbolPublicacionesBST();
                if(miarbolBst != nullptr){
                    nodoBST* nodo = miarbolBst->buscarNodoporFecha(fechaU);
                    if(nodo != nullptr){
                        listaNodoPub* lista = nodo->getPublicacionesBST();
                        if(lista != nullptr){
                            nodoSimplePub* nodoS = lista->buscarNodoporCorreoId(correoU,id);
                            if(nodoS != nullptr){
                                ArbolB* arbolB = nodoS->getArbolComentarios();
                                if(arbolB != nullptr){
                                    arbolB->insert(fecha,hora,correoComento,contenido);
                                    QMessageBox::information(ventana,"Comentario","Se ha comentado la publicacion con exito!");
                                    arbolB->verArbol();
                                }
                            }
                        }
                    }
                }
            }
        }
    }catch (runtime_error& e) {
        std::cerr << "Se ha producido una excepción: mostrarARBOL " << e.what() << std::endl;
        QMessageBox::information(ventana,"Advertencia","Error al agregar comentario!");
    }
}
