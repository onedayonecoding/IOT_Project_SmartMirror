#include "../inc/ui.h"
#include "ui_ui.h"
#include "../inc/DateTimeWidget.h"
#include "../inc/settingform.h"
#include "../inc/schedule.h"
#include "../inc/ClickableLabel.h"

#include <QFile>
#include <QPushButton>
#include <QProcess>
#include <QTextStream>
#include <QTextCodec> // QT5 가능
#include <QTextBrowser>
#include <QUrl>
#include <QDebug>


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
    ui->WeatherLabel->setStyleSheet(css);



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
    QProcess::execute("../weather/weather");

    //날씨 표시
    QFile w("../weather/weather.txt");

    if(!w.open(QFile::ReadOnly | QFile::Text)){
        qDebug("could not open wheather");
       exit(1);
    }
    else{
        QTextStream weathertext(&w);
        QString weather=weathertext.readLine();
        QTextCodec *codec = QTextCodec::codecForLocale();   // QT 5  txt utf-8 encoding
        QString strUnicodeLine = codec->toUnicode( weather.toLocal8Bit() );

        ui->WeatherLabel->setText(weather);
    }
    w.close();

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
        QProcess::execute("../../lib/motor/motor_on");
        qDebug("on");
    }else{
        ui->FanButton->setText("On");
        QProcess::execute("../../lib/motor/motor_off");
        qDebug("off");
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
    QProcess::execute("../../lib/url.sh");
}


void UI::TempUpdate(){
    QString T="0";
    vector<QString> temp;

    QFile t("../../lib/Temperature/Temperature.txt");             // 온도 파일 열기

    if(!t.open(QFile::ReadOnly | QFile::Text)){
        qDebug("could not open temperature");
        exit(1);
    }else{                                              // 3번째 단어가 온도일시
        QTextStream in(&t);
        QString word=in.readLine();
        //qDebug()<<word;
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
    QFile h("../../lib/Temperature/Humidity.txt");            //  파일 열기

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
        ui->VoiceButton->setText("음성인식 종료");
        Vmessage = new QLabel(this);
        Vmessage->show();
        Vmessage->resize(300,200);
        Vmessage->move(300,100);
        VT->setInterval(1000);
        connect(VT,&QTimer::timeout,this,&UI::VoiceUpdate);

        VT->start(); //타이머 시작
    }else{
        ui->VoiceButton->setText("음성인식");
        VT->stop();  //종료
        Vmessage->close();
    }

}

void UI::VoiceUpdate(){
    QFile *f = new QFile("../message.txt");
    if(!f->open(QFile::ReadOnly | QFile::Text)){
        qDebug("cannot find voicefile");

    }else{
        QString message =f->readLine();

        QString css = QString("font : 100px; font : hy헤드라인m; color : #fffff1");
        Vmessage->setStyleSheet(css);
        Vmessage->setText(message);

    }
}

void UI::VoiceCommand(){
    QFile *f = new QFile("../message.txt");
    if(QString::compare(ui->VoiceButton->text(),"음성인식 종료")==0){

        if(!f->open(QFile::ReadOnly | QFile::Text)){
            qDebug("cannot find voicefile");

        }else{

            QString message =f->readLine();

            if(QString::compare(message,"거울모드")==0){
                MirrorMode();

            }else if(QString::compare(message,"cancle")==0){
                MirrorButton2->close();
                scheDule->close();
                settingForm->close();
                this->show();
            }else if(QString::compare(message,"fan on")==0||QString::compare(message,"fan off")==0){
                FanOnOff();
            }else if(QString::compare(message,"air on")==0||QString::compare(message,"air off")==0){
                AirOnOff();
            }else if(QString::compare(message,"일정")==0){
                Sch();
            }
            /*else if(QString::compare(message,"감정인식")==0){
                Web();
            }*/

        }
    }
}
