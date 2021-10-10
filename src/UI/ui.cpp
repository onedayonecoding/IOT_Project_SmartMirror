#include "../inc/ui.h"
#include "ui_ui.h"
#include "DateTimeWidget.h"
#include "setting.h"


double T=20.11; //현재온도 센서 위치 정해지면 바꾸어야함

UI::UI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UI)
{
    ui->setupUi(this);
    QString css = QString("color : #fffff1");
    ui->MirrorButton1->setStyleSheet(css);
    ui->AirButton->setStyleSheet(css);
    ui->FanButton->setStyleSheet(css);
    ui->ULtemperature->setStyleSheet(css);
    ui->AirLabel->setStyleSheet(css);
    ui->Fan->setStyleSheet(css);

    //시간 날짜 표시
    DateTimeWidget * datetimeWidget = new DateTimeWidget(this);
    ui->TimeLayout->addWidget(datetimeWidget);

    // UI 온도표시
    QString tem=QString("%1℃").arg(T); //
    ui->ULtemperature->setText(tem);

    // 거울 모드
    connect(ui->MirrorButton1,SIGNAL(clicked()),SLOT(MirrorMode()));
    connect(MirrorButton2,SIGNAL(clicked()),SLOT(MirrorModeClose()));

    // 선풍기, 에어컨 온오프
    connect(ui->AirButton,SIGNAL(clicked()),SLOT(AirOnOff()));
    connect(ui->FanButton,SIGNAL(clicked()),SLOT(FanOnOff()));

    //설정 버튼
    connect(ui->SettingButton,SIGNAL(clicked()),SLOT(setting()));

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

void UI::setting(){

}


