/********************************************************************************
** Form generated from reading UI file 'publicaciones.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PUBLICACIONES_H
#define UI_PUBLICACIONES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Publicaciones
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_3;
    QGroupBox *groupBox_3;
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QComboBox *cmbFecha;
    QGroupBox *groupBox_2;
    QPushButton *pushButton_2;
    QLabel *label_3;
    QLabel *label_5;
    QLineEdit *txtCantidad;
    QComboBox *cmbOrden;
    QGroupBox *groupBox_4;
    QPushButton *btnComentar;
    QPushButton *btnVercoment;
    QPushButton *btnVerArbol;
    QPushButton *btnCrearPub;
    QPlainTextEdit *plainTextEdit;
    QLineEdit *txtUsuario;
    QLabel *label_7;
    QLabel *lblUsuario;
    QLineEdit *txtFecha;
    QLabel *lblFecha;

    void setupUi(QMainWindow *Publicaciones)
    {
        if (Publicaciones->objectName().isEmpty())
            Publicaciones->setObjectName("Publicaciones");
        Publicaciones->resize(1268, 729);
        Publicaciones->setStyleSheet(QString::fromUtf8("background-color: rgb(216, 229, 158);\n"
""));
        centralwidget = new QWidget(Publicaciones);
        centralwidget->setObjectName("centralwidget");
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(1100, 670, 141, 41));
        pushButton_3->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_3->setStyleSheet(QString::fromUtf8("font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;\n"
""));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(20, 30, 421, 621));
        groupBox = new QGroupBox(groupBox_3);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 30, 341, 181));
        groupBox->setStyleSheet(QString::fromUtf8("font: 12pt \"Sitka\";"));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(80, 120, 171, 41));
        pushButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        cmbFecha = new QComboBox(groupBox);
        cmbFecha->addItem(QString());
        cmbFecha->addItem(QString());
        cmbFecha->setObjectName("cmbFecha");
        cmbFecha->setGeometry(QRect(30, 50, 281, 41));
        cmbFecha->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        cmbFecha->setStyleSheet(QString::fromUtf8("padding: 5px;\n"
"font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;\n"
"text-align: center;\n"
""));
        groupBox_2 = new QGroupBox(groupBox_3);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(10, 260, 341, 261));
        groupBox_2->setStyleSheet(QString::fromUtf8("font: 12pt \"Sitka\";"));
        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(90, 200, 171, 41));
        pushButton_2->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_2->setStyleSheet(QString::fromUtf8("font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(50, 70, 91, 20));
        label_3->setStyleSheet(QString::fromUtf8("font: 600 14pt \"Segoe UI Semibold\";"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 140, 131, 20));
        label_5->setStyleSheet(QString::fromUtf8("font: 600 14pt \"Segoe UI Semibold\";"));
        txtCantidad = new QLineEdit(groupBox_2);
        txtCantidad->setObjectName("txtCantidad");
        txtCantidad->setGeometry(QRect(150, 140, 171, 31));
        txtCantidad->setStyleSheet(QString::fromUtf8("font: 600 11pt \"Segoe UI Variable Display Semib\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        cmbOrden = new QComboBox(groupBox_2);
        cmbOrden->addItem(QString());
        cmbOrden->addItem(QString());
        cmbOrden->addItem(QString());
        cmbOrden->addItem(QString());
        cmbOrden->setObjectName("cmbOrden");
        cmbOrden->setGeometry(QRect(150, 60, 171, 41));
        cmbOrden->setStyleSheet(QString::fromUtf8("text-align: center;\n"
"font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;\n"
"padding: 5px;\n"
""));
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(460, 30, 781, 621));
        btnComentar = new QPushButton(groupBox_4);
        btnComentar->setObjectName("btnComentar");
        btnComentar->setGeometry(QRect(40, 520, 141, 41));
        btnComentar->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnComentar->setStyleSheet(QString::fromUtf8("font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;\n"
""));
        btnVercoment = new QPushButton(groupBox_4);
        btnVercoment->setObjectName("btnVercoment");
        btnVercoment->setGeometry(QRect(220, 520, 211, 41));
        btnVercoment->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnVercoment->setStyleSheet(QString::fromUtf8("font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;\n"
""));
        btnVerArbol = new QPushButton(groupBox_4);
        btnVerArbol->setObjectName("btnVerArbol");
        btnVerArbol->setGeometry(QRect(480, 520, 271, 41));
        btnVerArbol->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnVerArbol->setStyleSheet(QString::fromUtf8("font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;\n"
""));
        btnCrearPub = new QPushButton(groupBox_4);
        btnCrearPub->setObjectName("btnCrearPub");
        btnCrearPub->setGeometry(QRect(490, 20, 261, 41));
        btnCrearPub->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnCrearPub->setStyleSheet(QString::fromUtf8("font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;\n"
""));
        plainTextEdit = new QPlainTextEdit(groupBox_4);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setEnabled(false);
        plainTextEdit->setGeometry(QRect(40, 220, 711, 281));
        plainTextEdit->setStyleSheet(QString::fromUtf8("font: 600 11pt \"Segoe UI Variable Display Semib\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        txtUsuario = new QLineEdit(groupBox_4);
        txtUsuario->setObjectName("txtUsuario");
        txtUsuario->setEnabled(false);
        txtUsuario->setGeometry(QRect(150, 110, 321, 26));
        txtUsuario->setStyleSheet(QString::fromUtf8("font: 600 11pt \"Segoe UI Variable Display Semib\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(40, 190, 271, 20));
        label_7->setStyleSheet(QString::fromUtf8("font: 600 12pt \"Segoe UI Semibold\";"));
        lblUsuario = new QLabel(groupBox_4);
        lblUsuario->setObjectName("lblUsuario");
        lblUsuario->setGeometry(QRect(40, 110, 101, 20));
        lblUsuario->setStyleSheet(QString::fromUtf8("font: 600 12pt \"Segoe UI Semibold\";"));
        txtFecha = new QLineEdit(groupBox_4);
        txtFecha->setObjectName("txtFecha");
        txtFecha->setEnabled(false);
        txtFecha->setGeometry(QRect(150, 150, 321, 26));
        txtFecha->setStyleSheet(QString::fromUtf8("font: 600 11pt \"Segoe UI Variable Display Semib\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        lblFecha = new QLabel(groupBox_4);
        lblFecha->setObjectName("lblFecha");
        lblFecha->setGeometry(QRect(70, 150, 81, 20));
        lblFecha->setStyleSheet(QString::fromUtf8("font: 600 12pt \"Segoe UI Semibold\";"));
        Publicaciones->setCentralWidget(centralwidget);

        retranslateUi(Publicaciones);

        QMetaObject::connectSlotsByName(Publicaciones);
    } // setupUi

    void retranslateUi(QMainWindow *Publicaciones)
    {
        Publicaciones->setWindowTitle(QCoreApplication::translate("Publicaciones", "MainWindow", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Publicaciones", "REGRESAR", nullptr));
        groupBox_3->setTitle(QString());
        groupBox->setTitle(QCoreApplication::translate("Publicaciones", "FECHA", nullptr));
        pushButton->setText(QCoreApplication::translate("Publicaciones", "APLICAR", nullptr));
        cmbFecha->setItemText(0, QString());
        cmbFecha->setItemText(1, QCoreApplication::translate("Publicaciones", "TODOS", nullptr));

        groupBox_2->setTitle(QCoreApplication::translate("Publicaciones", "RECORRIDO LIMITADO", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Publicaciones", "APLICAR", nullptr));
        label_3->setText(QCoreApplication::translate("Publicaciones", "ORDEN:", nullptr));
        label_5->setText(QCoreApplication::translate("Publicaciones", "CANTIDAD:", nullptr));
        cmbOrden->setItemText(0, QString());
        cmbOrden->setItemText(1, QCoreApplication::translate("Publicaciones", "PreOrden", nullptr));
        cmbOrden->setItemText(2, QCoreApplication::translate("Publicaciones", "PosOrden", nullptr));
        cmbOrden->setItemText(3, QCoreApplication::translate("Publicaciones", "InOrden", nullptr));

        groupBox_4->setTitle(QString());
        btnComentar->setText(QCoreApplication::translate("Publicaciones", "COMENTAR", nullptr));
        btnVercoment->setText(QCoreApplication::translate("Publicaciones", "VER COMENTARIOS", nullptr));
        btnVerArbol->setText(QCoreApplication::translate("Publicaciones", "VER ARBOL COMENTARIOS", nullptr));
        btnCrearPub->setText(QCoreApplication::translate("Publicaciones", "CREAR UNA PUBLICACION", nullptr));
        label_7->setText(QCoreApplication::translate("Publicaciones", "TEXTO PUBLICACION: ", nullptr));
        lblUsuario->setText(QCoreApplication::translate("Publicaciones", "USUARIO: ", nullptr));
        lblFecha->setText(QCoreApplication::translate("Publicaciones", "FECHA: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Publicaciones: public Ui_Publicaciones {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PUBLICACIONES_H
