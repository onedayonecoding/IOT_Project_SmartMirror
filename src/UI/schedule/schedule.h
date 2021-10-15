#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <QWidget>
#include <QTextEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class Schedule;
             }
QT_END_NAMESPACE

class Schedule : public QWidget
{
    Q_OBJECT

public:
    explicit Schedule(QWidget *parent = nullptr);
    ~Schedule();
    Ui::Schedule *ui;
    QTextEdit *sch=new QTextEdit();

public slots:
   void MakeFile();

private slots:
   void on_calendarWidget_clicked(const QDate &date);
};
#endif // SCHEDULE_H
