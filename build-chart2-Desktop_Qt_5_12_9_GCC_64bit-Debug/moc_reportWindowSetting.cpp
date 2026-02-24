/****************************************************************************
** Meta object code from reading C++ file 'reportWindowSetting.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Documents/report_window/reportWindowSetting.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'reportWindowSetting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ReportWindowSetting_t {
    QByteArrayData data[17];
    char stringdata0[276];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ReportWindowSetting_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ReportWindowSetting_t qt_meta_stringdata_ReportWindowSetting = {
    {
QT_MOC_LITERAL(0, 0, 19), // "ReportWindowSetting"
QT_MOC_LITERAL(1, 20, 16), // "on_pdfCsvClicked"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 18), // "QMap<QString,bool>"
QT_MOC_LITERAL(4, 57, 23), // "exportGrpCheckboxStates"
QT_MOC_LITERAL(5, 81, 15), // "on_graphChanged"
QT_MOC_LITERAL(6, 97, 11), // "std::string"
QT_MOC_LITERAL(7, 109, 10), // "buttonName"
QT_MOC_LITERAL(8, 120, 24), // "on_currentSessionChecked"
QT_MOC_LITERAL(9, 145, 19), // "on_dateRangeChecked"
QT_MOC_LITERAL(10, 165, 9), // "startDate"
QT_MOC_LITERAL(11, 175, 7), // "endDate"
QT_MOC_LITERAL(12, 183, 9), // "sessionId"
QT_MOC_LITERAL(13, 193, 17), // "on_csvPdfBtnClick"
QT_MOC_LITERAL(14, 211, 13), // "on_dateUpdate"
QT_MOC_LITERAL(15, 225, 18), // "on_dateRangeUpdate"
QT_MOC_LITERAL(16, 244, 31) // "on_sessionIdComboBoxTextChanged"

    },
    "ReportWindowSetting\0on_pdfCsvClicked\0"
    "\0QMap<QString,bool>\0exportGrpCheckboxStates\0"
    "on_graphChanged\0std::string\0buttonName\0"
    "on_currentSessionChecked\0on_dateRangeChecked\0"
    "startDate\0endDate\0sessionId\0"
    "on_csvPdfBtnClick\0on_dateUpdate\0"
    "on_dateRangeUpdate\0on_sessionIdComboBoxTextChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ReportWindowSetting[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       5,    1,   57,    2, 0x06 /* Public */,
       8,    0,   60,    2, 0x06 /* Public */,
       9,    3,   61,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    0,   68,    2, 0x08 /* Private */,
      14,    0,   69,    2, 0x08 /* Private */,
      15,    0,   70,    2, 0x08 /* Private */,
      16,    0,   71,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDate, QMetaType::QDate, QMetaType::Int,   10,   11,   12,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ReportWindowSetting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ReportWindowSetting *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pdfCsvClicked((*reinterpret_cast< const QMap<QString,bool>(*)>(_a[1]))); break;
        case 1: _t->on_graphChanged((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 2: _t->on_currentSessionChecked(); break;
        case 3: _t->on_dateRangeChecked((*reinterpret_cast< const QDate(*)>(_a[1])),(*reinterpret_cast< const QDate(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 4: _t->on_csvPdfBtnClick(); break;
        case 5: _t->on_dateUpdate(); break;
        case 6: _t->on_dateRangeUpdate(); break;
        case 7: _t->on_sessionIdComboBoxTextChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ReportWindowSetting::*)(const QMap<QString,bool> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ReportWindowSetting::on_pdfCsvClicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ReportWindowSetting::*)(const std::string & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ReportWindowSetting::on_graphChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ReportWindowSetting::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ReportWindowSetting::on_currentSessionChecked)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ReportWindowSetting::*)(const QDate & , const QDate & , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ReportWindowSetting::on_dateRangeChecked)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ReportWindowSetting::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_ReportWindowSetting.data,
    qt_meta_data_ReportWindowSetting,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ReportWindowSetting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ReportWindowSetting::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ReportWindowSetting.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ReportWindowSetting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void ReportWindowSetting::on_pdfCsvClicked(const QMap<QString,bool> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ReportWindowSetting::on_graphChanged(const std::string & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ReportWindowSetting::on_currentSessionChecked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ReportWindowSetting::on_dateRangeChecked(const QDate & _t1, const QDate & _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
