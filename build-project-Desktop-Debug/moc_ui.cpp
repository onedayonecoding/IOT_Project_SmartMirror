/****************************************************************************
** Meta object code from reading C++ file 'ui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/inc/ui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UI_t {
    QByteArrayData data[13];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UI_t qt_meta_stringdata_UI = {
    {
QT_MOC_LITERAL(0, 0, 2), // "UI"
QT_MOC_LITERAL(1, 3, 10), // "MirrorMode"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 8), // "AirOnOff"
QT_MOC_LITERAL(4, 24, 8), // "FanOnOff"
QT_MOC_LITERAL(5, 33, 7), // "Setting"
QT_MOC_LITERAL(6, 41, 3), // "Sch"
QT_MOC_LITERAL(7, 45, 3), // "Web"
QT_MOC_LITERAL(8, 49, 10), // "TempUpdate"
QT_MOC_LITERAL(9, 60, 10), // "HumiUpdate"
QT_MOC_LITERAL(10, 71, 5), // "Voice"
QT_MOC_LITERAL(11, 77, 11), // "VoiceUpdate"
QT_MOC_LITERAL(12, 89, 12) // "VoiceCommand"

    },
    "UI\0MirrorMode\0\0AirOnOff\0FanOnOff\0"
    "Setting\0Sch\0Web\0TempUpdate\0HumiUpdate\0"
    "Voice\0VoiceUpdate\0VoiceCommand"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x0a /* Public */,
       3,    0,   70,    2, 0x0a /* Public */,
       4,    0,   71,    2, 0x0a /* Public */,
       5,    0,   72,    2, 0x0a /* Public */,
       6,    0,   73,    2, 0x0a /* Public */,
       7,    0,   74,    2, 0x0a /* Public */,
       8,    0,   75,    2, 0x0a /* Public */,
       9,    0,   76,    2, 0x0a /* Public */,
      10,    0,   77,    2, 0x0a /* Public */,
      11,    0,   78,    2, 0x0a /* Public */,
      12,    0,   79,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void UI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UI *_t = static_cast<UI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->MirrorMode(); break;
        case 1: _t->AirOnOff(); break;
        case 2: _t->FanOnOff(); break;
        case 3: _t->Setting(); break;
        case 4: _t->Sch(); break;
        case 5: _t->Web(); break;
        case 6: _t->TempUpdate(); break;
        case 7: _t->HumiUpdate(); break;
        case 8: _t->Voice(); break;
        case 9: _t->VoiceUpdate(); break;
        case 10: _t->VoiceCommand(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject UI::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_UI.data,
      qt_meta_data_UI,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *UI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UI.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int UI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
