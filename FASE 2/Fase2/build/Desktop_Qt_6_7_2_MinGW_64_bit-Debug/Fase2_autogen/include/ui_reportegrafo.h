/********************************************************************************
** Form generated from reading UI file 'reportegrafo.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTEGRAFO_H
#define UI_REPORTEGRAFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_reporteGrafo
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_3;
    QPushButton *btnUsers;
    QLabel *lblUser;

    void setupUi(QMainWindow *reporteGrafo)
    {
        if (reporteGrafo->objectName().isEmpty())
            reporteGrafo->setObjectName("reporteGrafo");
        reporteGrafo->resize(854, 683);
        reporteGrafo->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 241, 172)"));
        centralwidget = new QWidget(reporteGrafo);
        centralwidget->setObjectName("centralwidget");
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(700, 600, 121, 51));
        pushButton_3->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_3->setStyleSheet(QString::fromUtf8("font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;\n"
""));
        btnUsers = new QPushButton(centralwidget);
        btnUsers->setObjectName("btnUsers");
        btnUsers->setGeometry(QRect(330, 580, 201, 51));
        btnUsers->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnUsers->setStyleSheet(QString::fromUtf8("font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        lblUser = new QLabel(centralwidget);
        lblUser->setObjectName("lblUser");
        lblUser->setGeometry(QRect(20, 20, 811, 531));
        lblUser->setStyleSheet(QString::fromUtf8("font: 600 20pt \"Segoe UI Variable Display Semib\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        reporteGrafo->setCentralWidget(centralwidget);

        retranslateUi(reporteGrafo);

        QMetaObject::connectSlotsByName(reporteGrafo);
    } // setupUi

    void retranslateUi(QMainWindow *reporteGrafo)
    {
        reporteGrafo->setWindowTitle(QCoreApplication::translate("reporteGrafo", "MainWindow", nullptr));
        pushButton_3->setText(QCoreApplication::translate("reporteGrafo", "REGRESAR", nullptr));
        btnUsers->setText(QCoreApplication::translate("reporteGrafo", "GENERAR REPORTES", nullptr));
        lblUser->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class reporteGrafo: public Ui_reporteGrafo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTEGRAFO_H
