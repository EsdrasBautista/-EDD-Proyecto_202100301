#ifndef VERCOMENTARIOS_H
#define VERCOMENTARIOS_H

#include <QMainWindow>
#include "listaPublicaciones.h"
#include "listaEnlazadaArbol.h"


namespace Ui {
class verComentarios;
}

class verComentarios : public QMainWindow
{
    Q_OBJECT

public:
    explicit verComentarios(QWidget *parent = nullptr,listaEnlazadaArb* lista = nullptr,const std::string& correo = "",const std::string& fecha = "", int id = 0);
    ~verComentarios();
    void llenarComentarios();

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::verComentarios *ui;
    listaEnlazadaArb* listaArbol;
    string correoUsuario;
    string fechaU;
    int idU;
};

#endif // VERCOMENTARIOS_H
