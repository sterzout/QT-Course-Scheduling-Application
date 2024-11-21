#include "wintertermpage.h"
#include "ui_wintertermpage.h"

winterTermPage::winterTermPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::winterTermPage)
{
    ui->setupUi(this);
}

winterTermPage::~winterTermPage()
{
    delete ui;
}
