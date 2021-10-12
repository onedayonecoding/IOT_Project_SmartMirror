#ifndef SETTING_H
#define SETTING_H

#include <QWidget>
namespace Ui { class Setting; }

class Setting : public QWidget
{
    Q_OBJECT
public:
    explicit Setting(QWidget *parent = nullptr);

signals:
private:
    Ui::Setting *ui;

public slots:
    void setting();

};

#endif // SETTING_H
