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
    QLabel *courselabel;
    QLabel *activeUserLabel;
    QPushButton *wintertermbutton;
    QPushButton *falltermbutton;
    QLabel *courseselectedbox;
    QPushButton *goToTimetable;
    QPushButton *adminmode;
    QPushButton *pushButton;
    QComboBox *CoursesComboBox;
    QLabel *adminerrormessage;
    QLabel *facultylabel;
    QPushButton *courseCompleted;

    void setupUi(QDialog *CoursePage)
    {
        if (CoursePage->objectName().isEmpty())
            CoursePage->setObjectName("CoursePage");
        CoursePage->resize(700, 500);
        welcomelabel = new QLabel(CoursePage);
        welcomelabel->setObjectName("welcomelabel");
        welcomelabel->setGeometry(QRect(190, 20, 291, 41));
        facultyComboBox = new QComboBox(CoursePage);
        facultyComboBox->setObjectName("facultyComboBox");
        facultyComboBox->setGeometry(QRect(80, 100, 591, 32));
        courselabel = new QLabel(CoursePage);
        courselabel->setObjectName("courselabel");
        courselabel->setGeometry(QRect(10, 140, 58, 16));
        activeUserLabel = new QLabel(CoursePage);
        activeUserLabel->setObjectName("activeUserLabel");
        activeUserLabel->setGeometry(QRect(10, 20, 191, 16));
        wintertermbutton = new QPushButton(CoursePage);
        wintertermbutton->setObjectName("wintertermbutton");
        wintertermbutton->setGeometry(QRect(380, 250, 200, 100));
        falltermbutton = new QPushButton(CoursePage);
        falltermbutton->setObjectName("falltermbutton");
        falltermbutton->setGeometry(QRect(100, 250, 200, 100));
        falltermbutton->setMaximumSize(QSize(300, 300));
        courseselectedbox = new QLabel(CoursePage);
        courseselectedbox->setObjectName("courseselectedbox");
        courseselectedbox->setGeometry(QRect(10, 190, 761, 51));
        QFont font;
        font.setPointSize(20);
        courseselectedbox->setFont(font);
        courseselectedbox->setStyleSheet(QString::fromUtf8(""));
        goToTimetable = new QPushButton(CoursePage);
        goToTimetable->setObjectName("goToTimetable");
        goToTimetable->setGeometry(QRect(380, 370, 200, 100));
        adminmode = new QPushButton(CoursePage);
        adminmode->setObjectName("adminmode");
        adminmode->setGeometry(QRect(0, 460, 100, 32));
        pushButton = new QPushButton(CoursePage);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(560, 10, 100, 32));
        CoursesComboBox = new QComboBox(CoursePage);
        CoursesComboBox->setObjectName("CoursesComboBox");
        CoursesComboBox->setGeometry(QRect(80, 140, 591, 32));
        adminerrormessage = new QLabel(CoursePage);
        adminerrormessage->setObjectName("adminerrormessage");
        adminerrormessage->setGeometry(QRect(20, 440, 58, 16));
        facultylabel = new QLabel(CoursePage);
        facultylabel->setObjectName("facultylabel");
        facultylabel->setGeometry(QRect(10, 110, 58, 16));
        courseCompleted = new QPushButton(CoursePage);
        courseCompleted->setObjectName("courseCompleted");
        courseCompleted->setGeometry(QRect(100, 370, 200, 100));

        retranslateUi(CoursePage);

        QMetaObject::connectSlotsByName(CoursePage);
    } // setupUi

    void retranslateUi(QDialog *CoursePage)
    {
        CoursePage->setWindowTitle(QCoreApplication::translate("CoursePage", "Dialog", nullptr));
        welcomelabel->setText(QCoreApplication::translate("CoursePage", "WELCOME TO THE COURSE SELECTION PAGE", nullptr));
        courselabel->setText(QCoreApplication::translate("CoursePage", "Course : ", nullptr));
        activeUserLabel->setText(QCoreApplication::translate("CoursePage", "User Active:", nullptr));
        wintertermbutton->setText(QCoreApplication::translate("CoursePage", "Winter Term", nullptr));
        falltermbutton->setText(QCoreApplication::translate("CoursePage", "Fall Term", nullptr));
        courseselectedbox->setText(QString());
        goToTimetable->setText(QCoreApplication::translate("CoursePage", "Current Timetable", nullptr));
        adminmode->setText(QCoreApplication::translate("CoursePage", "Admin Mode", nullptr));
        pushButton->setText(QCoreApplication::translate("CoursePage", "Logout", nullptr));
        adminerrormessage->setText(QString());
        facultylabel->setText(QCoreApplication::translate("CoursePage", "Faculty : ", nullptr));
        courseCompleted->setText(QCoreApplication::translate("CoursePage", "Mark Course as Complete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CoursePage: public Ui_CoursePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COURSEPAGE_H
