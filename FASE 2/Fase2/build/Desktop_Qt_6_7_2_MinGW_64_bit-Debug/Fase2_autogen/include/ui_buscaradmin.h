/********************************************************************************
** Form generated from reading UI file 'buscaradmin.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUSCARADMIN_H
#define UI_BUSCARADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BuscarAdmin
{
public:
    QWidget *centralwidget;
    QLabel *label_3;
    QPushButton *btnBuscar;
    QLabel *label_5;
    QComboBox *cmbOrden;
    QLineEdit *txtCorreo;
    QPushButton *btnAplicar;
    QTableWidget *tlbUs;
    QPushButton *pushButton_3;

    void setupUi(QMainWindow *BuscarAdmin)
    {
        if (BuscarAdmin->objectName().isEmpty())
            BuscarAdmin->setObjectName("BuscarAdmin");
        BuscarAdmin->resize(1123, 640);
        BuscarAdmin->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 241, 172)"));
        centralwidget = new QWidget(BuscarAdmin);
        centralwidget->setObjectName("centralwidget");
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(610, 30, 91, 20));
        label_3->setStyleSheet(QString::fromUtf8("font: 600 14pt \"Segoe UI Semibold\";"));
        btnBuscar = new QPushButton(centralwidget);
        btnBuscar->setObjectName("btnBuscar");
        btnBuscar->setGeometry(QRect(400, 60, 131, 41));
        btnBuscar->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnBuscar->setStyleSheet(QString::fromUtf8("font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(240, 30, 101, 20));
        label_5->setStyleSheet(QString::fromUtf8("font: 600 14pt \"Segoe UI Semibold\";"));
        cmbOrden = new QComboBox(centralwidget);
        cmbOrden->addItem(QString());
        cmbOrden->addItem(QString());
        cmbOrden->addItem(QString());
        cmbOrden->addItem(QString());
        cmbOrden->setObjectName("cmbOrden");
        cmbOrden->setGeometry(QRect(570, 60, 171, 41));
        cmbOrden->setStyleSheet(QString::fromUtf8("text-align: center;\n"
"font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;\n"
"padding: 5px;\n"
""));
        txtCorreo = new QLineEdit(centralwidget);
        txtCorreo->setObjectName("txtCorreo");
        txtCorreo->setGeometry(QRect(180, 70, 211, 31));
        txtCorreo->setStyleSheet(QString::fromUtf8("font: 600 11pt \"Segoe UI Variable Display Semib\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        btnAplicar = new QPushButton(centralwidget);
        btnAplicar->setObjectName("btnAplicar");
        btnAplicar->setGeometry(QRect(750, 60, 131, 41));
        btnAplicar->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnAplicar->setStyleSheet(QString::fromUtf8("font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        tlbUs = new QTableWidget(centralwidget);
        tlbUs->setObjectName("tlbUs");
        tlbUs->setEnabled(true);
        tlbUs->setGeometry(QRect(10, 140, 1091, 431));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(960, 580, 141, 41));
        pushButton_3->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_3->setStyleSheet(QString::fromUtf8("font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;\n"
""));
        BuscarAdmin->setCentralWidget(centralwidget);

        retranslateUi(BuscarAdmin);

        QMetaObject::connectSlotsByName(BuscarAdmin);
    } // setupUi

    void retranslateUi(QMainWindow *BuscarAdmin)
    {
        BuscarAdmin->setWindowTitle(QCoreApplication::translate("BuscarAdmin", "MainWindow", nullptr));
        label_3->setText(QCoreApplication::translate("BuscarAdmin", "ORDEN:", nullptr));
        btnBuscar->setText(QCoreApplication::translate("BuscarAdmin", "BUSCAR", nullptr));
        label_5->setText(QCoreApplication::translate("BuscarAdmin", "CORREO:", nullptr));
        cmbOrden->setItemText(0, QString());
        cmbOrden->setItemText(1, QCoreApplication::translate("BuscarAdmin", "PreOrden", nullptr));
        cmbOrden->setItemText(2, QCoreApplication::translate("BuscarAdmin", "PostOrden", nullptr));
        cmbOrden->setItemText(3, QCoreApplication::translate("BuscarAdmin", "InOrden", nullptr));

        btnAplicar->setText(QCoreApplication::translate("BuscarAdmin", "APLICAR", nullptr));
        pushButton_3->setText(QCoreApplication::translate("BuscarAdmin", "REGRESAR", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BuscarAdmin: public Ui_BuscarAdmin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUSCARADMIN_H
