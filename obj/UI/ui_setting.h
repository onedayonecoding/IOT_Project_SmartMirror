/********************************************************************************
** Form generated from reading UI file 'setting.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
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
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label1;
    QScrollBar *onoff1;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *Off;
    QLabel *On;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label1_2;
    QScrollBar *onoff1_2;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *Off_2;
    QLabel *On_2;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label2_2;
    QScrollBar *onoff2_2;

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

        layoutWidget1 = new QWidget(setting);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(80, 170, 511, 61));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label1 = new QLabel(layoutWidget1);
        label1->setObjectName(QString::fromUtf8("label1"));
        label1->setMaximumSize(QSize(150, 50));
        label1->setFont(font);

        horizontalLayout->addWidget(label1);

        onoff1 = new QScrollBar(layoutWidget1);
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

        layoutWidget2 = new QWidget(setting);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(260, 127, 321, 35));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        Off = new QLabel(layoutWidget2);
        Off->setObjectName(QString::fromUtf8("Off"));
        Off->setMaximumSize(QSize(150, 50));
        Off->setFont(font);
        Off->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(Off);

        On = new QLabel(layoutWidget2);
        On->setObjectName(QString::fromUtf8("On"));
        On->setMaximumSize(QSize(150, 50));
        On->setFont(font);
        On->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(On);

        layoutWidget_2 = new QWidget(setting);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(670, 463, 511, 61));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label1_2 = new QLabel(layoutWidget_2);
        label1_2->setObjectName(QString::fromUtf8("label1_2"));
        label1_2->setMaximumSize(QSize(150, 50));
        label1_2->setFont(font);

        horizontalLayout_4->addWidget(label1_2);

        onoff1_2 = new QScrollBar(layoutWidget_2);
        onoff1_2->setObjectName(QString::fromUtf8("onoff1_2"));
        sizePolicy.setHeightForWidth(onoff1_2->sizePolicy().hasHeightForWidth());
        onoff1_2->setSizePolicy(sizePolicy);
        onoff1_2->setMaximumSize(QSize(500, 100));
        onoff1_2->setContextMenuPolicy(Qt::NoContextMenu);
        onoff1_2->setLayoutDirection(Qt::LeftToRight);
        onoff1_2->setMaximum(1);
        onoff1_2->setPageStep(1);
        onoff1_2->setTracking(true);
        onoff1_2->setOrientation(Qt::Horizontal);
        onoff1_2->setInvertedControls(true);

        horizontalLayout_4->addWidget(onoff1_2);

        layoutWidget_3 = new QWidget(setting);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(850, 420, 321, 35));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        Off_2 = new QLabel(layoutWidget_3);
        Off_2->setObjectName(QString::fromUtf8("Off_2"));
        Off_2->setMaximumSize(QSize(150, 50));
        Off_2->setFont(font);
        Off_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(Off_2);

        On_2 = new QLabel(layoutWidget_3);
        On_2->setObjectName(QString::fromUtf8("On_2"));
        On_2->setMaximumSize(QSize(150, 50));
        On_2->setFont(font);
        On_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(On_2);

        layoutWidget_4 = new QWidget(setting);
        layoutWidget_4->setObjectName(QString::fromUtf8("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(670, 533, 511, 61));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label2_2 = new QLabel(layoutWidget_4);
        label2_2->setObjectName(QString::fromUtf8("label2_2"));
        label2_2->setMaximumSize(QSize(150, 50));
        label2_2->setFont(font);

        horizontalLayout_6->addWidget(label2_2);

        onoff2_2 = new QScrollBar(layoutWidget_4);
        onoff2_2->setObjectName(QString::fromUtf8("onoff2_2"));
        sizePolicy.setHeightForWidth(onoff2_2->sizePolicy().hasHeightForWidth());
        onoff2_2->setSizePolicy(sizePolicy);
        onoff2_2->setMaximumSize(QSize(500, 100));
        onoff2_2->setContextMenuPolicy(Qt::NoContextMenu);
        onoff2_2->setLayoutDirection(Qt::LeftToRight);
        onoff2_2->setMaximum(1);
        onoff2_2->setPageStep(1);
        onoff2_2->setTracking(true);
        onoff2_2->setOrientation(Qt::Horizontal);
        onoff2_2->setInvertedControls(true);

        horizontalLayout_6->addWidget(onoff2_2);


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
        label1_2->setText(QCoreApplication::translate("setting", "\352\270\260\353\212\2451", nullptr));
        Off_2->setText(QCoreApplication::translate("setting", "Off", nullptr));
        On_2->setText(QCoreApplication::translate("setting", "On", nullptr));
        label2_2->setText(QCoreApplication::translate("setting", "\352\270\260\353\212\2452", nullptr));
    } // retranslateUi

};

namespace Ui {
    class setting: public Ui_setting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTING_H
