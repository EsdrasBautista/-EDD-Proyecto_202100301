/********************************************************************************
** Form generated from reading UI file 'reportemerkle.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTEMERKLE_H
#define UI_REPORTEMERKLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_reporteMerkle
{
public:
    QWidget *centralwidget;
    QPushButton *btnUsers;
    QPushButton *pushButton_3;
    QLabel *lblUser;
    QComboBox *cmbOrden;
    QLabel *label_3;

    void setupUi(QMainWindow *reporteMerkle)
    {
        if (reporteMerkle->objectName().isEmpty())
            reporteMerkle->setObjectName("reporteMerkle");
        reporteMerkle->resize(879, 749);
        reporteMerkle->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 241, 172)"));
        centralwidget = new QWidget(reporteMerkle);
        centralwidget->setObjectName("centralwidget");
        btnUsers = new QPushButton(centralwidget);
        btnUsers->setObjectName("btnUsers");
        btnUsers->setGeometry(QRect(550, 40, 201, 51));
        btnUsers->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnUsers->setStyleSheet(QString::fromUtf8("font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(720, 680, 121, 51));
        pushButton_3->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_3->setStyleSheet(QString::fromUtf8("font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;\n"
""));
        lblUser = new QLabel(centralwidget);
        lblUser->setObjectName("lblUser");
        lblUser->setGeometry(QRect(30, 120, 811, 531));
        lblUser->setStyleSheet(QString::fromUtf8("font: 600 20pt \"Segoe UI Variable Display Semib\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        cmbOrden = new QComboBox(centralwidget);
        cmbOrden->addItem(QString());
        cmbOrden->addItem(QString());
        cmbOrden->addItem(QString());
        cmbOrden->addItem(QString());
        cmbOrden->setObjectName("cmbOrden");
        cmbOrden->setGeometry(QRect(350, 50, 171, 41));
        cmbOrden->setStyleSheet(QString::fromUtf8("text-align: center;\n"
"font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;\n"
"padding: 5px;\n"
""));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(220, 60, 121, 20));
        label_3->setStyleSheet(QString::fromUtf8("font: 600 14pt \"Segoe UI Semibold\";"));
        reporteMerkle->setCentralWidget(centralwidget);

        retranslateUi(reporteMerkle);

        QMetaObject::connectSlotsByName(reporteMerkle);
    } // setupUi

    void retranslateUi(QMainWindow *reporteMerkle)
    {
        reporteMerkle->setWindowTitle(QCoreApplication::translate("reporteMerkle", "MainWindow", nullptr));
        btnUsers->setText(QCoreApplication::translate("reporteMerkle", "GENERAR REPORTES", nullptr));
        pushButton_3->setText(QCoreApplication::translate("reporteMerkle", "REGRESAR", nullptr));
        lblUser->setText(QString());
        cmbOrden->setItemText(0, QString());
        cmbOrden->setItemText(1, QCoreApplication::translate("reporteMerkle", "PreOrden", nullptr));
        cmbOrden->setItemText(2, QCoreApplication::translate("reporteMerkle", "PosOrden", nullptr));
        cmbOrden->setItemText(3, QCoreApplication::translate("reporteMerkle", "InOrden", nullptr));

        label_3->setText(QCoreApplication::translate("reporteMerkle", "USUARIOS:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class reporteMerkle: public Ui_reporteMerkle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTEMERKLE_H
