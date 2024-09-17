/********************************************************************************
** Form generated from reading UI file 'buscar.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUSCAR_H
#define UI_BUSCAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Buscar
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLabel *lblCorreo_2;
    QLineEdit *txtNombres;
    QLabel *label_4;
    QLineEdit *txtApellidos;
    QLabel *label_5;
    QLabel *lblCorreo;
    QLineEdit *txtFechaN;
    QLineEdit *txtCorreoU;
    QPushButton *pushButton_3;
    QLineEdit *txtBuscar;
    QPushButton *btnBuscar;
    QLabel *lblCorreo_3;

    void setupUi(QMainWindow *Buscar)
    {
        if (Buscar->objectName().isEmpty())
            Buscar->setObjectName("Buscar");
        Buscar->resize(824, 562);
        Buscar->setStyleSheet(QString::fromUtf8("background-color: rgb(216, 229, 158);"));
        centralwidget = new QWidget(Buscar);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(40, 160, 751, 311));
        groupBox->setStyleSheet(QString::fromUtf8("font: 12pt \"Sitka\";"));
        lblCorreo_2 = new QLabel(groupBox);
        lblCorreo_2->setObjectName("lblCorreo_2");
        lblCorreo_2->setGeometry(QRect(130, 40, 121, 20));
        lblCorreo_2->setStyleSheet(QString::fromUtf8("font: 600 14pt \"Segoe UI Semibold\";"));
        txtNombres = new QLineEdit(groupBox);
        txtNombres->setObjectName("txtNombres");
        txtNombres->setEnabled(false);
        txtNombres->setGeometry(QRect(290, 30, 341, 31));
        txtNombres->setStyleSheet(QString::fromUtf8("font: 600 11pt \"Segoe UI Variable Display Semib\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(120, 110, 131, 20));
        label_4->setStyleSheet(QString::fromUtf8("font: 600 14pt \"Segoe UI Semibold\";"));
        txtApellidos = new QLineEdit(groupBox);
        txtApellidos->setObjectName("txtApellidos");
        txtApellidos->setEnabled(false);
        txtApellidos->setGeometry(QRect(290, 100, 341, 31));
        txtApellidos->setStyleSheet(QString::fromUtf8("font: 600 11pt \"Segoe UI Variable Display Semib\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(40, 240, 231, 20));
        label_5->setStyleSheet(QString::fromUtf8("font: 600 14pt \"Segoe UI Semibold\";"));
        lblCorreo = new QLabel(groupBox);
        lblCorreo->setObjectName("lblCorreo");
        lblCorreo->setGeometry(QRect(160, 170, 101, 20));
        lblCorreo->setStyleSheet(QString::fromUtf8("font: 600 14pt \"Segoe UI Semibold\";"));
        txtFechaN = new QLineEdit(groupBox);
        txtFechaN->setObjectName("txtFechaN");
        txtFechaN->setEnabled(false);
        txtFechaN->setGeometry(QRect(290, 230, 341, 31));
        txtFechaN->setStyleSheet(QString::fromUtf8("font: 600 11pt \"Segoe UI Variable Display Semib\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        txtCorreoU = new QLineEdit(groupBox);
        txtCorreoU->setObjectName("txtCorreoU");
        txtCorreoU->setEnabled(false);
        txtCorreoU->setGeometry(QRect(290, 170, 341, 31));
        txtCorreoU->setStyleSheet(QString::fromUtf8("font: 600 11pt \"Segoe UI Variable Display Semib\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(670, 490, 121, 41));
        pushButton_3->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_3->setStyleSheet(QString::fromUtf8("font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;\n"
""));
        txtBuscar = new QLineEdit(centralwidget);
        txtBuscar->setObjectName("txtBuscar");
        txtBuscar->setGeometry(QRect(240, 90, 341, 31));
        txtBuscar->setStyleSheet(QString::fromUtf8("font: 600 11pt \"Segoe UI Variable Display Semib\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        btnBuscar = new QPushButton(centralwidget);
        btnBuscar->setObjectName("btnBuscar");
        btnBuscar->setGeometry(QRect(600, 90, 121, 31));
        btnBuscar->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnBuscar->setStyleSheet(QString::fromUtf8("font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;\n"
""));
        lblCorreo_3 = new QLabel(centralwidget);
        lblCorreo_3->setObjectName("lblCorreo_3");
        lblCorreo_3->setGeometry(QRect(240, 50, 381, 20));
        lblCorreo_3->setStyleSheet(QString::fromUtf8("font: 600 14pt \"Segoe UI Semibold\";"));
        Buscar->setCentralWidget(centralwidget);

        retranslateUi(Buscar);

        QMetaObject::connectSlotsByName(Buscar);
    } // setupUi

    void retranslateUi(QMainWindow *Buscar)
    {
        Buscar->setWindowTitle(QCoreApplication::translate("Buscar", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Buscar", "DATOS USUARIO", nullptr));
        lblCorreo_2->setText(QCoreApplication::translate("Buscar", "NOMBRES:", nullptr));
        label_4->setText(QCoreApplication::translate("Buscar", "APELLIDOS:", nullptr));
        label_5->setText(QCoreApplication::translate("Buscar", "FECHA NACIMIENTO:", nullptr));
        lblCorreo->setText(QCoreApplication::translate("Buscar", "CORREO:", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Buscar", "REGRESAR", nullptr));
        btnBuscar->setText(QCoreApplication::translate("Buscar", "BUSCAR", nullptr));
        lblCorreo_3->setText(QCoreApplication::translate("Buscar", "INGRESA EL CORREO DEL USUARIO", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Buscar: public Ui_Buscar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUSCAR_H
