/****************************************************************************
** Meta object code from reading C++ file 'SupportCanvas3D.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.11)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ui/SupportCanvas3D.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SupportCanvas3D.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.11. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SupportCanvas3D_t {
    QByteArrayData data[22];
    char stringdata0[316];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SupportCanvas3D_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SupportCanvas3D_t qt_meta_stringdata_SupportCanvas3D = {
    {
QT_MOC_LITERAL(0, 0, 15), // "SupportCanvas3D"
QT_MOC_LITERAL(1, 16, 18), // "aspectRatioChanged"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 13), // "resetUpVector"
QT_MOC_LITERAL(4, 50, 14), // "setCameraAxisX"
QT_MOC_LITERAL(5, 65, 14), // "setCameraAxisY"
QT_MOC_LITERAL(6, 80, 14), // "setCameraAxisZ"
QT_MOC_LITERAL(7, 95, 20), // "setCameraAxonometric"
QT_MOC_LITERAL(8, 116, 23), // "updateCameraHeightAngle"
QT_MOC_LITERAL(9, 140, 23), // "updateCameraTranslation"
QT_MOC_LITERAL(10, 164, 21), // "updateCameraRotationU"
QT_MOC_LITERAL(11, 186, 21), // "updateCameraRotationV"
QT_MOC_LITERAL(12, 208, 21), // "updateCameraRotationN"
QT_MOC_LITERAL(13, 230, 16), // "updateCameraClip"
QT_MOC_LITERAL(14, 247, 7), // "addEdge"
QT_MOC_LITERAL(15, 255, 11), // "VoronoiEdge"
QT_MOC_LITERAL(16, 267, 4), // "edge"
QT_MOC_LITERAL(17, 272, 11), // "addBuilding"
QT_MOC_LITERAL(18, 284, 7), // "Polygon"
QT_MOC_LITERAL(19, 292, 8), // "building"
QT_MOC_LITERAL(20, 301, 8), // "addGreen"
QT_MOC_LITERAL(21, 310, 5) // "green"

    },
    "SupportCanvas3D\0aspectRatioChanged\0\0"
    "resetUpVector\0setCameraAxisX\0"
    "setCameraAxisY\0setCameraAxisZ\0"
    "setCameraAxonometric\0updateCameraHeightAngle\0"
    "updateCameraTranslation\0updateCameraRotationU\0"
    "updateCameraRotationV\0updateCameraRotationN\0"
    "updateCameraClip\0addEdge\0VoronoiEdge\0"
    "edge\0addBuilding\0Polygon\0building\0"
    "addGreen\0green"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SupportCanvas3D[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   90,    2, 0x0a /* Public */,
       4,    0,   91,    2, 0x0a /* Public */,
       5,    0,   92,    2, 0x0a /* Public */,
       6,    0,   93,    2, 0x0a /* Public */,
       7,    0,   94,    2, 0x0a /* Public */,
       8,    0,   95,    2, 0x0a /* Public */,
       9,    0,   96,    2, 0x0a /* Public */,
      10,    0,   97,    2, 0x0a /* Public */,
      11,    0,   98,    2, 0x0a /* Public */,
      12,    0,   99,    2, 0x0a /* Public */,
      13,    0,  100,    2, 0x0a /* Public */,
      14,    1,  101,    2, 0x0a /* Public */,
      17,    1,  104,    2, 0x0a /* Public */,
      20,    1,  107,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

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
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void, 0x80000000 | 18,   21,

       0        // eod
};

void SupportCanvas3D::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SupportCanvas3D *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->aspectRatioChanged(); break;
        case 1: _t->resetUpVector(); break;
        case 2: _t->setCameraAxisX(); break;
        case 3: _t->setCameraAxisY(); break;
        case 4: _t->setCameraAxisZ(); break;
        case 5: _t->setCameraAxonometric(); break;
        case 6: _t->updateCameraHeightAngle(); break;
        case 7: _t->updateCameraTranslation(); break;
        case 8: _t->updateCameraRotationU(); break;
        case 9: _t->updateCameraRotationV(); break;
        case 10: _t->updateCameraRotationN(); break;
        case 11: _t->updateCameraClip(); break;
        case 12: _t->addEdge((*reinterpret_cast< VoronoiEdge(*)>(_a[1]))); break;
        case 13: _t->addBuilding((*reinterpret_cast< Polygon(*)>(_a[1]))); break;
        case 14: _t->addGreen((*reinterpret_cast< Polygon(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SupportCanvas3D::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SupportCanvas3D::aspectRatioChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SupportCanvas3D::staticMetaObject = { {
    &QGLWidget::staticMetaObject,
    qt_meta_stringdata_SupportCanvas3D.data,
    qt_meta_data_SupportCanvas3D,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SupportCanvas3D::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SupportCanvas3D::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SupportCanvas3D.stringdata0))
        return static_cast<void*>(this);
    return QGLWidget::qt_metacast(_clname);
}

int SupportCanvas3D::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
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
void SupportCanvas3D::aspectRatioChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
