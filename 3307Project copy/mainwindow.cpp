#include "mainwindow.h"
#include "coursepage.h"
#include "user.h"
#include "student.h"
#include "admin.h"

#include "ui_mainwindow.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <QDebug>
#include <string>
#include "loginorcreate.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    qDebug() << "Button clicked"; // Check if the function is being called

    std::string username = ui->usertext->text().toStdString();
    std::string password = ui->userpass->text().toStdString();
    User* loggedInUser = validateLogin(username, password);


    if (loggedInUser) {
        ui->errormessagebox->setText("Login successful");
        if(loggedInUser->getUserID() == "admin"){
            this->close();
            Admin *admin = new Admin(loggedInUser->getName(),loggedInUser->getUserID(),loggedInUser->getEmail(),loggedInUser->getPassword());
            CoursePage *next = new CoursePage(admin);
            next->show();
        }else{
            this->close();
            Student *student = new Student(loggedInUser->getName(),loggedInUser->getUserID(),loggedInUser->getEmail(),loggedInUser->getPassword());
            std::ofstream outfile("/Users/sterzout/3307Project/studentCourseInfo.txt");
            std::string userId = student->name;
            QStringList prerequisites = student->getPrerequisites();
            std::string prerequisitesStr = prerequisites.join(", ").toStdString(); // Convert QStringList to a comma-separated string
            outfile << userId << "," << prerequisitesStr << std::endl;
            CoursePage *next = new CoursePage(student);
            next->show();
        }

    } else {
        ui->errormessagebox->setText("Invalid username or password");
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    this->close();
    loginorcreate *back = new loginorcreate();
    back->show();
}
User* MainWindow::validateLogin(const std::string& username, const std::string& password) {
    std::ifstream file("/Users/sterzout/3307Project/userlogininfo.txt");
    if (!file.is_open()) {
        ui->errormessagebox->setText("Error: Unable to open user data file.");
        return nullptr;
    }

    std::string line;
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
            if (fileUsername == username && fileActualPassword == password) {
                return new User(fileUsername, filePassword, fileEmail, fileActualPassword); // Return the User object
            }
        }
    }

    return nullptr; // Return nullptr if no match is found
}
