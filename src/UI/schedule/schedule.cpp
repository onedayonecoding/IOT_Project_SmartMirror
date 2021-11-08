#include "../../header/schedule.h"
#include "ui_schedule.h"
#include "../../header/ui.h"

#include <QFile>
#include <QPushButton>
#include <QTextStream>

using namespace std;

Schedule::Schedule(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Schedule)
{
    ui->setupUi(this);

    this->setWindowFlag(Qt::FramelessWindowHint);
    QString css = QString("color : white");
    ui->pushButton->setStyleSheet(css);
    setStyleSheet("background:gray");

    connect(ui->pushButton,SIGNAL(clicked()),SLOT(cancle()));

}

Schedule::~Schedule()
{
    delete ui;
    //if(openui) delete openui;
}


void Schedule::on_calendarWidget_clicked(const QDate &date)
{
    QString a = date.toString();
    QString text = QString(a+"\n 일정을 쓰세요!!");    // 일정이 없을시 초기값

    QString sdate=date.toString();
    QFile h("schedule/"+sdate+".txt");

    if(h.open(QFile::ReadOnly | QFile::Text)){  //파일이 있으면 기존일정 대로
        text=h.readAll();
    }
    h.close();

    QPushButton *ok = new QPushButton(sch);
    sch->setPlainText(text);
    sch->resize(224,600);
    sch->move(800,0);
    ok->setText("완 료");
    ok->move(0,400);
    ok->resize(224,200);

    sch->setWindowFlag(Qt::FramelessWindowHint);
    sch->show();

    QString css = QString("font : 20px; font : hy헤드라인m");
    ok->setStyleSheet(css);

    connect(ok,SIGNAL(clicked()),sch,SLOT(close()));
    connect(ok,SIGNAL(clicked()),this,SLOT(close()));
    connect(ok,SIGNAL(clicked()),SLOT(MakeFile()));
}

void Schedule::MakeFile(){
    openui=new UI;

    QDate date = ui->calendarWidget->selectedDate();
    QString sdate=date.toString();
    QFile::remove("schedule/"+sdate+".txt"); //기존 일정 내용 지우기 위해서
    QFile makefile("schedule/"+sdate+".txt");

    makefile.open(QFile::WriteOnly|QFile::Append|QFile::Text);
    QTextStream SaveFile(&makefile);
    QString schtext = sch->toPlainText();
    SaveFile<<schtext;
    makefile.close();


    openui->show();

}
void Schedule::cancle(){
    this->close();
    openui=new UI;
    openui->show();
}

