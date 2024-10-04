#ifndef COMENTARU_H
#define COMENTARU_H

#include <QMainWindow>

#include "listaPublicaciones.h"
#include "listaEnlazadaArbol.h"

namespace Ui {
class ComentarU;
}

class ComentarU : public QMainWindow
{
    Q_OBJECT

public:
    explicit ComentarU(QWidget *parent = nullptr,listaEnlazadaArb* lista = nullptr,const std::string& correo = "",const std::string& fecha = "", int id = 0, nodoSimplePub *nodoPubs = nullptr,const std::string& correoC="");
    ~ComentarU();
    void llenarCampos();

private slots:
    void on_btnComentar_clicked();

    void on_btnRegresar_clicked();

private:
    Ui::ComentarU *ui;
    listaEnlazadaArb* listaArbol;
    string correoUsuario;
    string correoUsuarioC;
    string fechaU;
    int idU;
    nodoSimplePub* nodoActualPubs;
};

#endif // COMENTARU_H
