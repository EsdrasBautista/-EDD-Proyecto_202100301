#include "publicaciones.h"
#include "ui_publicaciones.h"
#include "./publicaciones.h"
#include "./GestionarSoli.h"
#include "./listaEnlazadaArbol.h"
#include "./nodoPublicacion.h"
#include "./crearpublicacion.h"

#include <QMessageBox>


Publicaciones::Publicaciones(QWidget *parent,listaEnlazadaArb* lista, const std::string& correo,listaPublicaciones* listap)
    : QMainWindow(parent)
    , ui(new Ui::Publicaciones),
    listaArbol(lista),      // Inicializar listaArbol
    correoUsuario(correo),   // Inicializar correoUsuario
    listaPub(listap)
{
    ui->setupUi(this);
    this->setWindowTitle("Publicaciones");

}

Publicaciones::~Publicaciones()
{
    delete ui;
}

void Publicaciones::on_pushButton_3_clicked()
{
    this->close();  // Cerrar la ventana actual CrearUser
    QWidget *parent = this->parentWidget();  // Obtener la ventana principal
    if (parent) {
        parent->show();  // Mostrar la ventana principal si existe
    }
}


void Publicaciones::on_btnCrearPub_clicked()
{
    CrearPublicacion *crear = new CrearPublicacion(this,listaArbol,correoUsuario,listaPub);
    this->hide();
    crear->show();
}

