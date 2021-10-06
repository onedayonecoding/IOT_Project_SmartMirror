#include "ui.h"
#include "ui_ui.h"

double T=20.11; //현재온도 센서 위치 정해지면 바꾸어야함

UI::UI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UI)
{
    ui->setupUi(this);

    // UI 온도표시 시작
    QString str=QString("%1℃").arg(T); //
    ui->ULtemperature->setText(str);
    connect(ui->ULtemperature,SIGNAL(linkActivated(QString)),SLOT(UI_temp()));
    // UI 온도표시 끝

    connect(ui->MirrorButton1,SIGNAL(clicked()),SLOT(Mirror));

}

UI::~UI()
{
    delete ui;
}

void UI::MirrorMode(){
    QPushButton *MirrorButton2 = new QPushButton();
    MirrorButton2->show();
}

