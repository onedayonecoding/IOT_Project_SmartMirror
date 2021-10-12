#include "Setting.h"
#include "ui_setting.h"

Setting::Setting(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::setting)
{
    ui->setupUi(this);
    QString css = QString("color : white");
    ui->label1->setStyleSheet(css);
    ui->label2->setStyleSheet(css);
    ui->On->setStyleSheet(css);
    ui->Off->setStyleSheet(css);
    ui->onoff1->setStyleSheet("background : blue ; color : white");
    ui->onoff2->setStyleSheet("background : blue ; color : white");
}


void Setting::setting(){
    QString css = QString("color : white");
    ui->label1->setStyleSheet(css);
    ui->label2->setStyleSheet(css);
    ui->On->setStyleSheet(css);
    ui->Off->setStyleSheet(css);
    ui->onoff1->setStyleSheet("background : blue ; color : white");
    ui->onoff2->setStyleSheet("background : blue ; color : white");
}
