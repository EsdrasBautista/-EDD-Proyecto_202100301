/********************************************************************************
** Form generated from reading UI file 'cargaradmin.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARGARADMIN_H
#define UI_CARGARADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CargarAdmin
{
public:
    QWidget *centralwidget;
    QGroupBox *grbRec;
    QLineEdit *txtusers;
    QPushButton *btnUsers;
    QGroupBox *grbRec_2;
    QLineEdit *txtSoli;
    QPushButton *btnSoli;
    QGroupBox *grbRec_3;
    QLineEdit *txtPub;
    QPushButton *btnPub;
    QPushButton *pushButton_3;

    void setupUi(QMainWindow *CargarAdmin)
    {
        if (CargarAdmin->objectName().isEmpty())
            CargarAdmin->setObjectName("CargarAdmin");
        CargarAdmin->resize(1043, 546);
        CargarAdmin->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 241, 172)"));
        centralwidget = new QWidget(CargarAdmin);
        centralwidget->setObjectName("centralwidget");
        grbRec = new QGroupBox(centralwidget);
        grbRec->setObjectName("grbRec");
        grbRec->setGeometry(QRect(20, 20, 321, 411));
        grbRec->setStyleSheet(QString::fromUtf8("font: 12pt \"Sitka\";"));
        txtusers = new QLineEdit(grbRec);
        txtusers->setObjectName("txtusers");
        txtusers->setEnabled(false);
        txtusers->setGeometry(QRect(40, 190, 251, 31));
        txtusers->setStyleSheet(QString::fromUtf8("font: 600 11pt \"Segoe UI Variable Display Semib\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        btnUsers = new QPushButton(grbRec);
        btnUsers->setObjectName("btnUsers");
        btnUsers->setGeometry(QRect(60, 260, 201, 51));
        btnUsers->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnUsers->setStyleSheet(QString::fromUtf8("font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        grbRec_2 = new QGroupBox(centralwidget);
        grbRec_2->setObjectName("grbRec_2");
        grbRec_2->setGeometry(QRect(360, 20, 321, 411));
        grbRec_2->setStyleSheet(QString::fromUtf8("font: 12pt \"Sitka\";"));
        txtSoli = new QLineEdit(grbRec_2);
        txtSoli->setObjectName("txtSoli");
        txtSoli->setEnabled(false);
        txtSoli->setGeometry(QRect(40, 190, 251, 31));
        txtSoli->setStyleSheet(QString::fromUtf8("font: 600 11pt \"Segoe UI Variable Display Semib\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        btnSoli = new QPushButton(grbRec_2);
        btnSoli->setObjectName("btnSoli");
        btnSoli->setGeometry(QRect(60, 260, 211, 51));
        btnSoli->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnSoli->setStyleSheet(QString::fromUtf8("font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        grbRec_3 = new QGroupBox(centralwidget);
        grbRec_3->setObjectName("grbRec_3");
        grbRec_3->setGeometry(QRect(700, 20, 321, 411));
        grbRec_3->setStyleSheet(QString::fromUtf8("font: 12pt \"Sitka\";"));
        txtPub = new QLineEdit(grbRec_3);
        txtPub->setObjectName("txtPub");
        txtPub->setEnabled(false);
        txtPub->setGeometry(QRect(40, 190, 251, 31));
        txtPub->setStyleSheet(QString::fromUtf8("font: 600 11pt \"Segoe UI Variable Display Semib\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        btnPub = new QPushButton(grbRec_3);
        btnPub->setObjectName("btnPub");
        btnPub->setGeometry(QRect(50, 260, 231, 51));
        btnPub->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnPub->setStyleSheet(QString::fromUtf8("font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(900, 460, 121, 51));
        pushButton_3->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_3->setStyleSheet(QString::fromUtf8("font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;\n"
""));
        CargarAdmin->setCentralWidget(centralwidget);

        retranslateUi(CargarAdmin);

        QMetaObject::connectSlotsByName(CargarAdmin);
    } // setupUi

    void retranslateUi(QMainWindow *CargarAdmin)
    {
        CargarAdmin->setWindowTitle(QCoreApplication::translate("CargarAdmin", "MainWindow", nullptr));
        grbRec->setTitle(QCoreApplication::translate("CargarAdmin", "USUARIOS", nullptr));
        btnUsers->setText(QCoreApplication::translate("CargarAdmin", "CARGAR USUARIOS", nullptr));
        grbRec_2->setTitle(QCoreApplication::translate("CargarAdmin", "SOLICITUDES", nullptr));
        btnSoli->setText(QCoreApplication::translate("CargarAdmin", "CARGAR SOLICITUDES", nullptr));
        grbRec_3->setTitle(QCoreApplication::translate("CargarAdmin", "PUBLICACIONES", nullptr));
        btnPub->setText(QCoreApplication::translate("CargarAdmin", "CARGAR PUBLICACIONES", nullptr));
        pushButton_3->setText(QCoreApplication::translate("CargarAdmin", "REGRESAR", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CargarAdmin: public Ui_CargarAdmin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARGARADMIN_H
