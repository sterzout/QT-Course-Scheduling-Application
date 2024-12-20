/********************************************************************************
** Form generated from reading UI file 'prerequisitepage.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREREQUISITEPAGE_H
#define UI_PREREQUISITEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_prerequisitePage
{
public:
    QPushButton *addcourse;
    QLabel *facultyname;
    QLabel *coursename;
    QLabel *courseprereqs;
    QPushButton *RequestDropCourse;
    QLabel *courseavailability;

    void setupUi(QDialog *prerequisitePage)
    {
        if (prerequisitePage->objectName().isEmpty())
            prerequisitePage->setObjectName("prerequisitePage");
        prerequisitePage->resize(700, 500);
        addcourse = new QPushButton(prerequisitePage);
        addcourse->setObjectName("addcourse");
        addcourse->setGeometry(QRect(130, 260, 221, 91));
        QFont font;
        font.setPointSize(15);
        addcourse->setFont(font);
        facultyname = new QLabel(prerequisitePage);
        facultyname->setObjectName("facultyname");
        facultyname->setGeometry(QRect(140, 30, 361, 51));
        facultyname->setFont(font);
        coursename = new QLabel(prerequisitePage);
        coursename->setObjectName("coursename");
        coursename->setGeometry(QRect(140, 70, 361, 61));
        coursename->setFont(font);
        courseprereqs = new QLabel(prerequisitePage);
        courseprereqs->setObjectName("courseprereqs");
        courseprereqs->setGeometry(QRect(140, 100, 501, 81));
        courseprereqs->setFont(font);
        courseprereqs->setWordWrap(true);
        RequestDropCourse = new QPushButton(prerequisitePage);
        RequestDropCourse->setObjectName("RequestDropCourse");
        RequestDropCourse->setGeometry(QRect(390, 260, 211, 91));
        RequestDropCourse->setFont(font);
        courseavailability = new QLabel(prerequisitePage);
        courseavailability->setObjectName("courseavailability");
        courseavailability->setGeometry(QRect(140, 160, 341, 41));
        courseavailability->setFont(font);

        retranslateUi(prerequisitePage);

        QMetaObject::connectSlotsByName(prerequisitePage);
    } // setupUi

    void retranslateUi(QDialog *prerequisitePage)
    {
        prerequisitePage->setWindowTitle(QCoreApplication::translate("prerequisitePage", "Dialog", nullptr));
        addcourse->setText(QCoreApplication::translate("prerequisitePage", "Confirm Course as Complete", nullptr));
        facultyname->setText(QCoreApplication::translate("prerequisitePage", "Faculty: ", nullptr));
        coursename->setText(QCoreApplication::translate("prerequisitePage", "Course: ", nullptr));
        courseprereqs->setText(QCoreApplication::translate("prerequisitePage", "Course Prerequisites:", nullptr));
        RequestDropCourse->setText(QCoreApplication::translate("prerequisitePage", "Request Course Removal", nullptr));
        courseavailability->setText(QCoreApplication::translate("prerequisitePage", "Course Availability:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class prerequisitePage: public Ui_prerequisitePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREREQUISITEPAGE_H
