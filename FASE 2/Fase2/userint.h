#ifndef USERINT_H
#define USERINT_H

#include <QMainWindow>
#include "listaEnlazadaArbol.h"
#include "nodoPublicacion.h"
#include "relacionAmistad.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

namespace Ui {
class UserInt;
}

class UserInt : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserInt(QWidget *parent = nullptr,listaEnlazadaArb* lista = nullptr,const std::string& correo = "", listaPublicaciones* listap = nullptr,listaAdyacencia* grafoAdy = nullptr );
    ~UserInt();
    void setNombreUsuario(string nombre);
    void actualizarNombreUsuario();


private slots:
    void on_pushButton_clicked();

    void on_actionPERFIL_triggered();

    void on_actionBUSCAR_triggered();

    void on_actionSOLICITUDES_triggered();

    void on_actionPUBLICACIONES_triggered();

    void on_pushButton_2_clicked();

    void on_actionGENERAR_REPORTES_triggered();

    void on_actionGRAFO_AMISTAD_triggered();

    void on_actionADYACENCIA_AMISTAD_triggered();

private:
    Ui::UserInt *ui;
    listaEnlazadaArb* listaArbol;
    listaPublicaciones* listaPub;
    string correoUsuario;
    listaAdyacencia* grafoAdy;

};

#endif // USERINT_H
