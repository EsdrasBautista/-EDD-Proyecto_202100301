#ifndef PERFIL_H
#define PERFIL_H

#include <QMainWindow>
#include "listaEnlazadaArbol.h"


namespace Ui {
class Perfil;
}

class Perfil : public QMainWindow
{
    Q_OBJECT

public:
    explicit Perfil(QWidget *parent = nullptr,listaEnlazadaArb* lista = nullptr,const std::string& correo = "");
    ~Perfil();
    void llenarCampos();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Perfil *ui;
    listaEnlazadaArb* listaArbol;
    string correoUsuario;
};

#endif // PERFIL_H
