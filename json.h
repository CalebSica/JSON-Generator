#ifndef JSON_H
#define JSON_H

#include <QMainWindow>

namespace Ui {
class JSON;
}

class JSON : public QMainWindow
{
    Q_OBJECT

public:
    explicit JSON(QWidget *parent = 0);
    ~JSON();

private slots:
    void on_item_clicked(bool checked);

    void on_sameName_clicked(bool checked);

    void on_gen_clicked();

    void on_reset_clicked();

    void on_browse_clicked();

    void on_pushButton_clicked();

    void on_actionExit_triggered();

    void on_actionAbout_triggered();

private:
    Ui::JSON *ui;
};

#endif // JSON_H
