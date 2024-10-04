#ifndef PUBLICACIONES_H
#define PUBLICACIONES_H

#include <QMainWindow>
#include "listaEnlazadaArbol.h"
#include "listaPublicaciones.h"

namespace Ui {
class Publicaciones;
}

class Publicaciones : public QMainWindow
{
    Q_OBJECT

public:
    explicit Publicaciones(QWidget *parent = nullptr,listaEnlazadaArb* lista = nullptr,const std::string& correo = "",listaPublicaciones* listap = nullptr);
    ~Publicaciones();
    void llenarComboFecha();
    void llenarBST();
    void limpiarCombo();
    void limpiarInfo();
    void actualizarTodosPubs();

private slots:

    void on_pushButton_3_clicked();
    void on_btnCrearPub_clicked();

    void on_pushButton_clicked();

    void on_btnSiguiente_clicked();

    void on_pushButton_2_clicked();

    void on_btnComentar_clicked();

    void on_btnAnterior_clicked();

    void on_btnVercoment_clicked();

    void on_btnVerArbol_clicked();

private:
    Ui::Publicaciones *ui;
    listaEnlazadaArb* listaArbol;
    string correoUsuario;
    listaPublicaciones* listaPub;
    nodoSimplePub* nodoActualPubs;

    void llenarComboFecha(nodoBST* raiz);

};

#endif // PUBLICACIONES_H
