#include "../inc/ui.h"
#include "ui_ui.h"
#include "DateTimeWidget/DateTimeWidget.h"
#include "settingform/settingform.h"
#include "schedule/schedule.h"

#include <QFile>
#include <QPushButton>
#include <QProcess>
//#include <QTextCodec>  QT5 가능

using namespace std;


UI::UI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UI)
{
    ui->setupUi(this);
    settingForm = new SettingForm;
    scheDule = new Schedule;

    // 글씨 흰색으로 변환
    QString css = QString("color : #fffff1");
    ui->MirrorButton1->setStyleSheet(css);
    ui->AirButton->setStyleSheet(css);
    ui->FanButton->setStyleSheet(css);
    ui->ULtemperature->setStyleSheet(css);
    ui->AirLabel->setStyleSheet(css);
    ui->Fan->setStyleSheet(css);
    ui->SchButton->setStyleSheet(css);
    ui->SchLabel->setStyleSheet(css);
    ui->WLabel->setStyleSheet(css);
    ui->WeatherLabel->setStyleSheet(css);

    //시간 날짜 표시
    DateTimeWidget * datetimeWidget = new DateTimeWidget(this);
    ui->TimeLayout->addWidget(datetimeWidget);

    // UI 온도표시
    QString T="0";
    vector<QString> temp;

    QFile t("../../lib/temperature.txt");             // 온도 파일 열기

    if(!t.open(QFile::ReadOnly | QFile::Text)){
        qDebug("could not open temperature");
        exit(1);
    }else{                                              // 두번째 단어가 온도일시
        QTextStream in(&t);
        QString word=in.readLine();
        qDebug()<<word;
        QStringList temp = word.split(" ");
        T = temp[1];
    }
    t.close();                                        //온도 파일 닫기
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

    //일정 버튼
    connect(ui->SchButton,SIGNAL(clicked()),SLOT(Sch()));

    //일정 표시
    QString sdate = QDate::currentDate().toString();
    qDebug()<<sdate;
    QFile sch("../"+sdate+".txt");

    if(!sch.open(QFile::ReadOnly | QFile::Text)){
        qDebug("could not open schdule");
        ui->SchLabel->setText("일정없음");
    }
    else{
        QString contents = sch.readAll();
        ui->SchLabel->setText(contents);
    }
    sch.close();

    //날씨 프로세스 실행
    QProcess::execute("weather.exe");

    //날씨 표시
    QFile w("weather.txt");

    if(!w.open(QFile::ReadOnly | QFile::Text)){
        qDebug("could not open wheather");
        exit(1);
    }
    else{
        QTextStream weathertext(&w);
        QString weather=weathertext.readLine();
        /*QTextCodec *codec = QTextCodec::codecForLocale();    QT 5 가능
        QString strUnicodeLine = codec->toUnicode( weather.toLocal8Bit() );*/

        ui->WeatherLabel->setText(weather);
    }
    w.close();

}

UI::~UI()
{
    delete ui;
    if(settingForm) delete settingForm;
    if(scheDule) delete scheDule;
}

void UI::MirrorMode(){       //거울모드 메소드
    this->close();
    MirrorButton2->move(0,0);
    MirrorButton2->resize(1024,600);
    MirrorButton2->setStyleSheet("background:black");
    MirrorButton2->show();
    //모니터 전원 끄기
}

void UI::MirrorModeClose(){
    MirrorButton2->close();
    this->show();
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
    this->close();
    settingForm->show();
    settingForm->move(0,0);
}

void UI::Sch(){
    scheDule->show();
    scheDule->move(0,0);
    this->close();
}




