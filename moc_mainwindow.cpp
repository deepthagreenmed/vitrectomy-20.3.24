/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[91];
    char stringdata0[1595];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 21), // "airinjectoronFinished"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 13), // "receiveString"
QT_MOC_LITERAL(4, 48, 3), // "str"
QT_MOC_LITERAL(5, 52, 14), // "receiveString0"
QT_MOC_LITERAL(6, 67, 3), // "val"
QT_MOC_LITERAL(7, 71, 14), // "receiveString1"
QT_MOC_LITERAL(8, 86, 14), // "receiveString2"
QT_MOC_LITERAL(9, 101, 14), // "receiveString3"
QT_MOC_LITERAL(10, 116, 7), // "led1val"
QT_MOC_LITERAL(11, 124, 7), // "led2val"
QT_MOC_LITERAL(12, 132, 6), // "vacval"
QT_MOC_LITERAL(13, 139, 6), // "vaclnl"
QT_MOC_LITERAL(14, 146, 6), // "vitval"
QT_MOC_LITERAL(15, 153, 6), // "vitlnl"
QT_MOC_LITERAL(16, 160, 7), // "typevit"
QT_MOC_LITERAL(17, 168, 6), // "diaval"
QT_MOC_LITERAL(18, 175, 12), // "aibackground"
QT_MOC_LITERAL(19, 188, 10), // "on_clicked"
QT_MOC_LITERAL(20, 199, 5), // "digit"
QT_MOC_LITERAL(21, 205, 15), // "on_clickedenter"
QT_MOC_LITERAL(22, 221, 19), // "on_clickedbackspace"
QT_MOC_LITERAL(23, 241, 13), // "airinjectoron"
QT_MOC_LITERAL(24, 255, 9), // "vitvalset"
QT_MOC_LITERAL(25, 265, 14), // "nonlinearcall3"
QT_MOC_LITERAL(26, 280, 21), // "transitionToNewScreen"
QT_MOC_LITERAL(27, 302, 7), // "setZero"
QT_MOC_LITERAL(28, 310, 11), // "updateLabel"
QT_MOC_LITERAL(29, 322, 12), // "updateLabel2"
QT_MOC_LITERAL(30, 335, 9), // "diathermy"
QT_MOC_LITERAL(31, 345, 14), // "airinjectoroff"
QT_MOC_LITERAL(32, 360, 14), // "updatetimedate"
QT_MOC_LITERAL(33, 375, 19), // "increaseVaccumValue"
QT_MOC_LITERAL(34, 395, 19), // "decreaseVaccumValue"
QT_MOC_LITERAL(35, 415, 23), // "increaseVitrectomyValue"
QT_MOC_LITERAL(36, 439, 23), // "decreaseVitrectomyValue"
QT_MOC_LITERAL(37, 463, 22), // "increaseDiathermyValue"
QT_MOC_LITERAL(38, 486, 22), // "decreaseDiathermyValue"
QT_MOC_LITERAL(39, 509, 24), // "increaseAirInjectorValue"
QT_MOC_LITERAL(40, 534, 24), // "decreaseAirInjectorValue"
QT_MOC_LITERAL(41, 559, 16), // "increaseledvalue"
QT_MOC_LITERAL(42, 576, 16), // "decreaseledvalue"
QT_MOC_LITERAL(43, 593, 17), // "increaseledvalue2"
QT_MOC_LITERAL(44, 611, 17), // "decreaseledvalue2"
QT_MOC_LITERAL(45, 629, 18), // "increasesiliconoil"
QT_MOC_LITERAL(46, 648, 18), // "decreasesiliconoil"
QT_MOC_LITERAL(47, 667, 18), // "showsettingswindow"
QT_MOC_LITERAL(48, 686, 13), // "sil_oil_onoff"
QT_MOC_LITERAL(49, 700, 20), // "vac_linear_nonlinear"
QT_MOC_LITERAL(50, 721, 10), // "led1_onoff"
QT_MOC_LITERAL(51, 732, 9), // "dia_onoff"
QT_MOC_LITERAL(52, 742, 8), // "ai_onoff"
QT_MOC_LITERAL(53, 751, 9), // "vit_onoff"
QT_MOC_LITERAL(54, 761, 10), // "setsurgeon"
QT_MOC_LITERAL(55, 772, 23), // "on_increase_vac_pressed"
QT_MOC_LITERAL(56, 796, 24), // "on_increase_vac_released"
QT_MOC_LITERAL(57, 821, 23), // "on_decrease_vac_pressed"
QT_MOC_LITERAL(58, 845, 24), // "on_decrease_vac_released"
QT_MOC_LITERAL(59, 870, 23), // "on_increase_vit_pressed"
QT_MOC_LITERAL(60, 894, 24), // "on_increase_vit_released"
QT_MOC_LITERAL(61, 919, 23), // "on_decrease_vit_pressed"
QT_MOC_LITERAL(62, 943, 24), // "on_decrease_vit_released"
QT_MOC_LITERAL(63, 968, 27), // "on_increase_sil_oil_pressed"
QT_MOC_LITERAL(64, 996, 28), // "on_increase_sil_oil_released"
QT_MOC_LITERAL(65, 1025, 27), // "on_decrease_sil_oil_pressed"
QT_MOC_LITERAL(66, 1053, 28), // "on_decrease_sil_oil_released"
QT_MOC_LITERAL(67, 1082, 24), // "on_increase_led1_pressed"
QT_MOC_LITERAL(68, 1107, 25), // "on_increase_led1_released"
QT_MOC_LITERAL(69, 1133, 24), // "on_decrease_led1_pressed"
QT_MOC_LITERAL(70, 1158, 25), // "on_decrease_led1_released"
QT_MOC_LITERAL(71, 1184, 22), // "on_increase_ai_pressed"
QT_MOC_LITERAL(72, 1207, 23), // "on_increase_ai_released"
QT_MOC_LITERAL(73, 1231, 22), // "on_decrease_ai_pressed"
QT_MOC_LITERAL(74, 1254, 23), // "on_decrease_ai_released"
QT_MOC_LITERAL(75, 1278, 23), // "on_increase_dia_pressed"
QT_MOC_LITERAL(76, 1302, 24), // "on_increase_dia_released"
QT_MOC_LITERAL(77, 1327, 23), // "on_decrease_dia_pressed"
QT_MOC_LITERAL(78, 1351, 24), // "on_decrease_dia_released"
QT_MOC_LITERAL(79, 1376, 24), // "on_increase_led2_pressed"
QT_MOC_LITERAL(80, 1401, 25), // "on_increase_led2_released"
QT_MOC_LITERAL(81, 1427, 24), // "on_decrease_led2_pressed"
QT_MOC_LITERAL(82, 1452, 25), // "on_decrease_led2_released"
QT_MOC_LITERAL(83, 1478, 20), // "vit_linear_nonlinear"
QT_MOC_LITERAL(84, 1499, 10), // "led2_onoff"
QT_MOC_LITERAL(85, 1510, 12), // "comboboxload"
QT_MOC_LITERAL(86, 1523, 17), // "onComboBoxClicked"
QT_MOC_LITERAL(87, 1541, 14), // "timerCompleted"
QT_MOC_LITERAL(88, 1556, 15), // "showsetupscreen"
QT_MOC_LITERAL(89, 1572, 10), // "swap_onoff"
QT_MOC_LITERAL(90, 1583, 11) // "drain_onoff"

    },
    "MainWindow\0airinjectoronFinished\0\0"
    "receiveString\0str\0receiveString0\0val\0"
    "receiveString1\0receiveString2\0"
    "receiveString3\0led1val\0led2val\0vacval\0"
    "vaclnl\0vitval\0vitlnl\0typevit\0diaval\0"
    "aibackground\0on_clicked\0digit\0"
    "on_clickedenter\0on_clickedbackspace\0"
    "airinjectoron\0vitvalset\0nonlinearcall3\0"
    "transitionToNewScreen\0setZero\0updateLabel\0"
    "updateLabel2\0diathermy\0airinjectoroff\0"
    "updatetimedate\0increaseVaccumValue\0"
    "decreaseVaccumValue\0increaseVitrectomyValue\0"
    "decreaseVitrectomyValue\0increaseDiathermyValue\0"
    "decreaseDiathermyValue\0increaseAirInjectorValue\0"
    "decreaseAirInjectorValue\0increaseledvalue\0"
    "decreaseledvalue\0increaseledvalue2\0"
    "decreaseledvalue2\0increasesiliconoil\0"
    "decreasesiliconoil\0showsettingswindow\0"
    "sil_oil_onoff\0vac_linear_nonlinear\0"
    "led1_onoff\0dia_onoff\0ai_onoff\0vit_onoff\0"
    "setsurgeon\0on_increase_vac_pressed\0"
    "on_increase_vac_released\0"
    "on_decrease_vac_pressed\0"
    "on_decrease_vac_released\0"
    "on_increase_vit_pressed\0"
    "on_increase_vit_released\0"
    "on_decrease_vit_pressed\0"
    "on_decrease_vit_released\0"
    "on_increase_sil_oil_pressed\0"
    "on_increase_sil_oil_released\0"
    "on_decrease_sil_oil_pressed\0"
    "on_decrease_sil_oil_released\0"
    "on_increase_led1_pressed\0"
    "on_increase_led1_released\0"
    "on_decrease_led1_pressed\0"
    "on_decrease_led1_released\0"
    "on_increase_ai_pressed\0on_increase_ai_released\0"
    "on_decrease_ai_pressed\0on_decrease_ai_released\0"
    "on_increase_dia_pressed\0"
    "on_increase_dia_released\0"
    "on_decrease_dia_pressed\0"
    "on_decrease_dia_released\0"
    "on_increase_led2_pressed\0"
    "on_increase_led2_released\0"
    "on_decrease_led2_pressed\0"
    "on_decrease_led2_released\0"
    "vit_linear_nonlinear\0led2_onoff\0"
    "comboboxload\0onComboBoxClicked\0"
    "timerCompleted\0showsetupscreen\0"
    "swap_onoff\0drain_onoff"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      86,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  444,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,  445,    2, 0x0a /* Public */,
       5,    1,  448,    2, 0x0a /* Public */,
       7,    1,  451,    2, 0x0a /* Public */,
       8,    1,  454,    2, 0x0a /* Public */,
       9,    1,  457,    2, 0x0a /* Public */,
      10,    1,  460,    2, 0x0a /* Public */,
      11,    1,  463,    2, 0x0a /* Public */,
      12,    1,  466,    2, 0x0a /* Public */,
      13,    1,  469,    2, 0x0a /* Public */,
      14,    1,  472,    2, 0x0a /* Public */,
      15,    1,  475,    2, 0x0a /* Public */,
      16,    1,  478,    2, 0x0a /* Public */,
      17,    1,  481,    2, 0x0a /* Public */,
      18,    0,  484,    2, 0x0a /* Public */,
      19,    1,  485,    2, 0x0a /* Public */,
      21,    0,  488,    2, 0x0a /* Public */,
      22,    0,  489,    2, 0x0a /* Public */,
      23,    0,  490,    2, 0x0a /* Public */,
      24,    0,  491,    2, 0x0a /* Public */,
      25,    0,  492,    2, 0x08 /* Private */,
      26,    0,  493,    2, 0x08 /* Private */,
      27,    0,  494,    2, 0x08 /* Private */,
      28,    0,  495,    2, 0x08 /* Private */,
      29,    0,  496,    2, 0x08 /* Private */,
      30,    0,  497,    2, 0x08 /* Private */,
      31,    0,  498,    2, 0x08 /* Private */,
      32,    0,  499,    2, 0x08 /* Private */,
      33,    0,  500,    2, 0x08 /* Private */,
      34,    0,  501,    2, 0x08 /* Private */,
      35,    0,  502,    2, 0x08 /* Private */,
      36,    0,  503,    2, 0x08 /* Private */,
      37,    0,  504,    2, 0x08 /* Private */,
      38,    0,  505,    2, 0x08 /* Private */,
      39,    0,  506,    2, 0x08 /* Private */,
      40,    0,  507,    2, 0x08 /* Private */,
      41,    0,  508,    2, 0x08 /* Private */,
      42,    0,  509,    2, 0x08 /* Private */,
      43,    0,  510,    2, 0x08 /* Private */,
      44,    0,  511,    2, 0x08 /* Private */,
      45,    0,  512,    2, 0x08 /* Private */,
      46,    0,  513,    2, 0x08 /* Private */,
      47,    0,  514,    2, 0x08 /* Private */,
      48,    0,  515,    2, 0x08 /* Private */,
      49,    0,  516,    2, 0x08 /* Private */,
      50,    0,  517,    2, 0x08 /* Private */,
      51,    0,  518,    2, 0x08 /* Private */,
      52,    0,  519,    2, 0x08 /* Private */,
      53,    0,  520,    2, 0x08 /* Private */,
      54,    0,  521,    2, 0x08 /* Private */,
      55,    0,  522,    2, 0x08 /* Private */,
      56,    0,  523,    2, 0x08 /* Private */,
      57,    0,  524,    2, 0x08 /* Private */,
      58,    0,  525,    2, 0x08 /* Private */,
      59,    0,  526,    2, 0x08 /* Private */,
      60,    0,  527,    2, 0x08 /* Private */,
      61,    0,  528,    2, 0x08 /* Private */,
      62,    0,  529,    2, 0x08 /* Private */,
      63,    0,  530,    2, 0x08 /* Private */,
      64,    0,  531,    2, 0x08 /* Private */,
      65,    0,  532,    2, 0x08 /* Private */,
      66,    0,  533,    2, 0x08 /* Private */,
      67,    0,  534,    2, 0x08 /* Private */,
      68,    0,  535,    2, 0x08 /* Private */,
      69,    0,  536,    2, 0x08 /* Private */,
      70,    0,  537,    2, 0x08 /* Private */,
      71,    0,  538,    2, 0x08 /* Private */,
      72,    0,  539,    2, 0x08 /* Private */,
      73,    0,  540,    2, 0x08 /* Private */,
      74,    0,  541,    2, 0x08 /* Private */,
      75,    0,  542,    2, 0x08 /* Private */,
      76,    0,  543,    2, 0x08 /* Private */,
      77,    0,  544,    2, 0x08 /* Private */,
      78,    0,  545,    2, 0x08 /* Private */,
      79,    0,  546,    2, 0x08 /* Private */,
      80,    0,  547,    2, 0x08 /* Private */,
      81,    0,  548,    2, 0x08 /* Private */,
      82,    0,  549,    2, 0x08 /* Private */,
      83,    0,  550,    2, 0x08 /* Private */,
      84,    0,  551,    2, 0x08 /* Private */,
      85,    0,  552,    2, 0x08 /* Private */,
      86,    0,  553,    2, 0x08 /* Private */,
      87,    0,  554,    2, 0x08 /* Private */,
      88,    0,  555,    2, 0x08 /* Private */,
      89,    0,  556,    2, 0x08 /* Private */,
      90,    0,  557,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   20,
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->airinjectoronFinished(); break;
        case 1: _t->receiveString((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->receiveString0((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->receiveString1((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->receiveString2((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->receiveString3((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->led1val((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->led2val((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->vacval((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->vaclnl((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->vitval((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->vitlnl((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->typevit((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->diaval((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->aibackground(); break;
        case 15: _t->on_clicked((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 16: _t->on_clickedenter(); break;
        case 17: _t->on_clickedbackspace(); break;
        case 18: _t->airinjectoron(); break;
        case 19: _t->vitvalset(); break;
        case 20: _t->nonlinearcall3(); break;
        case 21: _t->transitionToNewScreen(); break;
        case 22: _t->setZero(); break;
        case 23: _t->updateLabel(); break;
        case 24: _t->updateLabel2(); break;
        case 25: _t->diathermy(); break;
        case 26: _t->airinjectoroff(); break;
        case 27: _t->updatetimedate(); break;
        case 28: _t->increaseVaccumValue(); break;
        case 29: _t->decreaseVaccumValue(); break;
        case 30: _t->increaseVitrectomyValue(); break;
        case 31: _t->decreaseVitrectomyValue(); break;
        case 32: _t->increaseDiathermyValue(); break;
        case 33: _t->decreaseDiathermyValue(); break;
        case 34: _t->increaseAirInjectorValue(); break;
        case 35: _t->decreaseAirInjectorValue(); break;
        case 36: _t->increaseledvalue(); break;
        case 37: _t->decreaseledvalue(); break;
        case 38: _t->increaseledvalue2(); break;
        case 39: _t->decreaseledvalue2(); break;
        case 40: _t->increasesiliconoil(); break;
        case 41: _t->decreasesiliconoil(); break;
        case 42: _t->showsettingswindow(); break;
        case 43: _t->sil_oil_onoff(); break;
        case 44: _t->vac_linear_nonlinear(); break;
        case 45: _t->led1_onoff(); break;
        case 46: _t->dia_onoff(); break;
        case 47: _t->ai_onoff(); break;
        case 48: _t->vit_onoff(); break;
        case 49: _t->setsurgeon(); break;
        case 50: _t->on_increase_vac_pressed(); break;
        case 51: _t->on_increase_vac_released(); break;
        case 52: _t->on_decrease_vac_pressed(); break;
        case 53: _t->on_decrease_vac_released(); break;
        case 54: _t->on_increase_vit_pressed(); break;
        case 55: _t->on_increase_vit_released(); break;
        case 56: _t->on_decrease_vit_pressed(); break;
        case 57: _t->on_decrease_vit_released(); break;
        case 58: _t->on_increase_sil_oil_pressed(); break;
        case 59: _t->on_increase_sil_oil_released(); break;
        case 60: _t->on_decrease_sil_oil_pressed(); break;
        case 61: _t->on_decrease_sil_oil_released(); break;
        case 62: _t->on_increase_led1_pressed(); break;
        case 63: _t->on_increase_led1_released(); break;
        case 64: _t->on_decrease_led1_pressed(); break;
        case 65: _t->on_decrease_led1_released(); break;
        case 66: _t->on_increase_ai_pressed(); break;
        case 67: _t->on_increase_ai_released(); break;
        case 68: _t->on_decrease_ai_pressed(); break;
        case 69: _t->on_decrease_ai_released(); break;
        case 70: _t->on_increase_dia_pressed(); break;
        case 71: _t->on_increase_dia_released(); break;
        case 72: _t->on_decrease_dia_pressed(); break;
        case 73: _t->on_decrease_dia_released(); break;
        case 74: _t->on_increase_led2_pressed(); break;
        case 75: _t->on_increase_led2_released(); break;
        case 76: _t->on_decrease_led2_pressed(); break;
        case 77: _t->on_decrease_led2_released(); break;
        case 78: _t->vit_linear_nonlinear(); break;
        case 79: _t->led2_onoff(); break;
        case 80: _t->comboboxload(); break;
        case 81: _t->onComboBoxClicked(); break;
        case 82: _t->timerCompleted(); break;
        case 83: _t->showsetupscreen(); break;
        case 84: _t->swap_onoff(); break;
        case 85: _t->drain_onoff(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::airinjectoronFinished)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


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
        if (_id < 86)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 86;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 86)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 86;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::airinjectoronFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
