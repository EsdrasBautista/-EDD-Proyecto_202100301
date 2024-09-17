/********************************************************************************
** Form generated from reading UI file 'userint.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERINT_H
#define UI_USERINT_H

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

class Ui_UserInt
{
public:
    QAction *actionPERFIL;
    QAction *actionBUSCAR;
    QAction *actionPUBLICACIONES;
    QAction *actionSOLICITUDES;
    QAction *actionGENERAR_REPORTES;
    QWidget *centralwidget;
    QLabel *label;
    QLabel *lblNombreU;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QMenu *menuPERFIL;
    QMenu *menuREPORTES;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *UserInt)
    {
        if (UserInt->objectName().isEmpty())
            UserInt->setObjectName("UserInt");
        UserInt->resize(755, 355);
        UserInt->setStyleSheet(QString::fromUtf8("background-color: rgb(216, 229, 158);"));
        actionPERFIL = new QAction(UserInt);
        actionPERFIL->setObjectName("actionPERFIL");
        actionBUSCAR = new QAction(UserInt);
        actionBUSCAR->setObjectName("actionBUSCAR");
        actionPUBLICACIONES = new QAction(UserInt);
        actionPUBLICACIONES->setObjectName("actionPUBLICACIONES");
        actionSOLICITUDES = new QAction(UserInt);
        actionSOLICITUDES->setObjectName("actionSOLICITUDES");
        actionGENERAR_REPORTES = new QAction(UserInt);
        actionGENERAR_REPORTES->setObjectName("actionGENERAR_REPORTES");
        centralwidget = new QWidget(UserInt);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(280, 70, 231, 31));
        label->setStyleSheet(QString::fromUtf8("font: 900 20pt \"Segoe UI Black\";"));
        lblNombreU = new QLabel(centralwidget);
        lblNombreU->setObjectName("lblNombreU");
        lblNombreU->setGeometry(QRect(50, 150, 651, 51));
        lblNombreU->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        lblNombreU->setAutoFillBackground(false);
        lblNombreU->setStyleSheet(QString::fromUtf8("font: 900 18pt \"Segoe UI Black\";"));
        lblNombreU->setAlignment(Qt::AlignmentFlag::AlignCenter);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(570, 260, 161, 41));
        pushButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(40, 250, 111, 41));
        pushButton_2->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_2->setStyleSheet(QString::fromUtf8("font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        UserInt->setCentralWidget(centralwidget);
        menubar = new QMenuBar(UserInt);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 755, 26));
        menuPERFIL = new QMenu(menubar);
        menuPERFIL->setObjectName("menuPERFIL");
        menuREPORTES = new QMenu(menubar);
        menuREPORTES->setObjectName("menuREPORTES");
        UserInt->setMenuBar(menubar);
        statusbar = new QStatusBar(UserInt);
        statusbar->setObjectName("statusbar");
        UserInt->setStatusBar(statusbar);

        menubar->addAction(menuPERFIL->menuAction());
        menubar->addAction(menuREPORTES->menuAction());
        menuPERFIL->addAction(actionPERFIL);
        menuPERFIL->addAction(actionBUSCAR);
        menuPERFIL->addAction(actionPUBLICACIONES);
        menuPERFIL->addAction(actionSOLICITUDES);
        menuPERFIL->addSeparator();
        menuREPORTES->addAction(actionGENERAR_REPORTES);
        menuREPORTES->addSeparator();

        retranslateUi(UserInt);

        QMetaObject::connectSlotsByName(UserInt);
    } // setupUi

    void retranslateUi(QMainWindow *UserInt)
    {
        UserInt->setWindowTitle(QCoreApplication::translate("UserInt", "MainWindow", nullptr));
        actionPERFIL->setText(QCoreApplication::translate("UserInt", "PERFIL", nullptr));
        actionBUSCAR->setText(QCoreApplication::translate("UserInt", "BUSCAR", nullptr));
        actionPUBLICACIONES->setText(QCoreApplication::translate("UserInt", "PUBLICACIONES", nullptr));
        actionSOLICITUDES->setText(QCoreApplication::translate("UserInt", "SOLICITUDES", nullptr));
        actionGENERAR_REPORTES->setText(QCoreApplication::translate("UserInt", "GENERAR REPORTES", nullptr));
        label->setText(QCoreApplication::translate("UserInt", "BIENVENIDO", nullptr));
        lblNombreU->setText(QCoreApplication::translate("UserInt", ".", nullptr));
        pushButton->setText(QCoreApplication::translate("UserInt", "CERRAR SESION", nullptr));
        pushButton_2->setText(QCoreApplication::translate("UserInt", "ver amigos", nullptr));
        menuPERFIL->setTitle(QCoreApplication::translate("UserInt", "MENU OPCIONES", nullptr));
        menuREPORTES->setTitle(QCoreApplication::translate("UserInt", "REPORTES", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserInt: public Ui_UserInt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERINT_H
