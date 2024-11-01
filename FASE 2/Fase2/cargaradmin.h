#ifndef CARGARADMIN_H
#define CARGARADMIN_H

#include <QMainWindow>
#include "listaEnlazadaArbol.h"
#include "listaPublicaciones.h"

namespace Ui {
class CargarAdmin;
}

class CargarAdmin : public QMainWindow
{
    Q_OBJECT

public:
    explicit CargarAdmin(QWidget *parent = nullptr,listaEnlazadaArb* lista = nullptr,listaPublicaciones* listapubs = nullptr,listaAdyacencia* grafo = nullptr);
    ~CargarAdmin();

private slots:
    void on_pushButton_3_clicked();

    void on_btnUsers_clicked();

    void on_btnSoli_clicked();

    void on_btnPub_clicked();

private:
    Ui::CargarAdmin *ui;
    listaEnlazadaArb* listaArbol;
    listaPublicaciones* listaPubs;
    string rutaUser;
    string rutaPub;
    string rutaSoli;
    listaAdyacencia* grafoAdy;
};

#endif // CARGARADMIN_H
