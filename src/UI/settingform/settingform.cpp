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

    //2초마다 옵션 감지
    QTimer *a = new QTimer();
    a->setInterval(2000);
    connect(a,&QTimer::timeout,this,&SettingForm::detect);
    connect(a,&QTimer::timeout,this,&SettingForm::autoair);
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

//인체감지 센서 작동시 화면 검은색으로
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
        f.close();
    }
}
void SettingForm::autoair(){
    QFile air("senser/Air.txt");
    QTextStream Airtext(&air);

    if(!air.open(QFile::ReadWrite | QFile::Text)){
        qDebug("could not open Airfile");
        exit(1);
    }
    QString word=Airtext.readLine();

    if(ui->onoff2->value()==0){
        if(word=="auto"){
            QFile::remove("senser/Air.txt");
            QFile air("senser/Air.txt");
            air.open(QFile::WriteOnly|QFile::Append|QFile::Text);
            QTextStream Airtext2(&air);

            Airtext2<<"off";
            air.close();
        }

    }else{
        if(word=="on"||word=="off"){
            QFile::remove("senser/Air.txt");
            QFile air("senser/Air.txt");
            air.open(QFile::WriteOnly|QFile::Append|QFile::Text);
            QTextStream Airtext(&air);
            Airtext<<"auto";
            air.close();

            qDebug("air auto on");
        }
    }
    air.close();
}
