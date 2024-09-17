#ifndef SOLICITUDES_H
#define SOLICITUDES_H

#include <QMainWindow>
#include "listaEnlazadaArbol.h"
namespace Ui {
class Solicitudes;
}

class Solicitudes : public QMainWindow
{
    Q_OBJECT

public:
    explicit Solicitudes(QWidget *parent = nullptr,listaEnlazadaArb* lista = nullptr,const std::string& correo = "");
    ~Solicitudes();
    void tablaUser();
    void tablaEnv();
    void tablaRec();
    void llenarTblUser(nodoArbol* raiz,int &fila);
    void llenarTblRec(NodoPila* pila, int &fila);
    void llenarTblEnv(NodoLisaE *envio,int &fila);
    void refrescarTablaUser();
    void refrescarTablaRec();
    void refrescarTablaEnv();

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::Solicitudes *ui;
    listaEnlazadaArb* listaArbol;
    string correoUsuario;
};

#endif // SOLICITUDES_H
