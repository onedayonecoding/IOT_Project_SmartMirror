#ifndef UI_H
#define UI_H

#include <QWidget>
#include <QPushButton>  //추후 메모리 문제로 고민 필요

class SettingForm;

QT_BEGIN_NAMESPACE
namespace Ui { class UI; }
QT_END_NAMESPACE

class UI : public QWidget
{
    Q_OBJECT

public:
    UI(QWidget *parent = nullptr);
    ~UI();


public slots:
    void MirrorMode();
    void MirrorModeClose();
    void AirOnOff();
    void FanOnOff();
    void Setting();
    void SettingClose();

private:
    Ui::UI *ui;
    QPushButton *MirrorButton2=new QPushButton(0);   //거울모드 버튼
    SettingForm* settingForm;
};
#endif // UI_H
