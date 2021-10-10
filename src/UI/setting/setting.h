#ifndef SETTING_H
#define SETTING_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class setting; }
QT_END_NAMESPACE

class setting : public QWidget
{
    Q_OBJECT

public:
    setting(QWidget *parent = nullptr);
    ~setting();

private:
    Ui::setting *ui;
};
#endif // SETTING_H
