#include "coursepage.h"
#include "ui_coursepage.h"
#include "loginorcreate.h"
#include "coursecatalog.h"
#include <QFile>
#include <QList>
#include "falltermpage.h"
#include "prerequisitepage.h"
#include "user.h"
#include "admin.h"
#include "student.h"
#include <QTextStream>
#include <QDebug>
#include "course.h"
#include <fstream>
#include <sstream>
#include <QDebug>
#include <string>

CoursePage::CoursePage(User* user, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CoursePage)
    , currentUser(user) // Initialize the currentUser member
    , courseCatalog(CourseCatalog::getInstance()) // Get the singleton instance of CourseCatalog
{
    ui->setupUi(this);

    // Example usage: Display a welcome message with the user's username
    if (currentUser) {
        ui->welcomelabel->setText("Welcome, " + QString::fromStdString(currentUser->getName()));
        ui->activeUserLabel->setText("User Active: "+ QString::fromStdString(currentUser->getUserID()));
    }

    loadCoursesFromFile("/Users/sterzout/3307Project/courses.txt");  // Load courses from a file (modify path as needed)
    loadFaculties();  // Load the faculties into the combo box

}

CoursePage::~CoursePage()
{
    delete ui;
}

void CoursePage::on_pushButton_clicked()
{
    loginorcreate *goback = new loginorcreate();
    goback->show();
    connect(goback, &QWidget::destroyed, goback, &QObject::deleteLater);  // Deletes goback when it's destroyed
}

void CoursePage::loadFaculties()
{
    QStringList faculties;
    for (Course* course : courseCatalog->getCourses()) {
        QString faculty = course->getFaculty();
        if (!faculties.contains(faculty)) {
            faculties.append(faculty);
            qDebug() << "course: " << course->getCourseName();
        }
    }

    ui->facultyComboBox->addItems(faculties);  // Populate the combo box with faculty names
}

void CoursePage::on_facultyComboBox_activated(int index)
{
    QString selectedFaculty = ui->facultyComboBox->currentText();  // Get selected faculty
    loadCoursesByFaculty(selectedFaculty);  // Load the courses for that faculty
}

void CoursePage::loadCoursesByFaculty(const QString& facultyName)
{
    ui->CoursesComboBox->clear();  // Clear the previous courses

    for (Course* course : courseCatalog->getCourses()) {
        if (course->getFaculty() == facultyName) {
            ui->CoursesComboBox->addItem(course->getCourseName());
            // Add matching courses
        }
    }
}

void CoursePage::on_CoursesComboBox_activated(int index)
{
    QString selectedCourse = ui->CoursesComboBox->currentText();  // Get selected course
    qDebug() << "Selected course: " << selectedCourse;
    for (Course* course : courseCatalog->getCourses()){
        if (course->getCourseName() == selectedCourse){
            ui->courseselectedbox->setText("Faculty: " + course->getFaculty() + "\n"+ "Course Selected: "+ selectedCourse);
        }
    }
}



void CoursePage::loadCoursesFromFile(const QString &fileName)
{
    std::ifstream file(fileName.toStdString());
    if (!file.is_open()) {
        ui->courseselectedbox->setText("Error: Unable to open course data file.");
        return;  // Exit if the file can't be opened
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string fileFaculty, fileCourse, filePrerequisites;

        // Parse the line in order: faculty, course name, prerequisites
        if (std::getline(ss, fileFaculty, ',') &&
            std::getline(ss, fileCourse, ',') &&
            std::getline(ss, filePrerequisites)) {

            // Trim leading and trailing spaces
            fileFaculty.erase(0, fileFaculty.find_first_not_of(' '));
            fileFaculty.erase(fileFaculty.find_last_not_of(' ') + 1);

            fileCourse.erase(0, fileCourse.find_first_not_of(' '));
            fileCourse.erase(fileCourse.find_last_not_of(' ') + 1);

            filePrerequisites.erase(0, filePrerequisites.find_first_not_of(' '));
            filePrerequisites.erase(filePrerequisites.find_last_not_of(' ') + 1);

            // Debugging output
            qDebug() << "Parsed Faculty:" << QString::fromStdString(fileFaculty)
                     << ", Course Name:" << QString::fromStdString(fileCourse)
                     << ", Prerequisites:" << QString::fromStdString(filePrerequisites);

            // Split the prerequisites into a list
            QStringList prerequisitesList;
            if (!filePrerequisites.empty()) {
                std::stringstream prereqStream(filePrerequisites);
                std::string prereq;
                while (std::getline(prereqStream, prereq, ',')) {
                    // Trim spaces from each prerequisite course
                    QString prereqTrimmed = QString::fromStdString(prereq);
                    prereqTrimmed = prereqTrimmed.trimmed();
                    prerequisitesList.append(prereqTrimmed);
                }
            }

            // Create a new Course object and add it to the catalog
            Course* course = new Course(QString::fromStdString(fileFaculty),
                                        QString::fromStdString(fileCourse),
                                        prerequisitesList);

            // Add the course to the catalog
            courseCatalog->addCourse(course);
        }
    }

    file.close();

    // Reload the faculties into the combo box after loading courses
}

void CoursePage::on_falltermbutton_clicked()
{
    QString selectedCourse = ui->CoursesComboBox->currentText();  // Get selected course
    qDebug() << "Selected course: " << selectedCourse;
    for (Course* course : courseCatalog->getCourses()){
        if (course->getCourseName() == selectedCourse){
            Course* course1 = new Course(course->getFaculty(),
                                        course->getCourseName(),course->getPrerequisites());
            fallTermPage *nextPage = new fallTermPage(currentUser, course1);
            this->hide();
            nextPage->show();
        }
    }
}


void CoursePage::on_adminmode_clicked()
{
    Admin* admin = dynamic_cast<Admin*>(currentUser);
    if (admin) {
        ui->adminerrormessage->setText("Admin");
    } else {
        Student* student = dynamic_cast<Student*>(currentUser);
        if (student) {
            ui->adminerrormessage->setText("Student");
        } else {
            ui->adminerrormessage->setText("Unknown user type");
        }
    }
}

void CoursePage::on_courseCompleted_clicked()
{
    QString selectedCourse = ui->CoursesComboBox->currentText();  // Get selected course
    qDebug() << "Selected course: " << selectedCourse;
    for (Course* course : courseCatalog->getCourses()){
        if (course->getCourseName() == selectedCourse){
            Course* course1 = new Course(course->getFaculty(),
                                         course->getCourseName(),course->getPrerequisites());
            prerequisitePage *nextPage1 = new prerequisitePage(currentUser, course1);
            this->hide();
            nextPage1->show();
        }
    }
}

