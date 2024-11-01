#include "./solicitudes.h"
#include "ui_solicitudes.h"
#include "./GestionarSoli.h"
#include "./listaEnlazadaArbol.h"

Solicitudes::Solicitudes(QWidget *parent,listaEnlazadaArb* lista, const std::string& correo,listaAdyacencia* grafo)
    : QMainWindow(parent)
    , ui(new Ui::Solicitudes),
    listaArbol(lista),      // Inicializar listaArbol
    correoUsuario(correo),   // Inicializar correoUsuario
    grafoAdy(grafo)
{
    ui->setupUi(this);
    this->setWindowTitle("Solicitudes");
    tablaUser();
    tablaEnv();
    tablaRec();

}

Solicitudes::~Solicitudes()
{
    delete ui;
}


//---------------------------------------------------------------------------------------------------

void Solicitudes::tablaUser(){
    ui->tlbUs->setColumnCount(5);
    QStringList l;
    l<<"Nombres"<<"Apellidos"<<"Correo"<<"FechaNac"<<"Enviar";
    ui->tlbUs->setHorizontalHeaderLabels(l);

    ui->tlbUs->setColumnWidth(0,250);
    ui->tlbUs->setColumnWidth(1,250);
    ui->tlbUs->setColumnWidth(2,250);
    ui->tlbUs->setColumnWidth(3,250);
    ui->tlbUs->setColumnWidth(4,250);
    int fila = 0;
    llenarTblUser(listaArbol->getRaiz(),fila);
}

void Solicitudes::llenarTblUser(nodoArbol *node, int &fila){
    nodoArbol *usuario = listaArbol->buscarNodoPorCorreoArb(correoUsuario);
    PilaSolicitudesRecibidas *mipila = usuario->getPilaSolicitudesRecibidas();
    ListaSolicitudesEnviadas *milista = usuario->getListaDeSolicitudesEnviadas();
    //listaAmistad *mimatriz = usuario->getListaAmigos();
    listaAdyacencia *mimatriz = usuario->getListaAmistadGrafo();

    if(node == nullptr) return;

    llenarTblUser(node->getIzquierda(), fila);

    bool existeP = mipila->existe(node->getCorreo());
    bool existeL = milista->existe(node->getCorreo());

    if(node->getCorreo() != correoUsuario && !existeL && !existeP && !mimatriz->verificarAmistadGrafo(node->getCorreo())){
        ui->tlbUs->insertRow(fila);

        QTableWidgetItem* nombreItem = new QTableWidgetItem(QString::fromStdString(node->getNombres()));
        nombreItem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        ui->tlbUs->setItem(fila, 0, nombreItem);

        QTableWidgetItem* apellidoItem = new QTableWidgetItem(QString::fromStdString(node->getApellidos()));
        apellidoItem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        ui->tlbUs->setItem(fila, 1, apellidoItem);

        QTableWidgetItem* correoItem = new QTableWidgetItem(QString::fromStdString(node->getCorreo()));
        correoItem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        ui->tlbUs->setItem(fila, 2, correoItem);

        QTableWidgetItem* fechaNacItem = new QTableWidgetItem(QString::fromStdString(node->getFechaNacimiento()));
        fechaNacItem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        ui->tlbUs->setItem(fila, 3, fechaNacItem);

        QPushButton *enviarButton = new QPushButton("Enviar");
        ui->tlbUs->setCellWidget(fila, 4, enviarButton);

        QObject::disconnect(enviarButton, &QPushButton::clicked, this, nullptr);

        connect(enviarButton, &QPushButton::clicked, this, [this, node]() {
            gestionarSoli::enviarSolicitud(*listaArbol, correoUsuario, node->getCorreo(), this);
            refrescarTablaUser();
            refrescarTablaEnv();
        });

        fila++;
    }

    llenarTblUser(node->getDerecha(), fila);
}


void Solicitudes::refrescarTablaUser(){
    ui->tlbUs->setRowCount(0);
    int fila = 0;
    llenarTblUser(listaArbol->getRaiz(), fila);
}


//---------------------------------------------------------------------------------------------------


void Solicitudes::tablaEnv(){
    ui->tlbEnv->setColumnCount(2);
    QStringList l;
    l<<"Correo"<<"Estado";
    ui->tlbEnv->setHorizontalHeaderLabels(l);
    ui->tlbEnv->setColumnWidth(0,250);
    ui->tlbEnv->setColumnWidth(1,250);

    nodoArbol *user = listaArbol->buscarNodoPorCorreoArb(correoUsuario);
    ListaSolicitudesEnviadas *milista = user->getListaDeSolicitudesEnviadas();
    int fila = 0;
    if(milista->getHead() != nullptr){
        llenarTblEnv(milista->getHead(),fila);
    }
}



void Solicitudes::llenarTblEnv(NodoLisaE *envio, int &fila){

    if(envio == nullptr)return;

    while (envio != nullptr) {

        if(envio->getEstadoSolicitudE() == "PENDIENTE"){
            ui->tlbEnv->insertRow(fila);

            QTableWidgetItem* correoItem = new QTableWidgetItem(QString::fromStdString(envio->getCorreoUsuarioE()));
            correoItem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
            ui->tlbEnv->setItem(fila, 0, correoItem);

            QPushButton *cancelarButton = new QPushButton("Cancelar");
            ui->tlbEnv->setCellWidget(fila, 1, cancelarButton);


            QObject::disconnect(cancelarButton, &QPushButton::clicked, this, nullptr);

            connect(cancelarButton, &QPushButton::clicked, this, [this, envio]() {
                gestionarSoli::cancelarSolicitud(*listaArbol,correoUsuario,envio->getCorreoUsuarioE(), this);
                refrescarTablaUser();
                refrescarTablaEnv();

            });

            fila++;

        }
        envio = envio->getSiguiente();
    }

}

void Solicitudes::refrescarTablaEnv(){
    ui->tlbEnv->setRowCount(0);
    int fila = 0;
    nodoArbol *user = listaArbol->buscarNodoPorCorreoArb(correoUsuario);
    ListaSolicitudesEnviadas *milista = user->getListaDeSolicitudesEnviadas();
    milista->verListaSolEnviadas();
    llenarTblEnv(milista->getHead(),fila);

}

//---------------------------------------------------------------------------------------------------

void Solicitudes::tablaRec(){
    ui->tlbRec->setColumnCount(3);
    QStringList l;
    l<<"Correo"<<"Aceptar"<<"Rechazar";
    ui->tlbRec->setHorizontalHeaderLabels(l);
    ui->tlbRec->setColumnWidth(0,250);
    ui->tlbRec->setColumnWidth(1,250);
    ui->tlbRec->setColumnWidth(2,250);

    nodoArbol *user = listaArbol->buscarNodoPorCorreoArb(correoUsuario);
    PilaSolicitudesRecibidas *mipila = user->getPilaSolicitudesRecibidas();
    int fila = 0;
    if(mipila->getHead() != nullptr){
        llenarTblRec(mipila->getHead(),fila);
    }
}


void Solicitudes::llenarTblRec(NodoPila *pila, int &fila){

    if (pila == nullptr) return;

    while (pila != nullptr) {
        ui->tlbRec->insertRow(fila);

        QTableWidgetItem* correoItem = new QTableWidgetItem(QString::fromStdString(pila->getCorreoUsuario()));
        correoItem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        ui->tlbRec->setItem(fila, 0, correoItem);

        QPushButton *aceptarButton = new QPushButton("Aceptar");
        ui->tlbRec->setCellWidget(fila, 1, aceptarButton);

        QPushButton *rechazarButton = new QPushButton("Rechazar");
        ui->tlbRec->setCellWidget(fila, 2, rechazarButton);


        QObject::disconnect(aceptarButton, &QPushButton::clicked, this, nullptr);
        QObject::disconnect(rechazarButton, &QPushButton::clicked, this, nullptr);

        connect(aceptarButton, &QPushButton::clicked, this, [this, pila]() {
            gestionarSoli::aceptarSolicitud(*listaArbol, pila->getCorreoUsuario(), correoUsuario, this,*grafoAdy);
            refrescarTablaRec();
        });
        connect(rechazarButton, &QPushButton::clicked, this, [this, pila]() {
            gestionarSoli::rechazarSolicitud(*listaArbol, pila->getCorreoUsuario(), correoUsuario, this);
            refrescarTablaUser();
            refrescarTablaRec();

        });

        fila++;
        pila = pila->getSiguiente();
    }
}


void Solicitudes::refrescarTablaRec(){
    ui->tlbRec->setRowCount(0);
    int fila = 0;
    nodoArbol *user = listaArbol->buscarNodoPorCorreoArb(correoUsuario);
    PilaSolicitudesRecibidas *mipila = user->getPilaSolicitudesRecibidas();
    llenarTblRec(mipila->getHead(), fila);
}



void Solicitudes::on_pushButton_3_clicked()
{
    this->close();  // Cerrar la ventana actual CrearUser
    QWidget *parent = this->parentWidget();  // Obtener la ventana principal
    if (parent) {
        parent->show();  // Mostrar la ventana principal si existe
    }
}

