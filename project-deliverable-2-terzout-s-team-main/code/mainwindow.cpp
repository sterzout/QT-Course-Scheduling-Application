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
    qDebug() << "Button clicked"; // Debugging output

    // Fetching user input
    std::string username = ui->usertext->text().toStdString();
    std::string password = ui->userpass->text().toStdString();
    User* loggedInUser = validateLogin(username, password);

    if (loggedInUser) {
        ui->errormessagebox->setText("Login successful");

        if (loggedInUser->getUserID() == "admin") {
            this->close();
            Admin* admin = new Admin(loggedInUser->getName(), loggedInUser->getUserID(),
                                     loggedInUser->getEmail(), loggedInUser->getPassword());
            CoursePage* next = new CoursePage(admin);
            next->show();
        } else {
            this->close();
            Student* student = new Student(loggedInUser->getName(), loggedInUser->getUserID(),
                                           loggedInUser->getEmail(), loggedInUser->getPassword());

            std::string filePath = "/Users/sterzout/3307Project copy/studentCourseInfo.txt";
            std::ifstream infile(filePath); // Open the file for reading
            std::ofstream tempFile("/Users/sterzout/3307Project copy/temp.txt"); // Open a temporary file for writing
            std::string line;
            std::string userId = student->getUserID();
            QStringList newPrerequisites = student->getCompletedCourses();
            newPrerequisites.append("Intro to Business");
            bool foundUser = false;

            // Process the file line by line
            while (std::getline(infile, line)) {
                std::stringstream ss(line);
                std::string existingUserId;
                std::getline(ss, existingUserId, ','); // Extract the userId

                if (existingUserId == userId) {
                    // Found the user, update their prerequisites
                    foundUser = true;
                    // Extract the current prerequisites (after the 'Courses Completed:' part)
                    size_t startPos = line.find("Courses Completed: ");
                    if (startPos != std::string::npos) {
                        // Extract existing prerequisites (if any)
                        std::string existingPrerequisites = line.substr(startPos + 19); // Skip 'Courses Completed: '
                        QStringList existingPrereqList = QString::fromStdString(existingPrerequisites).split(", ");
                        for (const QString& prereq : newPrerequisites) {
                            if (!existingPrereqList.contains(prereq)) {
                                existingPrereqList.append(prereq);
                            }
                        }
                        // Write updated line to temp file
                        tempFile << userId << ", Courses Completed: "
                                 << existingPrereqList.join(", ").toStdString() << std::endl;
                    }
                } else {
                    // Write the unmodified line to temp file
                    tempFile << line << std::endl;
                }
            }

            infile.close();

            if (!foundUser) {
                // User not found, append a new record
                tempFile << userId << ", Courses Completed: "
                         << newPrerequisites.join(", ").toStdString() << std::endl;
            }

            tempFile.close(); // Close the temp file

            // Replace the old file with the updated one
            std::remove(filePath.c_str()); // Delete the original file
            std::rename("/Users/sterzout/3307Project copy/temp.txt", filePath.c_str()); // Rename the temp file to the original file name

            // Proceed to the next page
            CoursePage* next = new CoursePage(student);
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
    std::ifstream file("/Users/sterzout/3307Project copy/userlogininfo.txt");
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
