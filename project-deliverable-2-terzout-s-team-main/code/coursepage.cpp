#include "coursepage.h"
#include "ui_coursepage.h"
#include "loginorcreate.h"
#include "coursecatalog.h"
#include <QFile>
#include <QList>
#include "falltermpage.h"
#include "wintertermpage.h".h"
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
#include <QDir>
#include "coursetimetable.h"
CoursePage::CoursePage(User* user, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CoursePage)
    , currentUser(user)
    , courseCatalog(CourseCatalog::getInstance()) // Get the singleton instance of CourseCatalog
{
    ui->setupUi(this);
    //print the user info
    if (currentUser) {
        ui->welcomelabel->setText("Welcome, " + QString::fromStdString(currentUser->getName()));
        ui->activeUserLabel->setText("User Active: "+ QString::fromStdString(currentUser->getUserID()));
    }
    //load the courses into the catalog, update the saved courses or new courses from previous sessions to the current logged
    //in user. also load the faculties
    loadCoursesFromFile("/Users/sterzout/Documents/THIRD YEAR/project-deliverable-2-terzout-s-team-main/code/courses.txt");
    loadUserCourses();
    loadFaculties();  // Load the faculties into the combo box

}

CoursePage::~CoursePage()
{
    delete ui;
}

//back to prev page
void CoursePage::on_pushButton_clicked()
{
    loginorcreate *goback = new loginorcreate();
    goback->show();
    connect(goback, &QWidget::destroyed, goback, &QObject::deleteLater);  // Deletes goback when it's destroyed
}
//load faculties method
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
    //clicking this button/faculty combobox will list all faculties available to students
    QString selectedFaculty = ui->facultyComboBox->currentText();  // Get selected faculty
    loadCoursesByFaculty(selectedFaculty);  // Load the courses for that faculty
}

void CoursePage::loadCoursesByFaculty(const QString& facultyName)
{
    //loads the courses by the their common faculty
    ui->CoursesComboBox->clear();
    for (Course* course : courseCatalog->getCourses()) {
        if (course->getFaculty() == facultyName) {
            ui->CoursesComboBox->addItem(course->getCourseName());
        }
    }
}

void CoursePage::on_CoursesComboBox_activated(int index)
{    //clicking this button/course combobox will list all course available to students in the faculty they selected before
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
    //parses the txt and loads the file into a course constructor acceptable format
    std::ifstream file(fileName.toStdString());
    if (!file.is_open()) {
        ui->courseselectedbox->setText("Error: Unable to open course data file.");
        return;
        // return and message error if not openable
    }
    //parse each line
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string fileFaculty, fileCourse, filePrerequisites;

        // parse the line in order: faculty, course name, prerequisites
        if (std::getline(ss, fileFaculty, ',') &&
            std::getline(ss, fileCourse, ',') &&
            std::getline(ss, filePrerequisites)) {

            // trim leading and trailing spaces
            fileFaculty.erase(0, fileFaculty.find_first_not_of(' '));
            fileFaculty.erase(fileFaculty.find_last_not_of(' ') + 1);

            fileCourse.erase(0, fileCourse.find_first_not_of(' '));
            fileCourse.erase(fileCourse.find_last_not_of(' ') + 1);

            filePrerequisites.erase(0, filePrerequisites.find_first_not_of(' '));
            filePrerequisites.erase(filePrerequisites.find_last_not_of(' ') + 1);

            // debugging output to help see what is printed
            qDebug() << "Parsed Faculty:" << QString::fromStdString(fileFaculty)
                     << ", Course Name:" << QString::fromStdString(fileCourse)
                     << ", Prerequisites:" << QString::fromStdString(filePrerequisites);

            // split the prerequisites into a list
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
            //makes new course out of data we parsed and adds to cousecatalog
            Course* course = new Course(QString::fromStdString(fileFaculty),
                                        QString::fromStdString(fileCourse),
                                        prerequisitesList);

            courseCatalog->addCourse(course);
        }
    }

    file.close();
}
void CoursePage::loadUserCourses() {
    // get the username (or userID) of the current user
    std::string currentUserID = currentUser->getUserID();  // Ensure userID is converted to std::string

    // check if courses have already been loaded for the current user
    Student* student = dynamic_cast<Student*>(currentUser);
    if (!student) {
        qDebug() << "currentUser is not a Student.";
        return;
    }

    // if courses are already loaded skip the appending
    if (!student->getFallCourses().isEmpty() || !student->getWinterCourses().isEmpty()) {
        qDebug() << "Courses already loaded.";
        return;
    }

    // open the file containing the user course data
    std::ifstream file("/Users/sterzout/Documents/THIRD YEAR/project-deliverable-2-terzout-s-team-main/code/studentCourseInfo.txt");

    if (!file.is_open()) {
        qDebug() << "Unable to open courses file.";
        return;
    }

    std::string line;
    bool userFound = false;
    QFile fileOpen("/Users/sterzout/Documents/THIRD YEAR/project-deliverable-2-terzout-s-team-main/code/userlogininfo.txt");
    //open file
    if (!fileOpen.open(QIODevice::ReadOnly | QIODevice::Text)) {
        ui->courseselectedbox->setText("Error: Unable to open user data file.");
    } else {
        QTextStream file(&fileOpen);
        while (!file.atEnd()) {
            //while file not at end, split line by the / character
            QString line = file.readLine();
            QStringList parts = line.split("/");
            //if the split is greater than 4 which it always is, then trim the first 4 parts
            if (parts.size() > 4) {
                if (parts[0] == currentUser->name) {
                    qDebug() << "Found user: " << parts[0];

                    QString name = parts[0].trimmed();
                    QString userID = parts[1].trimmed();
                    QString email = parts[2].trimmed();
                    QString passcode = parts[3].trimmed();
                    //print to debug to confirm correct parsed info

                    qDebug() << "Name: " << name << ", UserID: " << userID << ", Email: " << email << ", Passcode: " << passcode;
                    //parse the other two parts into lists since they are fall and winter courses lists respectively
                    QStringList fallCoursesList = parts[4].split(",");
                    QStringList winterCoursesList = parts[5].split(",");

                    qDebug() << "Fall Courses List: " << fallCoursesList;
                    qDebug() << "Winter Courses List: " << winterCoursesList;
                    //remove any empty spaces
                    fallCoursesList.removeAll("");
                    winterCoursesList.removeAll("");

                    // append fall courses if not already added
                    for (QString fallCourse : fallCoursesList) {
                        fallCourse = fallCourse.trimmed();
                        if (!student->getFallCourses().contains(fallCourse)) {
                            qDebug() << "Adding fall course: " << fallCourse;
                            student->getFallCourses().append(fallCourse);
                        }
                    }

                    // append winter courses if not already added
                    for (QString winterCourse : winterCoursesList) {
                        winterCourse = winterCourse.trimmed();
                        if (!student->getWinterCourses().contains(winterCourse)) {
                            qDebug() << "Adding winter course: " << winterCourse;
                            student->getWinterCourses().append(winterCourse);
                        }
                    }
                    //debug to confirm once more
                    qDebug() << "fall courses after update: " << student->getFallCourses();
                    qDebug() << "winter courses after update: " << student->getWinterCourses();
                    qDebug() << "completed courses after update: " << student->getCompletedCourses();

                    fileOpen.close();
                    return;
                }
            } else {
                // data format was wrong so we check with debug format
                qDebug() << "Invalid data format, skipping line.";
            }
        }
        // only if user not found
        qDebug() << "User not found in the data file.";
    }

    file.close();
}







void CoursePage::on_falltermbutton_clicked()
{   //take current course and pass throught to the fall page
    QString selectedCourse = ui->CoursesComboBox->currentText();
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
{   // check if admin or student
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
{   //take current course and pass throught to the course completed page, this is not an essential part of the code so we
    // will complete this full in the later iterations
    QString selectedCourse = ui->CoursesComboBox->currentText();
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


void CoursePage::on_wintertermbutton_clicked()
{   //take current course and pass throught to the winter page

    QString selectedCourse = ui->CoursesComboBox->currentText();
    qDebug() << "Selected course: " << selectedCourse;
    for (Course* course : courseCatalog->getCourses()){
        if (course->getCourseName() == selectedCourse){
            Course* course1 = new Course(course->getFaculty(),
                                         course->getCourseName(),course->getPrerequisites());
            winterTermPage *nextPage = new winterTermPage(currentUser, course1);
            this->hide();
            nextPage->show();
        }
    }

}


void CoursePage::on_goToTimetable_clicked()
{
    // check current users timetable
    courseTimetable *seeTable = new courseTimetable(currentUser);
    this->hide();
    seeTable->show();
}

