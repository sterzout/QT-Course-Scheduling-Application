#include "falltermpage.h"
#include "student.h"
#include "admin.h"
#include "coursecatalog.h"
#include "coursepage.h"
#include "ui_falltermpage.h"

fallTermPage::fallTermPage(User* user, Course* course, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::fallTermPage)
    , currentUser(user) // Initialize the currentUser member
    , currentCourse(course)

{
    ui->setupUi(this);
    ui->coursename->setText("Course: " + course->getCourseName());
    ui->facultyname->setText("Faculty: " + course->getFaculty());
    ui->studentid->setText(QString::fromStdString(user->userID));
    // for (const QString &str : user.get()) {
    // ui->studentmajor->setText(QString::fromStdString(user->userID));
    // ui->studentcompletedcourses->setText(QString::fromStdString(user->userID));
    // ui->studentid->setText(QString::fromStdString(user->userID));
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
void fallTermPage::on_addcourse_clicked()
{
    Student* student = dynamic_cast<Student*>(currentUser);
    if (student) {
        ui->detectbutton->setText("Student");
        Course* course1 = new Course(ui->facultyname->text(),ui->coursename->text(),currentCourse->getPrerequisites());

        if (student->addCourseToFall(course1)){
            ui->errormessagebox->setText("Course Successfully added");
            ui->errormessagebox->setAlignment(Qt::AlignCenter);


        }else{
            ui->errormessagebox->setText("Course cannot be added due to overlapping (Course was already completed or found in current timetable)");
            ui->errormessagebox->setAlignment(Qt::AlignCenter);

        }
    }
}

void fallTermPage::on_dropcourse_clicked()
{
    Student* student = dynamic_cast<Student*>(currentUser);
    if (student) {
        Course* course1 = new Course(currentCourse->getFaculty(),currentCourse->getCourseName(),currentCourse->getPrerequisites());

        if (student->dropCourseFromFall(course1)){
            ui->errormessagebox->setText("Course Successfully dropped");
            ui->errormessagebox->setAlignment(Qt::AlignCenter);


        }else{
            ui->errormessagebox->setText("Course is not in timetable");
            ui->errormessagebox->setAlignment(Qt::AlignCenter);

        }
    }
}


void fallTermPage::on_detectbutton_2_clicked()
{
    this->close();
    CoursePage *goBack = new CoursePage(currentUser);
    goBack->show();
}

