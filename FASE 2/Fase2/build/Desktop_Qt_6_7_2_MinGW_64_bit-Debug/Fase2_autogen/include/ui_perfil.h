/********************************************************************************
** Form generated from reading UI file 'perfil.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERFIL_H
#define UI_PERFIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Perfil
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
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QMainWindow *Perfil)
    {
        if (Perfil->objectName().isEmpty())
            Perfil->setObjectName("Perfil");
        Perfil->resize(888, 565);
        Perfil->setStyleSheet(QString::fromUtf8("background-color: rgb(216, 229, 158);"));
        centralwidget = new QWidget(Perfil);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(50, 60, 751, 371));
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
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(290, 450, 161, 51));
        pushButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(490, 450, 191, 51));
        pushButton_2->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_2->setStyleSheet(QString::fromUtf8("font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(740, 500, 121, 41));
        pushButton_3->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_3->setStyleSheet(QString::fromUtf8("font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;\n"
""));
        Perfil->setCentralWidget(centralwidget);

        retranslateUi(Perfil);

        QMetaObject::connectSlotsByName(Perfil);
    } // setupUi

    void retranslateUi(QMainWindow *Perfil)
    {
        Perfil->setWindowTitle(QCoreApplication::translate("Perfil", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Perfil", "DATOS PERFIL", nullptr));
        label_3->setText(QCoreApplication::translate("Perfil", "CONTRASE\303\221A: ", nullptr));
        lblCorreo_2->setText(QCoreApplication::translate("Perfil", "NOMBRES:", nullptr));
        label_4->setText(QCoreApplication::translate("Perfil", "APELLIDOS:", nullptr));
        label_5->setText(QCoreApplication::translate("Perfil", "FECHA NACIMIENTO:", nullptr));
        lblCorreo->setText(QCoreApplication::translate("Perfil", "CORREO:", nullptr));
        pushButton->setText(QCoreApplication::translate("Perfil", "MODIFICAR", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Perfil", "ELIMINAR CUENTA", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Perfil", "REGRESAR", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Perfil: public Ui_Perfil {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERFIL_H
