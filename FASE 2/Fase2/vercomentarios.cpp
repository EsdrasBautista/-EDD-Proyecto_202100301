#include "vercomentarios.h"
#include "ui_vercomentarios.h"
#include "./listaPublicaciones.h"
#include "./listaEnlazadaArbol.h"
#include "./GestionarSoli.h"
#include <QMessageBox>


verComentarios::verComentarios(QWidget *parent,listaEnlazadaArb* lista,const std::string& correo,const std::string& fecha,int id)
    : QMainWindow(parent)
    , ui(new Ui::verComentarios),
    listaArbol(lista),
    correoUsuario(correo),
    fechaU(fecha),
    idU(id)
{
    ui->setupUi(this);
    this->setWindowTitle("VerComentarios");

}

verComentarios::~verComentarios()
{
    delete ui;
}

void verComentarios::on_pushButton_3_clicked()
{
    this->close();  // Cerrar la ventana actual CrearUser
    QWidget *parent = this->parentWidget();  // Obtener la ventana principal
    if (parent) {
        parent->show();  // Mostrar la ventana principal si existe
    }
}

void verComentarios::llenarComentarios(){
    QPlainTextEdit* txtarea = ui->txtArea;
    txtarea->clear();

    gestionarSoli::verComentarios(*listaArbol,correoUsuario,fechaU,idU,txtarea);


}
