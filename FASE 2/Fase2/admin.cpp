#include "admin.h"
#include "ui_admin.h"
#include "buscaradmin.h"
#include "cargaradmin.h"
#include "reportesadmin.h"
#include "reportegrafo.h"
#include "reporteady.h"
#include "reportemerkle.h"

Admin::Admin(QWidget *parent, listaEnlazadaArb* lista,listaPublicaciones* listap,listaAdyacencia *grafo)
    : QMainWindow(parent)
    , ui(new Ui::Admin),
    listaArbol(lista),
    listaPub(listap),
    grafoAdy(grafo)
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
    BuscarAdmin *buscar = new BuscarAdmin(this,listaArbol,listaPub);
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
    CargarAdmin *cargar = new CargarAdmin(this,listaArbol,listaPub,grafoAdy);
    this->hide();
    cargar->show();
}


void Admin::on_actionREPORTES_triggered()
{
    ReportesAdmin *repo = new ReportesAdmin(this,listaArbol,listaPub);
    this->hide();
    repo->show();
}


void Admin::on_actionAMISTAD_triggered()
{
    reporteGrafo *repo = new reporteGrafo(this,grafoAdy);
    this->hide();
    repo->show();
}


void Admin::on_actionADYACENCIA_AMISTAD_triggered()
{
    reporteAdy *repo = new reporteAdy(this,grafoAdy);
    this->hide();
    repo->show();
}


void Admin::on_actionMERKLE_POR_USUARIO_triggered()
{
    reporteMerkle *repo = new reporteMerkle(this,listaArbol);
    this->hide();
    repo->show();
}

