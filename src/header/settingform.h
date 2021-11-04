#ifndef SETTINGFORM_H
#define SETTINGFORM_H
#include "ui.h"
#include "ClickableLabel.h"

#include <QWidget>



class UI;

namespace Ui {
class SettingForm;
}

class SettingForm : public QWidget
{
    Q_OBJECT

public:
    explicit SettingForm(QWidget *parent = nullptr);
    ~SettingForm();
    Ui::SettingForm *ui;

private:
    UI *openui;
    ClickableLabel *MirrorButton2 = new ClickableLabel();

public slots:
    void settingclose();
    void detect();
    void autoair();

};

#endif // SETTINGFORM_H
