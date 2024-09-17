#ifndef REPORTESADMIN_H
#define REPORTESADMIN_H

#include <QMainWindow>
#include "listaEnlazadaArbol.h"
#include "nodoPublicacion.h"

namespace Ui {
class ReportesAdmin;
}

class ReportesAdmin : public QMainWindow
{
    Q_OBJECT

public:
    explicit ReportesAdmin(QWidget *parent = nullptr,listaEnlazadaArb* lista = nullptr,listaPublicaciones* listap = nullptr);
    ~ReportesAdmin();

private slots:
    void on_btnUsers_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::ReportesAdmin *ui;
    listaEnlazadaArb* listaArbol;
    listaPublicaciones* listaPub;
};

#endif // REPORTESADMIN_H
