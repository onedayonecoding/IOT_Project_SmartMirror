#include "ui.h"
#include "ui_ui.h"

double T=20.11; //현재온도

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


}

UI::~UI()
{
    delete ui;
}

void UI::MirrorMode(){

}

