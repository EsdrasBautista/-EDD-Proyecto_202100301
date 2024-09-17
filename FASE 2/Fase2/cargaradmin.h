#ifndef CARGARADMIN_H
#define CARGARADMIN_H

#include <QMainWindow>
#include "listaEnlazadaArbol.h"

namespace Ui {
class CargarAdmin;
}

class CargarAdmin : public QMainWindow
{
    Q_OBJECT

public:
    explicit CargarAdmin(QWidget *parent = nullptr,listaEnlazadaArb* lista = nullptr);
    ~CargarAdmin();

private slots:
    void on_pushButton_3_clicked();

    void on_btnUsers_clicked();

    void on_btnSoli_clicked();

private:
    Ui::CargarAdmin *ui;
    listaEnlazadaArb* listaArbol;
    string rutaUser;
    string rutaPub;
    string rutaSoli;
};

#endif // CARGARADMIN_H
