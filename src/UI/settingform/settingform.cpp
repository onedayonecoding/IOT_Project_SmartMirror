#include "../../inc/settingform.h"
#include "ui_settingform.h"
#include "../../inc/ui.h"

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

    connect(ui->quitbutton,SIGNAL(clicked()),SLOT(settingclose()));

    setStyleSheet("background:black");
}

SettingForm::~SettingForm()
{
    delete ui;
    if(openui) delete openui;
}

void SettingForm::settingclose(){
    openui=new UI;

    openui->show();

    this->close();
}
