/********************************************************************************
** Form generated from reading UI file 'settingform.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGFORM_H
#define UI_SETTINGFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingForm
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label1;
    QScrollBar *onoff1;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *Off;
    QLabel *On;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label2;
    QScrollBar *onoff2;
    QPushButton *quitbutton;

    void setupUi(QWidget *SettingForm)
    {
        if (SettingForm->objectName().isEmpty())
            SettingForm->setObjectName(QString::fromUtf8("SettingForm"));
        SettingForm->resize(1024, 600);
        layoutWidget = new QWidget(SettingForm);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(90, 190, 511, 61));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label1 = new QLabel(layoutWidget);
        label1->setObjectName(QString::fromUtf8("label1"));
        label1->setMaximumSize(QSize(150, 50));
        QFont font;
        font.setFamilies({QString::fromUtf8("HY\355\227\244\353\223\234\353\235\274\354\235\270M")});
        font.setPointSize(20);
        label1->setFont(font);

        horizontalLayout->addWidget(label1);

        onoff1 = new QScrollBar(layoutWidget);
        onoff1->setObjectName(QString::fromUtf8("onoff1"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
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

        layoutWidget_2 = new QWidget(SettingForm);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(270, 147, 321, 35));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        Off = new QLabel(layoutWidget_2);
        Off->setObjectName(QString::fromUtf8("Off"));
        Off->setMaximumSize(QSize(150, 50));
        Off->setFont(font);
        Off->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(Off);

        On = new QLabel(layoutWidget_2);
        On->setObjectName(QString::fromUtf8("On"));
        On->setMaximumSize(QSize(150, 50));
        On->setFont(font);
        On->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(On);

        layoutWidget_3 = new QWidget(SettingForm);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(90, 260, 511, 61));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label2 = new QLabel(layoutWidget_3);
        label2->setObjectName(QString::fromUtf8("label2"));
        label2->setMaximumSize(QSize(150, 50));
        label2->setFont(font);

        horizontalLayout_2->addWidget(label2);

        onoff2 = new QScrollBar(layoutWidget_3);
        onoff2->setObjectName(QString::fromUtf8("onoff2"));
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

        quitbutton = new QPushButton(SettingForm);
        quitbutton->setObjectName(QString::fromUtf8("quitbutton"));
        quitbutton->setGeometry(QRect(820, 490, 131, 71));
        quitbutton->setFont(font);

        retranslateUi(SettingForm);

        QMetaObject::connectSlotsByName(SettingForm);
    } // setupUi

    void retranslateUi(QWidget *SettingForm)
    {
        SettingForm->setWindowTitle(QCoreApplication::translate("SettingForm", "Form", nullptr));
        label1->setText(QCoreApplication::translate("SettingForm", "\352\270\260\353\212\2451", nullptr));
        Off->setText(QCoreApplication::translate("SettingForm", "Off", nullptr));
        On->setText(QCoreApplication::translate("SettingForm", "On", nullptr));
        label2->setText(QCoreApplication::translate("SettingForm", "\352\270\260\353\212\2452", nullptr));
        quitbutton->setText(QCoreApplication::translate("SettingForm", "Quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingForm: public Ui_SettingForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGFORM_H
