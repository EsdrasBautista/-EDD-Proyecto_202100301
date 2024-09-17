#ifndef BUSCARADMIN_H
#define BUSCARADMIN_H

#include <QMainWindow>
#include "listaEnlazadaArbol.h"

namespace Ui {
class BuscarAdmin;
}

class BuscarAdmin : public QMainWindow
{
    Q_OBJECT

public:
    explicit BuscarAdmin(QWidget *parent = nullptr,listaEnlazadaArb* lista = nullptr);
    ~BuscarAdmin();
    void llenarTabla(nodoArbol* raiz,int &fila);
    void ActualizarTabla();
    void tablaUser();
    void buscar();
    void limpiarTabla();
    void OpcionesOrden();

private slots:
    void on_btnBuscar_clicked();

    void on_pushButton_3_clicked();

    void on_btnAplicar_clicked();

private:
    Ui::BuscarAdmin *ui;
    listaEnlazadaArb* listaArbol;

};

#endif // BUSCARADMIN_H