/********************************************************************************
** Form generated from reading UI file 'setting.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTING_H
#define UI_SETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_setting
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label2;
    QScrollBar *onoff2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label1;
    QScrollBar *onoff1;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *Off;
    QLabel *On;

    void setupUi(QWidget *setting)
    {
        if (setting->objectName().isEmpty())
            setting->setObjectName(QString::fromUtf8("setting"));
        setting->resize(800, 600);
        layoutWidget = new QWidget(setting);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(80, 240, 511, 61));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label2 = new QLabel(layoutWidget);
        label2->setObjectName(QString::fromUtf8("label2"));
        label2->setMaximumSize(QSize(150, 50));
        QFont font;
        font.setFamilies({QString::fromUtf8("HY\355\227\244\353\223\234\353\235\274\354\235\270M")});
        font.setPointSize(20);
        label2->setFont(font);

        horizontalLayout_2->addWidget(label2);

        onoff2 = new QScrollBar(layoutWidget);
        onoff2->setObjectName(QString::fromUtf8("onoff2"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(onoff2->sizePolicy().hasHeightForWidth());
        onoff2->setSizePolicy(sizePolicy);
        onoff2->setMaximumSize(QSize(500, 100));
        onoff2->setContextMenuPolicy(Qt::NoContextMenu);
        onoff2->setLayoutDirection(Qt::LeftToRight);
        onoff2->setMaximum(1);
        onoff2->setPageStep(1);
        onoff2->setTracking(true);
        onoff2->setOrientation(Qt::Horizontal);
        onoff2->setInvertedControls(true);

        horizontalLayout_2->addWidget(onoff2);

        widget = new QWidget(setting);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(80, 170, 511, 61));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label1 = new QLabel(widget);
        label1->setObjectName(QString::fromUtf8("label1"));
        label1->setMaximumSize(QSize(150, 50));
        label1->setFont(font);

        horizontalLayout->addWidget(label1);

        onoff1 = new QScrollBar(widget);
        onoff1->setObjectName(QString::fromUtf8("onoff1"));
        sizePolicy.setHeightForWidth(onoff1->sizePolicy().hasHeightForWidth());
        onoff1->setSizePolicy(sizePolicy);
        onoff1->setMaximumSize(QSize(500, 100));
        onoff1->setContextMenuPolicy(Qt::NoContextMenu);
        onoff1->setLayoutDirection(Qt::LeftToRight);
        onoff1->setMaximum(1);
        onoff1->setPageStep(1);
        onoff1->setTracking(true);
        onoff1->setOrientation(Qt::Horizontal);
        onoff1->setInvertedControls(true);

        horizontalLayout->addWidget(onoff1);

        widget1 = new QWidget(setting);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(260, 127, 321, 29));
        horizontalLayout_3 = new QHBoxLayout(widget1);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        Off = new QLabel(widget1);
        Off->setObjectName(QString::fromUtf8("Off"));
        Off->setMaximumSize(QSize(150, 50));
        Off->setFont(font);
        Off->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(Off);

        On = new QLabel(widget1);
        On->setObjectName(QString::fromUtf8("On"));
        On->setMaximumSize(QSize(150, 50));
        On->setFont(font);
        On->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(On);


        retranslateUi(setting);

        QMetaObject::connectSlotsByName(setting);
    } // setupUi

    void retranslateUi(QWidget *setting)
    {
        setting->setWindowTitle(QCoreApplication::translate("setting", "setting", nullptr));
        label2->setText(QCoreApplication::translate("setting", "\352\270\260\353\212\2452", nullptr));
        label1->setText(QCoreApplication::translate("setting", "\352\270\260\353\212\2451", nullptr));
        Off->setText(QCoreApplication::translate("setting", "Off", nullptr));
        On->setText(QCoreApplication::translate("setting", "On", nullptr));
    } // retranslateUi

};

namespace Ui {
    class setting: public Ui_setting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTING_H
