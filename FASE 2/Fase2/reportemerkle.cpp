#include "reportemerkle.h"
#include "ui_reportemerkle.h"
#include <QMessageBox>
#include "GestionarSoli.h"

reporteMerkle::reporteMerkle(QWidget *parent,listaEnlazadaArb* lista)
    : QMainWindow(parent)
    , ui(new Ui::reporteMerkle),
    listaArbol(lista)
{
    ui->setupUi(this);
    this->setWindowTitle("ReporteMerkle");
    llenarCombo();
}

reporteMerkle::~reporteMerkle()
{
    delete ui;
}

void reporteMerkle::llenarCombo(){
    if(listaArbol != nullptr){
        ui->cmbOrden->clear();
        llenarComboRecursivo(listaArbol->getRaiz());
    }
}

void reporteMerkle::llenarComboRecursivo(nodoArbol *actual){
    if(actual != nullptr){
        ui->cmbOrden->addItem(QString::fromStdString(actual->getCorreo()));
        llenarComboRecursivo(actual->getIzquierda());
        llenarComboRecursivo(actual->getDerecha());
    }
}

void reporteMerkle::on_btnUsers_clicked()
{
    QString seleccionado = ui->cmbOrden->currentText();
    std::string valorSeleccionado = seleccionado.toStdString();
    if(valorSeleccionado == ""){
        QMessageBox::warning(this,"Advertencia","Debes de seleccionar un Usuario!");
    }else{
        bool estado = gestionarSoli::generarMerkleUsuario(*listaArbol,valorSeleccionado);
        if(estado){
            QString rutaImg = "C:/Users/bauti/Desktop/USAC/2024/SEMESTRE 2/EDD/LAB/PROYECTO/FASE 2/Fase2/build/Desktop_Qt_6_7_2_MinGW_64_bit-Debug/merkle.png";

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
    }
}


void reporteMerkle::on_pushButton_3_clicked()
{
    this->close();  // Cerrar la ventana actual CrearUser
    QWidget *parent = this->parentWidget();  // Obtener la ventana principal
    if (parent) {
        parent->show();  // Mostrar la ventana principal si existe
    }
}

