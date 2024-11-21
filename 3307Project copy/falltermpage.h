#ifndef FALLTERMPAGE_H
#define FALLTERMPAGE_H

#include <QDialog>
#include "user.h"

#include "course.h"

namespace Ui {
class fallTermPage;
}

class fallTermPage : public QDialog
{
    Q_OBJECT

public:
    explicit fallTermPage(User* user, Course* course, QWidget *parent = nullptr);
    ~fallTermPage();

private slots:
    void on_detectbutton_clicked();

private:
    User* currentUser;  // Current logged-in user

    Ui::fallTermPage *ui;
};

#endif // FALLTERMPAGE_H
