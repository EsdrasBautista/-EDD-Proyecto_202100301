#include "reportesadmin.h"
#include "ui_reportesadmin.h"
#include <QPixmap>
#include <QMessageBox>


ReportesAdmin::ReportesAdmin(QWidget *parent,listaEnlazadaArb* lista,listaPublicaciones* listap)
    : QMainWindow(parent)
    , ui(new Ui::ReportesAdmin),
    listaArbol(lista),
    listaPub(listap)
{
    ui->setupUi(this);
    this->setWindowTitle("ReportesAdmin");
}

ReportesAdmin::~ReportesAdmin()
{
    delete ui;
}

void ReportesAdmin::on_btnUsers_clicked()
{
    listaArbol->graph(); //AVL
    listaPub->graficarListaP(); //publicacionesGeneral_

    QString ruta1 = QString::fromStdString("C:/Users/bauti/Desktop/USAC/2024/SEMESTRE 2/EDD/LAB/PROYECTO/FASE 2/Fase2/build/Desktop_Qt_6_7_2_MinGW_64_bit-Debug/AVL.png");
    QString ruta2 = QString::fromStdString("C:/Users/bauti/Desktop/USAC/2024/SEMESTRE 2/EDD/LAB/PROYECTO/FASE 2/Fase2/build/Desktop_Qt_6_7_2_MinGW_64_bit-Debug/listaPublicacionesGeneral.png");

    QPixmap pixmapUser(ruta1);
    QPixmap pixmapPub(ruta2);

    if (!pixmapUser.isNull() && !pixmapPub.isNull()) {
        QPixmap scaledPixmapUser = pixmapUser.scaled(ui->lblUser->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        ui->lblUser->setPixmap(scaledPixmapUser);

        QPixmap scaledPixmapPub = pixmapPub.scaled(ui->lblPub->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        ui->lblPub->setPixmap(scaledPixmapPub);

        QMessageBox::information(this, "Graficas", "¡Se generaron los reportes con Exito!");
    } else {
        QMessageBox::warning(this, "Error", "No se pudieron cargar las imagenes generadas.");
    }
}


void ReportesAdmin::on_pushButton_3_clicked()
{
    this->close();  // Cerrar la ventana actual CrearUser
    QWidget *parent = this->parentWidget();  // Obtener la ventana principal
    if (parent) {
        parent->show();  // Mostrar la ventana principal si existe
    }
}

