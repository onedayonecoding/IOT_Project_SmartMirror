/********************************************************************************
** Form generated from reading UI file 'ui.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UI_H
#define UI_UI_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UI
{
public:
    QLabel *WLabel;
    QLabel *WeatherLabel;
    QPushButton *pushButton_3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *MirrorButton1;
    QPushButton *SettingButton;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QLabel *ULtemperature;
    QLabel *AirLabel;
    QPushButton *AirButton;
    QLabel *Fan;
    QPushButton *FanButton;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *SchButton;
    QLabel *SchLabel;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *TimeLayout;

    void setupUi(QWidget *UI)
    {
        if (UI->objectName().isEmpty())
            UI->setObjectName(QString::fromUtf8("UI"));
        UI->resize(1024, 600);
        UI->setCursor(QCursor(Qt::ArrowCursor));
        WLabel = new QLabel(UI);
        WLabel->setObjectName(QString::fromUtf8("WLabel"));
        WLabel->setGeometry(QRect(30, 380, 181, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("HY\355\227\244\353\223\234\353\235\274\354\235\270M")});
        font.setPointSize(20);
        WLabel->setFont(font);
        WeatherLabel = new QLabel(UI);
        WeatherLabel->setObjectName(QString::fromUtf8("WeatherLabel"));
        WeatherLabel->setGeometry(QRect(30, 440, 181, 51));
        WeatherLabel->setFont(font);
        pushButton_3 = new QPushButton(UI);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(390, 380, 171, 71));
        pushButton_3->setFont(font);
        layoutWidget = new QWidget(UI);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 510, 308, 81));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        MirrorButton1 = new QPushButton(layoutWidget);
        MirrorButton1->setObjectName(QString::fromUtf8("MirrorButton1"));
        MirrorButton1->setMaximumSize(QSize(300, 150));
        MirrorButton1->setFont(font);

        horizontalLayout->addWidget(MirrorButton1);

        SettingButton = new QPushButton(layoutWidget);
        SettingButton->setObjectName(QString::fromUtf8("SettingButton"));
        SettingButton->setMaximumSize(QSize(100, 150));
        SettingButton->setFont(font);
        SettingButton->setText(QString::fromUtf8(""));
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/setting.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/images/setting.png"), QSize(), QIcon::Normal, QIcon::On);
        SettingButton->setIcon(icon);
        SettingButton->setIconSize(QSize(60, 60));
        SettingButton->setCheckable(false);

        horizontalLayout->addWidget(SettingButton);

        layoutWidget1 = new QWidget(UI);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 240, 279, 93));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        ULtemperature = new QLabel(layoutWidget1);
        ULtemperature->setObjectName(QString::fromUtf8("ULtemperature"));
        ULtemperature->setFont(font);

        gridLayout->addWidget(ULtemperature, 0, 0, 2, 1);

        AirLabel = new QLabel(layoutWidget1);
        AirLabel->setObjectName(QString::fromUtf8("AirLabel"));
        AirLabel->setFont(font);

        gridLayout->addWidget(AirLabel, 0, 1, 1, 1);

        AirButton = new QPushButton(layoutWidget1);
        AirButton->setObjectName(QString::fromUtf8("AirButton"));
        AirButton->setFont(font);

        gridLayout->addWidget(AirButton, 0, 2, 1, 1);

        Fan = new QLabel(layoutWidget1);
        Fan->setObjectName(QString::fromUtf8("Fan"));
        Fan->setFont(font);

        gridLayout->addWidget(Fan, 1, 1, 1, 1);

        FanButton = new QPushButton(layoutWidget1);
        FanButton->setObjectName(QString::fromUtf8("FanButton"));
        FanButton->setFont(font);

        gridLayout->addWidget(FanButton, 1, 2, 1, 1);

        layoutWidget2 = new QWidget(UI);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(760, 390, 231, 151));
        verticalLayout_2 = new QVBoxLayout(layoutWidget2);
        verticalLayout_2->setSpacing(15);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(5, 5, 5, 5);
        SchButton = new QPushButton(layoutWidget2);
        SchButton->setObjectName(QString::fromUtf8("SchButton"));
        SchButton->setFont(font);

        verticalLayout_2->addWidget(SchButton);

        SchLabel = new QLabel(layoutWidget2);
        SchLabel->setObjectName(QString::fromUtf8("SchLabel"));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("HY\355\227\244\353\223\234\353\235\274\354\235\270M")});
        font1.setPointSize(12);
        SchLabel->setFont(font1);
        SchLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout_2->addWidget(SchLabel);

        layoutWidget3 = new QWidget(UI);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(760, 240, 181, 109));
        verticalLayout_3 = new QVBoxLayout(layoutWidget3);
        verticalLayout_3->setSpacing(15);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(5, 5, 5, 5);
        pushButton_4 = new QPushButton(layoutWidget3);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setFont(font);

        verticalLayout_3->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(layoutWidget3);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setFont(font);

        verticalLayout_3->addWidget(pushButton_5);

        verticalLayoutWidget = new QWidget(UI);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(360, 490, 241, 80));
        TimeLayout = new QVBoxLayout(verticalLayoutWidget);
        TimeLayout->setObjectName(QString::fromUtf8("TimeLayout"));
        TimeLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(UI);

        QMetaObject::connectSlotsByName(UI);
    } // setupUi

    void retranslateUi(QWidget *UI)
    {
        UI->setWindowTitle(QCoreApplication::translate("UI", "UI", nullptr));
        WLabel->setText(QCoreApplication::translate("UI", "\354\230\244\353\212\230\354\235\230 \353\202\240\354\224\250", nullptr));
        WeatherLabel->setText(QCoreApplication::translate("UI", "\353\202\240\354\224\250 \352\267\270\353\246\274", nullptr));
        pushButton_3->setText(QCoreApplication::translate("UI", "\354\235\214\354\204\261\354\235\270\354\213\235", nullptr));
        MirrorButton1->setText(QCoreApplication::translate("UI", "\352\261\260\354\232\270\353\252\250\353\223\234", nullptr));
        ULtemperature->setText(QCoreApplication::translate("UI", "\354\230\250\353\217\204", nullptr));
        AirLabel->setText(QCoreApplication::translate("UI", "\354\227\220\354\226\264\354\273\250", nullptr));
        AirButton->setText(QCoreApplication::translate("UI", "On", nullptr));
        Fan->setText(QCoreApplication::translate("UI", "\354\204\240\355\222\215\352\270\260", nullptr));
        FanButton->setText(QCoreApplication::translate("UI", "Off", nullptr));
        SchButton->setText(QCoreApplication::translate("UI", "\354\235\274\354\240\225", nullptr));
        SchLabel->setText(QCoreApplication::translate("UI", "\354\235\274\354\240\225 \353\202\264\354\232\251", nullptr));
        pushButton_4->setText(QCoreApplication::translate("UI", "\352\270\260\353\212\2451 \353\262\204\355\212\274", nullptr));
        pushButton_5->setText(QCoreApplication::translate("UI", "\352\270\260\353\212\2452 \353\262\204\355\212\274", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UI: public Ui_UI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UI_H
