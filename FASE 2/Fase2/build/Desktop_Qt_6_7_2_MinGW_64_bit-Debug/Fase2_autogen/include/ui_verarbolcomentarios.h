/********************************************************************************
** Form generated from reading UI file 'verarbolcomentarios.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VERARBOLCOMENTARIOS_H
#define UI_VERARBOLCOMENTARIOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_verArbolComentarios
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_3;
    QLabel *lblimg;

    void setupUi(QMainWindow *verArbolComentarios)
    {
        if (verArbolComentarios->objectName().isEmpty())
            verArbolComentarios->setObjectName("verArbolComentarios");
        verArbolComentarios->resize(800, 582);
        verArbolComentarios->setStyleSheet(QString::fromUtf8("background-color: rgb(216, 229, 158);"));
        centralwidget = new QWidget(verArbolComentarios);
        centralwidget->setObjectName("centralwidget");
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(670, 530, 121, 41));
        pushButton_3->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_3->setStyleSheet(QString::fromUtf8("font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;\n"
""));
        lblimg = new QLabel(centralwidget);
        lblimg->setObjectName("lblimg");
        lblimg->setGeometry(QRect(10, 10, 781, 491));
        lblimg->setStyleSheet(QString::fromUtf8("font: 600 20pt \"Segoe UI Variable Display Semib\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        verArbolComentarios->setCentralWidget(centralwidget);

        retranslateUi(verArbolComentarios);

        QMetaObject::connectSlotsByName(verArbolComentarios);
    } // setupUi

    void retranslateUi(QMainWindow *verArbolComentarios)
    {
        verArbolComentarios->setWindowTitle(QCoreApplication::translate("verArbolComentarios", "MainWindow", nullptr));
        pushButton_3->setText(QCoreApplication::translate("verArbolComentarios", "REGRESAR", nullptr));
        lblimg->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class verArbolComentarios: public Ui_verArbolComentarios {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERARBOLCOMENTARIOS_H
