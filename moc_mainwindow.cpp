/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   35,   35,   35, 0x08,
      36,   35,   35,   35, 0x08,
      58,   35,   35,   35, 0x08,
      83,   35,   35,   35, 0x08,
     107,   35,   35,   35, 0x08,
     131,   35,   35,   35, 0x08,
     156,   35,   35,   35, 0x08,
     181,   35,   35,   35, 0x08,
     205,   35,   35,   35, 0x08,
     229,   35,   35,   35, 0x08,
     255,   35,   35,   35, 0x08,
     279,   35,   35,   35, 0x08,
     304,   35,   35,   35, 0x08,
     330,   35,   35,   35, 0x08,
     362,  392,  405,   35, 0x08,
     410,   35,   35,   35, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0on_buttondown_clicked()\0\0"
    "on_buttonup_clicked()\0on_buttonright_clicked()\0"
    "on_buttonleft_clicked()\0on_buttonplus_clicked()\0"
    "on_buttonminus_clicked()\0"
    "on_createpoint_clicked()\0"
    "on_createline_clicked()\0on_createpoly_clicked()\0"
    "on_addpolypoint_clicked()\0"
    "on_buttonmove_clicked()\0"
    "on_buttonscale_clicked()\0"
    "on_buttonrotate_clicked()\0"
    "on_buttonrotatewindow_clicked()\0"
    "eventFilter(QObject*,QEvent*)\0"
    "object,event\0bool\0updateScreen()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_buttondown_clicked(); break;
        case 1: _t->on_buttonup_clicked(); break;
        case 2: _t->on_buttonright_clicked(); break;
        case 3: _t->on_buttonleft_clicked(); break;
        case 4: _t->on_buttonplus_clicked(); break;
        case 5: _t->on_buttonminus_clicked(); break;
        case 6: _t->on_createpoint_clicked(); break;
        case 7: _t->on_createline_clicked(); break;
        case 8: _t->on_createpoly_clicked(); break;
        case 9: _t->on_addpolypoint_clicked(); break;
        case 10: _t->on_buttonmove_clicked(); break;
        case 11: _t->on_buttonscale_clicked(); break;
        case 12: _t->on_buttonrotate_clicked(); break;
        case 13: _t->on_buttonrotatewindow_clicked(); break;
        case 14: { bool _r = _t->eventFilter((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QEvent*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 15: _t->updateScreen(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
