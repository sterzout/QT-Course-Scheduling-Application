/********************************************************************************
** Form generated from reading UI file 'createaccountpage.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEACCOUNTPAGE_H
#define UI_CREATEACCOUNTPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_createaccountpage
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *usertext;
    QLineEdit *usertext_2;
    QLineEdit *usertext_3;
    QLineEdit *usertext_4;
    QLabel *errormessageaccount;

    void setupUi(QDialog *createaccountpage)
    {
        if (createaccountpage->objectName().isEmpty())
            createaccountpage->setObjectName("createaccountpage");
        createaccountpage->resize(500, 500);
        createaccountpage->setMaximumSize(QSize(500, 500));
        label = new QLabel(createaccountpage);
        label->setObjectName("label");
        label->setGeometry(QRect(200, 20, 131, 21));
        pushButton = new QPushButton(createaccountpage);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(200, 180, 111, 32));
        layoutWidget = new QWidget(createaccountpage);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(140, 60, 111, 111));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName("label_5");

        verticalLayout->addWidget(label_5);

        layoutWidget1 = new QWidget(createaccountpage);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(270, 60, 127, 116));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        usertext = new QLineEdit(layoutWidget1);
        usertext->setObjectName("usertext");

        verticalLayout_2->addWidget(usertext);

        usertext_2 = new QLineEdit(layoutWidget1);
        usertext_2->setObjectName("usertext_2");

        verticalLayout_2->addWidget(usertext_2);

        usertext_3 = new QLineEdit(layoutWidget1);
        usertext_3->setObjectName("usertext_3");

        verticalLayout_2->addWidget(usertext_3);

        usertext_4 = new QLineEdit(layoutWidget1);
        usertext_4->setObjectName("usertext_4");

        verticalLayout_2->addWidget(usertext_4);

        errormessageaccount = new QLabel(createaccountpage);
        errormessageaccount->setObjectName("errormessageaccount");
        errormessageaccount->setGeometry(QRect(140, 230, 241, 20));

        retranslateUi(createaccountpage);

        QMetaObject::connectSlotsByName(createaccountpage);
    } // setupUi

    void retranslateUi(QDialog *createaccountpage)
    {
        createaccountpage->setWindowTitle(QCoreApplication::translate("createaccountpage", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("createaccountpage", "Create Your Account", nullptr));
        pushButton->setText(QCoreApplication::translate("createaccountpage", "Create Account", nullptr));
        label_2->setText(QCoreApplication::translate("createaccountpage", "Full Name:", nullptr));
        label_3->setText(QCoreApplication::translate("createaccountpage", "User ID:", nullptr));
        label_4->setText(QCoreApplication::translate("createaccountpage", "Email:", nullptr));
        label_5->setText(QCoreApplication::translate("createaccountpage", "Password:", nullptr));
        errormessageaccount->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class createaccountpage: public Ui_createaccountpage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEACCOUNTPAGE_H
