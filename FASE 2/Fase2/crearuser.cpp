#include "crearuser.h"
#include "ui_crearuser.h"
#include "./mainwindow.h"
#include <QMessageBox>


CrearUser::CrearUser(QWidget *parent,listaEnlazadaArb* lista)
    : QMainWindow(parent)
    , ui(new Ui::CrearUser),
    listaArbol(lista)
{
    ui->setupUi(this);

    this->setWindowTitle("CrearUsuario");
}

CrearUser::~CrearUser()
{
    delete ui;
}

void CrearUser::on_btnRegresar_clicked()
{
    this->close();  // Cerrar la ventana actual CrearUser
    QWidget *parent = this->parentWidget();  // Obtener la ventana principal
    if (parent) {
        parent->show();  // Mostrar la ventana principal si existe
    }
}


void CrearUser::on_btnCrearUser_clicked()
{
    QString qnombre = ui->txtNombres->text();
    QString qapellidos = ui->txtApellidos->text();
    QString qcorreo = ui->txtCorreoU->text();
    QString qcontra = ui->txtContraU->text();
    QString qfechaN = ui->txtFechaN->text();


    if(qnombre.isEmpty() || qapellidos.isEmpty() || qcorreo.isEmpty() || qcontra.isEmpty() || qfechaN.isEmpty()){
        QMessageBox::warning(this, "Error al crear Usuario", "Llena todos los campos!");

    } else {

        string nombre = qnombre.toStdString();
        string apellidos = qapellidos.toStdString();
        string correo = qcorreo.toStdString();
        string contra = qcontra.toStdString();
        string fechaN = qfechaN.toStdString();
        bool verificar = listaArbol->verificarCorreoArb(correo);
        if(verificar){
            listaArbol->agregarUsuario(nombre, apellidos, correo, contra, fechaN);
            QMessageBox::information(this, "Usuario Creado", "El usuario ha sido creado con éxito!");
            ui->txtNombres->clear();
            ui->txtApellidos->clear();
            ui->txtCorreoU->clear();
            ui->txtContraU->clear();
            ui->txtFechaN->clear();

        }else{
            QMessageBox::warning(this, "Error al crear Usuario", "Correo ya existente!");
            ui->txtCorreoU->clear();
        }

    }



}

