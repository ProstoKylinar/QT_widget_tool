#ifndef TAB1_H
#define TAB1_H

#include <QWidget>
#include <QComboBox>
#include <QCheckBox>
#include <QCommandLinkButton>
#include <QMouseEvent>
#include <QLabel>
#include <QDateEdit>
#include <QDateTimeEdit>
#include <QDial>
#include <QDoubleSpinBox>
#include <QFocusFrame>
#include <QFontComboBox>
#include <QLCDNumber>
#include <QLineEdit>
#include <QMenu>
#include <QProgressBar>
#include <QPushButton>
#include <QRadioButton>
#include <QScrollArea>
#include <QScrollBar>
#include <QSizeGrip>
#include <QSlider>
#include <QSpinBox>
#include <QTabBar>
#include <QTabWidget>
#include <QTimeEdit>
#include <QToolBox>
#include <QTextEdit>
#include <QString>


class myComboBox : public QComboBox
{
    Q_OBJECT
public:
    myComboBox(QWidget *parent = 0);
protected:
    void mouseMoveEvent(QMouseEvent *e);
signals:
    void info(QString);
};

class myCheckBox : public QCheckBox
{
    Q_OBJECT
public:
    myCheckBox(const QString parent);
protected:
    void mouseMoveEvent(QMouseEvent *e);
signals:
    void info(QString);
};

class myCommandLinkButton : public QCommandLinkButton
{
    Q_OBJECT
public:
    myCommandLinkButton(QWidget *parent = 0);
protected:
    void mouseMoveEvent(QMouseEvent *e);
signals:
    void info(QString);
};

class myDateEdit : public QDateEdit
{
    Q_OBJECT
public:
    myDateEdit(QWidget *parent = 0);
protected:
    void mouseMoveEvent(QMouseEvent *e);
signals:
    void info(QString);
};

class myDateTimeEdit : public QDateTimeEdit
{
    Q_OBJECT
public:
    myDateTimeEdit(QWidget *parent = 0);
protected:
    void mouseMoveEvent(QMouseEvent *e);
signals:
    void info(QString);
};

class myDial : public QDial
{
    Q_OBJECT
public:
    myDial(QWidget *parent = 0);
protected:
    void mouseMoveEvent(QMouseEvent *e);
signals:
    void info(QString);
};

class myDoubleSpinBox : public QDoubleSpinBox
{
    Q_OBJECT
public:
    myDoubleSpinBox(QWidget *parent = 0);
protected:
    void mouseMoveEvent(QMouseEvent *e);
signals:
    void info(QString);
};

class myFocusFrame : public QFocusFrame
{
    Q_OBJECT
public:
    myFocusFrame(QWidget *parent = 0);
protected:
    void mouseMoveEvent(QMouseEvent *e);
signals:
    void info(QString);
};

class myFontComboBox : public QFontComboBox
{
    Q_OBJECT
public:
    myFontComboBox(QWidget *parent = 0);
protected:
    void mouseMoveEvent(QMouseEvent *e);
signals:
    void info(QString);
};

class myLCDNumber : public QLCDNumber
{
    Q_OBJECT
public:
    myLCDNumber(QWidget *parent = 0);
protected:
    void mouseMoveEvent(QMouseEvent *e);
signals:
    void info(QString);
};

class myLabel : public QLabel
{
    Q_OBJECT
public:
    myLabel(QWidget *parent = 0);
protected:
    void mouseMoveEvent(QMouseEvent *e);
signals:
    void info(QString);
};

class myLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    myLineEdit(QWidget *parent = 0);
protected:
    void mouseMoveEvent(QMouseEvent *e);
signals:
    void info(QString);
};

class myMenu : public QMenu
{
    Q_OBJECT
public:
    myMenu(QWidget *parent = 0);
protected:
    void mouseMoveEvent(QMouseEvent *e);
signals:
    void info(QString);
};

class myProgressBar : public QProgressBar
{
    Q_OBJECT
public:
    myProgressBar(QWidget *parent = 0);
protected:
    void mouseMoveEvent(QMouseEvent *e);
signals:
    void info(QString);
};

class myPushButton : public QPushButton
{
    Q_OBJECT
public:
    myPushButton(QWidget *parent = 0);
protected:
    void mouseMoveEvent(QMouseEvent *e);
signals:
    void info(QString);
};

class myRadioButton : public QRadioButton
{
    Q_OBJECT
public:
    myRadioButton(const QString parent);
protected:
    void mouseMoveEvent(QMouseEvent *e);
signals:
    void info(QString);
};

class myScrollArea : public QScrollArea
{
    Q_OBJECT
public:
    myScrollArea(QWidget *parent = 0);
protected:
    void mouseMoveEvent(QMouseEvent *e);
signals:
    void info(QString);
};

class myScrollBar : public QScrollBar
{
    Q_OBJECT
public:
    myScrollBar(QWidget *parent = 0);
protected:
    void mouseMoveEvent(QMouseEvent *e);
signals:
    void info(QString);
};

class mySizeGrip : public QSizeGrip
{
    Q_OBJECT
public:
    mySizeGrip(QWidget *parent = 0);
protected:
    void mouseMoveEvent(QMouseEvent *e);
signals:
    void info(QString);
};

class mySlider : public QSlider
{
    Q_OBJECT
public:
    mySlider(QWidget *parent = 0);
protected:
    void mouseMoveEvent(QMouseEvent *e);
signals:
    void info(QString);
};

class mySpinBox : public QSpinBox
{
    Q_OBJECT
public:
    mySpinBox(QWidget *parent = 0);
protected:
    void mouseMoveEvent(QMouseEvent *e);
signals:
    void info(QString);
};

class myTabBar : public QTabBar
{
    Q_OBJECT
public:
    myTabBar(QWidget *parent = 0);
protected:
    void mouseMoveEvent(QMouseEvent *e);
signals:
    void info(QString);
};

class myTabWidget : public QTabWidget
{
    Q_OBJECT
public:
    myTabWidget(QWidget *parent = 0);
protected:
    void mouseMoveEvent(QMouseEvent *e);
signals:
    void info(QString);
};

class myTimeEdit : public QTimeEdit
{
    Q_OBJECT
public:
    myTimeEdit(QWidget *parent = 0);
protected:
    void mouseMoveEvent(QMouseEvent *e);
signals:
    void info(QString);
};

class myToolBox : public QToolBox
{
    Q_OBJECT
public:
    myToolBox(QWidget *parent = 0, Qt::WindowFlags f = 0);
protected:
    void mouseMoveEvent(QMouseEvent *e);
signals:
    void info(QString);
};

class myWidget : public QWidget
{
    Q_OBJECT
public:
    myWidget(QWidget *parent = 0);
protected:
    void mouseMoveEvent(QMouseEvent *e);
signals:
    void info(QString);
};
#endif // TAB1_H
