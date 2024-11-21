/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *usernamelabel;
    QLabel *userpasswordlabel;
    QLineEdit *usertext;
    QLineEdit *userpass;
    QPushButton *pushButton;
    QLabel *errormessagebox;
    QPushButton *pushButton_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(500, 500);
        MainWindow->setMaximumSize(QSize(500, 500));
        MainWindow->setAutoFillBackground(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        usernamelabel = new QLabel(centralwidget);
        usernamelabel->setObjectName("usernamelabel");
        usernamelabel->setGeometry(QRect(160, 190, 71, 16));
        userpasswordlabel = new QLabel(centralwidget);
        userpasswordlabel->setObjectName("userpasswordlabel");
        userpasswordlabel->setGeometry(QRect(160, 210, 61, 16));
        usertext = new QLineEdit(centralwidget);
        usertext->setObjectName("usertext");
        usertext->setGeometry(QRect(230, 190, 113, 21));
        userpass = new QLineEdit(centralwidget);
        userpass->setObjectName("userpass");
        userpass->setGeometry(QRect(230, 210, 113, 21));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(190, 240, 100, 32));
        pushButton->setAutoFillBackground(true);
        errormessagebox = new QLabel(centralwidget);
        errormessagebox->setObjectName("errormessagebox");
        errormessagebox->setGeometry(QRect(150, 140, 201, 20));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(20, 10, 61, 32));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        usernamelabel->setText(QCoreApplication::translate("MainWindow", "Username:", nullptr));
        userpasswordlabel->setText(QCoreApplication::translate("MainWindow", "Password:", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        errormessagebox->setText(QString());
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
