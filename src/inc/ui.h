#ifndef UI_H
#define UI_H

#include <QWidget>
#include <QPushButton>

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
    void setting();

private:
    Ui::UI *ui;
    QPushButton *MirrorButton2 = new QPushButton(0);


};
#endif // UI_H
