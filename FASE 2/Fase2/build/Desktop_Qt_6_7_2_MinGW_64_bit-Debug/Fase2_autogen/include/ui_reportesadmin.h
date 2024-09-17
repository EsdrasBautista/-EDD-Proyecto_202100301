/********************************************************************************
** Form generated from reading UI file 'reportesadmin.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTESADMIN_H
#define UI_REPORTESADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReportesAdmin
{
public:
    QWidget *centralwidget;
    QGroupBox *grbRec_2;
    QLabel *lblPub;
    QPushButton *btnUsers;
    QGroupBox *grbRec_3;
    QLabel *lblUser;
    QPushButton *pushButton_3;

    void setupUi(QMainWindow *ReportesAdmin)
    {
        if (ReportesAdmin->objectName().isEmpty())
            ReportesAdmin->setObjectName("ReportesAdmin");
        ReportesAdmin->resize(1131, 691);
        ReportesAdmin->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 241, 172)"));
        centralwidget = new QWidget(ReportesAdmin);
        centralwidget->setObjectName("centralwidget");
        grbRec_2 = new QGroupBox(centralwidget);
        grbRec_2->setObjectName("grbRec_2");
        grbRec_2->setGeometry(QRect(570, 40, 551, 511));
        grbRec_2->setStyleSheet(QString::fromUtf8("font: 12pt \"Sitka\";"));
        lblPub = new QLabel(grbRec_2);
        lblPub->setObjectName("lblPub");
        lblPub->setGeometry(QRect(10, 30, 531, 471));
        lblPub->setStyleSheet(QString::fromUtf8("font: 600 20pt \"Segoe UI Variable Display Semib\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        btnUsers = new QPushButton(centralwidget);
        btnUsers->setObjectName("btnUsers");
        btnUsers->setGeometry(QRect(460, 570, 201, 51));
        btnUsers->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnUsers->setStyleSheet(QString::fromUtf8("font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        grbRec_3 = new QGroupBox(centralwidget);
        grbRec_3->setObjectName("grbRec_3");
        grbRec_3->setGeometry(QRect(10, 40, 551, 511));
        grbRec_3->setStyleSheet(QString::fromUtf8("font: 12pt \"Sitka\";"));
        lblUser = new QLabel(grbRec_3);
        lblUser->setObjectName("lblUser");
        lblUser->setGeometry(QRect(10, 30, 531, 471));
        lblUser->setStyleSheet(QString::fromUtf8("font: 600 20pt \"Segoe UI Variable Display Semib\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(990, 620, 121, 51));
        pushButton_3->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_3->setStyleSheet(QString::fromUtf8("font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;\n"
""));
        ReportesAdmin->setCentralWidget(centralwidget);

        retranslateUi(ReportesAdmin);

        QMetaObject::connectSlotsByName(ReportesAdmin);
    } // setupUi

    void retranslateUi(QMainWindow *ReportesAdmin)
    {
        ReportesAdmin->setWindowTitle(QCoreApplication::translate("ReportesAdmin", "MainWindow", nullptr));
        grbRec_2->setTitle(QCoreApplication::translate("ReportesAdmin", "LISTA DE PUBLICACIONES", nullptr));
        lblPub->setText(QString());
        btnUsers->setText(QCoreApplication::translate("ReportesAdmin", "GENERAR REPORTES", nullptr));
        grbRec_3->setTitle(QCoreApplication::translate("ReportesAdmin", "ARBOL DE USUARIOS", nullptr));
        lblUser->setText(QString());
        pushButton_3->setText(QCoreApplication::translate("ReportesAdmin", "REGRESAR", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReportesAdmin: public Ui_ReportesAdmin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTESADMIN_H
