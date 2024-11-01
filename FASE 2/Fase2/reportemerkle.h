#ifndef REPORTEMERKLE_H
#define REPORTEMERKLE_H

#include <QMainWindow>
#include "listaEnlazadaArbol.h"
namespace Ui {
class reporteMerkle;
}

class reporteMerkle : public QMainWindow
{
    Q_OBJECT

public:
    explicit reporteMerkle(QWidget *parent = nullptr,listaEnlazadaArb* lista = nullptr);
    ~reporteMerkle();
    void llenarCombo();
    void llenarComboRecursivo(nodoArbol* actual);

private slots:
    void on_btnUsers_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::reporteMerkle *ui;
    listaEnlazadaArb* listaArbol;

};

#endif // REPORTEMERKLE_H
