/********************************************************************************
** Form generated from reading UI file 'comentaru.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMENTARU_H
#define UI_COMENTARU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ComentarU
{
public:
    QWidget *centralwidget;
    QPushButton *btnRegresar;
    QGroupBox *groupBox_2;
    QLabel *lblUsuario;
    QLabel *lblFecha;
    QLabel *label_7;
    QLineEdit *txtUsuario;
    QPlainTextEdit *plnText;
    QLabel *lblImagen;
    QLineEdit *txtFecha;
    QGroupBox *groupBox_3;
    QPlainTextEdit *txtComentario;
    QPushButton *btnComentar;
    QTimeEdit *txtHora;
    QLabel *lblCorreo;
    QDateEdit *txtFechaa;
    QLabel *label_4;

    void setupUi(QMainWindow *ComentarU)
    {
        if (ComentarU->objectName().isEmpty())
            ComentarU->setObjectName("ComentarU");
        ComentarU->resize(975, 778);
        ComentarU->setStyleSheet(QString::fromUtf8("background-color: rgb(216, 229, 158);"));
        centralwidget = new QWidget(ComentarU);
        centralwidget->setObjectName("centralwidget");
        btnRegresar = new QPushButton(centralwidget);
        btnRegresar->setObjectName("btnRegresar");
        btnRegresar->setGeometry(QRect(820, 720, 141, 41));
        btnRegresar->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnRegresar->setStyleSheet(QString::fromUtf8("font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;\n"
""));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(30, 20, 891, 411));
        groupBox_2->setStyleSheet(QString::fromUtf8("font: 12pt \"Sitka\";"));
        lblUsuario = new QLabel(groupBox_2);
        lblUsuario->setObjectName("lblUsuario");
        lblUsuario->setGeometry(QRect(100, 40, 91, 20));
        lblUsuario->setStyleSheet(QString::fromUtf8("font: 600 12pt \"Segoe UI Semibold\";"));
        lblFecha = new QLabel(groupBox_2);
        lblFecha->setObjectName("lblFecha");
        lblFecha->setGeometry(QRect(130, 80, 71, 20));
        lblFecha->setStyleSheet(QString::fromUtf8("font: 600 12pt \"Segoe UI Semibold\";"));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(100, 120, 271, 20));
        label_7->setStyleSheet(QString::fromUtf8("font: 600 12pt \"Segoe UI Semibold\";"));
        txtUsuario = new QLineEdit(groupBox_2);
        txtUsuario->setObjectName("txtUsuario");
        txtUsuario->setEnabled(false);
        txtUsuario->setGeometry(QRect(210, 40, 321, 26));
        txtUsuario->setStyleSheet(QString::fromUtf8("font: 600 11pt \"Segoe UI Variable Display Semib\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        plnText = new QPlainTextEdit(groupBox_2);
        plnText->setObjectName("plnText");
        plnText->setEnabled(false);
        plnText->setGeometry(QRect(100, 150, 711, 111));
        plnText->setStyleSheet(QString::fromUtf8("font: 600 11pt \"Segoe UI Variable Display Semib\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        lblImagen = new QLabel(groupBox_2);
        lblImagen->setObjectName("lblImagen");
        lblImagen->setEnabled(false);
        lblImagen->setGeometry(QRect(100, 270, 301, 111));
        lblImagen->setStyleSheet(QString::fromUtf8("font: 600 20pt \"Segoe UI Variable Display Semib\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        txtFecha = new QLineEdit(groupBox_2);
        txtFecha->setObjectName("txtFecha");
        txtFecha->setEnabled(false);
        txtFecha->setGeometry(QRect(210, 80, 321, 26));
        txtFecha->setStyleSheet(QString::fromUtf8("font: 600 11pt \"Segoe UI Variable Display Semib\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(40, 440, 891, 241));
        groupBox_3->setStyleSheet(QString::fromUtf8("font: 12pt \"Sitka\";"));
        txtComentario = new QPlainTextEdit(groupBox_3);
        txtComentario->setObjectName("txtComentario");
        txtComentario->setEnabled(true);
        txtComentario->setGeometry(QRect(30, 40, 511, 141));
        txtComentario->setStyleSheet(QString::fromUtf8("font: 600 11pt \"Segoe UI Variable Display Semib\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        btnComentar = new QPushButton(groupBox_3);
        btnComentar->setObjectName("btnComentar");
        btnComentar->setGeometry(QRect(730, 180, 141, 41));
        btnComentar->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnComentar->setStyleSheet(QString::fromUtf8("font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;\n"
""));
        txtHora = new QTimeEdit(groupBox_3);
        txtHora->setObjectName("txtHora");
        txtHora->setGeometry(QRect(710, 115, 161, 31));
        txtHora->setStyleSheet(QString::fromUtf8("font: 600 11pt \"Segoe UI Variable Display Semib\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        lblCorreo = new QLabel(groupBox_3);
        lblCorreo->setObjectName("lblCorreo");
        lblCorreo->setGeometry(QRect(630, 120, 81, 20));
        lblCorreo->setStyleSheet(QString::fromUtf8("font: 600 14pt \"Segoe UI Semibold\";"));
        txtFechaa = new QDateEdit(groupBox_3);
        txtFechaa->setObjectName("txtFechaa");
        txtFechaa->setGeometry(QRect(710, 60, 161, 31));
        txtFechaa->setStyleSheet(QString::fromUtf8("font: 600 11pt \"Segoe UI Variable Display Semib\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(620, 60, 81, 20));
        label_4->setStyleSheet(QString::fromUtf8("font: 600 14pt \"Segoe UI Semibold\";"));
        ComentarU->setCentralWidget(centralwidget);

        retranslateUi(ComentarU);

        QMetaObject::connectSlotsByName(ComentarU);
    } // setupUi

    void retranslateUi(QMainWindow *ComentarU)
    {
        ComentarU->setWindowTitle(QCoreApplication::translate("ComentarU", "MainWindow", nullptr));
        btnRegresar->setText(QCoreApplication::translate("ComentarU", "REGRESAR", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("ComentarU", "PUBLICACION A COMENTAR", nullptr));
        lblUsuario->setText(QCoreApplication::translate("ComentarU", "USUARIO: ", nullptr));
        lblFecha->setText(QCoreApplication::translate("ComentarU", "FECHA: ", nullptr));
        label_7->setText(QCoreApplication::translate("ComentarU", "TEXTO PUBLICACION: ", nullptr));
        lblImagen->setText(QString());
        groupBox_3->setTitle(QCoreApplication::translate("ComentarU", "COMENTARIO", nullptr));
        btnComentar->setText(QCoreApplication::translate("ComentarU", "COMENTAR", nullptr));
        lblCorreo->setText(QCoreApplication::translate("ComentarU", "HORA:", nullptr));
        label_4->setText(QCoreApplication::translate("ComentarU", "FECHA:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ComentarU: public Ui_ComentarU {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMENTARU_H
