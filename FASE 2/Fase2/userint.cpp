#include "userint.h"
#include "ui_userint.h"
#include "./mainwindow.h"
#include "./perfil.h"
#include "./buscar.h"
#include "./solicitudes.h"
#include "./publicaciones.h"
#include "./GestionarSoli.h"
#include "./reportesuser.h"
#include "./reporteamistaduser.h"
#include "./reporteadyuser.h"


UserInt::UserInt(QWidget *parent,listaEnlazadaArb* lista, const std::string& correo,listaPublicaciones* listap,listaAdyacencia* grafo)
    : QMainWindow(parent)
    , ui(new Ui::UserInt),
    listaArbol(lista),
    correoUsuario(correo),
    listaPub(listap),
    grafoAdy(grafo)
{
    ui->setupUi(this);
    this->setWindowTitle("MiUsuario");


}

UserInt::~UserInt()
{
    delete ui;
}

void UserInt::actualizarNombreUsuario(){
    nodoArbol* usuarioNodo = listaArbol->buscarNodoPorCorreoArb(correoUsuario);

    if (usuarioNodo != nullptr) {
        std::string nombreCompleto = usuarioNodo->getNombres() + " " + usuarioNodo->getApellidos();
        setNombreUsuario(nombreCompleto);
    }
}

void UserInt::setNombreUsuario(string nombre)
{
    QString qNombre = QString::fromStdString(nombre);

    ui->lblNombreU->setText(qNombre);
}

void UserInt::on_pushButton_clicked()
{
    this->close();  // Cerrar la ventana actual CrearUser
    QWidget *parent = this->parentWidget();  // Obtener la ventana principal
    if (parent) {
        parent->show();  // Mostrar la ventana principal si existe
    }
}



void UserInt::on_actionPERFIL_triggered()
{
    Perfil *perfil = new Perfil(this,listaArbol,correoUsuario);
    this->hide();
    perfil->show();
}


void UserInt::on_actionBUSCAR_triggered()
{
    Buscar *buscar = new Buscar(this,listaArbol);
    this->hide();
    buscar->show();
}


void UserInt::on_actionSOLICITUDES_triggered()
{
    Solicitudes *sol = new Solicitudes(this,listaArbol,correoUsuario,grafoAdy);
    this->hide();
    sol->show();
}


void UserInt::on_actionPUBLICACIONES_triggered()
{
    Publicaciones *pub = new Publicaciones(this,listaArbol,correoUsuario,listaPub);
    this->hide();
    pub->llenarBST();
    pub->llenarComboFecha();
    pub->actualizarTodosPubs();
    pub->show();

}


void UserInt::on_pushButton_2_clicked()
{
    gestionarSoli::verAmigos(*listaArbol,correoUsuario);
}


void UserInt::on_actionGENERAR_REPORTES_triggered()
{
    reportesUser *repo = new reportesUser(this,listaArbol,correoUsuario,listaPub);
    this->hide();
    repo->show();
    repo->llenarComboFecha();

}


void UserInt::on_actionGRAFO_AMISTAD_triggered()
{
    reporteAmistadUser *repo = new reporteAmistadUser(this,listaArbol,correoUsuario);
    this->hide();
    repo->show();
}


void UserInt::on_actionADYACENCIA_AMISTAD_triggered()
{
    reporteAdyUser *repo = new reporteAdyUser(this,listaArbol,correoUsuario);
    this->hide();
    repo->show();
}

