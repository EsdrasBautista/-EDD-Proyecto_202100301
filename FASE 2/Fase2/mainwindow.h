#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "listaEnlazadaArbol.h"
#include "nodoPublicacion.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_btnIngresar_clicked();

    void on_btnCrear_clicked();

    void on_btnVerU_clicked();

    void on_btnInfo_clicked();

private:
    Ui::MainWindow *ui;
    listaEnlazadaArb *listaArbol;
    listaPublicaciones *listaPub;
};
#endif // MAINWINDOW_H
