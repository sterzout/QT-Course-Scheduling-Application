#include "coursetimetable.h"
#include "ui_coursetimetable.h"
#include "user.h"
#include "coursepage.h"
#include "student.h"
#include "course.h"

courseTimetable::courseTimetable(User* user, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::courseTimetable)
    , currentUser(user)
{
    ui->setupUi(this);

    // Ensure currentUser is a Student
    Student* student = dynamic_cast<Student*>(currentUser);
    if (student) {
        // Set student ID
        qDebug() << "Fall Courses Size:" << student->getFallCourses().size();
        qDebug() << "Winter Courses Size:" << student->getWinterCourses().size();
        qDebug() << "Fall Courses Content:" << student->getFallCourses();
        qDebug() << "Winter Courses Content:" << student->getWinterCourses();

        ui->identification->setText("Student ID: " + QString::fromStdString(currentUser->getUserID()));

        // Populate Fall Term Table
        const auto& fallCourses = student->getFallCourses();
        ui->falltableWidget->setRowCount(fallCourses.size());
        int row = 0;
        for (const QString& courseName : fallCourses) {
            QTableWidgetItem* courseNameItem = new QTableWidgetItem(courseName);
            ui->falltableWidget->setItem(row, 0, courseNameItem);
            row++;
        }

        // Populate Winter Term Table
        const auto& winterCourses = student->getWinterCourses();
        ui->wintertableWidget->setRowCount(winterCourses.size());
        row = 0;
        for (const QString& courseName : winterCourses) {
            QTableWidgetItem* courseNameItem = new QTableWidgetItem(courseName);
            ui->wintertableWidget->setItem(row, 0, courseNameItem);
            row++;
        }
    }

    // Show the tables
    ui->falltableWidget->show();
    ui->wintertableWidget->show();
}

courseTimetable::~courseTimetable()
{
    delete ui;
}

void courseTimetable::on_pushButton_clicked()
{
    // Navigate back to CoursePage
    CoursePage* back = new CoursePage(currentUser);
    this->close();
    back->show();
}
