#include "admin.h"
#include "ui_admin.h"
#include "buscaradmin.h"
#include "cargaradmin.h"
#include "reportesadmin.h"

Admin::Admin(QWidget *parent, listaEnlazadaArb* lista,listaPublicaciones* listap)
    : QMainWindow(parent)
    , ui(new Ui::Admin),
    listaArbol(lista),
    listaPub(listap)
{
    ui->setupUi(this);
    this->setWindowTitle("Administrador");
}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_actionBUSCAR_triggered()
{
    BuscarAdmin *buscar = new BuscarAdmin(this,listaArbol);
    this->hide();
    buscar->show();
}


void Admin::on_pushButton_clicked()
{
    this->close();  // Cerrar la ventana actual CrearUser
    QWidget *parent = this->parentWidget();  // Obtener la ventana principal
    if (parent) {
        parent->show();  // Mostrar la ventana principal si existe
    }
}


void Admin::on_actionCARGA_MASIVA_triggered()
{
    CargarAdmin *cargar = new CargarAdmin(this,listaArbol);
    this->hide();
    cargar->show();
}


void Admin::on_actionREPORTES_triggered()
{
    ReportesAdmin *repo = new ReportesAdmin(this,listaArbol,listaPub);
    this->hide();
    repo->show();
}

