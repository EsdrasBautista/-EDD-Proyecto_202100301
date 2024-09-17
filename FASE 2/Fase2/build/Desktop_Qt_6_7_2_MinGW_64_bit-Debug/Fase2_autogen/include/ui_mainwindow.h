/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *lblCorreo;
    QLineEdit *txtCorreo;
    QLabel *label_3;
    QLineEdit *txtContra;
    QPushButton *btnIngresar;
    QPushButton *btnCrear;
    QPushButton *btnSalir;
    QPushButton *btnInfo;
    QPushButton *btnVerU;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(714, 341);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(212, 210, 255);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(220, 20, 231, 61));
        label->setStyleSheet(QString::fromUtf8("font: 900 18pt \"Segoe UI Black\";"));
        lblCorreo = new QLabel(centralwidget);
        lblCorreo->setObjectName("lblCorreo");
        lblCorreo->setGeometry(QRect(120, 120, 101, 20));
        lblCorreo->setStyleSheet(QString::fromUtf8("font: 600 14pt \"Segoe UI Semibold\";"));
        txtCorreo = new QLineEdit(centralwidget);
        txtCorreo->setObjectName("txtCorreo");
        txtCorreo->setGeometry(QRect(300, 115, 271, 31));
        txtCorreo->setStyleSheet(QString::fromUtf8("font: 600 11pt \"Segoe UI Variable Display Semib\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(120, 190, 161, 20));
        label_3->setStyleSheet(QString::fromUtf8("font: 600 14pt \"Segoe UI Semibold\";"));
        txtContra = new QLineEdit(centralwidget);
        txtContra->setObjectName("txtContra");
        txtContra->setGeometry(QRect(300, 185, 271, 31));
        txtContra->setStyleSheet(QString::fromUtf8("font: 600 11pt \"Segoe UI Variable Display Semib\";\n"
"background-color: rgb(255, 255, 255);\n"
"border: 5px solid white;\n"
"border-radius: 10px;"));
        txtContra->setEchoMode(QLineEdit::EchoMode::Password);
        btnIngresar = new QPushButton(centralwidget);
        btnIngresar->setObjectName("btnIngresar");
        btnIngresar->setGeometry(QRect(300, 240, 101, 29));
        btnIngresar->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnIngresar->setStyleSheet(QString::fromUtf8("font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        btnCrear = new QPushButton(centralwidget);
        btnCrear->setObjectName("btnCrear");
        btnCrear->setGeometry(QRect(420, 240, 161, 29));
        btnCrear->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnCrear->setStyleSheet(QString::fromUtf8("font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        btnSalir = new QPushButton(centralwidget);
        btnSalir->setObjectName("btnSalir");
        btnSalir->setGeometry(QRect(610, 290, 93, 29));
        btnSalir->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnSalir->setStyleSheet(QString::fromUtf8("border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;\n"
"font: 900 10pt \"Segoe UI Black\";\n"
"\n"
""));
        btnInfo = new QPushButton(centralwidget);
        btnInfo->setObjectName("btnInfo");
        btnInfo->setGeometry(QRect(10, 290, 141, 29));
        btnInfo->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnInfo->setStyleSheet(QString::fromUtf8("border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;\n"
"font: 900 10pt \"Segoe UI Black\";\n"
"\n"
""));
        btnVerU = new QPushButton(centralwidget);
        btnVerU->setObjectName("btnVerU");
        btnVerU->setGeometry(QRect(20, 30, 93, 29));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);
        QObject::connect(btnSalir, &QPushButton::clicked, MainWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "INICIAR SESION", nullptr));
        lblCorreo->setText(QCoreApplication::translate("MainWindow", "CORREO:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "CONTRASE\303\221A: ", nullptr));
        btnIngresar->setText(QCoreApplication::translate("MainWindow", "INGRESAR", nullptr));
        btnCrear->setText(QCoreApplication::translate("MainWindow", "CREAR USUARIO", nullptr));
        btnSalir->setText(QCoreApplication::translate("MainWindow", "SALIR", nullptr));
        btnInfo->setText(QCoreApplication::translate("MainWindow", "INFORMACION", nullptr));
        btnVerU->setText(QCoreApplication::translate("MainWindow", "ver usuarios", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
