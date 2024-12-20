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
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QLabel *userpasswordlabel;
    QPushButton *pushButton_2;
    QLineEdit *userpass;
    QLabel *errormessagebox;
    QPushButton *pushButton;
    QLabel *usernamelabel;
    QLineEdit *usertext;

    void setupUi(QDialog *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(500, 500);
        userpasswordlabel = new QLabel(MainWindow);
        userpasswordlabel->setObjectName("userpasswordlabel");
        userpasswordlabel->setGeometry(QRect(170, 230, 61, 16));
        pushButton_2 = new QPushButton(MainWindow);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(30, 30, 61, 32));
        pushButton_2->setStyleSheet(QString::fromUtf8("color: white\n"
";\n"
""));
        userpass = new QLineEdit(MainWindow);
        userpass->setObjectName("userpass");
        userpass->setGeometry(QRect(240, 230, 113, 21));
        errormessagebox = new QLabel(MainWindow);
        errormessagebox->setObjectName("errormessagebox");
        errormessagebox->setGeometry(QRect(160, 160, 201, 20));
        errormessagebox->setStyleSheet(QString::fromUtf8("color: white;\n"
""));
        pushButton = new QPushButton(MainWindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(200, 260, 100, 32));
        pushButton->setAutoFillBackground(false);
        usernamelabel = new QLabel(MainWindow);
        usernamelabel->setObjectName("usernamelabel");
        usernamelabel->setGeometry(QRect(170, 210, 71, 16));
        usertext = new QLineEdit(MainWindow);
        usertext->setObjectName("usertext");
        usertext->setGeometry(QRect(240, 210, 113, 21));

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QDialog *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Dialog", nullptr));
        userpasswordlabel->setText(QCoreApplication::translate("MainWindow", "Password:", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        errormessagebox->setText(QString());
        pushButton->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        usernamelabel->setText(QCoreApplication::translate("MainWindow", "Username:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
