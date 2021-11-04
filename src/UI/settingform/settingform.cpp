#include "../../header/settingform.h"
#include "ui_settingform.h"



#include<qfile.h>
#include <QTextStream>

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
    connect(ui->onoff1,SIGNAL(valueChanged(int)),SLOT(detect()));
    setStyleSheet("background:black");

    QTimer *a = new QTimer();
    a->setInterval(2000);
    connect(a,&QTimer::timeout,this,&SettingForm::detect);
    a->start(); //타이머 시작
}

SettingForm::~SettingForm()
{
    delete ui;
    if(openui) delete openui;
}

void SettingForm::settingclose(){
    openui=new UI;
    this->close();

    openui->show();
}

void SettingForm::detect(){
    if(ui->onoff1->value()==0){
        qDebug("off");
    }else{
        qDebug("on");
        QFile f("senser/motion.txt");
        if(!f.open(QFile::ReadOnly | QFile::Text)){
            qDebug("could not open motionfile");
            exit(1);
        }else{
            QTextStream in(&f);
            QString word=in.readLine();

            MirrorButton2->move(0,0);
            MirrorButton2->resize(1024,600);
            MirrorButton2->setWindowFlag(Qt::FramelessWindowHint);
            MirrorButton2->setStyleSheet("background-color:black");
            if(word=="motion = off"){
                MirrorButton2->show();
                qDebug("detect on");
            }else if(word=="motion = on"){
                MirrorButton2->close();
                qDebug("detect off");
            }else{
                qDebug("fail detect");
            }
        }
    }
}
void SettingForm::autoair(){
    if(ui->onoff2->value()==0){
        qDebug("off");
    }else{
        qDebug("on");
    }
}
