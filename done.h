#ifndef DONE_H
#define DONE_H

#include <QDialog>

namespace Ui {
class done;
}

class done : public QDialog
{
    Q_OBJECT

public:
    explicit done(QWidget *parent = 0);
    ~done();

private:
    Ui::done *ui;
};

#endif // DONE_H
