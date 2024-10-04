#include "./cargaradmin.h"
#include "ui_cargaradmin.h"

#include <QFileDialog>
#include <QPixmap>
#include <QDate>
#include <QMessageBox>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QDebug>
#include "./GestionarSoli.h"

CargarAdmin::CargarAdmin(QWidget *parent,listaEnlazadaArb* lista,listaPublicaciones* listaP)
    : QMainWindow(parent)
    , ui(new Ui::CargarAdmin),
    listaArbol(lista),
    listaPubs(listaP)

{
    ui->setupUi(this);
    this->setWindowTitle("CargarArchivos");
}




CargarAdmin::~CargarAdmin()
{
    delete ui;
}

void CargarAdmin::on_pushButton_3_clicked()
{
    this->close();  // Cerrar la ventana actual CrearUser
    QWidget *parent = this->parentWidget();  // Obtener la ventana principal
    if (parent) {
        parent->show();  // Mostrar la ventana principal si existe
    }
}


void CargarAdmin::on_btnUsers_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Seleccionar Archivo"), "", tr("Archivos (*.json)"));
    if (fileName.isEmpty()) {
        return;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, tr("Error"), tr("No se pudo abrir el archivo JSON"));
        return;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument jsonDoc(QJsonDocument::fromJson(jsonData));
    if (jsonDoc.isNull() || !jsonDoc.isArray()) {
        QMessageBox::warning(this, tr("Error"), tr("El archivo JSON no es válido o no está bien estructurado"));
        return;
    }

    // Procesar el array de usuarios
    QJsonArray jsonArray = jsonDoc.array();
    qDebug() << "Número de usuarios en el archivo:" << jsonArray.size();

    for (const QJsonValue &value : jsonArray) {
        QJsonObject jsonObj = value.toObject();

        QString nombres = jsonObj["nombres"].toString();
        QString apellidos = jsonObj["apellidos"].toString();
        QString fechaNacimiento = jsonObj["fecha_de_nacimiento"].toString();
        QString correo = jsonObj["correo"].toString();
        QString contrasena = jsonObj["contraseña"].toString();

        if (nombres.isEmpty() || apellidos.isEmpty() || fechaNacimiento.isEmpty() || correo.isEmpty() || contrasena.isEmpty()) {
            QMessageBox::warning(this, tr("Error"), tr("Algunos datos están vacíos"));
        } else {
            listaArbol->agregarUsuario(nombres.toStdString(), apellidos.toStdString(), correo.toStdString(), contrasena.toStdString(), fechaNacimiento.toStdString());
        }
    }

    QFileInfo fileInfo(fileName);
    QString fileNameOnly = fileInfo.fileName();
    ui->txtusers->setText(fileNameOnly);

    QMessageBox::information(this, tr("Carga Exitosa"), tr("Usuarios agregados con éxito"));
}



void CargarAdmin::on_btnSoli_clicked()
{
    rutaSoli= "";
    QString fileName = QFileDialog::getOpenFileName(this, tr("Seleccionar Archivo"), "", tr("Archivos (*.json)"));
    if (!fileName.isEmpty()) {
        QFileInfo fileInfo(fileName);
        QString fileNameOnly = fileInfo.fileName();
        ui->txtSoli->setText(fileNameOnly);

        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::warning(this, "Error", "No se pudo abrir el archivo JSON");
            return;
        }
        QByteArray jsonData = file.readAll();
        file.close();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
        if (jsonDoc.isNull() || !jsonDoc.isArray()) {
            QMessageBox::warning(this, "Error", "El archivo JSON no es valido o no esta bien estructurado");
            return;
        }

        // Procesar el array de usuarios
        QJsonArray jsonArray = jsonDoc.array();
        for (int i = 0; i < jsonArray.size(); ++i) {
            QJsonObject userObject = jsonArray[i].toObject();

            std::string emisor = userObject.value("emisor").toString().toStdString();
            std::string receptor = userObject.value("receptor").toString().toStdString();
            std::string estado = userObject.value("estado").toString().toStdString();

            if(estado == "ACEPTADA"){
                gestionarSoli::aceptarSolicitudD(*listaArbol,receptor,emisor,this);
            }else if(estado == "PENDIENTE"){
                gestionarSoli::enviarSolicitud(*listaArbol,emisor,receptor,this);
            }

        }
        QMessageBox::information(this,"Carga Exitosa","Solicitudes cargadas con Exito!");


    }
}


void CargarAdmin::on_btnPub_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Seleccionar Archivo"), "", tr("Archivos (*.json)"));
    if (fileName.isEmpty()) {
        return;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, tr("Error"), tr("No se pudo abrir el archivo JSON"));
        return;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument jsonDoc(QJsonDocument::fromJson(jsonData));
    if (jsonDoc.isNull() || !jsonDoc.isArray()) {
        QMessageBox::warning(this, tr("Error"), tr("El archivo JSON no es válido o no está bien estructurado"));
        return;
    }

    // Procesar el array de publicaciones
    QJsonArray jsonArray = jsonDoc.array();
    for (const QJsonValue &value : jsonArray) {
        QJsonObject jsonObj = value.toObject();

        QString correo = jsonObj["correo"].toString();
        QString contenido = jsonObj["contenido"].toString();
        QString fecha = jsonObj["fecha"].toString();
        QString hora = jsonObj["hora"].toString();

        // Verificar si los campos no están vacíos
        if (correo.isEmpty() || contenido.isEmpty() || fecha.isEmpty() || hora.isEmpty()) {
            QMessageBox::warning(this, tr("Error"), tr("Algunos datos de la publicación están vacíos"));
            continue;
        }

        std::string correoStr = correo.toStdString();
        std::string contenidoStr = contenido.toStdString();
        std::string fechaStr = fecha.toStdString();
        std::string horaStr = hora.toStdString();

        // Aquí agregaríamos la publicación a la estructura de datos correspondiente
        int id = gestionarSoli::agregarPubDesdeAdmin(*listaArbol, correoStr, contenidoStr, fechaStr, horaStr,this);
        listaPubs->agregarPub(correoStr,contenidoStr,fechaStr,horaStr);

        // Procesar los comentarios de la publicación
        if (id <= -1) {
            std::cout << "Error al agregar la publicación: ID no valido." << std::endl;
            continue;  // Saltamos al siguiente JSON si hay un problema con esta publicación
        }

        std::cout << "ID de la publicacion: " << id << std::endl;


        if (jsonObj.contains("comentarios")) {
            QJsonArray comentariosArray = jsonObj["comentarios"].toArray();


            for (const QJsonValue &comentarioValue : comentariosArray) {
                QJsonObject comentarioObj = comentarioValue.toObject();

                QString correoComentario = comentarioObj["correo"].toString();
                QString comentarioTexto = comentarioObj["comentario"].toString();
                QString fechaComentario = comentarioObj["fecha"].toString();
                QString horaComentario = comentarioObj["hora"].toString();

                // Verificamos si los campos están vacíos
                if (correoComentario.isEmpty() || comentarioTexto.isEmpty() || fechaComentario.isEmpty() || horaComentario.isEmpty()) {
                    std::cout << "Datos del comentario incompletos." << std::endl;
                    QMessageBox::warning(this, tr("Error"), tr("Algunos datos del comentario estan vacíos"));
                    continue;  // Saltar al siguiente comentario
                }

                std::cout << "Procesando comentario de: " << correoComentario.toStdString() << std::endl;

                std::string correoComentarioStr = correoComentario.toStdString();
                std::string comentarioTextoStr = comentarioTexto.toStdString();
                std::string fechaComentarioStr = fechaComentario.toStdString();
                std::string horaComentarioStr = horaComentario.toStdString();

                // Llamada a agregarComentario (agrega mensaje de depuración en esta función)
                gestionarSoli::agregarComentarioAdmin(*listaArbol, correoStr, fechaStr, id, fechaComentarioStr, horaComentarioStr, comentarioTextoStr, correoComentarioStr, this);

                std::cout << "Numero de comentarios: " << comentariosArray.size() << std::endl;
            }

        }
    }

    QFileInfo fileInfo(fileName);
    QString fileNameOnly = fileInfo.fileName();
    ui->txtPub->setText(fileNameOnly);

    QMessageBox::information(this, tr("Carga Exitosa"), tr("Publicaciones agregadas con exito"));
}


