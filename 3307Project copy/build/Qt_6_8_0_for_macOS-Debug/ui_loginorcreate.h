/********************************************************************************
** Form generated from reading UI file 'loginorcreate.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINORCREATE_H
#define UI_LOGINORCREATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_loginorcreate
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *loginorcreate)
    {
        if (loginorcreate->objectName().isEmpty())
            loginorcreate->setObjectName("loginorcreate");
        loginorcreate->resize(500, 500);
        loginorcreate->setMaximumSize(QSize(500, 500));
        label = new QLabel(loginorcreate);
        label->setObjectName("label");
        label->setGeometry(QRect(120, 20, 281, 31));
        pushButton = new QPushButton(loginorcreate);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(140, 110, 121, 32));
        pushButton_2 = new QPushButton(loginorcreate);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(270, 110, 121, 32));

        retranslateUi(loginorcreate);

        QMetaObject::connectSlotsByName(loginorcreate);
    } // setupUi

    void retranslateUi(QDialog *loginorcreate)
    {
        loginorcreate->setWindowTitle(QCoreApplication::translate("loginorcreate", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("loginorcreate", "Welcome to the UWO Course Selection Page", nullptr));
        pushButton->setText(QCoreApplication::translate("loginorcreate", "Login", nullptr));
        pushButton_2->setText(QCoreApplication::translate("loginorcreate", "Create Account", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loginorcreate: public Ui_loginorcreate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINORCREATE_H
