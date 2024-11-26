#ifndef CREATEACCOUNTPAGE_H
#define CREATEACCOUNTPAGE_H

#include <QDialog>

namespace Ui {
class createaccountpage;
}

class createaccountpage : public QDialog
{
    Q_OBJECT

public:
    explicit createaccountpage(QWidget *parent = nullptr);
    ~createaccountpage();

private slots:
    void on_pushButton_clicked();

private:
    Ui::createaccountpage *ui;
};

#endif // CREATEACCOUNTPAGE_H
