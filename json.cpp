#include "json.h"
#include "ui_json.h"
#include <fstream>
#include <QFileDialog>
#include "about.h"

using namespace std;

JSON::JSON(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::JSON) {
        ui->setupUi(this);
        ui->threeD->setDisabled(true);
        ui->dir->setPlaceholderText("Directory to save .json file in");
        ui->ID->setPlaceholderText("ID of your mod");
        ui->name->setPlaceholderText("Ex: diamondSword");
        this->setFixedSize(this->size());
    }

JSON::~JSON() {
    delete ui;
}

void JSON::on_item_clicked(bool checked) {
    if (checked) {
        ui->sameName->setText("Texture name same as item name?");
        ui->label_2->setText("Name of item:");
        ui->name->setToolTip("Use actual name of item, not the unlocalized name");
        ui->q2->setToolTip("Use actual name of item, not the unlocalized name");
        ui->threeD->setDisabled(false);
        ui->stairs->setDisabled(true);
    }
    else {
        ui->sameName->setText("Texture name same as block name?");
        ui->label_2->setText("Name of block:");
        ui->name->setToolTip("Use actual name of block, not the unlocalized name");
        ui->q2->setToolTip("Use actual name of block, not the unlocalized name");
        ui->threeD->setDisabled(true);
        ui->threeD->setChecked(false);
        ui->stairs->setDisabled(false);
    }
}

void JSON::on_sameName_clicked(bool checked) {
    if (checked) {
        ui->label_3->setDisabled(true);
        ui->textName->setDisabled(true);
    }
    else {
       ui->label_3->setDisabled(false);
       ui->textName->setDisabled(false);
    }
}

void JSON::on_gen_clicked() {
    QString textName = ui->textName->text();
    if (ui->sameName->isChecked())
        textName = ui->name->text();
    QString name = ui->dir->text() + "/" + ui->name->text() + ".json";
    QByteArray tempName = name.toLocal8Bit();
    const char* charName = tempName.data();

    string outputItem = "{\n\t \"parent\": \"" + ui->ID->text().toStdString() + ":builtin/generated\",\n\t \"textures\": {\n\t\t \"layer0\": \"" + ui->ID->text().toStdString() + ":items/" + textName.toStdString() + "\"\n\t },\n\t \"display\": {\n\t\t \"thirdperson\": {\n\t\t\t \"rotation\": [ -90, 0, 0 ],\n\t\t\t \"translation\": [ 0, 1, -3 ],\n\t\t\t \"scale\": [ 0.55, 0.55, 0.55 ]\n\t\t },\n\t\t \"firstperson\": {\n\t\t\t \"rotation\": [ 0, -135, 25 ],\n\t\t\t \"translation\": [ 0, 4, 2 ],\n\t\t\t \"scale\": [ 1.7, 1.7, 1.7 ],\n\t\t }\n\t }\n}";
    string outputItem3D = "{\n\t \"parent\": \"" + ui->ID->text().toStdString() + ":builtin/generated\",\n\t \"textures\": {\n\t\t \"layer0\": \"" + ui->ID->text().toStdString() + ":items/" + textName.toStdString() + "\"\n\t },\n\t \"display\": {\n\t\t \"thirdperson\": {\n\t\t\t \"rotation\": [ 0, 90, -35 ],\n\t\t\t \"translation\": [ 0, 1.25, -3.5 ],\n\t\t\t \"scale\": [ 0.85, 0.85, 0.85 ]\n\t\t },\n\t\t \"firstperson\": {\n\t\t\t \"rotation\": [ 0, -135, 25 ],\n\t\t\t \"translation\": [ 0, 4, 2 ],\n\t\t\t \"scale\": [ 1.7, 1.7, 1.7 ],\n\t\t }\n\t }\n}";
    string outputBlock = "";

    try {
        ofstream outputFile;
        outputFile.open(charName);
        if (ui->item->isChecked()) {
            if (!ui->threeD->isChecked())
                outputFile << outputItem << endl;
            else
                outputFile << outputItem3D << endl;
        }
        else {
            outputFile << outputBlock << endl; //Incomplete
        }

        outputFile.close();
    }
    catch(...) {
        ui->gen->setText("Generation Failed");
    }
    ui->gen->setText("Generated!");
}

void JSON::on_reset_clicked() {
    ui->ID->setText("");
    ui->name->setText("");
    ui->textName->setText("");
    ui->dir->setText("");
    ui->item->setChecked(false);
    ui->sameName->setChecked(false);
    ui->item->setChecked(false);
    ui->threeD->setChecked(false);
    ui->stairs->setChecked(false);
    ui->gen->setText("Generate");
    ui->threeD->setDisabled(true);
    ui->label_3->setDisabled(false);
    ui->textName->setDisabled(false);
    ui->stairs->setDisabled(false);
}

void JSON::on_browse_clicked() {
    QString path = QFileDialog::getExistingDirectory(this, tr("Choose Directory"), "/home/", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    ui->dir->setText(path);
}

void JSON::on_pushButton_clicked() {
    About* w = new About();
    w->setWindowFlags(Qt::Tool);
    w->setAttribute(Qt::WA_DeleteOnClose);
    w->show();
}


void JSON::on_actionExit_triggered() {
    this->close();
}

void JSON::on_actionAbout_triggered() {
    About* w = new About();
    w->setWindowFlags(Qt::Tool);
    w->setAttribute(Qt::WA_DeleteOnClose);
    w->show();
}
