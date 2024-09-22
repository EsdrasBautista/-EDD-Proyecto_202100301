/********************************************************************************
** Form generated from reading UI file 'modificaradmin.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFICARADMIN_H
#define UI_MODIFICARADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModificarAdmin
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLabel *label_3;
    QLabel *lblCorreo_2;
    QLineEdit *txtNombres;
    QLabel *label_4;
    QLineEdit *txtApellidos;
    QLabel *label_5;
    QLabel *lblCorreo;
    QLineEdit *txtContraU;
    QLineEdit *txtFechaN;
    QLineEdit *txtCorreoU;
    QPushButton *btnModificar;
    QPushButton *btnRegresar;

    void setupUi(QMainWindow *ModificarAdmin)
    {
        if (ModificarAdmin->objectName().isEmpty())
            ModificarAdmin->setObjectName("ModificarAdmin");
        ModificarAdmin->resize(868, 548);
        ModificarAdmin->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 241, 172)\n"
""));
        centralwidget = new QWidget(ModificarAdmin);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 40, 751, 371));
        groupBox->setStyleSheet(QString::fromUtf8("font: 12pt \"Sitka\";"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(100, 240, 161, 20));
        label_3->setStyleSheet(QString::fromUtf8("font: 600 14pt \"Segoe UI Semibold\";"));
        lblCorreo_2 = new QLabel(groupBox);
        lblCorreo_2->setObjectName("lblCorreo_2");
        lblCorreo_2->setGeometry(QRect(130, 40, 121, 20));
        lblCorreo_2->setStyleSheet(QString::fromUtf8("font: 600 14pt \"Segoe UI Semibold\";"));
        txtNombres = new QLineEdit(groupBox);
        txtNombres->setObjectName("txtNombres");
        txtNombres->setEnabled(true);
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
        txtApellidos->setGeometry(QRect(290, 100, 341, 31));
        txtApellidos->setStyleSheet(QString::fromUtf8("font: 600 11pt \"Segoe UI Variable Display Semib\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 300, 231, 20));
        label_5->setStyleSheet(QString::fromUtf8("font: 600 14pt \"Segoe UI Semibold\";"));
        lblCorreo = new QLabel(groupBox);
        lblCorreo->setObjectName("lblCorreo");
        lblCorreo->setGeometry(QRect(160, 170, 101, 20));
        lblCorreo->setStyleSheet(QString::fromUtf8("font: 600 14pt \"Segoe UI Semibold\";"));
        txtContraU = new QLineEdit(groupBox);
        txtContraU->setObjectName("txtContraU");
        txtContraU->setGeometry(QRect(290, 240, 341, 31));
        txtContraU->setStyleSheet(QString::fromUtf8("font: 600 11pt \"Segoe UI Variable Display Semib\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        txtContraU->setEchoMode(QLineEdit::EchoMode::Normal);
        txtFechaN = new QLineEdit(groupBox);
        txtFechaN->setObjectName("txtFechaN");
        txtFechaN->setGeometry(QRect(290, 300, 341, 31));
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
        btnModificar = new QPushButton(centralwidget);
        btnModificar->setObjectName("btnModificar");
        btnModificar->setGeometry(QRect(350, 430, 161, 51));
        btnModificar->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnModificar->setStyleSheet(QString::fromUtf8("font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        btnRegresar = new QPushButton(centralwidget);
        btnRegresar->setObjectName("btnRegresar");
        btnRegresar->setGeometry(QRect(700, 480, 121, 41));
        btnRegresar->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnRegresar->setStyleSheet(QString::fromUtf8("font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;\n"
""));
        ModificarAdmin->setCentralWidget(centralwidget);

        retranslateUi(ModificarAdmin);

        QMetaObject::connectSlotsByName(ModificarAdmin);
    } // setupUi

    void retranslateUi(QMainWindow *ModificarAdmin)
    {
        ModificarAdmin->setWindowTitle(QCoreApplication::translate("ModificarAdmin", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ModificarAdmin", "DATOS PERFIL", nullptr));
        label_3->setText(QCoreApplication::translate("ModificarAdmin", "CONTRASE\303\221A: ", nullptr));
        lblCorreo_2->setText(QCoreApplication::translate("ModificarAdmin", "NOMBRES:", nullptr));
        label_4->setText(QCoreApplication::translate("ModificarAdmin", "APELLIDOS:", nullptr));
        label_5->setText(QCoreApplication::translate("ModificarAdmin", "FECHA NACIMIENTO:", nullptr));
        lblCorreo->setText(QCoreApplication::translate("ModificarAdmin", "CORREO:", nullptr));
        btnModificar->setText(QCoreApplication::translate("ModificarAdmin", "MODIFICAR", nullptr));
        btnRegresar->setText(QCoreApplication::translate("ModificarAdmin", "REGRESAR", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModificarAdmin: public Ui_ModificarAdmin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFICARADMIN_H
