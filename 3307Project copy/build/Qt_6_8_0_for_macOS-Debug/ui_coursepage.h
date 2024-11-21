/********************************************************************************
** Form generated from reading UI file 'coursepage.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COURSEPAGE_H
#define UI_COURSEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CoursePage
{
public:
    QLabel *welcomelabel;
    QComboBox *facultyComboBox;
    QLabel *facultylabel;
    QComboBox *CoursesComboBox;
    QLabel *courselabel;
    QPushButton *pushButton;
    QLabel *activeUserLabel;
    QLabel *errormessagebox1;

    void setupUi(QDialog *CoursePage)
    {
        if (CoursePage->objectName().isEmpty())
            CoursePage->setObjectName("CoursePage");
        CoursePage->resize(700, 500);
        welcomelabel = new QLabel(CoursePage);
        welcomelabel->setObjectName("welcomelabel");
        welcomelabel->setGeometry(QRect(200, 20, 291, 41));
        facultyComboBox = new QComboBox(CoursePage);
        facultyComboBox->setObjectName("facultyComboBox");
        facultyComboBox->setGeometry(QRect(90, 100, 591, 32));
        facultylabel = new QLabel(CoursePage);
        facultylabel->setObjectName("facultylabel");
        facultylabel->setGeometry(QRect(20, 110, 58, 16));
        CoursesComboBox = new QComboBox(CoursePage);
        CoursesComboBox->setObjectName("CoursesComboBox");
        CoursesComboBox->setGeometry(QRect(90, 140, 591, 32));
        courselabel = new QLabel(CoursePage);
        courselabel->setObjectName("courselabel");
        courselabel->setGeometry(QRect(20, 140, 58, 16));
        pushButton = new QPushButton(CoursePage);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(570, 10, 100, 32));
        activeUserLabel = new QLabel(CoursePage);
        activeUserLabel->setObjectName("activeUserLabel");
        activeUserLabel->setGeometry(QRect(20, 20, 191, 16));
        errormessagebox1 = new QLabel(CoursePage);
        errormessagebox1->setObjectName("errormessagebox1");
        errormessagebox1->setGeometry(QRect(200, 210, 291, 41));

        retranslateUi(CoursePage);

        QMetaObject::connectSlotsByName(CoursePage);
    } // setupUi

    void retranslateUi(QDialog *CoursePage)
    {
        CoursePage->setWindowTitle(QCoreApplication::translate("CoursePage", "Dialog", nullptr));
        welcomelabel->setText(QCoreApplication::translate("CoursePage", "WELCOME TO THE COURSE SELECTION PAGE", nullptr));
        facultylabel->setText(QCoreApplication::translate("CoursePage", "Faculty : ", nullptr));
        courselabel->setText(QCoreApplication::translate("CoursePage", "Course : ", nullptr));
        pushButton->setText(QCoreApplication::translate("CoursePage", "Logout", nullptr));
        activeUserLabel->setText(QCoreApplication::translate("CoursePage", "User Active:", nullptr));
        errormessagebox1->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CoursePage: public Ui_CoursePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COURSEPAGE_H
