#ifndef REPORTESUSER_H
#define REPORTESUSER_H

#include <QMainWindow>
#include "listaEnlazadaArbol.h"
#include "listaPublicaciones.h"

namespace Ui {
class reportesUser;
}

class reportesUser : public QMainWindow
{
    Q_OBJECT

public:
    explicit reportesUser(QWidget *parent = nullptr, listaEnlazadaArb *lista = nullptr, const std::string &correo = "", listaPublicaciones *listap = nullptr);
    ~reportesUser();
    void llenarComboFecha();
    void limpiarCombo();


private slots:
    void on_btnBst_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::reportesUser *ui;
    listaEnlazadaArb* listaArbol;
    string correoUsuario;
    listaPublicaciones* listaPub;
    void llenarComboFecha(nodoBST* raiz);

};

#endif // REPORTESUSER_H
