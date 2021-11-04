#ifndef ALARM_H
#define ALARM_H

#include <QLabel>
#include <QWidget>
#include <QTimeEdit>
#include <QPushButton>
#include <QTimer>
#include <QVBoxLayout>

class Alarm : public QWidget {
    Q_OBJECT

public:
    explicit Alarm(QWidget* parent = Q_NULLPTR);
    QString stime;


signals:
    void clicked();


private:
    QTimeEdit *alarmtime;
    QPushButton *submit;
    QTime time;

    QTimer * timer;
    QPushButton *alarmbutton;
    int alarmnum=0, shownum=0;
    QLabel *showtime = new QLabel(parentWidget());
    QPushButton *cancle = new QPushButton(parentWidget());


public slots:
    void SetTime();
    void Alarmcheck();

    void ShowAlarmtime();
    void DeleteAlarm();

};

#endif // ALARM_H
