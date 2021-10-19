#ifndef SETTINGFORM_H
#define SETTINGFORM_H

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

public slots:
    void settingclose();

};

#endif // SETTINGFORM_H
