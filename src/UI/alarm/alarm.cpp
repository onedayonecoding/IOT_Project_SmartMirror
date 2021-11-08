
#include <QVBoxLayout>
#include <QDebug>
#include<QTime>
#include<QProcess>

#include "../../header/alarm.h"
Alarm::Alarm(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout * layout = new QVBoxLayout(this);
    QSizePolicy policy(QSizePolicy::Expanding,QSizePolicy::Fixed);
    QFont mFont("Consolas", 20, QFont::Bold);

    alarmtime = new QTimeEdit();
    submit = new QPushButton("알람 설정");
    alarmtime->setFont(mFont);
    submit->setFont(mFont);

    QString css = QString("background-color : black;color : white");
    alarmtime->setStyleSheet(css);

    layout->addWidget(alarmtime);
    layout->addWidget(submit);
    setLayout(layout);
    setSizePolicy(policy);

    connect(submit,SIGNAL(clicked()),SLOT(SetTime()));

    timer = new QTimer(this);
    timer->setInterval(1000);

    connect(timer,&QTimer::timeout,this,&Alarm::Alarmcheck);
    connect(timer,&QTimer::timeout,this,&Alarm::ShowAlarmtime);
    timer->start();
}

void Alarm::SetTime(){
    time = alarmtime->time();

    stime = time.toString("hh:mm AP");
    qDebug("dd");
    qDebug() << stime;
}

void Alarm::Alarmcheck(){
    qDebug()<<alarmnum;
    if(stime==QTime::currentTime().toString(("hh:mm AP"))){
        qDebug("alarm");
        if(alarmnum==0){
            QProcess *process =new QProcess;
            process->setWorkingDirectory("../UI/alarm");
            process->start("./alarm");
            process->waitForFinished();

            alarmbutton = new QPushButton("alarmcheck");

            alarmbutton->resize(1024,600);
            alarmbutton->move(0,0);
            alarmbutton->show();
            alarmnum=1;

        }
        connect(alarmbutton,SIGNAL(clicked()),this,SLOT(DeleteAlarm()));
        connect(alarmbutton,SIGNAL(clicked()),alarmbutton,SLOT(close()));

    }
}


void Alarm::ShowAlarmtime(){

    qDebug()<<stime;

    if(stime !=""&&shownum==0){
        QFont mFont("Consolas", 20, QFont::Bold);
        showtime->setFont(mFont);
        cancle->setFont(mFont);
        QString css = QString("color : white");
        showtime->setStyleSheet(css);

        showtime->resize(300,50);
        showtime ->move (300,0);
        showtime->setText("알람시간 : "+stime);
        cancle->resize(120,50);
        cancle->move(600,0);
        cancle->setText("알람취소");

        showtime->show();
        cancle->show();
        shownum=1;
    }else if(stime==""){
        showtime->close();
        cancle->close();
        shownum=0;
    }
    connect(cancle,SIGNAL(clicked()),SLOT(DeleteAlarm()));
}

void Alarm::DeleteAlarm(){
    stime = "";
    alarmnum=0;
}

