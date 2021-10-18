#include "schedule.h"
#include "ui_schedule.h"

#include <QFile>
#include <QPushButton>

using namespace std;

Schedule::Schedule(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Schedule)
{
    ui->setupUi(this);
    QString css = QString("color : white");
    ui->pushButton->setStyleSheet(css);
    setStyleSheet("background:gray");

    connect(ui->pushButton,SIGNAL(clicked()),SLOT(close()));
}

Schedule::~Schedule()
{
    delete ui;
}


void Schedule::on_calendarWidget_clicked(const QDate &date)
{
    QString a = date.toString();
    QString text = QString(a+"\n 일정을 쓰세요!!");

    QPushButton *ok = new QPushButton(sch);
    sch->setPlainText(text);
    sch->resize(224,600);
    sch->move(800,0);
    ok->setText("완 료");
    ok->move(0,400);
    ok->resize(224,200);
    sch->show();

    QString css = QString("font : 20px; font : hy헤드라인m");
    ok->setStyleSheet(css);


    connect(ok,SIGNAL(clicked()),SLOT(MakeFile()));
    connect(ok,SIGNAL(clicked()),sch,SLOT(close()));
}

void Schedule::MakeFile(){

    QDate date = ui->calendarWidget->selectedDate();
    QString sdate=date.toString();

    QFile makefile("../"+sdate+".txt");
    makefile.open(QFile::WriteOnly|QFile::Append|QFile::Text);
    QTextStream SaveFile(&makefile);
    QString schtext = sch->toPlainText();
    SaveFile<<schtext;
    makefile.close();
}
