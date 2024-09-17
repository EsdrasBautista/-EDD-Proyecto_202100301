#ifndef CREARUSER_H
#define CREARUSER_H

#include <QMainWindow>
#include "listaEnlazadaArbol.h"

namespace Ui {
class CrearUser;
}

class CrearUser : public QMainWindow
{
    Q_OBJECT

public:
    explicit CrearUser(QWidget *parent = nullptr,listaEnlazadaArb* lista = nullptr);
    ~CrearUser();

private slots:
    void on_btnRegresar_clicked();

    void on_btnCrearUser_clicked();

private:
    Ui::CrearUser *ui;
    listaEnlazadaArb* listaArbol;
};

#endif // CREARUSER_H
