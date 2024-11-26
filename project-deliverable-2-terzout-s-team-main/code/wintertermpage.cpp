#include "wintertermpage.h"
#include "ui_wintertermpage.h"
#include "student.h"
#include "user.h"
#include "coursepage.h"

winterTermPage::winterTermPage(User* user, Course* course, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::winterTermPage)
    , currentUser(user) // Initialize the currentUser member
    , currentCourse(course)
{
    ui->setupUi(this);

    ui->courselabel->setText("Course: " + currentCourse->getCourseName());
    ui->facultylabel->setText("Faculty: " + currentCourse->getFaculty());

    QString prerequisitesText = "Prerequisites: ";
    for (const QString &str : currentCourse->getPrerequisites()) {
        if (currentCourse->getPrerequisites().size()==0){
            prerequisitesText += str + "";
        }
        if (currentCourse->getPrerequisites().size()==1){
            prerequisitesText += str + "";
        }else{
            prerequisitesText += str + ", "; // Append each prerequisite followed by a comma
        }
    }
    ui->courseprereqs->setText(prerequisitesText);
}

winterTermPage::~winterTermPage()
{
    delete ui;
}

void winterTermPage::on_addCourse_clicked()
{
    Student* student = dynamic_cast<Student*>(currentUser);
    qDebug() << QString::fromStdString(student->userID);


    if (student) {
        Course* course1 = new Course(currentCourse->getFaculty(),currentCourse->getCourseName(),currentCourse->getPrerequisites());

        if (student->addCourseToWinter(course1)){
            ui->errormessagebox->setText("Course Successfully added");
            ui->errormessagebox->setAlignment(Qt::AlignCenter);


        }else{
            ui->errormessagebox->setText("Course cannot be added due to overlapping (Course was already completed or found in current timetable)");
            ui->errormessagebox->setAlignment(Qt::AlignCenter);

        }
    }


}


void winterTermPage::on_dropCourse_clicked()
{
    Student* student = dynamic_cast<Student*>(currentUser);
    if (student) {
        Course* course1 = new Course(currentCourse->getFaculty(),currentCourse->getCourseName(),currentCourse->getPrerequisites());

        if (student->dropCourseFromWinter(course1)){
            ui->errormessagebox->setText("Course Successfully dropped");
            ui->errormessagebox->setAlignment(Qt::AlignCenter);


        }else{
            ui->errormessagebox->setText("Course is not in timetable");
            ui->errormessagebox->setAlignment(Qt::AlignCenter);

        }
    }
}


void winterTermPage::on_addCourse_2_clicked()
{
    this->close();
    CoursePage *back = new CoursePage(currentUser);
    back->show();
}


void winterTermPage::on_resetWinterTerm_clicked()
{
    Student* student = dynamic_cast<Student*>(currentUser);
    if (student){
        for (const QString& courseRemove : student->getWinterCourses()) {
            student->getWinterCourses().removeAll(courseRemove);
            ui->errormessagebox->setText("Winter Term Cleared");
        }
    }
    ui->errormessagebox->setText("Winter Term Cleared" + student->getWinterCourses().size());

}

void winterTermPage::on_back_clicked()
{

    this->close();
    CoursePage *goBack = new CoursePage(currentUser);
    goBack->show();

}

