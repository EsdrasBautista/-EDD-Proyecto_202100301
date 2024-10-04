#include "crearpublicacion.h"
#include "ui_crearpublicacion.h"
#include "./publicaciones.h"
#include <QFileDialog>
#include <QPixmap>
#include <QDate>
#include <QMessageBox>


CrearPublicacion::CrearPublicacion(QWidget *parent,listaEnlazadaArb* lista, const std::string& correo,listaPublicaciones* listap)
    : QMainWindow(parent)
    , ui(new Ui::CrearPublicacion),
    listaArbol(lista),      // Inicializar listaArbol
    correoUsuario(correo),   // Inicializar correoUsuario
    listaPub(listap)
{
    ui->setupUi(this);
    this->setWindowTitle("CrearPublicacion");
    ui->txtFecha->setDisplayFormat("dd/MM/yyyy");
    ui->txtFecha->setDate(QDate::currentDate());
    ui->txtHora->setTime(QTime::currentTime());
}

CrearPublicacion::~CrearPublicacion()
{
    delete ui;
}

void CrearPublicacion::on_pushButton_3_clicked()
{
    this->close();  // Cerrar la ventana actual CrearUser
    Publicaciones* parent = qobject_cast<Publicaciones*>(this->parentWidget());
    if (parent) {
        parent->llenarComboFecha();
        parent->llenarBST();
        parent->limpiarInfo();
        parent->actualizarTodosPubs();
        parent->show();  // Mostrar la ventana principal si existe
    }

}


void CrearPublicacion::on_btnImagen_clicked()
{
    rutaImagen= "";

    QString fileName = QFileDialog::getOpenFileName(this, tr("Seleccionar Imagen"), "", tr("Imagenes (*.png *.jpg *.jpeg )"));
    std::cout << fileName.toStdString() << std::endl;
    if (!fileName.isEmpty()) {
        QPixmap image(fileName);
        ui->lblImg->setPixmap(image.scaled(ui->lblImg->width(), ui->lblImg->height(), Qt::KeepAspectRatio));

        rutaImagen = fileName.toStdString();  //ruta de la imagen
        std::cout << rutaImagen << std::endl;
        // Obtener el nombre del archivo sin la ruta
        QFileInfo fileInfo(fileName);
        QString fileNameOnly = fileInfo.fileName();

        // Mostrar el nombre del archivo en el QLineEdit
        ui->txtImagen->setText(fileNameOnly);
    }
}


void CrearPublicacion::on_btnCrear_clicked(){

    nodoArbol *minodo = listaArbol->buscarNodoPorCorreoArb(correoUsuario);
    listaPublicaciones* milistapub = minodo->getListapublicaionesU();
    ArbolBST* arbolPub = minodo->getArbolPublicacionesBST();
    listaNodoPub *todosPubs = minodo->getListaTodasPubs();

    QTime horaSeleccionada = ui->txtHora->time();
    QString horaString = horaSeleccionada.toString("HH:mm");

    QString qFecha = ui->txtFecha->text();
    //QString qHora = ui->txtHora->text();
    QString qCont = ui->txtContenido->toPlainText();
    QString qImagen = ui->txtImagen->text();

    string fecha = qFecha.toStdString();
    //string hora = qHora.toStdString();
    string contenido = qCont.toStdString();
    string correo = minodo->getCorreo();
    string imagen = qImagen.toStdString();
    string hora = horaString.toStdString();


    if(fecha == "" || hora == "" || contenido == ""){
        QMessageBox::warning(this, "Error al crear Publicacion", "Llena todos los campos Obligatorios!");
    }else{
        if(imagen == ""){
            milistapub->agregarPub(correo,contenido,fecha,hora);
            listaPub->agregarPub(correo,contenido,fecha,hora);
            arbolPub->agregarPublicacionBST(correo,contenido,fecha,hora,"",milistapub->getContPublica());
            todosPubs->agregarPublicacionL(fecha,correo,contenido,hora,"",milistapub->getContPublica());
            QMessageBox::information(this,"Creada","Publicacion creada con Exito!");
            ui->txtContenido->clear();
            ui->txtFecha->setDisplayFormat("dd/MM/yyyy");
            ui->txtFecha->setDate(QDate::currentDate());
            ui->txtHora->setTime(QTime::currentTime());
            ui->txtImagen->clear();
            ui->lblImg->clear();
        }else{
            milistapub->agregarPubConImagen(correo,contenido,fecha,hora,imagen);
            listaPub->agregarPubConImagen(correo,contenido,fecha,hora,imagen);
            arbolPub->agregarPublicacionBST(correo,contenido,fecha,hora,imagen,milistapub->getContPublica());
            todosPubs->agregarPublicacionL(fecha,correo,contenido,hora,imagen,milistapub->getContPublica());
            QMessageBox::information(this,"Creada","Publicacion creada con Exito!!");
            ui->txtContenido->clear();
            ui->txtFecha->setDisplayFormat("dd/MM/yyyy");  // Establecer el formato de la fecha
            ui->txtFecha->setDate(QDate::currentDate());               ui->txtHora->setTime(QTime::currentTime());
            ui->txtImagen->clear();
            ui->lblImg->clear();
        }
    }
}

