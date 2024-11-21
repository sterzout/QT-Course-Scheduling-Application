#ifndef WINTERTERMPAGE_H
#define WINTERTERMPAGE_H

#include <QDialog>

namespace Ui {
class winterTermPage;
}

class winterTermPage : public QDialog
{
    Q_OBJECT

public:
    explicit winterTermPage(QWidget *parent = nullptr);
    ~winterTermPage();

private:
    Ui::winterTermPage *ui;
};

#endif // WINTERTERMPAGE_H
