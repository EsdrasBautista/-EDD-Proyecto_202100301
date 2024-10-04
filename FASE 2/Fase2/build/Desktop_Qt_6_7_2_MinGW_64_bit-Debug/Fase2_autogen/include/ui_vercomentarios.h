/********************************************************************************
** Form generated from reading UI file 'vercomentarios.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VERCOMENTARIOS_H
#define UI_VERCOMENTARIOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_verComentarios
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_3;
    QPlainTextEdit *txtArea;

    void setupUi(QMainWindow *verComentarios)
    {
        if (verComentarios->objectName().isEmpty())
            verComentarios->setObjectName("verComentarios");
        verComentarios->resize(964, 588);
        verComentarios->setStyleSheet(QString::fromUtf8("background-color: rgb(216, 229, 158);"));
        centralwidget = new QWidget(verComentarios);
        centralwidget->setObjectName("centralwidget");
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(780, 530, 141, 41));
        pushButton_3->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_3->setStyleSheet(QString::fromUtf8("font: 900 10pt \"Segoe UI Black\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;\n"
""));
        txtArea = new QPlainTextEdit(centralwidget);
        txtArea->setObjectName("txtArea");
        txtArea->setEnabled(false);
        txtArea->setGeometry(QRect(20, 30, 921, 421));
        txtArea->setStyleSheet(QString::fromUtf8("font: 600 11pt \"Segoe UI Variable Display Semib\";\n"
"border: 5px solid white;\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));
        verComentarios->setCentralWidget(centralwidget);

        retranslateUi(verComentarios);

        QMetaObject::connectSlotsByName(verComentarios);
    } // setupUi

    void retranslateUi(QMainWindow *verComentarios)
    {
        verComentarios->setWindowTitle(QCoreApplication::translate("verComentarios", "MainWindow", nullptr));
        pushButton_3->setText(QCoreApplication::translate("verComentarios", "REGRESAR", nullptr));
    } // retranslateUi

};

namespace Ui {
    class verComentarios: public Ui_verComentarios {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERCOMENTARIOS_H
