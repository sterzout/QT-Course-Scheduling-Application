#ifndef COURSETIMETABLE_H
#define COURSETIMETABLE_H

#include <QDialog>
#include "user.h"

namespace Ui {
class courseTimetable;
}

class courseTimetable : public QDialog
{
    Q_OBJECT

public:
    explicit courseTimetable(User* user, QWidget *parent = nullptr);
    ~courseTimetable();

private slots:
    void on_pushButton_clicked();

private:
    User* currentUser;  // Current logged-in user
    Ui::courseTimetable *ui;
};

#endif // COURSETIMETABLE_H
