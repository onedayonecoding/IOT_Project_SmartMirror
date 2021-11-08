#include "../header/ui.h"
#include "ui_ui.h"
#include "../header/DateTimeWidget.h"
#include "../header/settingform.h"
#include "../header/schedule.h"
#include "../header/ClickableLabel.h"



#include <QFile>
#include <QPushButton>
#include <QProcess>
#include <QTextStream>
#include <QTextCodec> // QT5 가능
#include <QDebug>
#include <string.h>
#include <QString>


using namespace std;


UI::UI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UI)
{
    ui->setupUi(this);
    settingForm = new SettingForm;
    scheDule = new Schedule;

    this->move(0,0);
    this->setStyleSheet("background:Black");
    this->setWindowFlag(Qt::FramelessWindowHint);

    // 글씨 흰색으로 변환
    QString css = QString("color : #fffff1");
    ui->ULtemperature->setStyleSheet(css);
    ui->ULhumidity->setStyleSheet(css);
    ui->AirLabel->setStyleSheet(css);
    ui->Fan->setStyleSheet(css);
    ui->SchLabel->setStyleSheet(css);
    ui->WLabel->setStyleSheet(css);
    ui->WLabel_T->setStyleSheet(css);

    //buttoncolor
     //css = QString("background-color : #000000; color:#fffff1");
     //ui->MindButton->setStyleSheet(css);
     //ui->MirrorButton1->setStyleSheet(css);
     //ui->FanButton->setStyleSheet(css);
     //ui->AirButton->setStyleSheet(css);
     //ui->SchButton->setStyleSheet(css);

    //시간 날짜 표시
    DateTimeWidget * datetimeWidget = new DateTimeWidget(this);
    ui->TimeLayout->addWidget(datetimeWidget);

    //알람 버튼
    alarm = new Alarm(this);
    alarm->move(800,100);
    alarm->close();
    connect(ui->AlarmButton,SIGNAL(clicked()),SLOT(SetAlarm()));

    // UI 온도표시
    QTimer *t = new QTimer();
    t->setInterval(2000);
    connect(t,&QTimer::timeout,this,&UI::TempUpdate);
    connect(t,&QTimer::timeout,this,&UI::HumiUpdate);
    connect(t,&QTimer::timeout,this,&UI::VoiceCommand);
    t->start(); //타이머 시작

    // 거울 모드
    connect(ui->MirrorButton1,SIGNAL(clicked()),SLOT(MirrorMode()));
    connect(MirrorButton2,SIGNAL(clicked()),MirrorButton2,SLOT(close()));
    connect(MirrorButton2,SIGNAL(clicked()),SLOT(show()));

    // 선풍기, 에어컨 온오프
    connect(ui->AirButton,SIGNAL(clicked()),SLOT(AirOnOff()));
    connect(ui->FanButton,SIGNAL(clicked()),SLOT(FanOnOff()));

    //설정 버튼
    connect(ui->SettingButton,SIGNAL(clicked()),SLOT(Setting()));

    //일정 버튼
    connect(ui->SchButton,SIGNAL(clicked()),SLOT(Sch()));

    //일정 표시
    QString sdate = QDate::currentDate().toString();
    //qDebug()<<sdate;
    QFile sch("schedule/"+sdate+".txt");

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

    Weathershow();
    QTimer* weathertime = new QTimer();
    weathertime->setInterval(3000000);
    connect(weathertime,&QTimer::timeout,this,&UI::WeatherProcess);
    connect(weathertime,&QTimer::timeout,this,&UI::Weathershow);
    weathertime->start(); // 30분 뒤 타이머 시작


    //감정인식 웹사이트 실행
    connect(ui->MindButton,SIGNAL(clicked()),SLOT(Web()));

    //음성인식
    connect(ui->VoiceButton,SIGNAL(clicked()),SLOT(Voice()));
    connect(ui->QuitButton,SIGNAL(clicked()),SLOT(close()));
}

//생성자
UI::~UI()
{
    delete ui;
    if(settingForm) delete settingForm;
    if(scheDule) delete scheDule;
}


//기능 메소드 작성 시작

void UI::SetAlarm(){
    if(alarmnum==0){
        alarm->show();
        alarmnum=1;
        qDebug("alarmon");
    }else{
        alarm->close();
        qDebug("alarmoff");
        alarmnum=0;
    }
}

void UI::MirrorMode(){       //거울모드 메소드
    this->close();
    MirrorButton2->move(0,0);
    MirrorButton2->resize(1024,600);
    MirrorButton2->setWindowFlag(Qt::FramelessWindowHint);
    MirrorButton2->setStyleSheet("background-color:black");
    MirrorButton2->show();
    //모니터 전원 끄기
}

void UI::AirOnOff(){
    QFile f("senser/Air.txt");
    QTextStream SaveFile(&f);
    if(!f.open(QFile::WriteOnly | QFile::Text)){
        qDebug("could not open Airfile");
        exit(1);
    }else{
        if(ui->AirButton->text()=="On"){
            ui->AirButton->setText("Off");
            SaveFile<<"on";
            qDebug("on");
        }else{
            ui->AirButton->setText("On");
            SaveFile<<"off";
            qDebug("off");
        }
    }
}

void UI::FanOnOff(){
    QFile f("senser/Motor.txt");
    QTextStream SaveFile(&f);
    if(!f.open(QFile::WriteOnly | QFile::Text)){
        qDebug("could not open Fanfile");
        exit(1);
    }else{
        if(ui->FanButton->text()=="On"){
            ui->FanButton->setText("Off");
            SaveFile<<"on";
            qDebug("on");
        }else{
            ui->FanButton->setText("On");
            SaveFile<<"off";
            qDebug("off");
        }
    }

}

void UI::Setting(){
    this->close();
    settingForm->show();
    settingForm->move(0,0);
}

void UI::Sch(){
    scheDule->move(0,0);
    scheDule->show();

    this->close();
}

void UI::Web(){
    QProcess::execute("minddetect/url.sh");
}


void UI::TempUpdate(){
    QString T="0";
    vector<QString> temp;

    QFile t("senser/Temperature.txt");             // 온도 파일 열기

    if(!t.open(QFile::ReadOnly | QFile::Text)){
        qDebug("could not open temperature");
        exit(1);
    }else{                                              // 3번째 단어가 온도일시
        QTextStream in(&t);
        QString word=in.readLine();

        QStringList temp = word.split(" ");
        T = temp[2];
    }
    t.close();                                        //온도 파일 닫기
    QString tem=QString("실내온도 : %1").arg(T); //
    ui->ULtemperature->setText(tem);
}

void UI::HumiUpdate(){
    QString T="0";
    vector<QString> temp;
    QFile h("senser/Humidity.txt");            //  파일 열기

    if(!h.open(QFile::ReadOnly | QFile::Text)){
        qDebug("could not open temperature");
        exit(1);
    }else{                                              // 3번째 단어가 온도일시
        QTextStream in(&h);
        QString word=in.readLine();
        //qDebug()<<word;
        QStringList temp = word.split(" ");
        T = temp[2];
    }
    h.close();                                        //온도 파일 닫기
    QString hum=QString("실내습도 : %1").arg(T); //식
    ui->ULhumidity->setText(hum);

}

//음성인식 타이머
void UI::Voice(){

    if(ui->VoiceButton->text()=="음성인식"){
        //QProcess::execute("voice/mic.sh");
        QProcess *process =new QProcess;
        process->setWorkingDirectory("voice");
        process->start("./mic.sh");
        process->waitForStarted();

        ui->VoiceButton->setText("음성인식 종료");
        Vmessage = new QLabel(this);
        Vmessage->show();
        Vmessage->resize(450,100);
        Vmessage->move(300,100);
        Vmessage->setAlignment(Qt::AlignHCenter);
        Vmessage->setAlignment(Qt::AlignVCenter);
        VT->setInterval(1000);
        connect(VT,&QTimer::timeout,this,&UI::VoiceUpdate);

        VT->start(); //타이머 시작
    }else{
        ui->VoiceButton->setText("음성인식");
        VT->stop();  //종료
        Vmessage->close();
        QFile *f = new QFile("voice/output.txt");
        if(!f->open(QFile::WriteOnly | QFile::Text)){
            qDebug("cannot find voicefile");

        }
        QTextStream SaveFile(f);
        QString schtext = "3초 뒤에 말하세요";
        SaveFile<<schtext;
    }

}

void UI::VoiceUpdate(){
    QFile *f = new QFile("voice/output.txt");
    if(!f->open(QFile::ReadOnly | QFile::Text)){
        qDebug("cannot find voicefile");

    }else{

        QString message =f->readLine();

        QString css = QString("font : 40px; font : hy헤드라인m; color : #fffff1");
        Vmessage->setStyleSheet(css);
        Vmessage->setText(message);

    }
}
void textclear(){
    QFile *a = new QFile("voice/output.txt");
    if(!a->open(QFile::WriteOnly | QFile::Text)){
        qDebug("cannot find voicefile");
    }
    QTextStream SaveFile(a);
    QString schtext = "";
    SaveFile<<schtext;
    a->close();
}
void UI::VoiceCommand(){
    QFile *f = new QFile("voice/output.txt");
    if(QString::compare(ui->VoiceButton->text(),"음성인식 종료")==0){

        if(!f->open(QFile::ReadOnly | QFile::Text)){
            qDebug("cannot find voicefile");

        }else{
            QString message =f->readLine();
            if(message.contains("거울")){
                MirrorMode();
                textclear();
            }else if(message.contains("취소")){
                MirrorButton2->close();
                scheDule->close();
                settingForm->close();
                this->show();
                textclear();
            }else if(message.contains("선풍기")){
                FanOnOff();
                textclear();
            }else if(message.contains("에어컨")){
                AirOnOff();
                textclear();
            }else if(message.contains("일정")){
                Sch();
                textclear();
            }
            else if(message.contains("감정")){
                Web();
                textclear();
            }
        }
    }
}

void UI::WeatherProcess(){
    QProcess *process =new QProcess;
    process->setWorkingDirectory("weather/dist");
    process->start("./weather");
}

void UI::Weathershow(){
    qDebug("weather show");
    //날씨 표시
    QFile w("weather/dist/weather.txt");

    if(!w.open(QFile::ReadOnly | QFile::Text)){
        qDebug("could not open wheather");
       exit(1);
    }
    else{
        QTextStream weathertext(&w);
        QString weather=weathertext.readAll();
        QStringList temp = weather.split("\n");
        QString w = temp[0];
        QString t = temp[1];
        QTextCodec *codec = QTextCodec::codecForLocale();   // QT 5  txt utf-8 encoding
        QString strUnicodeLine = codec->toUnicode( w.toLocal8Bit() );

        w_img[0].load(":/images/cloud.png");
        w_img[1].load(":/images/rain.png");
        w_img[2].load(":/images/snow.png");
        w_img[3].load(":/images/sun.png");
        w_img[4].load(":/images/cloudy.png");
        ui->WLabel->setText(w);
        ui->WLabel_T->setText(t);
        if(w=="현재날씨 : 흐림"){
            qDebug("흐림ｔ（");
            int w = 75;  //ui->Wimage->width();
            int h = 75;  //ui->Wimage->height();
            ui->Wimage->setPixmap(w_img[0].scaled(w,h,Qt::KeepAspectRatio));
        }else if(w=="현재날씨 : 비"||w=="현재날씨 : 약한비"||w=="현재날씨 : 강한비"){
            qDebug("비");
            int w = 75;  //ui->Wimage->width();
            int h = 75;  //ui->Wimage->height();
            ui->Wimage->setPixmap(w_img[1].scaled(w,h,Qt::KeepAspectRatio));
        }else if(w=="현재날씨 : 눈"||w=="현재날씨 : 약한눈"||w=="현재날씨 : 강한눈"||w=="현재날씨 : 진눈깨비"||w=="현재날씨 : 소낙눈"){
            qDebug("눈");
            int w = 75;  //ui->Wimage->width();
            int h = 75;  //ui->Wimage->height();
            ui->Wimage->setPixmap(w_img[2].scaled(w,h,Qt::KeepAspectRatio));
        }else if(w=="현재날씨 : 맑음"||w=="현재날씨 : 구름조금"){
            qDebug("맑음");
            int w = 75;  //ui->Wimage->width();
            int h = 75;  //ui->Wimage->height();
            ui->Wimage->setPixmap(w_img[3].scaled(w,h,Qt::KeepAspectRatio));
        }else if(w=="현재날씨 : 구름많음"){
            qDebug("구름많음");
            int w = 75;  //ui->Wimage->width();
            int h = 75;  //ui->Wimage->height();
            ui->Wimage->setPixmap(w_img[4].scaled(w,h,Qt::KeepAspectRatio));
        }
    }
    w.close();
}

void UI::Google(){
   QProcess::execute("");
}
