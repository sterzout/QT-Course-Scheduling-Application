#ifndef PREREQUISITEPAGE_H
#define PREREQUISITEPAGE_H
#include "user.h"
#include "course.h"
#include <QDialog>

namespace Ui {
class prerequisitePage;
}

class prerequisitePage : public QDialog
{
    Q_OBJECT

public:
    // this class is used for the later iteration to have request sent to admin for adding a completed course.
    // not essential but is practical to replicate more realistic process.
    explicit prerequisitePage(User* user, Course* course, QWidget *parent = nullptr);
    ~prerequisitePage();

private:
    Ui::prerequisitePage *ui;
};

#endif // PREREQUISITEPAGE_H
