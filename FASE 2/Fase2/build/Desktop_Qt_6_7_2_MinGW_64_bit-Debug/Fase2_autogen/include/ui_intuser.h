/********************************************************************************
** Form generated from reading UI file 'intuser.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTUSER_H
#define UI_INTUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_intUser
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;

    void setupUi(QDialog *intUser)
    {
        if (intUser->objectName().isEmpty())
            intUser->setObjectName("intUser");
        intUser->resize(656, 571);
        intUser->setStyleSheet(QString::fromUtf8("background-color: rgb(216, 229, 158);"));
        label = new QLabel(intUser);
        label->setObjectName("label");
        label->setGeometry(QRect(230, 20, 211, 31));
        label->setStyleSheet(QString::fromUtf8("font: 900 18pt \"Segoe UI Black\";"));
        label_2 = new QLabel(intUser);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 80, 651, 41));
        label_2->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label_2->setAutoFillBackground(false);
        label_2->setStyleSheet(QString::fromUtf8("font: 900 14pt \"Segoe UI Black\";"));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        pushButton = new QPushButton(intUser);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(230, 230, 181, 51));
        pushButton->setStyleSheet(QString::fromUtf8("font: 600 12pt \"Segoe UI Semibold\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        pushButton_2 = new QPushButton(intUser);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(230, 300, 181, 51));
        pushButton_2->setStyleSheet(QString::fromUtf8("font: 600 12pt \"Segoe UI Semibold\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        pushButton_3 = new QPushButton(intUser);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(230, 370, 181, 51));
        pushButton_3->setStyleSheet(QString::fromUtf8("font: 600 12pt \"Segoe UI Semibold\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        pushButton_4 = new QPushButton(intUser);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(230, 440, 181, 51));
        pushButton_4->setStyleSheet(QString::fromUtf8("font: 600 12pt \"Segoe UI Semibold\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        pushButton_5 = new QPushButton(intUser);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(230, 160, 181, 51));
        pushButton_5->setStyleSheet(QString::fromUtf8("font: 600 12pt \"Segoe UI Semibold\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        pushButton_6 = new QPushButton(intUser);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(450, 510, 181, 41));
        pushButton_6->setStyleSheet(QString::fromUtf8("font: 600 12pt \"Segoe UI Semibold\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));

        retranslateUi(intUser);

        QMetaObject::connectSlotsByName(intUser);
    } // setupUi

    void retranslateUi(QDialog *intUser)
    {
        intUser->setWindowTitle(QCoreApplication::translate("intUser", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("intUser", "BIENVENIDO", nullptr));
        label_2->setText(QCoreApplication::translate("intUser", ".....", nullptr));
        pushButton->setText(QCoreApplication::translate("intUser", "BUSCAR", nullptr));
        pushButton_2->setText(QCoreApplication::translate("intUser", "PUBLICACIONES", nullptr));
        pushButton_3->setText(QCoreApplication::translate("intUser", "SOLICITUDES", nullptr));
        pushButton_4->setText(QCoreApplication::translate("intUser", "REPORTES", nullptr));
        pushButton_5->setText(QCoreApplication::translate("intUser", "PERFIL", nullptr));
        pushButton_6->setText(QCoreApplication::translate("intUser", "CERRAR SESION", nullptr));
    } // retranslateUi

};

namespace Ui {
    class intUser: public Ui_intUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTUSER_H
