#include "createaccountpage.h"
#include "ui_createaccountpage.h"
#include "coursepage.h"
#include "student.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
createaccountpage::createaccountpage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::createaccountpage)
{
    ui->setupUi(this);
}

createaccountpage::~createaccountpage()
{
    delete ui;
}

void createaccountpage::on_pushButton_clicked()
{
    QString name = ui->usertext->text();
    QString username = ui->usertext_2->text();
    QString email = ui->usertext_3->text();
    QString password = ui->usertext_4->text();

    std::string nameStr = name.toStdString();
    std::string usernameStr = username.toStdString();
    std::string emailStr = email.toStdString();
    std::string passwordStr = password.toStdString();

    std::ifstream file("/Users/sterzout/3307Project/userlogininfo.txt");

    std::string line;
    bool userExists = false;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string fileUsername, filePassword, fileEmail, fileActualPassword;

        // Parse the line in order: username, password, email, actual_password
        if (std::getline(ss, fileUsername, ',') &&
            std::getline(ss, filePassword, ',') &&
            std::getline(ss, fileEmail, ',') &&
            std::getline(ss, fileActualPassword)) {

            // Trim leading whitespace if any
            // Trim leading and trailing whitespace
            fileUsername.erase(0, fileUsername.find_first_not_of(' '));  // Remove leading spaces
            fileUsername.erase(fileUsername.find_last_not_of(' ') + 1);  // Remove trailing spaces

            filePassword.erase(0, filePassword.find_first_not_of(' '));
            filePassword.erase(filePassword.find_last_not_of(' ') + 1);

            fileEmail.erase(0, fileEmail.find_first_not_of(' '));
            fileEmail.erase(fileEmail.find_last_not_of(' ') + 1);

            fileActualPassword.erase(0, fileActualPassword.find_first_not_of(' '));
            fileActualPassword.erase(fileActualPassword.find_last_not_of(' ') + 1);

            // Debugging output
            qDebug() << "Parsed Username:" << QString::fromStdString(fileUsername)
                     << ", Password:" << QString::fromStdString(fileActualPassword);

            // Check if credentials match
            if (fileUsername == name || fileActualPassword == password ||filePassword == usernameStr||fileEmail == emailStr) {
                userExists = true;
                break;
            }
        }
    }
    if (userExists){
        ui->errormessageaccount->setText("User is already taken. Unable to save account information.");
    }else{
        std::ofstream outfile("/Users/sterzout/3307Project/userlogininfo.txt", std::ios::app);

        outfile << nameStr << ","
                << usernameStr << ","

                << emailStr << ","
                << passwordStr << std::endl;

        outfile.close();

        ui->errormessageaccount->setText("Account created successfully!");

        Student *newStudent = new Student(nameStr, usernameStr, emailStr, passwordStr);
        std::ofstream newStudentCourseOutput("/Users/sterzout/3307Project/studentCourseInfo.txt", std::ios::app);


        newStudentCourseOutput << usernameStr << ", Courses Completed: " << std::endl;  // Empty courses completed
        newStudentCourseOutput.close();
        CoursePage *nextPage = new CoursePage(newStudent);
        this->close();
        nextPage->open();
    }

}
