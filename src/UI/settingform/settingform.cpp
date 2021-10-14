#include "settingform.h"
#include "ui_settingform.h"

SettingForm::SettingForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingForm)
{
    ui->setupUi(this);
    QString css = QString("color : white");
    ui->label1->setStyleSheet(css);
    ui->label2->setStyleSheet(css);
    ui->On->setStyleSheet(css);
    ui->Off->setStyleSheet(css);
    ui->quitbutton->setStyleSheet(css);
    ui->onoff1->setStyleSheet("background : gray ; color : black");
    ui->onoff2->setStyleSheet("background : gray ; color : black");
}

SettingForm::~SettingForm()
{
    delete ui;
}
