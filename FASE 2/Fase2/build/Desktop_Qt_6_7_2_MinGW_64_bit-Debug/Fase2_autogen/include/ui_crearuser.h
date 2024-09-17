/********************************************************************************
** Form generated from reading UI file 'crearuser.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREARUSER_H
#define UI_CREARUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CrearUser
{
public:
    QWidget *centralwidget;
    QPushButton *btnCrearUser;
    QPushButton *btnRegresar;
    QLabel *label_5;
    QLabel *lblCorreo;
    QLabel *lblCorreo_2;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_4;
    QLineEdit *txtNombres;
    QLineEdit *txtApellidos;
    QLineEdit *txtCorreoU;
    QLineEdit *txtContraU;
    QLineEdit *txtFechaN;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CrearUser)
    {
        if (CrearUser->objectName().isEmpty())
            CrearUser->setObjectName("CrearUser");
        CrearUser->resize(713, 643);
        CrearUser->setStyleSheet(QString::fromUtf8("background-color: rgb(212, 210, 255);"));
        centralwidget = new QWidget(CrearUser);
        centralwidget->setObjectName("centralwidget");
        btnCrearUser = new QPushButton(centralwidget);
        btnCrearUser->setObjectName("btnCrearUser");
        btnCrearUser->setGeometry(QRect(340, 470, 331, 31));
        btnCrearUser->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnCrearUser->setStyleSheet(QString::fromUtf8("font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        btnRegresar = new QPushButton(centralwidget);
        btnRegresar->setObjectName("btnRegresar");
        btnRegresar->setGeometry(QRect(540, 548, 121, 31));
        btnRegresar->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnRegresar->setStyleSheet(QString::fromUtf8("font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(70, 400, 231, 20));
        label_5->setStyleSheet(QString::fromUtf8("font: 600 14pt \"Segoe UI Semibold\";"));
        lblCorreo = new QLabel(centralwidget);
        lblCorreo->setObjectName("lblCorreo");
        lblCorreo->setGeometry(QRect(200, 270, 101, 20));
        lblCorreo->setStyleSheet(QString::fromUtf8("font: 600 14pt \"Segoe UI Semibold\";"));
        lblCorreo_2 = new QLabel(centralwidget);
        lblCorreo_2->setObjectName("lblCorreo_2");
        lblCorreo_2->setGeometry(QRect(170, 140, 121, 20));
        lblCorreo_2->setStyleSheet(QString::fromUtf8("font: 600 14pt \"Segoe UI Semibold\";"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(140, 340, 161, 20));
        label_3->setStyleSheet(QString::fromUtf8("font: 600 14pt \"Segoe UI Semibold\";"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(240, 20, 251, 61));
        label->setStyleSheet(QString::fromUtf8("font: 900 18pt \"Segoe UI Black\";"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(160, 210, 131, 20));
        label_4->setStyleSheet(QString::fromUtf8("font: 600 14pt \"Segoe UI Semibold\";"));
        txtNombres = new QLineEdit(centralwidget);
        txtNombres->setObjectName("txtNombres");
        txtNombres->setGeometry(QRect(330, 130, 341, 31));
        txtNombres->setStyleSheet(QString::fromUtf8("font: 600 11pt \"Segoe UI Variable Display Semib\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        txtApellidos = new QLineEdit(centralwidget);
        txtApellidos->setObjectName("txtApellidos");
        txtApellidos->setGeometry(QRect(330, 200, 341, 31));
        txtApellidos->setStyleSheet(QString::fromUtf8("font: 600 11pt \"Segoe UI Variable Display Semib\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        txtCorreoU = new QLineEdit(centralwidget);
        txtCorreoU->setObjectName("txtCorreoU");
        txtCorreoU->setGeometry(QRect(330, 270, 341, 31));
        txtCorreoU->setStyleSheet(QString::fromUtf8("font: 600 11pt \"Segoe UI Variable Display Semib\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        txtContraU = new QLineEdit(centralwidget);
        txtContraU->setObjectName("txtContraU");
        txtContraU->setGeometry(QRect(330, 340, 341, 31));
        txtContraU->setStyleSheet(QString::fromUtf8("font: 600 11pt \"Segoe UI Variable Display Semib\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        txtContraU->setEchoMode(QLineEdit::EchoMode::Password);
        txtFechaN = new QLineEdit(centralwidget);
        txtFechaN->setObjectName("txtFechaN");
        txtFechaN->setGeometry(QRect(330, 400, 341, 31));
        txtFechaN->setStyleSheet(QString::fromUtf8("font: 600 11pt \"Segoe UI Variable Display Semib\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        CrearUser->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CrearUser);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 713, 26));
        CrearUser->setMenuBar(menubar);
        statusbar = new QStatusBar(CrearUser);
        statusbar->setObjectName("statusbar");
        CrearUser->setStatusBar(statusbar);

        retranslateUi(CrearUser);

        QMetaObject::connectSlotsByName(CrearUser);
    } // setupUi

    void retranslateUi(QMainWindow *CrearUser)
    {
        CrearUser->setWindowTitle(QCoreApplication::translate("CrearUser", "MainWindow", nullptr));
        btnCrearUser->setText(QCoreApplication::translate("CrearUser", "CREAR", nullptr));
        btnRegresar->setText(QCoreApplication::translate("CrearUser", "REGRESAR", nullptr));
        label_5->setText(QCoreApplication::translate("CrearUser", "FECHA NACIMIENTO:", nullptr));
        lblCorreo->setText(QCoreApplication::translate("CrearUser", "CORREO:", nullptr));
        lblCorreo_2->setText(QCoreApplication::translate("CrearUser", "NOMBRES:", nullptr));
        label_3->setText(QCoreApplication::translate("CrearUser", "CONTRASE\303\221A: ", nullptr));
        label->setText(QCoreApplication::translate("CrearUser", "CREAR USUARIO", nullptr));
        label_4->setText(QCoreApplication::translate("CrearUser", "APELLIDOS:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CrearUser: public Ui_CrearUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREARUSER_H
