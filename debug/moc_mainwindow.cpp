/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[21];
    char stringdata0[312];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 12), // "startReading"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 14), // "moveMsgPassing"
QT_MOC_LITERAL(4, 40, 13), // "giveFirstData"
QT_MOC_LITERAL(5, 54, 22), // "on_Connect_btn_clicked"
QT_MOC_LITERAL(6, 77, 19), // "on_Read_btn_clicked"
QT_MOC_LITERAL(7, 97, 20), // "on_Clear_btn_clicked"
QT_MOC_LITERAL(8, 118, 18), // "on_pbT_Pos_clicked"
QT_MOC_LITERAL(9, 137, 17), // "on_pb_STF_clicked"
QT_MOC_LITERAL(10, 155, 27), // "on_cb_CyclePos_stateChanged"
QT_MOC_LITERAL(11, 183, 4), // "arg1"
QT_MOC_LITERAL(12, 188, 24), // "on_leT_Pos_returnPressed"
QT_MOC_LITERAL(13, 213, 26), // "on_cb_Logging_stateChanged"
QT_MOC_LITERAL(14, 240, 8), // "logToGui"
QT_MOC_LITERAL(15, 249, 12), // "readErrToGui"
QT_MOC_LITERAL(16, 262, 5), // "r_err"
QT_MOC_LITERAL(17, 268, 13), // "writeErrToGui"
QT_MOC_LITERAL(18, 282, 10), // "closeEvent"
QT_MOC_LITERAL(19, 293, 12), // "QCloseEvent*"
QT_MOC_LITERAL(20, 306, 5) // "event"

    },
    "MainWindow\0startReading\0\0moveMsgPassing\0"
    "giveFirstData\0on_Connect_btn_clicked\0"
    "on_Read_btn_clicked\0on_Clear_btn_clicked\0"
    "on_pbT_Pos_clicked\0on_pb_STF_clicked\0"
    "on_cb_CyclePos_stateChanged\0arg1\0"
    "on_leT_Pos_returnPressed\0"
    "on_cb_Logging_stateChanged\0logToGui\0"
    "readErrToGui\0r_err\0writeErrToGui\0"
    "closeEvent\0QCloseEvent*\0event"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,
       3,    1,   90,    2, 0x06 /* Public */,
       4,    0,   93,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   94,    2, 0x08 /* Private */,
       6,    0,   95,    2, 0x08 /* Private */,
       7,    0,   96,    2, 0x08 /* Private */,
       8,    0,   97,    2, 0x08 /* Private */,
       9,    0,   98,    2, 0x08 /* Private */,
      10,    1,   99,    2, 0x08 /* Private */,
      12,    0,  102,    2, 0x08 /* Private */,
      13,    1,  103,    2, 0x08 /* Private */,
      14,    1,  106,    2, 0x0a /* Public */,
      15,    1,  109,    2, 0x0a /* Public */,
      17,    1,  112,    2, 0x0a /* Public */,
      18,    1,  115,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 19,   20,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startReading(); break;
        case 1: _t->moveMsgPassing((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 2: _t->giveFirstData(); break;
        case 3: _t->on_Connect_btn_clicked(); break;
        case 4: _t->on_Read_btn_clicked(); break;
        case 5: _t->on_Clear_btn_clicked(); break;
        case 6: _t->on_pbT_Pos_clicked(); break;
        case 7: _t->on_pb_STF_clicked(); break;
        case 8: _t->on_cb_CyclePos_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_leT_Pos_returnPressed(); break;
        case 10: _t->on_cb_Logging_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->logToGui((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->readErrToGui((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->writeErrToGui((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::startReading)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::moveMsgPassing)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::giveFirstData)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::startReading()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainWindow::moveMsgPassing(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::giveFirstData()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
struct qt_meta_stringdata_CAN_Reader_t {
    QByteArrayData data[8];
    char stringdata0[99];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CAN_Reader_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CAN_Reader_t qt_meta_stringdata_CAN_Reader = {
    {
QT_MOC_LITERAL(0, 0, 10), // "CAN_Reader"
QT_MOC_LITERAL(1, 11, 14), // "readErrPassing"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 14), // "moveMsgPassing"
QT_MOC_LITERAL(4, 42, 14), // "sendDataToList"
QT_MOC_LITERAL(5, 57, 14), // "QVector<uchar>"
QT_MOC_LITERAL(6, 72, 14), // "restartReading"
QT_MOC_LITERAL(7, 87, 11) // "readCanFlow"

    },
    "CAN_Reader\0readErrPassing\0\0moveMsgPassing\0"
    "sendDataToList\0QVector<uchar>\0"
    "restartReading\0readCanFlow"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CAN_Reader[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       3,    1,   42,    2, 0x06 /* Public */,
       4,    1,   45,    2, 0x06 /* Public */,
       6,    0,   48,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Float,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void CAN_Reader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CAN_Reader *_t = static_cast<CAN_Reader *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->readErrPassing((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->moveMsgPassing((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 2: _t->sendDataToList((*reinterpret_cast< QVector<uchar>(*)>(_a[1]))); break;
        case 3: _t->restartReading(); break;
        case 4: _t->readCanFlow(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<uchar> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CAN_Reader::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CAN_Reader::readErrPassing)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CAN_Reader::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CAN_Reader::moveMsgPassing)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (CAN_Reader::*_t)(QVector<uchar> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CAN_Reader::sendDataToList)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (CAN_Reader::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CAN_Reader::restartReading)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject CAN_Reader::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CAN_Reader.data,
      qt_meta_data_CAN_Reader,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CAN_Reader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CAN_Reader::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CAN_Reader.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CAN_Reader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void CAN_Reader::readErrPassing(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CAN_Reader::moveMsgPassing(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CAN_Reader::sendDataToList(QVector<uchar> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CAN_Reader::restartReading()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
struct qt_meta_stringdata_CAN_Writer_t {
    QByteArrayData data[4];
    char stringdata0[41];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CAN_Writer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CAN_Writer_t qt_meta_stringdata_CAN_Writer = {
    {
QT_MOC_LITERAL(0, 0, 10), // "CAN_Writer"
QT_MOC_LITERAL(1, 11, 15), // "writeErrPassing"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 12) // "moveMsgToCan"

    },
    "CAN_Writer\0writeErrPassing\0\0moveMsgToCan"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CAN_Writer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   27,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Float,    2,

       0        // eod
};

void CAN_Writer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CAN_Writer *_t = static_cast<CAN_Writer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->writeErrPassing((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->moveMsgToCan((*reinterpret_cast< float(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CAN_Writer::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CAN_Writer::writeErrPassing)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject CAN_Writer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CAN_Writer.data,
      qt_meta_data_CAN_Writer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CAN_Writer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CAN_Writer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CAN_Writer.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CAN_Writer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void CAN_Writer::writeErrPassing(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_CAN_Helper_t {
    QByteArrayData data[6];
    char stringdata0[70];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CAN_Helper_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CAN_Helper_t qt_meta_stringdata_CAN_Helper = {
    {
QT_MOC_LITERAL(0, 0, 10), // "CAN_Helper"
QT_MOC_LITERAL(1, 11, 16), // "sendDataFromList"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 15), // "writeDataToList"
QT_MOC_LITERAL(4, 45, 14), // "QVector<uchar>"
QT_MOC_LITERAL(5, 60, 9) // "checkList"

    },
    "CAN_Helper\0sendDataFromList\0\0"
    "writeDataToList\0QVector<uchar>\0checkList"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CAN_Helper[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   32,    2, 0x0a /* Public */,
       5,    0,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void,

       0        // eod
};

void CAN_Helper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CAN_Helper *_t = static_cast<CAN_Helper *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendDataFromList((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->writeDataToList((*reinterpret_cast< QVector<uchar>(*)>(_a[1]))); break;
        case 2: _t->checkList(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<uchar> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CAN_Helper::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CAN_Helper::sendDataFromList)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject CAN_Helper::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CAN_Helper.data,
      qt_meta_data_CAN_Helper,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CAN_Helper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CAN_Helper::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CAN_Helper.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CAN_Helper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void CAN_Helper::sendDataFromList(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_CAN_ReadTrigger_t {
    QByteArrayData data[4];
    char stringdata0[54];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CAN_ReadTrigger_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CAN_ReadTrigger_t qt_meta_stringdata_CAN_ReadTrigger = {
    {
QT_MOC_LITERAL(0, 0, 15), // "CAN_ReadTrigger"
QT_MOC_LITERAL(1, 16, 17), // "sigRestartReading"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 18) // "slotRestartReading"

    },
    "CAN_ReadTrigger\0sigRestartReading\0\0"
    "slotRestartReading"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CAN_ReadTrigger[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   25,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void CAN_ReadTrigger::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CAN_ReadTrigger *_t = static_cast<CAN_ReadTrigger *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigRestartReading(); break;
        case 1: _t->slotRestartReading(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CAN_ReadTrigger::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CAN_ReadTrigger::sigRestartReading)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject CAN_ReadTrigger::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CAN_ReadTrigger.data,
      qt_meta_data_CAN_ReadTrigger,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CAN_ReadTrigger::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CAN_ReadTrigger::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CAN_ReadTrigger.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CAN_ReadTrigger::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void CAN_ReadTrigger::sigRestartReading()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
