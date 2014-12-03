#include "done.h"
#include "ui_done.h"

done::done(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::done)
{
    ui->setupUi(this);
}

done::~done()
{
    delete ui;
}
