#ifndef REPORTEGRAFO_H
#define REPORTEGRAFO_H

#include <QMainWindow>
#include "relacionAmistad.h"

namespace Ui {
class reporteGrafo;
}

class reporteGrafo : public QMainWindow
{
    Q_OBJECT

public:
    explicit reporteGrafo(QWidget *parent = nullptr, listaAdyacencia* grafo = nullptr);
    ~reporteGrafo();

private slots:
    void on_pushButton_3_clicked();

    void on_btnUsers_clicked();

private:
    Ui::reporteGrafo *ui;
    listaAdyacencia* grafoAdy;
};

#endif // REPORTEGRAFO_H
