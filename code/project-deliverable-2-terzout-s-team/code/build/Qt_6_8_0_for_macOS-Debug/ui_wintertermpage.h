/********************************************************************************
** Form generated from reading UI file 'wintertermpage.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINTERTERMPAGE_H
#define UI_WINTERTERMPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_winterTermPage
{
public:
    QPushButton *back;
    QPushButton *dropCourse;
    QLabel *errormessagebox;
    QLabel *facultylabel;
    QLabel *courseprereqs;
    QLabel *courselabel;
    QLabel *courseavailability;
    QPushButton *resetWinterTerm;
    QPushButton *addCourse;

    void setupUi(QDialog *winterTermPage)
    {
        if (winterTermPage->objectName().isEmpty())
            winterTermPage->setObjectName("winterTermPage");
        winterTermPage->resize(700, 500);
        back = new QPushButton(winterTermPage);
        back->setObjectName("back");
        back->setGeometry(QRect(10, 10, 91, 41));
        dropCourse = new QPushButton(winterTermPage);
        dropCourse->setObjectName("dropCourse");
        dropCourse->setGeometry(QRect(390, 300, 201, 111));
        errormessagebox = new QLabel(winterTermPage);
        errormessagebox->setObjectName("errormessagebox");
        errormessagebox->setGeometry(QRect(10, 240, 681, 41));
        facultylabel = new QLabel(winterTermPage);
        facultylabel->setObjectName("facultylabel");
        facultylabel->setGeometry(QRect(180, 0, 700, 50));
        courseprereqs = new QLabel(winterTermPage);
        courseprereqs->setObjectName("courseprereqs");
        courseprereqs->setGeometry(QRect(180, 100, 700, 50));
        courselabel = new QLabel(winterTermPage);
        courselabel->setObjectName("courselabel");
        courselabel->setGeometry(QRect(180, 50, 700, 50));
        courseavailability = new QLabel(winterTermPage);
        courseavailability->setObjectName("courseavailability");
        courseavailability->setGeometry(QRect(180, 150, 700, 50));
        resetWinterTerm = new QPushButton(winterTermPage);
        resetWinterTerm->setObjectName("resetWinterTerm");
        resetWinterTerm->setGeometry(QRect(10, 450, 161, 41));
        addCourse = new QPushButton(winterTermPage);
        addCourse->setObjectName("addCourse");
        addCourse->setGeometry(QRect(120, 300, 191, 111));

        retranslateUi(winterTermPage);

        QMetaObject::connectSlotsByName(winterTermPage);
    } // setupUi

    void retranslateUi(QDialog *winterTermPage)
    {
        winterTermPage->setWindowTitle(QCoreApplication::translate("winterTermPage", "Dialog", nullptr));
        back->setText(QCoreApplication::translate("winterTermPage", "Back", nullptr));
        dropCourse->setText(QCoreApplication::translate("winterTermPage", "Drop Course", nullptr));
        errormessagebox->setText(QString());
        facultylabel->setText(QCoreApplication::translate("winterTermPage", "Faculty:", nullptr));
        courseprereqs->setText(QCoreApplication::translate("winterTermPage", "Course Prerequisites:", nullptr));
        courselabel->setText(QCoreApplication::translate("winterTermPage", "Course:", nullptr));
        courseavailability->setText(QCoreApplication::translate("winterTermPage", "Course Availabilty: ", nullptr));
        resetWinterTerm->setText(QCoreApplication::translate("winterTermPage", "Reset Winter Term", nullptr));
        addCourse->setText(QCoreApplication::translate("winterTermPage", "Add Course", nullptr));
    } // retranslateUi

};

namespace Ui {
    class winterTermPage: public Ui_winterTermPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINTERTERMPAGE_H
