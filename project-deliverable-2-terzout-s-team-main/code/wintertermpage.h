#ifndef WINTERTERMPAGE_H
#define WINTERTERMPAGE_H
#include "course.h"
#include <QDialog>
#include "user.h"
namespace Ui {
class winterTermPage;
}

class winterTermPage : public QDialog
{
    Q_OBJECT

public:
    explicit winterTermPage(User* user, Course* course, QWidget *parent = nullptr);
    ~winterTermPage();

private slots:
    void on_addCourse_clicked();

    void on_dropCourse_clicked();

    void on_addCourse_2_clicked();

    void on_resetWinterTerm_clicked();

    void on_back_clicked();

private:
    User* currentUser;  // Current logged-in user
    Course* currentCourse;
    Ui::winterTermPage *ui;
};

#endif // WINTERTERMPAGE_H
