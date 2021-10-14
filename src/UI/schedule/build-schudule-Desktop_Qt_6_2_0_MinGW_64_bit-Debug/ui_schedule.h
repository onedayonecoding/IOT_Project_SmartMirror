/********************************************************************************
** Form generated from reading UI file 'schedule.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCHEDULE_H
#define UI_SCHEDULE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Schedule
{
public:
    QCalendarWidget *calendarWidget;

    void setupUi(QWidget *Schedule)
    {
        if (Schedule->objectName().isEmpty())
            Schedule->setObjectName(QString::fromUtf8("Schedule"));
        Schedule->resize(1500, 800);
        calendarWidget = new QCalendarWidget(Schedule);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setGeometry(QRect(0, 0, 1024, 600));
        QFont font;
        font.setPointSize(15);
        calendarWidget->setFont(font);
        calendarWidget->setSelectionMode(QCalendarWidget::SingleSelection);
        calendarWidget->setHorizontalHeaderFormat(QCalendarWidget::ShortDayNames);
        calendarWidget->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
        calendarWidget->setNavigationBarVisible(true);
        calendarWidget->setDateEditEnabled(true);

        retranslateUi(Schedule);

        QMetaObject::connectSlotsByName(Schedule);
    } // setupUi

    void retranslateUi(QWidget *Schedule)
    {
        Schedule->setWindowTitle(QCoreApplication::translate("Schedule", "Schedule", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Schedule: public Ui_Schedule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCHEDULE_H
