#ifndef UI_H
#define UI_H

#include <QWidget>
#include <QPushButton>  //추후 메모리 문제로 고민 필요
#include <QProcess>
#include <QTextBrowser>


#define SIGINT          2
#define SIGKILL         9
#define SIGSEGV         11
#define SIGTERM         15
#define SIGTSTP         20

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
    //void ExecuteProgram();


public slots:
    void MirrorMode();
    void MirrorModeClose();
    void AirOnOff();
    void FanOnOff();
    void Setting();
    void Sch();


private:
    Ui::UI *ui;
    QPushButton *MirrorButton2=new QPushButton(0);   //거울모드 버튼
    SettingForm* settingForm;
    Schedule* scheDule;
    QProcess *process;
    //QTextBrowser *textBrowser;


};
#endif // UI_H
