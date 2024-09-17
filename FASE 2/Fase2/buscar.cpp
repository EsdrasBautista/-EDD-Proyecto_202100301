#include "buscar.h"
#include "ui_buscar.h"
#include <QMessageBox>

Buscar::Buscar(QWidget *parent,listaEnlazadaArb* lista)
    : QMainWindow(parent)
    , ui(new Ui::Buscar),
    listaArbol(lista)
{
    ui->setupUi(this);
    this->setWindowTitle("BuscarUsuario");
}

Buscar::~Buscar()
{
    delete ui;
}

void Buscar::on_btnBuscar_clicked()
{
    QString qCorreo = ui->txtBuscar->text();  // Obtener texto como QString
    string correoUsuario = qCorreo.toStdString();

    nodoArbol* datos = nullptr;
    datos = listaArbol->buscarNodoPorCorreoArb(correoUsuario);

    if(datos == nullptr){
        QMessageBox::warning(this, "Error al Buscar Usuario", "Usuario no encontrado!");
    }else{

        string nombre = datos->getNombres();
        string apellido = datos->getApellidos();
        string correo = datos->getCorreo();
        string fechaN = datos->getFechaNacimiento();

        QString qNombre = QString::fromStdString(nombre);
        QString qApellido = QString::fromStdString(apellido);
        QString qCorreo = QString::fromStdString(correo);
        QString qFecha = QString:: fromStdString(fechaN);

        ui->txtNombres->setText(qNombre);
        ui->txtApellidos->setText(qApellido);
        ui->txtCorreoU->setText(qCorreo);
        ui->txtFechaN->setText(qFecha);
    }

}


void Buscar::on_pushButton_3_clicked()
{
    this->close();  // Cerrar la ventana actual CrearUser
    QWidget *parent = this->parentWidget();  // Obtener la ventana principal
    if (parent) {
        parent->show();  // Mostrar la ventana principal si existe
        ui->txtNombres->clear();
        ui->txtApellidos->clear();
        ui->txtCorreoU->clear();
        ui->txtBuscar->clear();
        ui->txtFechaN->clear();
    }
}

