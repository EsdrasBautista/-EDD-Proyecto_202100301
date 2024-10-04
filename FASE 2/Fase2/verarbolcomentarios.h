#ifndef VERARBOLCOMENTARIOS_H
#define VERARBOLCOMENTARIOS_H

#include <QMainWindow>
#include "listaEnlazadaArbol.h"
namespace Ui {
class verArbolComentarios;
}

class verArbolComentarios : public QMainWindow
{
    Q_OBJECT

public:
    explicit verArbolComentarios(QWidget *parent = nullptr,listaEnlazadaArb* lista = nullptr,const std::string& correo = "",const std::string& fecha = "", int id = 0);
    ~verArbolComentarios();

private slots:
    void on_pushButton_3_clicked();
    void mostrar();

private:
    Ui::verArbolComentarios *ui;
    listaEnlazadaArb* listaArbol;
    string correoUsuario;
    string fechaU;
    int idU;
};

#endif // VERARBOLCOMENTARIOS_H
