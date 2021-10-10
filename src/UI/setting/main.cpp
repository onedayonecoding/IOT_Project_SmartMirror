
#include "ui_setting.h"
#include <QApplication>
#include <QWidget>

QWidget::setting(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::setting)
{
    ui->setupUi(this);
    QString css = QString("color : white");
    ui->label1->setStyleSheet(css);
    ui->label2->setStyleSheet(css);
    ui->On->setStyleSheet(css);
    ui->Off->setStyleSheet(css);
    ui->onoff1->setStyleSheet("background : blue ; color : white");
    ui->onoff2->setStyleSheet("background : blue ; color : white");
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    setting w;
    w.setStyleSheet("background : black");
    w.show();
    return a.exec();
}
