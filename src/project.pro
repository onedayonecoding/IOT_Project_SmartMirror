QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    UI/ui.cpp\
    UI/DateTimeWidget/DateTimeWidget.cpp\
    UI/schedule/schedule.cpp\
    UI/settingform/settingform.cpp \
    UI/clickablelabel/clickablelabel.cpp \
    UI/alarm/alarm.cpp

HEADERS += \
    header/ui.h\
    header/DateTimeWidget.h\
    header/schedule.h\
    header/settingform.h \
    header/ClickableLabel.h \
    header/alarm.h

FORMS += \
    UI/ui.ui\
    UI/settingform/settingform.ui\
    UI/schedule/schedule.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=\
    UI/images.qrc
