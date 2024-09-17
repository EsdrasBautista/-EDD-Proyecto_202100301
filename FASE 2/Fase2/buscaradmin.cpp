#include "buscaradmin.h"
#include "ui_buscaradmin.h"
#include "./GestionarSoli.h"
#include <QMessageBox>



BuscarAdmin::BuscarAdmin(QWidget *parent,listaEnlazadaArb* lista)
    : QMainWindow(parent)
    , ui(new Ui::BuscarAdmin),
    listaArbol(lista)
{
    ui->setupUi(this);
    this->setWindowTitle("BuscarAdmin");
    tablaUser();

}

BuscarAdmin::~BuscarAdmin()
{
    delete ui;
}

void BuscarAdmin::tablaUser(){

    ui->tlbUs->setColumnCount(6);
    QStringList l;
    l<<"Nombres"<<"Apellidos"<<"Correo"<<"FechaNac"<<"Modificar"<<"Eliminar";
    ui->tlbUs->setHorizontalHeaderLabels(l);

    ui->tlbUs->setColumnWidth(0,250);
    ui->tlbUs->setColumnWidth(1,250);
    ui->tlbUs->setColumnWidth(2,250);
    ui->tlbUs->setColumnWidth(3,250);
    ui->tlbUs->setColumnWidth(4,250);
    ui->tlbUs->setColumnWidth(5,250);
    int fila = 0;

    if(listaArbol->getRaiz() != nullptr){
        llenarTabla(listaArbol->getRaiz(),fila);
    }else{
        QMessageBox::warning(this,"Listado Usuarios","No hay Usuarios!");
    }

}


void BuscarAdmin::llenarTabla(nodoArbol *node, int &fila) {
    if (node == nullptr) {
        return;
    }

    llenarTabla(node->getIzquierda(), fila);

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

    QPushButton *modButton = new QPushButton("Modificar");
    ui->tlbUs->setCellWidget(fila, 4, modButton);

    QPushButton *elimButton = new QPushButton("Eliminar");
    ui->tlbUs->setCellWidget(fila, 5, elimButton);


    QObject::disconnect(modButton, &QPushButton::clicked, this, nullptr);
    QObject::disconnect(elimButton, &QPushButton::clicked, this, nullptr);


    connect(modButton, &QPushButton::clicked, this, [this, node]() {

        ActualizarTabla();
    });

    connect(elimButton, &QPushButton::clicked, this, [this, node]() {
        gestionarSoli::EliminarCuenta(*listaArbol, node->getCorreo());
        ActualizarTabla();
    });

    fila++;
    llenarTabla(node->getDerecha(), fila);
}

void BuscarAdmin::ActualizarTabla() {
    ui->tlbUs->setRowCount(0);
    int fila = 0;
    if (listaArbol->getRaiz() == nullptr) {
        QMessageBox::warning(this,"Listado Usuarios","No hay Usuarios!");
        return;
    }
    llenarTabla(listaArbol->getRaiz(), fila);
}




void BuscarAdmin::buscar(){
    QString qcorreo = ui->txtCorreo->text();
    string correo = qcorreo.toStdString();

    if (correo == "") {
        QMessageBox::warning(this, "Error al buscar", "Llena el campo con el correo!");
        limpiarTabla();
        tablaUser();
        return;
    }

    nodoArbol *node = listaArbol->buscarNodoPorCorreoArb(correo);

    if (node == nullptr) {
        QMessageBox::warning(this, "No encontrado", "El correo ingresado no se encuentra en el árbol.");
        limpiarTabla();
        tablaUser();
        return;
    }

    limpiarTabla();

    ui->tlbUs->setColumnCount(6);
    QStringList l;
    l << "Nombres" << "Apellidos" << "Correo" << "FechaNac" << "Modificar" << "Eliminar";
    ui->tlbUs->setHorizontalHeaderLabels(l);

    ui->tlbUs->setColumnWidth(0, 250);
    ui->tlbUs->setColumnWidth(1, 250);
    ui->tlbUs->setColumnWidth(2, 250);
    ui->tlbUs->setColumnWidth(3, 250);
    ui->tlbUs->setColumnWidth(4, 250);
    ui->tlbUs->setColumnWidth(5, 250);

    // Inserta la nueva fila
    int fila = 0;
    ui->tlbUs->insertRow(fila);

    // Agrega los datos del nodo encontrado
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

    // Agrega botones de modificar y eliminar
    QPushButton *modButton = new QPushButton("Modificar");
    ui->tlbUs->setCellWidget(fila, 4, modButton);

    QPushButton *elimButton = new QPushButton("Eliminar");
    ui->tlbUs->setCellWidget(fila, 5, elimButton);

    // Conectar las señales de los botones
    QObject::disconnect(modButton, &QPushButton::clicked, this, nullptr);
    QObject::disconnect(elimButton, &QPushButton::clicked, this, nullptr);

    connect(modButton, &QPushButton::clicked, this, [this, node]() {
        // Lógica para modificar el nodo
        limpiarTabla();
        tablaUser();
    });

    connect(elimButton, &QPushButton::clicked, this, [this, node]() {
        // Lógica para eliminar el nodo
        limpiarTabla();
        tablaUser();
    });
}


void BuscarAdmin::on_btnBuscar_clicked()
{
    buscar();
}

void BuscarAdmin::limpiarTabla(){
    ui->tlbUs->clearContents();
    ui->tlbUs->setRowCount(0);
}

void BuscarAdmin::on_pushButton_3_clicked()
{
    this->close();  // Cerrar la ventana actual CrearUser
    QWidget *parent = this->parentWidget();  // Obtener la ventana principal
    if (parent) {
        parent->show();  // Mostrar la ventana principal si existe
    }
}

void BuscarAdmin::OpcionesOrden(){
    QString combo = ui->cmbOrden->currentText();

    if(combo == "PreOrden"){
        limpiarTabla();


    }else if(combo == "PosOrden"){
        limpiarTabla();


    }else if(combo == "InOrden"){
        limpiarTabla();
        tablaUser();
    }

}

void BuscarAdmin::on_btnAplicar_clicked()
{
    OpcionesOrden();
}

