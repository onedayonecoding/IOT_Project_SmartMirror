/********************************************************************************
** Form generated from reading UI file 'ui.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
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
    QPushButton *VoiceButton;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *MirrorButton1;
    QPushButton *SettingButton;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QLabel *Fan;
    QPushButton *FanButton;
    QLabel *AirLabel;
    QPushButton *AirButton;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *SchButton;
    QLabel *SchLabel;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *MindButton;
    QPushButton *pushButton_5;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *TimeLayout;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout;
    QLabel *ULtemperature;
    QLabel *ULhumidity;
    QPushButton *QuitButton;

    void setupUi(QWidget *UI)
    {
        if (UI->objectName().isEmpty())
            UI->setObjectName(QStringLiteral("UI"));
        UI->resize(1024, 600);
        UI->setCursor(QCursor(Qt::ArrowCursor));
        UI->setFocusPolicy(Qt::StrongFocus);
        WLabel = new QLabel(UI);
        WLabel->setObjectName(QStringLiteral("WLabel"));
        WLabel->setGeometry(QRect(30, 380, 181, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("HY\355\227\244\353\223\234\353\235\274\354\235\270M"));
        font.setPointSize(20);
        WLabel->setFont(font);
        WLabel->setStyleSheet(QStringLiteral(""));
        WeatherLabel = new QLabel(UI);
        WeatherLabel->setObjectName(QStringLiteral("WeatherLabel"));
        WeatherLabel->setGeometry(QRect(30, 440, 181, 51));
        WeatherLabel->setFont(font);
        VoiceButton = new QPushButton(UI);
        VoiceButton->setObjectName(QStringLiteral("VoiceButton"));
        VoiceButton->setGeometry(QRect(410, 380, 171, 71));
        VoiceButton->setFont(font);
        VoiceButton->setStyleSheet(QStringLiteral(""));
        layoutWidget = new QWidget(UI);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 510, 308, 81));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        MirrorButton1 = new QPushButton(layoutWidget);
        MirrorButton1->setObjectName(QStringLiteral("MirrorButton1"));
        MirrorButton1->setMaximumSize(QSize(300, 150));
        MirrorButton1->setFont(font);
        MirrorButton1->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(MirrorButton1);

        SettingButton = new QPushButton(layoutWidget);
        SettingButton->setObjectName(QStringLiteral("SettingButton"));
        SettingButton->setMaximumSize(QSize(100, 150));
        SettingButton->setFont(font);
        SettingButton->setText(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QStringLiteral("images/setting.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QStringLiteral(":/images/setting.png"), QSize(), QIcon::Normal, QIcon::On);
        SettingButton->setIcon(icon);
        SettingButton->setIconSize(QSize(60, 60));
        SettingButton->setCheckable(false);

        horizontalLayout->addWidget(SettingButton);

        layoutWidget1 = new QWidget(UI);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 240, 231, 131));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        Fan = new QLabel(layoutWidget1);
        Fan->setObjectName(QStringLiteral("Fan"));
        Fan->setFont(font);

        gridLayout->addWidget(Fan, 1, 0, 1, 1);

        FanButton = new QPushButton(layoutWidget1);
        FanButton->setObjectName(QStringLiteral("FanButton"));
        FanButton->setFont(font);
        FanButton->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(FanButton, 1, 1, 1, 1);

        AirLabel = new QLabel(layoutWidget1);
        AirLabel->setObjectName(QStringLiteral("AirLabel"));
        AirLabel->setFont(font);

        gridLayout->addWidget(AirLabel, 0, 0, 1, 1);

        AirButton = new QPushButton(layoutWidget1);
        AirButton->setObjectName(QStringLiteral("AirButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AirButton->sizePolicy().hasHeightForWidth());
        AirButton->setSizePolicy(sizePolicy);
        AirButton->setFont(font);
        AirButton->setFocusPolicy(Qt::NoFocus);
        AirButton->setAutoFillBackground(false);
        AirButton->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(AirButton, 0, 1, 1, 1);

        layoutWidget2 = new QWidget(UI);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(760, 390, 231, 151));
        verticalLayout_2 = new QVBoxLayout(layoutWidget2);
        verticalLayout_2->setSpacing(15);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(5, 5, 5, 5);
        SchButton = new QPushButton(layoutWidget2);
        SchButton->setObjectName(QStringLiteral("SchButton"));
        SchButton->setFont(font);

        verticalLayout_2->addWidget(SchButton);

        SchLabel = new QLabel(layoutWidget2);
        SchLabel->setObjectName(QStringLiteral("SchLabel"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("HY\355\227\244\353\223\234\353\235\274\354\235\270M"));
        font1.setPointSize(12);
        SchLabel->setFont(font1);
        SchLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout_2->addWidget(SchLabel);

        layoutWidget3 = new QWidget(UI);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(760, 240, 228, 109));
        verticalLayout_3 = new QVBoxLayout(layoutWidget3);
        verticalLayout_3->setSpacing(15);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(5, 5, 5, 5);
        MindButton = new QPushButton(layoutWidget3);
        MindButton->setObjectName(QStringLiteral("MindButton"));
        MindButton->setFont(font);

        verticalLayout_3->addWidget(MindButton);

        pushButton_5 = new QPushButton(layoutWidget3);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setFont(font);
        pushButton_5->setAutoFillBackground(true);
        pushButton_5->setStyleSheet(QStringLiteral(""));

        verticalLayout_3->addWidget(pushButton_5);

        verticalLayoutWidget = new QWidget(UI);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(370, 510, 281, 80));
        TimeLayout = new QVBoxLayout(verticalLayoutWidget);
        TimeLayout->setObjectName(QStringLiteral("TimeLayout"));
        TimeLayout->setContentsMargins(0, 0, 0, 0);
        layoutWidget4 = new QWidget(UI);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(20, 150, 261, 75));
        verticalLayout = new QVBoxLayout(layoutWidget4);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        ULtemperature = new QLabel(layoutWidget4);
        ULtemperature->setObjectName(QStringLiteral("ULtemperature"));
        ULtemperature->setFont(font);

        verticalLayout->addWidget(ULtemperature);

        ULhumidity = new QLabel(layoutWidget4);
        ULhumidity->setObjectName(QStringLiteral("ULhumidity"));
        ULhumidity->setFont(font);

        verticalLayout->addWidget(ULhumidity);

        QuitButton = new QPushButton(UI);
        QuitButton->setObjectName(QStringLiteral("QuitButton"));
        QuitButton->setGeometry(QRect(20, 60, 171, 71));
        QuitButton->setFont(font);
        QuitButton->setStyleSheet(QStringLiteral(""));

        retranslateUi(UI);

        QMetaObject::connectSlotsByName(UI);
    } // setupUi

    void retranslateUi(QWidget *UI)
    {
        UI->setWindowTitle(QApplication::translate("UI", "UI", nullptr));
        WLabel->setText(QApplication::translate("UI", "\354\230\244\353\212\230\354\235\230 \353\202\240\354\224\250", nullptr));
        WeatherLabel->setText(QApplication::translate("UI", "\353\202\240\354\224\250 \352\267\270\353\246\274", nullptr));
        VoiceButton->setText(QApplication::translate("UI", "\354\235\214\354\204\261\354\235\270\354\213\235", nullptr));
        MirrorButton1->setText(QApplication::translate("UI", "\352\261\260\354\232\270\353\252\250\353\223\234", nullptr));
        Fan->setText(QApplication::translate("UI", "\354\204\240\355\222\215\352\270\260", nullptr));
        FanButton->setText(QApplication::translate("UI", "On", nullptr));
        AirLabel->setText(QApplication::translate("UI", "\354\227\220\354\226\264\354\273\250", nullptr));
        AirButton->setText(QApplication::translate("UI", "On", nullptr));
        SchButton->setText(QApplication::translate("UI", "\354\235\274\354\240\225", nullptr));
        SchLabel->setText(QApplication::translate("UI", "\354\235\274\354\240\225 \353\202\264\354\232\251", nullptr));
        MindButton->setText(QApplication::translate("UI", "\352\260\220\354\240\225\354\235\270\354\213\235", nullptr));
        pushButton_5->setText(QApplication::translate("UI", "\352\270\260\353\212\2452 \353\262\204\355\212\274", nullptr));
        ULtemperature->setText(QApplication::translate("UI", "\354\230\250\353\217\204", nullptr));
        ULhumidity->setText(QApplication::translate("UI", "humi", nullptr));
        QuitButton->setText(QApplication::translate("UI", "Quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UI: public Ui_UI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UI_H
