#ifndef ADMIN_H
#define ADMIN_H

#include <QMainWindow>
#include "listaEnlazadaArbol.h"
#include "nodoPublicacion.h"

namespace Ui {
class Admin;
}

class Admin : public QMainWindow
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr,listaEnlazadaArb* lista = nullptr,listaPublicaciones* listap = nullptr);
    ~Admin();

private slots:
    void on_actionBUSCAR_triggered();

    void on_pushButton_clicked();

    void on_actionCARGA_MASIVA_triggered();

    void on_actionREPORTES_triggered();

private:
    Ui::Admin *ui;
    listaEnlazadaArb* listaArbol;
    listaPublicaciones* listaPub;
};

#endif // ADMIN_H
