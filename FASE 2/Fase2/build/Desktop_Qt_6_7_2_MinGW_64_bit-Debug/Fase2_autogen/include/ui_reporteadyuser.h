/********************************************************************************
** Form generated from reading UI file 'reporteadyuser.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTEADYUSER_H
#define UI_REPORTEADYUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_reporteAdyUser
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_3;
    QLabel *lblUser;
    QPushButton *btnUsers;

    void setupUi(QMainWindow *reporteAdyUser)
    {
        if (reporteAdyUser->objectName().isEmpty())
            reporteAdyUser->setObjectName("reporteAdyUser");
        reporteAdyUser->resize(972, 698);
        reporteAdyUser->setStyleSheet(QString::fromUtf8("background-color: rgb(216, 229, 158);"));
        centralwidget = new QWidget(reporteAdyUser);
        centralwidget->setObjectName("centralwidget");
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(830, 630, 121, 51));
        pushButton_3->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_3->setStyleSheet(QString::fromUtf8("font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;\n"
""));
        lblUser = new QLabel(centralwidget);
        lblUser->setObjectName("lblUser");
        lblUser->setGeometry(QRect(20, 20, 931, 531));
        lblUser->setStyleSheet(QString::fromUtf8("font: 600 20pt \"Segoe UI Variable Display Semib\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        btnUsers = new QPushButton(centralwidget);
        btnUsers->setObjectName("btnUsers");
        btnUsers->setGeometry(QRect(380, 580, 201, 51));
        btnUsers->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnUsers->setStyleSheet(QString::fromUtf8("font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        reporteAdyUser->setCentralWidget(centralwidget);

        retranslateUi(reporteAdyUser);

        QMetaObject::connectSlotsByName(reporteAdyUser);
    } // setupUi

    void retranslateUi(QMainWindow *reporteAdyUser)
    {
        reporteAdyUser->setWindowTitle(QCoreApplication::translate("reporteAdyUser", "MainWindow", nullptr));
        pushButton_3->setText(QCoreApplication::translate("reporteAdyUser", "REGRESAR", nullptr));
        lblUser->setText(QString());
        btnUsers->setText(QCoreApplication::translate("reporteAdyUser", "GENERAR REPORTES", nullptr));
    } // retranslateUi

};

namespace Ui {
    class reporteAdyUser: public Ui_reporteAdyUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTEADYUSER_H
