#include "../inc/ui.h"
#include "ui_ui.h"



double T=20.11; //현재온도 센서 위치 정해지면 바꾸어야함




UI::UI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UI)
{
    ui->setupUi(this);

    //시간 날짜 표시
    QString dayofweek;

    switch(t->tm_wday){
    case 0:
        dayofweek="Sun";
        break;
    case 1:
        dayofweek="Mon";
        break;
    case 2:
        dayofweek="Tue";
        break;
    case 3:
        dayofweek="Wen";
        break;
    case 4:
        dayofweek="Thu";
        break;
    case 6:
        dayofweek="Fri";
        break;
    default:
        dayofweek="Sat";
    }
    QString Date = QString("%1-%2-%3 %4").arg(t->tm_year-100,2,10,QLatin1Char('0'))
                                         .arg(t->tm_mon+1,2,10,QLatin1Char('0'))
                                         .arg(t->tm_mday,2,10,QLatin1Char('0'))
                                         .arg(dayofweek);
    int hour=(t->tm_hour)%12;
    QString noon;
    if((t->tm_hour)%12>0){
        noon="PM";
    }else noon="AM";


    QString Time = QString("%1:%2 %3").arg(hour,2,10,QLatin1Char('0'))
                                   .arg(t->tm_min,2,10,QLatin1Char('0'))
                                   .arg(noon);
    ui->DateLabel->setText(Date);
    ui->TimeLabel->setText(Time);


    // UI 온도표시
    QString tem=QString("%1℃").arg(T); //
    ui->ULtemperature->setText(tem);

    // 거울 모드
    connect(ui->MirrorButton1,SIGNAL(clicked()),SLOT(MirrorMode()));
    connect(MirrorButton2,SIGNAL(clicked()),SLOT(MirrorModeClose()));

    // 선풍기, 에어컨 온오프
    connect(ui->AirButton,SIGNAL(clicked()),SLOT(AirOnOff()));
    connect(ui->FanButton,SIGNAL(clicked()),SLOT(FanOnOff()));

}

UI::~UI()
{
    delete ui;
}

void UI::MirrorMode(){       //거울모드 메소드
    MirrorButton2->move(0,0);
    MirrorButton2->resize(1024,600);
    MirrorButton2->setStyleSheet("background:black");
    MirrorButton2->show();
    //모니터 전원 끄기
}

void UI::MirrorModeClose(){
    MirrorButton2->close();
    //모니터 전원 켜기
}

void UI::AirOnOff(){
    if(ui->AirButton->text()=="On"){
        ui->AirButton->setText("Off");
        //에어컨 off 기능 추가요망
    }else{
        ui->AirButton->setText("On");
        // 에어컨 on 기능 추가요망
    }
}

void UI::FanOnOff(){
    if(ui->FanButton->text()=="On"){
        ui->FanButton->setText("Off");
        //에어컨 off 기능 추가요망
    }else{
        ui->FanButton->setText("On");
        // 에어컨 on 기능 추가요망
    }
}
