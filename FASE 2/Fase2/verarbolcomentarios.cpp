#include "verarbolcomentarios.h"
#include "ui_verarbolcomentarios.h"
#include "./GestionarSoli.h"

verArbolComentarios::verArbolComentarios(QWidget *parent,listaEnlazadaArb* lista,const std::string& correo,const std::string& fecha,int id)
    : QMainWindow(parent)
    , ui(new Ui::verArbolComentarios),
    listaArbol(lista),
    correoUsuario(correo),
    fechaU(fecha),
    idU(id)
{
    ui->setupUi(this);
    this->setWindowTitle("ArbolComentarios");
    mostrar();
}

verArbolComentarios::~verArbolComentarios()
{
    delete ui;
}

void verArbolComentarios::on_pushButton_3_clicked()
{
    this->close();  // Cerrar la ventana actual CrearUser
    QWidget *parent = this->parentWidget();  // Obtener la ventana principal
    if (parent) {
        parent->show();  // Mostrar la ventana principal si existe
    }
}

void verArbolComentarios::mostrar(){
    QLabel *img = ui->lblimg;
    gestionarSoli::mostrarArbolB(*listaArbol,correoUsuario,fechaU,idU,img,this);
}
