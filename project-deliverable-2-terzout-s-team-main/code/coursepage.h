#ifndef COURSEPAGE_H
#define COURSEPAGE_H

#include <QDialog>
#include "user.h"
#include "coursecatalog.h"

namespace Ui {
class CoursePage;
}

class CoursePage : public QDialog
{
    Q_OBJECT

public:
    explicit CoursePage(User* user, QWidget *parent = nullptr);
    ~CoursePage();

private slots:
    void on_pushButton_clicked();  // Button for logging out or going back
    void on_facultyComboBox_activated(int index);  // Faculty selection change
    void on_CoursesComboBox_activated(int index);  // Course selection change


    void on_falltermbutton_clicked();

    void on_adminmode_clicked();


    void on_courseCompleted_clicked();

    void on_wintertermbutton_clicked();

    void on_goToTimetable_clicked();

private:
    Ui::CoursePage *ui;
    User* currentUser;  // Current logged-in user
    CourseCatalog* courseCatalog;  // Singleton instance of CourseCatalog

    void loadFaculties();  // Loads faculty names into the combo box
    void loadCoursesByFaculty(const QString& facultyName);  // Loads courses for a specific faculty
    void loadCoursesFromFile(const QString& fileName);  // Loads courses from the given file
};

#endif // COURSEPAGE_H
