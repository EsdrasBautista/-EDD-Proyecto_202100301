#ifndef BUSCAR_H
#define BUSCAR_H

#include <QMainWindow>
#include "listaEnlazadaArbol.h"

namespace Ui {
class Buscar;
}

class Buscar : public QMainWindow
{
    Q_OBJECT

public:
    explicit Buscar(QWidget *parent = nullptr,listaEnlazadaArb* lista = nullptr);
    ~Buscar();

private slots:
    void on_btnBuscar_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Buscar *ui;
    listaEnlazadaArb* listaArbol;
};

#endif // BUSCAR_H
