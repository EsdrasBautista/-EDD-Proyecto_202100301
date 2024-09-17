#ifndef CREARPUBLICACION_H
#define CREARPUBLICACION_H

#include <QMainWindow>
#include "listaEnlazadaArbol.h"
#include "nodoPublicacion.h"

namespace Ui {
class CrearPublicacion;
}

class CrearPublicacion : public QMainWindow
{
    Q_OBJECT

public:
    explicit CrearPublicacion(QWidget *parent = nullptr, listaEnlazadaArb* lista = nullptr, const std::string& correo = "", listaPublicaciones *listap = nullptr);
    ~CrearPublicacion();

private slots:
    void on_pushButton_3_clicked();

    void on_btnImagen_clicked();

    void on_btnCrear_clicked();

private:
    Ui::CrearPublicacion *ui;
    listaEnlazadaArb* listaArbol;
    listaPublicaciones* listaPub;
    string correoUsuario;
    string rutaImagen;
};

#endif // CREARPUBLICACION_H
