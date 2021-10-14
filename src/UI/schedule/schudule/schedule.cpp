#include "schedule.h"
#include "ui_schedule.h"
#include <QLabel>

Schedule::Schedule(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Schedule)
{
    ui->setupUi(this);
    connect(ui->calendarWidget,SIGNAL(clicked(QDate)),SLOT(SetSch(QDate)));
    //clicked에서 QDate를 SetSch에 전달
}

Schedule::~Schedule()
{
    delete ui;
}

void Schedule::SetSch(QDate date){
    QLabel *s = new QLabel();
    QString a = date.toString();
    s->setText(a);
    s->show();
}
