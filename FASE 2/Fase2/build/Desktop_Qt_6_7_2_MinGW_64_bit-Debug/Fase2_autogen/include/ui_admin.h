/********************************************************************************
** Form generated from reading UI file 'admin.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_H
#define UI_ADMIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Admin
{
public:
    QAction *actionBUSCAR;
    QAction *actionCARGA_MASIVA;
    QAction *actionREPORTES;
    QWidget *centralwidget;
    QLabel *label;
    QLabel *lblNombreU;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QMenu *menuOPCIONES;
    QMenu *menuREPORTES;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Admin)
    {
        if (Admin->objectName().isEmpty())
            Admin->setObjectName("Admin");
        Admin->resize(743, 375);
        Admin->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 241, 172)"));
        actionBUSCAR = new QAction(Admin);
        actionBUSCAR->setObjectName("actionBUSCAR");
        actionCARGA_MASIVA = new QAction(Admin);
        actionCARGA_MASIVA->setObjectName("actionCARGA_MASIVA");
        actionREPORTES = new QAction(Admin);
        actionREPORTES->setObjectName("actionREPORTES");
        centralwidget = new QWidget(Admin);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(270, 90, 231, 31));
        label->setStyleSheet(QString::fromUtf8("font: 900 20pt \"Segoe UI Black\";"));
        lblNombreU = new QLabel(centralwidget);
        lblNombreU->setObjectName("lblNombreU");
        lblNombreU->setGeometry(QRect(40, 170, 651, 51));
        lblNombreU->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        lblNombreU->setAutoFillBackground(false);
        lblNombreU->setStyleSheet(QString::fromUtf8("font: 900 18pt \"Segoe UI Black\";"));
        lblNombreU->setAlignment(Qt::AlignmentFlag::AlignCenter);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(560, 280, 161, 41));
        pushButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        Admin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Admin);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 743, 26));
        menuOPCIONES = new QMenu(menubar);
        menuOPCIONES->setObjectName("menuOPCIONES");
        menuREPORTES = new QMenu(menubar);
        menuREPORTES->setObjectName("menuREPORTES");
        Admin->setMenuBar(menubar);
        statusbar = new QStatusBar(Admin);
        statusbar->setObjectName("statusbar");
        Admin->setStatusBar(statusbar);

        menubar->addAction(menuOPCIONES->menuAction());
        menubar->addAction(menuREPORTES->menuAction());
        menuOPCIONES->addAction(actionBUSCAR);
        menuOPCIONES->addAction(actionCARGA_MASIVA);
        menuREPORTES->addAction(actionREPORTES);

        retranslateUi(Admin);

        QMetaObject::connectSlotsByName(Admin);
    } // setupUi

    void retranslateUi(QMainWindow *Admin)
    {
        Admin->setWindowTitle(QCoreApplication::translate("Admin", "MainWindow", nullptr));
        actionBUSCAR->setText(QCoreApplication::translate("Admin", "BUSCAR", nullptr));
        actionCARGA_MASIVA->setText(QCoreApplication::translate("Admin", "CARGA MASIVA", nullptr));
        actionREPORTES->setText(QCoreApplication::translate("Admin", "REPORTES", nullptr));
        label->setText(QCoreApplication::translate("Admin", "BIENVENIDO", nullptr));
        lblNombreU->setText(QCoreApplication::translate("Admin", "ADMIN", nullptr));
        pushButton->setText(QCoreApplication::translate("Admin", "CERRAR SESION", nullptr));
        menuOPCIONES->setTitle(QCoreApplication::translate("Admin", "OPCIONES", nullptr));
        menuREPORTES->setTitle(QCoreApplication::translate("Admin", "REPORTES", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Admin: public Ui_Admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_H
