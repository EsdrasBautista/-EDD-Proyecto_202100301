/********************************************************************************
** Form generated from reading UI file 'reporteamistaduser.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTEAMISTADUSER_H
#define UI_REPORTEAMISTADUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_reporteAmistadUser
{
public:
    QWidget *centralwidget;
    QLabel *lblUser;
    QPushButton *pushButton_3;
    QPushButton *btnUsers;

    void setupUi(QMainWindow *reporteAmistadUser)
    {
        if (reporteAmistadUser->objectName().isEmpty())
            reporteAmistadUser->setObjectName("reporteAmistadUser");
        reporteAmistadUser->resize(905, 648);
        reporteAmistadUser->setStyleSheet(QString::fromUtf8("background-color: rgb(216, 229, 158);"));
        centralwidget = new QWidget(reporteAmistadUser);
        centralwidget->setObjectName("centralwidget");
        lblUser = new QLabel(centralwidget);
        lblUser->setObjectName("lblUser");
        lblUser->setGeometry(QRect(40, 20, 811, 531));
        lblUser->setStyleSheet(QString::fromUtf8("font: 600 20pt \"Segoe UI Variable Display Semib\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(730, 580, 121, 51));
        pushButton_3->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_3->setStyleSheet(QString::fromUtf8("font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;\n"
""));
        btnUsers = new QPushButton(centralwidget);
        btnUsers->setObjectName("btnUsers");
        btnUsers->setGeometry(QRect(350, 580, 201, 51));
        btnUsers->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnUsers->setStyleSheet(QString::fromUtf8("font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        reporteAmistadUser->setCentralWidget(centralwidget);

        retranslateUi(reporteAmistadUser);

        QMetaObject::connectSlotsByName(reporteAmistadUser);
    } // setupUi

    void retranslateUi(QMainWindow *reporteAmistadUser)
    {
        reporteAmistadUser->setWindowTitle(QCoreApplication::translate("reporteAmistadUser", "MainWindow", nullptr));
        lblUser->setText(QString());
        pushButton_3->setText(QCoreApplication::translate("reporteAmistadUser", "REGRESAR", nullptr));
        btnUsers->setText(QCoreApplication::translate("reporteAmistadUser", "GENERAR REPORTES", nullptr));
    } // retranslateUi

};

namespace Ui {
    class reporteAmistadUser: public Ui_reporteAmistadUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTEAMISTADUSER_H
