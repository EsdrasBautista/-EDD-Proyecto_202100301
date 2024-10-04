#include "reportesuser.h"
#include "ui_reportesuser.h"
#include <QMessageBox>

reportesUser::reportesUser(QWidget *parent,listaEnlazadaArb* lista, const std::string& correo,listaPublicaciones* listap)
    : QMainWindow(parent)
    , ui(new Ui::reportesUser),
    listaArbol(lista),      // Inicializar listaArbol
    correoUsuario(correo),   // Inicializar correoUsuario
    listaPub(listap)
{
    ui->setupUi(this);
    this->setWindowTitle("ReportesUser");
    llenarComboFecha();
}

reportesUser::~reportesUser()
{
    delete ui;
}

void reportesUser::on_btnBst_clicked()
{
    QString Qfecha = ui->cmbFecha->currentText();
    string fecha =  Qfecha.toStdString();
    if(fecha == ""){
        QMessageBox::warning(this,"Advertencia","Error, Seleccion una fecha!");
    }else{

        nodoArbol* nodo = listaArbol->buscarNodoPorCorreoArb(correoUsuario);
        ArbolBST* arbolBst = nodo->getArbolPublicacionesBST();
        if(arbolBst != nullptr){
            nodoBST* arbolP = arbolBst->graficarNodoporFecha(fecha);
            if(arbolP != nullptr){
                QString ruta1 = QString::fromStdString("C:/Users/bauti/Desktop/USAC/2024/SEMESTRE 2/EDD/LAB/PROYECTO/FASE 2/Fase2/build/Desktop_Qt_6_7_2_MinGW_64_bit-Debug/AVLFecha.png");
                QPixmap pixmapUser(ruta1);
                if (!pixmapUser.isNull()){
                    QPixmap scaledPixmapUser = pixmapUser.scaled(ui->lblImagen->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
                    ui->lblImagen->setPixmap(scaledPixmapUser);
                    QMessageBox::information(this,"Exito","Se grafico con exito!");
                }else{
                    QMessageBox::warning(this,"Advertencia","Problemas al insertar la imagen!");
                }

            }else{
                QMessageBox::warning(this,"Advertencia","Error al graficar!");
            }
        }else{
            QMessageBox::warning(this,"Advertencia","No hay publicaciones aun!");
        }
    }



}

void reportesUser::limpiarCombo(){
    ui->cmbFecha->clear();
}

void reportesUser::llenarComboFecha(){
    nodoArbol* nodo = listaArbol->buscarNodoPorCorreoArb(correoUsuario);
    ArbolBST* arbolPub = nodo->getArbolPublicacionesBST();
    if (arbolPub != nullptr) {
        limpiarCombo();
        llenarComboFecha(arbolPub->getRaiz());
    }
}
void reportesUser::llenarComboFecha(nodoBST *raiz){
    if (raiz != nullptr) {
        llenarComboFecha(raiz->getIzq());
        QString fecha = QString::fromStdString(raiz->getfecha());
        ui->cmbFecha->addItem(fecha);
        llenarComboFecha(raiz->getDrcha());
    }
}

void reportesUser::on_pushButton_3_clicked()
{
    this->close();  // Cerrar la ventana actual CrearUser
    QWidget *parent = this->parentWidget();  // Obtener la ventana principal
    if (parent) {
        parent->show();  // Mostrar la ventana principal si existe
    }
}

