#include "falltermpage.h"
#include "student.h"
#include "admin.h"


#include "ui_falltermpage.h"

fallTermPage::fallTermPage(User* user, Course* course, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::fallTermPage)
    , currentUser(user) // Initialize the currentUser member
{
    ui->setupUi(this);
    ui->coursename->setText("Course: " + course->getCourseName());
    ui->facultyname->setText("Faculty: " + course->getFaculty());
    ui->studentid->setText(QString::fromStdString(user->userID));
    // for (const QString &str : user.get()) {
    ui->studentmajor->setText(QString::fromStdString(user->userID));


    ui->studentcompletedcourses->setText(QString::fromStdString(user->userID));
    ui->studentid->setText(QString::fromStdString(user->userID));


    QString prerequisitesText = "Prerequisites: ";
    for (const QString &str : course->getPrerequisites()) {
        if (course->getPrerequisites().size()==0){
            prerequisitesText += str + "";
        }
        if (course->getPrerequisites().size()==1){
            prerequisitesText += str + "";
        }else{
            prerequisitesText += str + ", "; // Append each prerequisite followed by a comma

        }
    }
    ui->courseprereqs->setText(prerequisitesText);
}

fallTermPage::~fallTermPage()
{
    delete ui;
}



void fallTermPage::on_detectbutton_clicked()
{
    Admin* admin = dynamic_cast<Admin*>(currentUser);
    if (admin) {
        ui->detectbutton->setText("Admin");
    } else {
        Student* student = dynamic_cast<Student*>(currentUser);
        if (student) {
            ui->detectbutton->setText("Student");
        } else {
            ui->detectbutton->setText("Unknown user type");
        }
    }


}





