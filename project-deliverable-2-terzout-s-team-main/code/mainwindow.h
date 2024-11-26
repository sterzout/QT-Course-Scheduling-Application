#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string> // Required for std::string
#include "user.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked(); // Slot for button click
    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;

    // Change the return type to User* to match the implementation
    User* validateLogin(const std::string& username, const std::string& password); // Updated return type
};

#endif // MAINWINDOW_H
