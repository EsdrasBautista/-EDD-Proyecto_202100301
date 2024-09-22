#ifndef COMENTARU_H
#define COMENTARU_H

#include <QMainWindow>

#include "listaPublicaciones.h"

namespace Ui {
class ComentarU;
}

class ComentarU : public QMainWindow
{
    Q_OBJECT

public:
    explicit ComentarU(QWidget *parent = nullptr, nodoSimplePub *nodoPubs = nullptr,const std::string& correo = "");
    ~ComentarU();
    void llenarCampos();

private slots:
    void on_btnComentar_clicked();

    void on_btnRegresar_clicked();

private:
    Ui::ComentarU *ui;
    nodoSimplePub* nodoActualPubs;
    string correoUsuario;
};

#endif // COMENTARU_H
