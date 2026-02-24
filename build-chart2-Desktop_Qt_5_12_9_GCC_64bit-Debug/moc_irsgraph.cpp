/****************************************************************************
** Meta object code from reading C++ file 'irsgraph.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Documents/report_window/irsgraph.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'irsgraph.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_IRSGraph_t {
    QByteArrayData data[12];
    char stringdata0[161];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IRSGraph_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IRSGraph_t qt_meta_stringdata_IRSGraph = {
    {
QT_MOC_LITERAL(0, 0, 8), // "IRSGraph"
QT_MOC_LITERAL(1, 9, 24), // "on_currentSessionChecked"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 19), // "on_dateRangeChecked"
QT_MOC_LITERAL(4, 55, 9), // "startDate"
QT_MOC_LITERAL(5, 65, 7), // "endDate"
QT_MOC_LITERAL(6, 73, 9), // "sessionId"
QT_MOC_LITERAL(7, 83, 16), // "on_pdfCsvClicked"
QT_MOC_LITERAL(8, 100, 18), // "QMap<QString,bool>"
QT_MOC_LITERAL(9, 119, 14), // "checkboxStates"
QT_MOC_LITERAL(10, 134, 15), // "on_dataReceived"
QT_MOC_LITERAL(11, 150, 10) // "jsonString"

    },
    "IRSGraph\0on_currentSessionChecked\0\0"
    "on_dateRangeChecked\0startDate\0endDate\0"
    "sessionId\0on_pdfCsvClicked\0"
    "QMap<QString,bool>\0checkboxStates\0"
    "on_dataReceived\0jsonString"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IRSGraph[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a /* Public */,
       3,    3,   35,    2, 0x0a /* Public */,
       7,    1,   42,    2, 0x0a /* Public */,
      10,    1,   45,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDate, QMetaType::QDate, QMetaType::Int,    4,    5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::QString,   11,

       0        // eod
};

void IRSGraph::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<IRSGraph *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_currentSessionChecked(); break;
        case 1: _t->on_dateRangeChecked((*reinterpret_cast< const QDate(*)>(_a[1])),(*reinterpret_cast< const QDate(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->on_pdfCsvClicked((*reinterpret_cast< const QMap<QString,bool>(*)>(_a[1]))); break;
        case 3: _t->on_dataReceived((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject IRSGraph::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_IRSGraph.data,
    qt_meta_data_IRSGraph,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *IRSGraph::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IRSGraph::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_IRSGraph.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int IRSGraph::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
struct qt_meta_stringdata_IRSGraph__LiveGraphThread_t {
    QByteArrayData data[13];
    char stringdata0[175];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IRSGraph__LiveGraphThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IRSGraph__LiveGraphThread_t qt_meta_stringdata_IRSGraph__LiveGraphThread = {
    {
QT_MOC_LITERAL(0, 0, 25), // "IRSGraph::LiveGraphThread"
QT_MOC_LITERAL(1, 26, 16), // "graphDataIsReady"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 10), // "jsonString"
QT_MOC_LITERAL(4, 55, 16), // "tableDataIsReady"
QT_MOC_LITERAL(5, 72, 10), // "totalPages"
QT_MOC_LITERAL(6, 83, 20), // "on_liveGraph_checked"
QT_MOC_LITERAL(7, 104, 15), // "on_ParamChanged"
QT_MOC_LITERAL(8, 120, 9), // "startDate"
QT_MOC_LITERAL(9, 130, 7), // "endDate"
QT_MOC_LITERAL(10, 138, 9), // "sessionId"
QT_MOC_LITERAL(11, 148, 14), // "on_pageChanged"
QT_MOC_LITERAL(12, 163, 11) // "currentPage"

    },
    "IRSGraph::LiveGraphThread\0graphDataIsReady\0"
    "\0jsonString\0tableDataIsReady\0totalPages\0"
    "on_liveGraph_checked\0on_ParamChanged\0"
    "startDate\0endDate\0sessionId\0on_pageChanged\0"
    "currentPage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IRSGraph__LiveGraphThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    2,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   47,    2, 0x0a /* Public */,
       7,    3,   48,    2, 0x0a /* Public */,
      11,    1,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    3,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDate, QMetaType::QDate, QMetaType::Int,    8,    9,   10,
    QMetaType::Void, QMetaType::Int,   12,

       0        // eod
};

void IRSGraph::LiveGraphThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LiveGraphThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->graphDataIsReady((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->tableDataIsReady((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->on_liveGraph_checked(); break;
        case 3: _t->on_ParamChanged((*reinterpret_cast< const QDate(*)>(_a[1])),(*reinterpret_cast< const QDate(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 4: _t->on_pageChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LiveGraphThread::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LiveGraphThread::graphDataIsReady)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (LiveGraphThread::*)(QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LiveGraphThread::tableDataIsReady)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject IRSGraph::LiveGraphThread::staticMetaObject = { {
    &QThread::staticMetaObject,
    qt_meta_stringdata_IRSGraph__LiveGraphThread.data,
    qt_meta_data_IRSGraph__LiveGraphThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *IRSGraph::LiveGraphThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IRSGraph::LiveGraphThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_IRSGraph__LiveGraphThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int IRSGraph::LiveGraphThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void IRSGraph::LiveGraphThread::graphDataIsReady(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void IRSGraph::LiveGraphThread::tableDataIsReady(QString _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
