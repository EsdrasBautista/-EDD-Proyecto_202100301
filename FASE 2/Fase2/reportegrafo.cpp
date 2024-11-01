#include "reportegrafo.h"
#include "ui_reportegrafo.h"
#include <QMessageBox>

reporteGrafo::reporteGrafo(QWidget *parent,listaAdyacencia* grafo)
    : QMainWindow(parent)
    , ui(new Ui::reporteGrafo),
    grafoAdy(grafo)
{
    ui->setupUi(this);
    this->setWindowTitle("ReporteGrafo");
}

reporteGrafo::~reporteGrafo()
{
    delete ui;
}

void reporteGrafo::on_pushButton_3_clicked()
{
    this->close();  // Cerrar la ventana actual CrearUser
    QWidget *parent = this->parentWidget();  // Obtener la ventana principal
    if (parent) {
        parent->show();  // Mostrar la ventana principal si existe
    }
}



void reporteGrafo::on_btnUsers_clicked()
{
    if(grafoAdy != nullptr){
        //generar el grafo
        bool estado = grafoAdy->crearGrafo();
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

