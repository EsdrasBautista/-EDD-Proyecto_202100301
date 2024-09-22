#ifndef MODIFICARADMIN_H
#define MODIFICARADMIN_H

#include <QMainWindow>
#include "listaEnlazadaArbol.h"

namespace Ui {
class ModificarAdmin;
}

class ModificarAdmin : public QMainWindow
{
    Q_OBJECT

public:
    explicit ModificarAdmin(QWidget *parent = nullptr,listaEnlazadaArb* lista = nullptr,const std::string& correo = "");
    ~ModificarAdmin();
    void llenarCamposAdmin();

private slots:
    void on_btnModificar_clicked();

    void on_btnRegresar_clicked();

private:
    Ui::ModificarAdmin *ui;
    listaEnlazadaArb* listaArbol;
    string correoUsuario;
};

#endif // MODIFICARADMIN_H
