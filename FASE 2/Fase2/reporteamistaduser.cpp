#include "reporteamistaduser.h"
#include "ui_reporteamistaduser.h"
#include "./GestionarSoli.h"
#include <QMessageBox>


reporteAmistadUser::reporteAmistadUser(QWidget *parent, listaEnlazadaArb *lista, const string &correo)
    : QMainWindow(parent)
    , ui(new Ui::reporteAmistadUser),
    listaArbol(lista),
    correoUsuario(correo)

{
    ui->setupUi(this);
    this->setWindowTitle("ReporteAmistad");
}

reporteAmistadUser::~reporteAmistadUser()
{
    delete ui;
}

void reporteAmistadUser::on_pushButton_3_clicked()
{
    this->close();  // Cerrar la ventana actual CrearUser
    QWidget *parent = this->parentWidget();  // Obtener la ventana principal
    if (parent) {
        parent->show();  // Mostrar la ventana principal si existe
    }
}


void reporteAmistadUser::on_btnUsers_clicked()
{
    if(listaArbol != nullptr){
        bool estado = gestionarSoli::generarGradoAmistadUser(*listaArbol,correoUsuario);
        if(estado){
            QString rutaImg = "C:/Users/bauti/Desktop/USAC/2024/SEMESTRE 2/EDD/LAB/PROYECTO/FASE 2/Fase2/build/Desktop_Qt_6_7_2_MinGW_64_bit-Debug/grafo.png";

            QPixmap pixmap(rutaImg);
            if (!pixmap.isNull()) {
                ui->lblUser->setPixmap(pixmap);
                ui->lblUser->setScaledContents(true);  // Ajusta la imagen al tamaño del label
            } else {
                QMessageBox::warning(this, "Advertencia", "No se pudo cargar la imagen generada.");
            }

        }else{
            QMessageBox::warning(this,"Advertencia","No se genero correctamente el grafo!");
        }
    }else{
        QMessageBox::warning(this,"Advertencia","No hay relacion de amistades aun!");
    }

}

