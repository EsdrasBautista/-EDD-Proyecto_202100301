/********************************************************************************
** Form generated from reading UI file 'solicitudes.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOLICITUDES_H
#define UI_SOLICITUDES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Solicitudes
{
public:
    QWidget *centralwidget;
    QGroupBox *grbUsuarios;
    QTableWidget *tlbUs;
    QGroupBox *grbRec;
    QTableWidget *tlbRec;
    QGroupBox *grbEnv;
    QTableWidget *tlbEnv;
    QPushButton *pushButton_3;

    void setupUi(QMainWindow *Solicitudes)
    {
        if (Solicitudes->objectName().isEmpty())
            Solicitudes->setObjectName("Solicitudes");
        Solicitudes->resize(1198, 700);
        Solicitudes->setStyleSheet(QString::fromUtf8("background-color: rgb(216, 229, 158);\n"
""));
        centralwidget = new QWidget(Solicitudes);
        centralwidget->setObjectName("centralwidget");
        grbUsuarios = new QGroupBox(centralwidget);
        grbUsuarios->setObjectName("grbUsuarios");
        grbUsuarios->setGeometry(QRect(50, 60, 1121, 261));
        grbUsuarios->setStyleSheet(QString::fromUtf8("font: 12pt \"Sitka\";"));
        tlbUs = new QTableWidget(grbUsuarios);
        tlbUs->setObjectName("tlbUs");
        tlbUs->setEnabled(true);
        tlbUs->setGeometry(QRect(20, 40, 1091, 192));
        grbRec = new QGroupBox(centralwidget);
        grbRec->setObjectName("grbRec");
        grbRec->setGeometry(QRect(50, 330, 621, 271));
        grbRec->setStyleSheet(QString::fromUtf8("font: 12pt \"Sitka\";"));
        tlbRec = new QTableWidget(grbRec);
        tlbRec->setObjectName("tlbRec");
        tlbRec->setEnabled(true);
        tlbRec->setGeometry(QRect(20, 30, 591, 231));
        grbEnv = new QGroupBox(centralwidget);
        grbEnv->setObjectName("grbEnv");
        grbEnv->setGeometry(QRect(680, 330, 491, 271));
        grbEnv->setStyleSheet(QString::fromUtf8("font: 12pt \"Sitka\";"));
        tlbEnv = new QTableWidget(grbEnv);
        tlbEnv->setObjectName("tlbEnv");
        tlbEnv->setEnabled(true);
        tlbEnv->setGeometry(QRect(10, 30, 471, 231));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(1020, 640, 141, 41));
        pushButton_3->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_3->setStyleSheet(QString::fromUtf8("font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;\n"
""));
        Solicitudes->setCentralWidget(centralwidget);

        retranslateUi(Solicitudes);

        QMetaObject::connectSlotsByName(Solicitudes);
    } // setupUi

    void retranslateUi(QMainWindow *Solicitudes)
    {
        Solicitudes->setWindowTitle(QCoreApplication::translate("Solicitudes", "MainWindow", nullptr));
        grbUsuarios->setTitle(QCoreApplication::translate("Solicitudes", "USUARIOS", nullptr));
        grbRec->setTitle(QCoreApplication::translate("Solicitudes", "SOLICITUDES RECIBIDAS", nullptr));
        grbEnv->setTitle(QCoreApplication::translate("Solicitudes", "SOLICITUDES ENVIADAS", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Solicitudes", "REGRESAR", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Solicitudes: public Ui_Solicitudes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOLICITUDES_H
