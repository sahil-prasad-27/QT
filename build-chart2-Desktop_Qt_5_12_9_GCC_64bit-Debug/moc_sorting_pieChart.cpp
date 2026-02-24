/****************************************************************************
** Meta object code from reading C++ file 'sorting_pieChart.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Documents/report_window/sorting_pieChart.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sorting_pieChart.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Sorting_PieChart_t {
    QByteArrayData data[14];
    char stringdata0[201];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Sorting_PieChart_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Sorting_PieChart_t qt_meta_stringdata_Sorting_PieChart = {
    {
QT_MOC_LITERAL(0, 0, 16), // "Sorting_PieChart"
QT_MOC_LITERAL(1, 17, 24), // "on_currentSessionChecked"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 19), // "on_dateRangeChecked"
QT_MOC_LITERAL(4, 63, 9), // "startDate"
QT_MOC_LITERAL(5, 73, 7), // "endDate"
QT_MOC_LITERAL(6, 81, 9), // "sessionId"
QT_MOC_LITERAL(7, 91, 16), // "on_pdfCsvClicked"
QT_MOC_LITERAL(8, 108, 18), // "QMap<QString,bool>"
QT_MOC_LITERAL(9, 127, 14), // "checkboxStates"
QT_MOC_LITERAL(10, 142, 15), // "on_dataReceived"
QT_MOC_LITERAL(11, 158, 10), // "jsonString"
QT_MOC_LITERAL(12, 169, 20), // "on_tableDataReceived"
QT_MOC_LITERAL(13, 190, 10) // "totalPages"

    },
    "Sorting_PieChart\0on_currentSessionChecked\0"
    "\0on_dateRangeChecked\0startDate\0endDate\0"
    "sessionId\0on_pdfCsvClicked\0"
    "QMap<QString,bool>\0checkboxStates\0"
    "on_dataReceived\0jsonString\0"
    "on_tableDataReceived\0totalPages"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Sorting_PieChart[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x0a /* Public */,
       3,    3,   40,    2, 0x0a /* Public */,
       7,    1,   47,    2, 0x0a /* Public */,
      10,    1,   50,    2, 0x08 /* Private */,
      12,    2,   53,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDate, QMetaType::QDate, QMetaType::Int,    4,    5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   11,   13,

       0        // eod
};

void Sorting_PieChart::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Sorting_PieChart *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_currentSessionChecked(); break;
        case 1: _t->on_dateRangeChecked((*reinterpret_cast< const QDate(*)>(_a[1])),(*reinterpret_cast< const QDate(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->on_pdfCsvClicked((*reinterpret_cast< const QMap<QString,bool>(*)>(_a[1]))); break;
        case 3: _t->on_dataReceived((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->on_tableDataReceived((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Sorting_PieChart::staticMetaObject = { {
    &IRSGraph::staticMetaObject,
    qt_meta_stringdata_Sorting_PieChart.data,
    qt_meta_data_Sorting_PieChart,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Sorting_PieChart::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Sorting_PieChart::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Sorting_PieChart.stringdata0))
        return static_cast<void*>(this);
    return IRSGraph::qt_metacast(_clname);
}

int Sorting_PieChart::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = IRSGraph::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
struct qt_meta_stringdata_Sorting_PieChart__LivePieChartThread_t {
    QByteArrayData data[8];
    char stringdata0[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Sorting_PieChart__LivePieChartThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Sorting_PieChart__LivePieChartThread_t qt_meta_stringdata_Sorting_PieChart__LivePieChartThread = {
    {
QT_MOC_LITERAL(0, 0, 36), // "Sorting_PieChart::LivePieChar..."
QT_MOC_LITERAL(1, 37, 15), // "on_ParamChanged"
QT_MOC_LITERAL(2, 53, 0), // ""
QT_MOC_LITERAL(3, 54, 9), // "startDate"
QT_MOC_LITERAL(4, 64, 7), // "endDate"
QT_MOC_LITERAL(5, 72, 9), // "sessionId"
QT_MOC_LITERAL(6, 82, 14), // "on_pageChanged"
QT_MOC_LITERAL(7, 97, 11) // "currentPage"

    },
    "Sorting_PieChart::LivePieChartThread\0"
    "on_ParamChanged\0\0startDate\0endDate\0"
    "sessionId\0on_pageChanged\0currentPage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Sorting_PieChart__LivePieChartThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   24,    2, 0x0a /* Public */,
       6,    1,   31,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QDate, QMetaType::QDate, QMetaType::Int,    3,    4,    5,
    QMetaType::Void, QMetaType::Int,    7,

       0        // eod
};

void Sorting_PieChart::LivePieChartThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LivePieChartThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_ParamChanged((*reinterpret_cast< const QDate(*)>(_a[1])),(*reinterpret_cast< const QDate(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->on_pageChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Sorting_PieChart::LivePieChartThread::staticMetaObject = { {
    &LiveGraphThread::staticMetaObject,
    qt_meta_stringdata_Sorting_PieChart__LivePieChartThread.data,
    qt_meta_data_Sorting_PieChart__LivePieChartThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Sorting_PieChart::LivePieChartThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Sorting_PieChart::LivePieChartThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Sorting_PieChart__LivePieChartThread.stringdata0))
        return static_cast<void*>(this);
    return LiveGraphThread::qt_metacast(_clname);
}

int Sorting_PieChart::LivePieChartThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = LiveGraphThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
