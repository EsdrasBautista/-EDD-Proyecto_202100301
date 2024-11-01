#ifndef REPORTEAMISTADUSER_H
#define REPORTEAMISTADUSER_H

#include <QMainWindow>
#include "listaEnlazadaArbol.h"
namespace Ui {
class reporteAmistadUser;
}

class reporteAmistadUser : public QMainWindow
{
    Q_OBJECT

public:
    explicit reporteAmistadUser(QWidget *parent = nullptr,listaEnlazadaArb* lista = nullptr,const std::string& correo = "");
    ~reporteAmistadUser();

private slots:
    void on_pushButton_3_clicked();

    void on_btnUsers_clicked();

private:
    Ui::reporteAmistadUser *ui;
    listaEnlazadaArb* listaArbol;
    string correoUsuario;
};

#endif // REPORTEAMISTADUSER_H
