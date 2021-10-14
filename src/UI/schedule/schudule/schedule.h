#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Schedule; }
QT_END_NAMESPACE

class Schedule : public QWidget
{
    Q_OBJECT

public:
    Schedule(QWidget *parent = nullptr);
    ~Schedule();

private:
    Ui::Schedule *ui;

public slots:
   void SetSch(QDate date);
};
#endif // SCHEDULE_H
