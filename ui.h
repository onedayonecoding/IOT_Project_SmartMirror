#ifndef UI_H
#define UI_H

#include <QWidget>

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

private:
    Ui::UI *ui;


};
#endif // UI_H
