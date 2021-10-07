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
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButton_3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *MirrorButton1;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QLabel *ULtemperature;
    QLabel *label_2;
    QPushButton *AirButton;
    QLabel *label_3;
    QPushButton *FanButton;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_6;
    QLabel *label_7;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout;
    QLabel *TimeLabel;
    QLabel *DateLabel;

    void setupUi(QWidget *UI)
    {
        if (UI->objectName().isEmpty())
            UI->setObjectName(QString::fromUtf8("UI"));
        UI->resize(1024, 600);
        UI->setCursor(QCursor(Qt::ArrowCursor));
        label_4 = new QLabel(UI);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 380, 181, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("HY\355\227\244\353\223\234\353\235\274\354\235\270M")});
        font.setPointSize(20);
        label_4->setFont(font);
        label_5 = new QLabel(UI);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 440, 181, 51));
        label_5->setFont(font);
        pushButton_3 = new QPushButton(UI);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(390, 380, 171, 71));
        pushButton_3->setFont(font);
        layoutWidget = new QWidget(UI);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 530, 308, 44));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        MirrorButton1 = new QPushButton(layoutWidget);
        MirrorButton1->setObjectName(QString::fromUtf8("MirrorButton1"));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("HY\355\227\244\353\223\234\353\235\274\354\235\270M")});
        font1.setPointSize(12);
        MirrorButton1->setFont(font1);

        horizontalLayout->addWidget(MirrorButton1);

        pushButton_8 = new QPushButton(layoutWidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setFont(font1);

        horizontalLayout->addWidget(pushButton_8);

        pushButton_9 = new QPushButton(layoutWidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setFont(font1);

        horizontalLayout->addWidget(pushButton_9);

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

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        AirButton = new QPushButton(layoutWidget1);
        AirButton->setObjectName(QString::fromUtf8("AirButton"));
        AirButton->setFont(font);

        gridLayout->addWidget(AirButton, 0, 2, 1, 1);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 1, 1, 1, 1);

        FanButton = new QPushButton(layoutWidget1);
        FanButton->setObjectName(QString::fromUtf8("FanButton"));
        FanButton->setFont(font);

        gridLayout->addWidget(FanButton, 1, 2, 1, 1);

        layoutWidget2 = new QWidget(UI);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(760, 490, 231, 78));
        verticalLayout_2 = new QVBoxLayout(layoutWidget2);
        verticalLayout_2->setSpacing(15);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(5, 5, 5, 5);
        label_6 = new QLabel(layoutWidget2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        verticalLayout_2->addWidget(label_6);

        label_7 = new QLabel(layoutWidget2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font1);
        label_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout_2->addWidget(label_7);

        layoutWidget3 = new QWidget(UI);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(760, 320, 181, 109));
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

        layoutWidget4 = new QWidget(UI);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(390, 490, 201, 83));
        verticalLayout = new QVBoxLayout(layoutWidget4);
        verticalLayout->setSpacing(21);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        TimeLabel = new QLabel(layoutWidget4);
        TimeLabel->setObjectName(QString::fromUtf8("TimeLabel"));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("HY\355\227\244\353\223\234\353\235\274\354\235\270M")});
        font2.setPointSize(22);
        TimeLabel->setFont(font2);
        TimeLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(TimeLabel);

        DateLabel = new QLabel(layoutWidget4);
        DateLabel->setObjectName(QString::fromUtf8("DateLabel"));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("HY\355\227\244\353\223\234\353\235\274\354\235\270M")});
        font3.setPointSize(14);
        DateLabel->setFont(font3);
        DateLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(DateLabel);


        retranslateUi(UI);

        QMetaObject::connectSlotsByName(UI);
    } // setupUi

    void retranslateUi(QWidget *UI)
    {
        UI->setWindowTitle(QCoreApplication::translate("UI", "UI", nullptr));
        label_4->setText(QCoreApplication::translate("UI", "\354\230\244\353\212\230\354\235\230 \353\202\240\354\224\250", nullptr));
        label_5->setText(QCoreApplication::translate("UI", "\353\202\240\354\224\250 \352\267\270\353\246\274", nullptr));
        pushButton_3->setText(QCoreApplication::translate("UI", "\354\235\214\354\204\261\354\235\270\354\213\235", nullptr));
        MirrorButton1->setText(QCoreApplication::translate("UI", "\352\261\260\354\232\270\353\252\250\353\223\234", nullptr));
        pushButton_8->setText(QCoreApplication::translate("UI", "auto", nullptr));
        pushButton_9->setText(QCoreApplication::translate("UI", "\354\204\244\354\240\225", nullptr));
        ULtemperature->setText(QCoreApplication::translate("UI", "\354\230\250\353\217\204", nullptr));
        label_2->setText(QCoreApplication::translate("UI", "\354\227\220\354\226\264\354\273\250", nullptr));
        AirButton->setText(QCoreApplication::translate("UI", "On", nullptr));
        label_3->setText(QCoreApplication::translate("UI", "\354\204\240\355\222\215\352\270\260", nullptr));
        FanButton->setText(QCoreApplication::translate("UI", "Off", nullptr));
        label_6->setText(QCoreApplication::translate("UI", "\354\235\274\354\240\225", nullptr));
        label_7->setText(QCoreApplication::translate("UI", "\354\235\274\354\240\225 \353\202\264\354\232\251", nullptr));
        pushButton_4->setText(QCoreApplication::translate("UI", "\352\270\260\353\212\2451 \353\262\204\355\212\274", nullptr));
        pushButton_5->setText(QCoreApplication::translate("UI", "\352\270\260\353\212\2452 \353\262\204\355\212\274", nullptr));
        TimeLabel->setText(QCoreApplication::translate("UI", "\354\213\234\352\260\204", nullptr));
        DateLabel->setText(QCoreApplication::translate("UI", "\353\202\240\354\247\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UI: public Ui_UI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UI_H
