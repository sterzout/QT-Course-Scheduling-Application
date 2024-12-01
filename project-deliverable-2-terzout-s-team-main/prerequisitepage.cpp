#include "prerequisitepage.h"
#include "ui_prerequisitepage.h"

prerequisitePage::prerequisitePage(User* user, Course* course, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::prerequisitePage)
//for later iteration
{
    ui->setupUi(this);
}

prerequisitePage::~prerequisitePage()
{
    delete ui;
}
