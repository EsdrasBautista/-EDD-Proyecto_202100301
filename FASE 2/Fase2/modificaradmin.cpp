#include "modificaradmin.h"
#include "ui_modificaradmin.h"
#include "./GestionarSoli.h"
#include "./buscaradmin.h"
#include <QMessageBox>

ModificarAdmin::ModificarAdmin(QWidget *parent,listaEnlazadaArb *lista, const std::string &correo)
    : QMainWindow(parent)
    , ui(new Ui::ModificarAdmin),
    listaArbol(lista),
    correoUsuario(correo)
{
    ui->setupUi(this);
    llenarCamposAdmin();
}

ModificarAdmin::~ModificarAdmin()
{
    delete ui;
}


void ModificarAdmin::llenarCamposAdmin(){
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

void ModificarAdmin::on_btnModificar_clicked()
{
    nodoArbol *minodo = listaArbol->buscarNodoPorCorreoArb(correoUsuario);

    QString qnombre = ui->txtNombres->text();
    QString qapellidos = ui->txtApellidos->text();
    QString qcontra = ui->txtContraU->text();
    QString qfechaN = ui->txtFechaN->text();

    if(qnombre.isEmpty() || qapellidos.isEmpty() || qcontra.isEmpty() || qfechaN.isEmpty()){
        QMessageBox::warning(this, "Error al crear Usuario", "Llena todos los campos!");

    }else{

        string nombre = qnombre.toStdString();
        string apellidos = qapellidos.toStdString();
        string contra = qcontra.toStdString();
        string fechaN = qfechaN.toStdString();

        if(nombre == minodo->getNombres() && apellidos == minodo->getApellidos() &&  contra == minodo->getContrasena() && fechaN == minodo->getFechaNacimiento()){
            QMessageBox::information(this, "Actualizacion", "No se actualizo ningun dato, los datos siguen igual!");
        }else{

            minodo->setNombres(nombre);
            minodo->setApellidos(apellidos);
            minodo->setContrasena(contra);
            minodo->setFechaNacimiento(fechaN);
            QMessageBox::information(this, "Actualizacion", "Datos Actualizados con Exito!!");

        }
    }
}


void ModificarAdmin::on_btnRegresar_clicked()
{
    this->close();  // Cerrar la ventana actual de perfil
    BuscarAdmin* parent = qobject_cast<BuscarAdmin*>(this->parentWidget());  // Obtener la ventana principal
    if (parent) {
        parent->ActualizarTabla();
        parent->show();  // Mostrar la ventana principal si existe
    }
}

