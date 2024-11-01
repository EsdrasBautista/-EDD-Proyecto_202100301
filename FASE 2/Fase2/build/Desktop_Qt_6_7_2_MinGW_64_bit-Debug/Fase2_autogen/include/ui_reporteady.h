/********************************************************************************
** Form generated from reading UI file 'reporteady.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTEADY_H
#define UI_REPORTEADY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_reporteAdy
{
public:
    QWidget *centralwidget;
    QLabel *lblUser;
    QPushButton *pushButton_3;
    QPushButton *btnUsers;

    void setupUi(QMainWindow *reporteAdy)
    {
        if (reporteAdy->objectName().isEmpty())
            reporteAdy->setObjectName("reporteAdy");
        reporteAdy->resize(978, 699);
        reporteAdy->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 241, 172)"));
        centralwidget = new QWidget(reporteAdy);
        centralwidget->setObjectName("centralwidget");
        lblUser = new QLabel(centralwidget);
        lblUser->setObjectName("lblUser");
        lblUser->setGeometry(QRect(30, 20, 931, 531));
        lblUser->setStyleSheet(QString::fromUtf8("font: 600 20pt \"Segoe UI Variable Display Semib\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(840, 630, 121, 51));
        pushButton_3->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_3->setStyleSheet(QString::fromUtf8("font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;\n"
""));
        btnUsers = new QPushButton(centralwidget);
        btnUsers->setObjectName("btnUsers");
        btnUsers->setGeometry(QRect(390, 580, 201, 51));
        btnUsers->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnUsers->setStyleSheet(QString::fromUtf8("font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        reporteAdy->setCentralWidget(centralwidget);

        retranslateUi(reporteAdy);

        QMetaObject::connectSlotsByName(reporteAdy);
    } // setupUi

    void retranslateUi(QMainWindow *reporteAdy)
    {
        reporteAdy->setWindowTitle(QCoreApplication::translate("reporteAdy", "MainWindow", nullptr));
        lblUser->setText(QString());
        pushButton_3->setText(QCoreApplication::translate("reporteAdy", "REGRESAR", nullptr));
        btnUsers->setText(QCoreApplication::translate("reporteAdy", "GENERAR REPORTES", nullptr));
    } // retranslateUi

};

namespace Ui {
    class reporteAdy: public Ui_reporteAdy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTEADY_H
