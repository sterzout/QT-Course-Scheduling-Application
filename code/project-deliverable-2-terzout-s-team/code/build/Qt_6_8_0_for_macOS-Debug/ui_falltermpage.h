/********************************************************************************
** Form generated from reading UI file 'falltermpage.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FALLTERMPAGE_H
#define UI_FALLTERMPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_fallTermPage
{
public:
    QLabel *facultyname;
    QLabel *courseprereqs;
    QPushButton *dropcourse;
    QPushButton *addcourse;
    QLabel *studentcompletedcourses;
    QLabel *errormessagebox;
    QLabel *studentid;
    QLabel *coursename;
    QPushButton *detectbutton;
    QLabel *studentmajor;
    QLabel *courseavailability;

    void setupUi(QDialog *fallTermPage)
    {
        if (fallTermPage->objectName().isEmpty())
            fallTermPage->setObjectName("fallTermPage");
        fallTermPage->resize(700, 500);
        facultyname = new QLabel(fallTermPage);
        facultyname->setObjectName("facultyname");
        facultyname->setGeometry(QRect(160, 10, 361, 51));
        QFont font;
        font.setPointSize(15);
        facultyname->setFont(font);
        courseprereqs = new QLabel(fallTermPage);
        courseprereqs->setObjectName("courseprereqs");
        courseprereqs->setGeometry(QRect(150, 80, 501, 81));
        courseprereqs->setFont(font);
        courseprereqs->setWordWrap(true);
        dropcourse = new QPushButton(fallTermPage);
        dropcourse->setObjectName("dropcourse");
        dropcourse->setGeometry(QRect(380, 240, 211, 91));
        dropcourse->setFont(font);
        addcourse = new QPushButton(fallTermPage);
        addcourse->setObjectName("addcourse");
        addcourse->setGeometry(QRect(130, 240, 191, 91));
        addcourse->setFont(font);
        studentcompletedcourses = new QLabel(fallTermPage);
        studentcompletedcourses->setObjectName("studentcompletedcourses");
        studentcompletedcourses->setGeometry(QRect(10, 380, 661, 41));
        studentcompletedcourses->setFont(font);
        errormessagebox = new QLabel(fallTermPage);
        errormessagebox->setObjectName("errormessagebox");
        errormessagebox->setGeometry(QRect(20, 199, 661, 31));
        studentid = new QLabel(fallTermPage);
        studentid->setObjectName("studentid");
        studentid->setGeometry(QRect(10, 340, 361, 51));
        studentid->setFont(font);
        coursename = new QLabel(fallTermPage);
        coursename->setObjectName("coursename");
        coursename->setGeometry(QRect(160, 50, 361, 61));
        coursename->setFont(font);
        detectbutton = new QPushButton(fallTermPage);
        detectbutton->setObjectName("detectbutton");
        detectbutton->setGeometry(QRect(450, 460, 100, 32));
        studentmajor = new QLabel(fallTermPage);
        studentmajor->setObjectName("studentmajor");
        studentmajor->setGeometry(QRect(10, 410, 361, 41));
        studentmajor->setFont(font);
        courseavailability = new QLabel(fallTermPage);
        courseavailability->setObjectName("courseavailability");
        courseavailability->setGeometry(QRect(150, 140, 341, 41));
        courseavailability->setFont(font);

        retranslateUi(fallTermPage);

        QMetaObject::connectSlotsByName(fallTermPage);
    } // setupUi

    void retranslateUi(QDialog *fallTermPage)
    {
        fallTermPage->setWindowTitle(QCoreApplication::translate("fallTermPage", "Dialog", nullptr));
        facultyname->setText(QCoreApplication::translate("fallTermPage", "Faculty: ", nullptr));
        courseprereqs->setText(QCoreApplication::translate("fallTermPage", "Course Prerequisites:", nullptr));
        dropcourse->setText(QCoreApplication::translate("fallTermPage", "Drop Course", nullptr));
        addcourse->setText(QCoreApplication::translate("fallTermPage", "Add Course", nullptr));
        studentcompletedcourses->setText(QCoreApplication::translate("fallTermPage", "Courses Completed:", nullptr));
        errormessagebox->setText(QString());
        studentid->setText(QCoreApplication::translate("fallTermPage", "StudentID:", nullptr));
        coursename->setText(QCoreApplication::translate("fallTermPage", "Course: ", nullptr));
        detectbutton->setText(QCoreApplication::translate("fallTermPage", "Detect", nullptr));
        studentmajor->setText(QCoreApplication::translate("fallTermPage", "Major:", nullptr));
        courseavailability->setText(QCoreApplication::translate("fallTermPage", "Course Availability:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class fallTermPage: public Ui_fallTermPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FALLTERMPAGE_H
