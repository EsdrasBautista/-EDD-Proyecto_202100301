#include "publicaciones.h"
#include "ui_publicaciones.h"
#include "./publicaciones.h"
#include "./GestionarSoli.h"
#include "./listaEnlazadaArbol.h"
#include "./nodoPublicacion.h"
#include "./crearpublicacion.h"
#include "./SimplePublicacion.h"
#include "./comentaru.h"
#include "./vercomentarios.h"
#include "./verarbolcomentarios.h"
#include <QIntValidator>

#include <QMessageBox>


Publicaciones::Publicaciones(QWidget *parent,listaEnlazadaArb* lista, const std::string& correo,listaPublicaciones* listap)
    : QMainWindow(parent)
    , ui(new Ui::Publicaciones),
    listaArbol(lista),      // Inicializar listaArbol
    correoUsuario(correo),   // Inicializar correoUsuario
    listaPub(listap),
    nodoActualPubs(nullptr)
{
    ui->setupUi(this);
    this->setWindowTitle("Publicaciones");
    llenarBST();
    llenarComboFecha();
    limpiarInfo();
    actualizarTodosPubs();
    QIntValidator *validador = new QIntValidator(1,100, this);
    ui->txtCantidad->setValidator(validador);


}

Publicaciones::~Publicaciones()
{
    delete ui;
}

void Publicaciones::on_pushButton_3_clicked()
{
    this->close();  // Cerrar la ventana actual CrearUser
    QWidget *parent = this->parentWidget();  // Obtener la ventana principal
    if (parent) {
        parent->show();  // Mostrar la ventana principal si existe
    }
}

void Publicaciones::actualizarTodosPubs(){
    gestionarSoli::agregarPublicacionesAmigos(*listaArbol,correoUsuario);
}

void Publicaciones::limpiarCombo(){
    ui->cmbFecha->clear();
    ui->cmbFecha->addItem("TODO");
}
void Publicaciones::on_btnCrearPub_clicked()
{
    CrearPublicacion *crear = new CrearPublicacion(this,listaArbol,correoUsuario,listaPub);
    this->hide();
    crear->show();
}

void Publicaciones::llenarBST(){
    gestionarSoli::agregarPublicacionesArbol(*listaArbol,correoUsuario);
}

void Publicaciones::llenarComboFecha(){
    nodoArbol* nodo = listaArbol->buscarNodoPorCorreoArb(correoUsuario);
    ArbolBST* arbolPub = nodo->getArbolPublicacionesBST();
    if (arbolPub != nullptr) {
        limpiarCombo();
        llenarComboFecha(arbolPub->getRaiz());
    }
}
void Publicaciones::llenarComboFecha(nodoBST *raiz){
    if (raiz != nullptr) {
        llenarComboFecha(raiz->getIzq());
        QString fecha = QString::fromStdString(raiz->getfecha());
        ui->cmbFecha->addItem(fecha);
        llenarComboFecha(raiz->getDrcha());
    }
}


void Publicaciones::on_pushButton_clicked()
{
    //mostrar publicaciones en una fecha en concreto
    QString qFecha = ui->cmbFecha->currentText();  // Obtener el texto seleccionado en el comboBox
    string fechaSeleccionada = qFecha.toStdString();

    QLineEdit* txtUsuario = ui->txtUsuario;
    QLineEdit* txtFecha = ui->txtFecha;
    QPlainTextEdit* textoPub = ui->plnText;
    QLabel* labelImagen = ui->lblImagen;
    nodoActualPubs = gestionarSoli::mostrarPublicacionesArbol(*listaArbol,correoUsuario,txtUsuario,txtFecha,textoPub,labelImagen,fechaSeleccionada);
}


void Publicaciones::on_pushButton_2_clicked()
{
    //aqui se aplica los ordenes y cantidades
    ui->txtUsuario->clear();
    QString qOrden = ui->cmbOrden->currentText();  // Obtener el texto seleccionado en el comboBox
    string ordenLista = qOrden.toStdString();
    QString qCant = ui->txtCantidad->text();
    string cantidads = qCant.toStdString();

    QLineEdit* txtUsuario = ui->txtUsuario;
    QLineEdit* txtFecha = ui->txtFecha;
    QPlainTextEdit* textoPub = ui->plnText;
    QLabel* labelImagen = ui->lblImagen;

    try {
        int cantidad = std::stoi(cantidads);

        if (cantidad < 1 || cantidad > (100)) {
            throw std::out_of_range("Cantidad fuera del rango permitido.");
        }

        nodoActualPubs = gestionarSoli::OrdenarPublicacionespor(*listaArbol,correoUsuario,txtUsuario,txtFecha,textoPub,labelImagen,cantidad,ordenLista);

    } catch (const std::invalid_argument&) {
        QMessageBox::warning(this, "Error", "El valor ingresado no es un número válido.");
    } catch (const std::out_of_range&) {
        QMessageBox::warning(this, "Error", "El valor ingresado está fuera del rango permitido.");
    }
}


void Publicaciones::on_btnSiguiente_clicked()
{
    if(nodoActualPubs != nullptr){
        nodoActualPubs = nodoActualPubs->getSiguiente();
        if(nodoActualPubs != nullptr){
            ui->txtUsuario->setText(QString::fromStdString(nodoActualPubs->getCorreoL()));
            ui->txtFecha->setText(QString::fromStdString(nodoActualPubs->getFechaL()));
            ui->plnText->setPlainText(QString::fromStdString(nodoActualPubs->getContenidoL()));

            if (nodoActualPubs->getImagen() != "") {
                QPixmap pixmap(QString::fromStdString(nodoActualPubs->getImagen()));
                ui->lblImagen->setPixmap(pixmap.scaled(ui->lblImagen->width(), ui->lblImagen->height(), Qt::KeepAspectRatio));
            } else {
                ui->lblImagen->clear();
            }

        }else{
            QMessageBox::information(this, "Fin", "No hay más publicaciones.");
        }
    }else{
        QMessageBox::information(this, "Publicacoines", "No hay más publicaciones.");
    }

}

void Publicaciones::limpiarInfo(){
    ui->txtCantidad->clear();
    ui->txtFecha->clear();
    ui->txtUsuario->clear();
    ui->lblImagen->clear();
    ui->plnText->clear();
}





void Publicaciones::on_btnComentar_clicked()
{
    if(nodoActualPubs != nullptr){
        ComentarU *coment = new ComentarU(this,listaArbol,nodoActualPubs->getCorreoL(),nodoActualPubs->getFechaL(),nodoActualPubs->getIdL(),nodoActualPubs,correoUsuario);
        this->hide();
        coment->show();
    }else{
        QMessageBox::warning(this,"Error","No hay publicacion para comentar");
    }

}


void Publicaciones::on_btnAnterior_clicked()
{
    if(nodoActualPubs != nullptr){
        nodoActualPubs = nodoActualPubs->getAnterior();
        if(nodoActualPubs != nullptr){
            ui->txtUsuario->setText(QString::fromStdString(nodoActualPubs->getCorreoL()));
            ui->txtFecha->setText(QString::fromStdString(nodoActualPubs->getFechaL()));
            ui->plnText->setPlainText(QString::fromStdString(nodoActualPubs->getContenidoL()));

            if (nodoActualPubs->getImagen() != "") {
                QPixmap pixmap(QString::fromStdString(nodoActualPubs->getImagen()));
                ui->lblImagen->setPixmap(pixmap.scaled(ui->lblImagen->width(), ui->lblImagen->height(), Qt::KeepAspectRatio));
            } else {
                ui->lblImagen->clear();
            }

        }else{
            QMessageBox::information(this, "Fin", "No hay más publicaciones.");
        }
    }else{
        QMessageBox::information(this, "Publicacoines", "No hay más publicaciones.");
    }
}


void Publicaciones::on_btnVercoment_clicked()
{
    if(nodoActualPubs != nullptr){
        verComentarios *coments = new verComentarios(this,listaArbol,nodoActualPubs->getCorreoL(),nodoActualPubs->getFechaL(),nodoActualPubs->getIdL());
        this->hide();
        coments->llenarComentarios();
        coments->show();

    }else{
        QMessageBox::warning(this,"Advertencia","No se puede ver los comentarios");
    }

}


void Publicaciones::on_btnVerArbol_clicked()
{
    if(nodoActualPubs != nullptr){
        verArbolComentarios *coments = new verArbolComentarios(this,listaArbol,nodoActualPubs->getCorreoL(),nodoActualPubs->getFechaL(),nodoActualPubs->getIdL());
        this->hide();
        coments->show();

    }else{
        QMessageBox::warning(this,"Advertencia","No se puede ver los comentarios");
    }
}

