/********************************************************************************
** Form generated from reading UI file 'crearpublicacion.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREARPUBLICACION_H
#define UI_CREARPUBLICACION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CrearPublicacion
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_3;
    QPushButton *btnCrear;
    QLineEdit *txtHora;
    QLabel *lblCorreo;
    QLabel *label_4;
    QLabel *lblCorreo_2;
    QPushButton *btnImagen;
    QPlainTextEdit *txtContenido;
    QDateEdit *txtFecha;
    QLabel *label_5;
    QLineEdit *txtImagen;
    QLabel *lblImg;

    void setupUi(QMainWindow *CrearPublicacion)
    {
        if (CrearPublicacion->objectName().isEmpty())
            CrearPublicacion->setObjectName("CrearPublicacion");
        CrearPublicacion->resize(866, 613);
        CrearPublicacion->setStyleSheet(QString::fromUtf8("background-color: rgb(216, 229, 158);\n"
""));
        centralwidget = new QWidget(CrearPublicacion);
        centralwidget->setObjectName("centralwidget");
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(710, 540, 121, 41));
        pushButton_3->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_3->setStyleSheet(QString::fromUtf8("font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;\n"
""));
        btnCrear = new QPushButton(centralwidget);
        btnCrear->setObjectName("btnCrear");
        btnCrear->setGeometry(QRect(360, 500, 161, 51));
        btnCrear->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnCrear->setStyleSheet(QString::fromUtf8("font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        txtHora = new QLineEdit(centralwidget);
        txtHora->setObjectName("txtHora");
        txtHora->setGeometry(QRect(280, 440, 341, 31));
        txtHora->setStyleSheet(QString::fromUtf8("font: 600 11pt \"Segoe UI Variable Display Semib\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        lblCorreo = new QLabel(centralwidget);
        lblCorreo->setObjectName("lblCorreo");
        lblCorreo->setGeometry(QRect(140, 440, 101, 20));
        lblCorreo->setStyleSheet(QString::fromUtf8("font: 600 14pt \"Segoe UI Semibold\";"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(140, 380, 131, 20));
        label_4->setStyleSheet(QString::fromUtf8("font: 600 14pt \"Segoe UI Semibold\";"));
        lblCorreo_2 = new QLabel(centralwidget);
        lblCorreo_2->setObjectName("lblCorreo_2");
        lblCorreo_2->setGeometry(QRect(140, 60, 121, 20));
        lblCorreo_2->setStyleSheet(QString::fromUtf8("font: 600 14pt \"Segoe UI Semibold\";"));
        btnImagen = new QPushButton(centralwidget);
        btnImagen->setObjectName("btnImagen");
        btnImagen->setGeometry(QRect(640, 30, 201, 51));
        btnImagen->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnImagen->setStyleSheet(QString::fromUtf8("font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        txtContenido = new QPlainTextEdit(centralwidget);
        txtContenido->setObjectName("txtContenido");
        txtContenido->setGeometry(QRect(140, 100, 691, 191));
        txtContenido->setStyleSheet(QString::fromUtf8("font: 600 11pt \"Segoe UI Variable Display Semib\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        txtFecha = new QDateEdit(centralwidget);
        txtFecha->setObjectName("txtFecha");
        txtFecha->setGeometry(QRect(280, 380, 341, 31));
        txtFecha->setStyleSheet(QString::fromUtf8("font: 600 11pt \"Segoe UI Variable Display Semib\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(120, 330, 131, 20));
        label_5->setStyleSheet(QString::fromUtf8("font: 600 14pt \"Segoe UI Semibold\";"));
        txtImagen = new QLineEdit(centralwidget);
        txtImagen->setObjectName("txtImagen");
        txtImagen->setEnabled(false);
        txtImagen->setGeometry(QRect(280, 320, 341, 31));
        txtImagen->setStyleSheet(QString::fromUtf8("font: 600 11pt \"Segoe UI Variable Display Semib\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        lblImg = new QLabel(centralwidget);
        lblImg->setObjectName("lblImg");
        lblImg->setGeometry(QRect(640, 320, 201, 161));
        lblImg->setStyleSheet(QString::fromUtf8("font: 600 20pt \"Segoe UI Variable Display Semib\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        CrearPublicacion->setCentralWidget(centralwidget);

        retranslateUi(CrearPublicacion);

        QMetaObject::connectSlotsByName(CrearPublicacion);
    } // setupUi

    void retranslateUi(QMainWindow *CrearPublicacion)
    {
        CrearPublicacion->setWindowTitle(QCoreApplication::translate("CrearPublicacion", "MainWindow", nullptr));
        pushButton_3->setText(QCoreApplication::translate("CrearPublicacion", "REGRESAR", nullptr));
        btnCrear->setText(QCoreApplication::translate("CrearPublicacion", "CREAR", nullptr));
        lblCorreo->setText(QCoreApplication::translate("CrearPublicacion", "HORA:", nullptr));
        label_4->setText(QCoreApplication::translate("CrearPublicacion", "FECHA:", nullptr));
        lblCorreo_2->setText(QCoreApplication::translate("CrearPublicacion", "CONTEIDO:", nullptr));
        btnImagen->setText(QCoreApplication::translate("CrearPublicacion", "AGREGAR IMAGEN", nullptr));
        label_5->setText(QCoreApplication::translate("CrearPublicacion", "IMAGEN:", nullptr));
        lblImg->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CrearPublicacion: public Ui_CrearPublicacion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREARPUBLICACION_H
