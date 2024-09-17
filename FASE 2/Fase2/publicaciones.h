#ifndef PUBLICACIONES_H
#define PUBLICACIONES_H

#include <QMainWindow>
#include "listaEnlazadaArbol.h"

namespace Ui {
class Publicaciones;
}

class Publicaciones : public QMainWindow
{
    Q_OBJECT

public:
    explicit Publicaciones(QWidget *parent = nullptr,listaEnlazadaArb* lista = nullptr,const std::string& correo = "",listaPublicaciones* listap = nullptr);
    ~Publicaciones();

private slots:
    void on_pushButton_3_clicked();

    void on_btnCrearPub_clicked();

private:
    Ui::Publicaciones *ui;
    listaEnlazadaArb* listaArbol;
    string correoUsuario;
    listaPublicaciones* listaPub;
};

#endif // PUBLICACIONES_H
