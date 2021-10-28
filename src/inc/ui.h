#ifndef UI_H
#define UI_H

#include"../inc/ClickableLabel.h"

#include <QWidget>
#include <QLabel>  //추후 메모리 문제로 고민 필요
#include <QProcess>
#include <QTextBrowser>
#include <QTimer>


class SettingForm;
class Schedule;


QT_BEGIN_NAMESPACE
namespace Ui { class UI; }
QT_END_NAMESPACE

class UI : public QWidget
{
    Q_OBJECT

public:
    UI(QWidget *parent = nullptr);
    ~UI();

    Ui::UI *ui;
    QTimer *VT = new QTimer();
    QLabel *Vmessage = new QLabel();


public slots:
    void MirrorMode();
    void AirOnOff();
    void FanOnOff();
    void Setting();
    void Sch();
    void Web();
    void TempUpdate();
    void HumiUpdate();
    void Voice();
    void VoiceUpdate();
    void VoiceCommand();


private:
    ClickableLabel *MirrorButton2=new ClickableLabel();   //거울모드 버튼
    SettingForm* settingForm;
    Schedule* scheDule;
    QProcess *process;

};
#endif // UI_H
