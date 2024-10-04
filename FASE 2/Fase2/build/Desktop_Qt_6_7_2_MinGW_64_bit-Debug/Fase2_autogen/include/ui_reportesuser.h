/********************************************************************************
** Form generated from reading UI file 'reportesuser.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTESUSER_H
#define UI_REPORTESUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_reportesUser
{
public:
    QWidget *centralwidget;
    QGroupBox *grbRec_3;
    QTableWidget *tlbPubs;
    QGroupBox *grbRec_4;
    QTableWidget *tlbCom;
    QGroupBox *grbRec_5;
    QComboBox *cmbFecha;
    QPushButton *btnBst;
    QLabel *lblImagen;
    QPushButton *btnTops;
    QPushButton *pushButton_3;

    void setupUi(QMainWindow *reportesUser)
    {
        if (reportesUser->objectName().isEmpty())
            reportesUser->setObjectName("reportesUser");
        reportesUser->resize(990, 750);
        reportesUser->setStyleSheet(QString::fromUtf8("background-color: rgb(216, 229, 158);"));
        centralwidget = new QWidget(reportesUser);
        centralwidget->setObjectName("centralwidget");
        grbRec_3 = new QGroupBox(centralwidget);
        grbRec_3->setObjectName("grbRec_3");
        grbRec_3->setGeometry(QRect(20, 30, 461, 261));
        grbRec_3->setStyleSheet(QString::fromUtf8("font: 12pt \"Sitka\";"));
        tlbPubs = new QTableWidget(grbRec_3);
        tlbPubs->setObjectName("tlbPubs");
        tlbPubs->setEnabled(true);
        tlbPubs->setGeometry(QRect(10, 30, 441, 211));
        grbRec_4 = new QGroupBox(centralwidget);
        grbRec_4->setObjectName("grbRec_4");
        grbRec_4->setGeometry(QRect(500, 30, 471, 261));
        grbRec_4->setStyleSheet(QString::fromUtf8("font: 12pt \"Sitka\";"));
        tlbCom = new QTableWidget(grbRec_4);
        tlbCom->setObjectName("tlbCom");
        tlbCom->setEnabled(true);
        tlbCom->setGeometry(QRect(10, 30, 451, 211));
        grbRec_5 = new QGroupBox(centralwidget);
        grbRec_5->setObjectName("grbRec_5");
        grbRec_5->setGeometry(QRect(10, 350, 961, 321));
        grbRec_5->setStyleSheet(QString::fromUtf8("font: 12pt \"Sitka\";"));
        cmbFecha = new QComboBox(grbRec_5);
        cmbFecha->setObjectName("cmbFecha");
        cmbFecha->setGeometry(QRect(40, 120, 281, 41));
        cmbFecha->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        cmbFecha->setStyleSheet(QString::fromUtf8("padding: 5px;\n"
"font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;\n"
"text-align: center;\n"
""));
        btnBst = new QPushButton(grbRec_5);
        btnBst->setObjectName("btnBst");
        btnBst->setGeometry(QRect(90, 180, 171, 41));
        btnBst->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnBst->setStyleSheet(QString::fromUtf8("font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        lblImagen = new QLabel(grbRec_5);
        lblImagen->setObjectName("lblImagen");
        lblImagen->setEnabled(false);
        lblImagen->setGeometry(QRect(350, 20, 601, 281));
        lblImagen->setStyleSheet(QString::fromUtf8("font: 600 20pt \"Segoe UI Variable Display Semib\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        btnTops = new QPushButton(centralwidget);
        btnTops->setObjectName("btnTops");
        btnTops->setGeometry(QRect(410, 300, 171, 41));
        btnTops->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnTops->setStyleSheet(QString::fromUtf8("font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(830, 690, 141, 41));
        pushButton_3->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_3->setStyleSheet(QString::fromUtf8("font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;\n"
""));
        reportesUser->setCentralWidget(centralwidget);

        retranslateUi(reportesUser);

        QMetaObject::connectSlotsByName(reportesUser);
    } // setupUi

    void retranslateUi(QMainWindow *reportesUser)
    {
        reportesUser->setWindowTitle(QCoreApplication::translate("reportesUser", "MainWindow", nullptr));
        grbRec_3->setTitle(QCoreApplication::translate("reportesUser", "FECHAS CON MAS PUBLICACIONES", nullptr));
        grbRec_4->setTitle(QCoreApplication::translate("reportesUser", "PUBLICACIONES CON MAS COMENTARIOS", nullptr));
        grbRec_5->setTitle(QCoreApplication::translate("reportesUser", "BST", nullptr));
        btnBst->setText(QCoreApplication::translate("reportesUser", "GENERAR", nullptr));
        lblImagen->setText(QString());
        btnTops->setText(QCoreApplication::translate("reportesUser", "GENERAR", nullptr));
        pushButton_3->setText(QCoreApplication::translate("reportesUser", "REGRESAR", nullptr));
    } // retranslateUi

};

namespace Ui {
    class reportesUser: public Ui_reportesUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTESUSER_H
