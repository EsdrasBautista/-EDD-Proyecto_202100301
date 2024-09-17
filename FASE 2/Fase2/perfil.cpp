#include "./perfil.h"
#include "ui_perfil.h"
#include "./userint.h"
#include "./mainwindow.h"
#include "./GestionarSoli.h"
#include <QMessageBox>


Perfil::Perfil(QWidget *parent, listaEnlazadaArb *lista, const std::string &correo)
    : QMainWindow(parent)
    , ui(new Ui::Perfil),
    listaArbol(lista),      // Inicializar listaArbol
    correoUsuario(correo)   // Inicializar correoUsuario
{
    ui->setupUi(this);
    this->setWindowTitle("Perfil");
    llenarCampos();
}

Perfil::~Perfil()
{
    delete ui;
}


void Perfil::on_pushButton_3_clicked()
{
    this->close();  // Cerrar la ventana actual de perfil
    UserInt* parent = qobject_cast<UserInt*>(this->parentWidget());  // Obtener la ventana principal
    if (parent) {
        parent->actualizarNombreUsuario();  // Actualizar manualmente el nombre en UserInt
        parent->show();  // Mostrar la ventana principal si existe
    }
}

void Perfil::llenarCampos(){
    nodoArbol* datos = nullptr;
    datos = listaArbol->buscarNodoPorCorreoArb(correoUsuario);

    string nombre = datos->getNombres();
    string apellido = datos->getApellidos();
    string correo = datos->getCorreo();
    string contra = datos->getContrasena();
    string fechaN = datos->getFechaNacimiento();

    QString qNombre = QString::fromStdString(nombre);
    QString qApellido = QString::fromStdString(apellido);
    QString qCorreo = QString::fromStdString(correo);
    QString qContra = QString::fromStdString(contra);
    QString qFecha = QString:: fromStdString(fechaN);

    ui->txtNombres->setText(qNombre);
    ui->txtApellidos->setText(qApellido);
    ui->txtCorreoU->setText(qCorreo);
    ui->txtContraU->setText(qContra);
    ui->txtFechaN->setText(qFecha);
}


void Perfil::on_pushButton_2_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Eliminar usuario", "¿Está seguro de que desea eliminar este usuario?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        gestionarSoli::EliminarCuenta(*listaArbol,correoUsuario);
        QMessageBox::information(this,"Estado Cuenta","Cuenta Eliminada con Exito!");


        this->close();
        UserInt* userIntWindow = qobject_cast<UserInt*>(this->parentWidget());
        if (userIntWindow) {
            userIntWindow->close();
            MainWindow* mainWindow = qobject_cast<MainWindow*>(userIntWindow->parentWidget());
            if (mainWindow) {
                mainWindow->show();
            }
        }

    } else {
        QMessageBox::information(this, "Cancelar", "El usuario no fue eliminado.");
    }

}


void Perfil::on_pushButton_clicked()
{
    nodoArbol *minodo = listaArbol->buscarNodoPorCorreoArb(correoUsuario);

    QString qnombre = ui->txtNombres->text();
    QString qapellidos = ui->txtApellidos->text();
    QString qcorreo = ui->txtCorreoU->text();
    QString qcontra = ui->txtContraU->text();
    QString qfechaN = ui->txtFechaN->text();

    if(qnombre.isEmpty() || qapellidos.isEmpty() || qcorreo.isEmpty() || qcontra.isEmpty() || qfechaN.isEmpty()){
        QMessageBox::warning(this, "Error al crear Usuario", "Llena todos los campos!");

    }else{

        string nombre = qnombre.toStdString();
        string apellidos = qapellidos.toStdString();
        string nuevoCorreo = qcorreo.toStdString();
        string contra = qcontra.toStdString();
        string fechaN = qfechaN.toStdString();

        if(nombre == minodo->getNombres() || apellidos == minodo->getApellidos() || nuevoCorreo == minodo->getCorreo() || contra == minodo->getContrasena() || fechaN == minodo->getFechaNacimiento()){
            QMessageBox::information(this, "Actualizacion", "No se actualizo ningun dato, los datos siguen igual!");
        }else{
            if (nuevoCorreo != correoUsuario) {
                minodo->setCorreo(nuevoCorreo);
                minodo->setNombres(nombre);
                minodo->setApellidos(apellidos);
                minodo->setContrasena(contra);
                minodo->setFechaNacimiento(fechaN);
                correoUsuario = nuevoCorreo;
                listaArbol->actualizarArbol(nuevoCorreo,true);
                QMessageBox::information(this, "Actualizacion", "Datos Actualizados con Exito!");

            }else{
                minodo->setNombres(nombre);
                minodo->setApellidos(apellidos);
                minodo->setContrasena(contra);
                minodo->setFechaNacimiento(fechaN);
                QMessageBox::information(this, "Actualizacion", "Datos Actualizados con Exito!!");
            }
        }
    }
}

