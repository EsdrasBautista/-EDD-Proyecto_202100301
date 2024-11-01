#ifndef REPORTEADY_H
#define REPORTEADY_H

#include <QMainWindow>
#include "relacionAmistad.h"

namespace Ui {
class reporteAdy;
}

class reporteAdy : public QMainWindow
{
    Q_OBJECT

public:
    explicit reporteAdy(QWidget *parent = nullptr,listaAdyacencia* grafo = nullptr);
    ~reporteAdy();

private slots:
    void on_pushButton_3_clicked();

    void on_btnUsers_clicked();

private:
    Ui::reporteAdy *ui;
    listaAdyacencia* grafoAdy;
};

#endif // REPORTEADY_H
