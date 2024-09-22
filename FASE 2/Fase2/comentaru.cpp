#include "comentaru.h"
#include "ui_comentaru.h"
#include "./listaPublicaciones.h"
#include "./GestionarSoli.h"


ComentarU::ComentarU(QWidget *parent,nodoSimplePub *nodoPubs,const std::string& correo )
    : QMainWindow(parent)
    , ui(new Ui::ComentarU),
    nodoActualPubs(nodoPubs),
    correoUsuario(correo)
{
    ui->setupUi(this);
    this->setWindowTitle("ComentarPublicacion");
    llenarCampos();
    ui->txtFechaa->setDate(QDate::currentDate());
    ui->txtHora->setTime(QTime::currentTime());
}

ComentarU::~ComentarU()
{
    delete ui;
}

void ComentarU::llenarCampos(){
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

    }
}



void ComentarU::on_btnComentar_clicked()
{
    if(nodoActualPubs != nullptr){

        QTime horaSeleccionada = ui->txtHora->time();
        QString horaString = horaSeleccionada.toString("HH:mm");

        QString qFecha = ui->txtFechaa->text();
        string fecha = qFecha.toStdString();
        QString qCont = ui->txtComentario->toPlainText();
        string contenido = qCont.toStdString();
        string hora = horaString.toStdString();


        gestionarSoli::agregarComentario(*nodoActualPubs,fecha,hora,contenido,correoUsuario,this);

        ui->txtComentario->clear();
        ui->txtFechaa->setDate(QDate::currentDate());
        ui->txtHora->setTime(QTime::currentTime());
    }
}


void ComentarU::on_btnRegresar_clicked()
{
    this->close();  // Cerrar la ventana actual CrearUser
    QWidget *parent = this->parentWidget();  // Obtener la ventana principal
    if (parent) {
        parent->show();  // Mostrar la ventana principal si existe
    }
}

