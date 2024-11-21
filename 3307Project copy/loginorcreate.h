#ifndef LOGINORCREATE_H
#define LOGINORCREATE_H

#include <QDialog>

namespace Ui {
class loginorcreate;
}

class loginorcreate : public QDialog
{
    Q_OBJECT

public:
    explicit loginorcreate(QWidget *parent = nullptr);
    ~loginorcreate();

private slots:
    void on_loginbutton_clicked();

    void on_createbutton_clicked();


private:
    Ui::loginorcreate *ui;
};

#endif // LOGINORCREATE_H
