#ifndef REPORTEADYUSER_H
#define REPORTEADYUSER_H

#include <QMainWindow>
#include "listaEnlazadaArbol.h"


namespace Ui {
class reporteAdyUser;
}

class reporteAdyUser : public QMainWindow
{
    Q_OBJECT

public:
    explicit reporteAdyUser(QWidget *parent = nullptr,listaEnlazadaArb* lista = nullptr,const std::string& correo = "");
    ~reporteAdyUser();

private slots:
    void on_pushButton_3_clicked();

    void on_btnUsers_clicked();

private:
    Ui::reporteAdyUser *ui;
    listaEnlazadaArb* listaArbol;
    string correoUsuario;
};

#endif // REPORTEADYUSER_H
