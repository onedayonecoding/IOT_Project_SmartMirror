

#include "../inc/ui.h"
#include "ui_ui.h"
#include "DateTimeWidget/DateTimeWidget.h"
#include "settingform/settingform.h"
#include "ui_settingform.h"


#include <fstream>
#include <vector>
#include <QPushButton>

using namespace std;



UI::UI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UI)
{

    ui->setupUi(this);
    settingForm = new SettingForm;
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
    double T=0;
    vector<string> temp;
    string word;
    ifstream ifs;
    ifs.open("../../lib/temperature.txt");               // 온도 파일 열기

    if(!ifs.is_open()){
        qDebug("could not open temperature");
        exit(1);
    }else{                                              // 두번째 단어가 온도일시
        int i=0;
        while(ifs>>word){
         temp.push_back(word);
         i++;
         if(i==2)break;
        }
        T=stod(temp[1]);
    }
    ifs.close();                                        //온도 파일 닫기
    QString tem=QString("%1℃").arg(T); //
    ui->ULtemperature->setText(tem);

    // 거울 모드
    connect(ui->MirrorButton1,SIGNAL(clicked()),SLOT(MirrorMode()));
    connect(MirrorButton2,SIGNAL(clicked()),SLOT(MirrorModeClose()));

    // 선풍기, 에어컨 온오프
    connect(ui->AirButton,SIGNAL(clicked()),SLOT(AirOnOff()));
    connect(ui->FanButton,SIGNAL(clicked()),SLOT(FanOnOff()));

    //설정 버튼
    connect(ui->SettingButton,SIGNAL(clicked()),SLOT(Setting()));
    connect(settingForm->ui->quitbutton,SIGNAL(clicked()),SLOT(SettingClose()));
}

UI::~UI()
{
    delete ui;
    if(settingForm) delete settingForm;
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

void UI::Setting(){
    settingForm->show();
    settingForm->move(0,0);
    settingForm->setStyleSheet("background:black");
}
void UI::SettingClose(){
    settingForm->close();
}
