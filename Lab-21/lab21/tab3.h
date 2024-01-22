#ifndef TAB3_H
#define TAB3_H

#include <QWidget>
#include <QButtonGroup>
#include <QMouseEvent>
#include <QGroupBox>
#include <QSplitter>
#include <QSplitterHandle>
#include <QStackedWidget>
#include <QTabWidget>

class myGroupBox : public QGroupBox
{
    Q_OBJECT
public:
    myGroupBox(const QString parent);
protected:
    void mouseMoveEvent(QMouseEvent *e);
signals:
    void info(QString);
};

class mySplitter : public QSplitter
{
    Q_OBJECT
public:
    mySplitter(QWidget *parent = 0);
protected:
    void mouseMoveEvent(QMouseEvent *e);
signals:
    void info(QString);
};

class mySplitterHandle : public QSplitterHandle
{
    Q_OBJECT
public:
    mySplitterHandle(Qt::Orientation, QSplitter *);
protected:
    void mouseMoveEvent(QMouseEvent *e);
signals:
    void info(QString);
};

class myStackedWidget : public QStackedWidget
{
    Q_OBJECT
public:
    myStackedWidget(QWidget *parent = 0);
protected:
    void mouseMoveEvent(QMouseEvent *e);
signals:
    void info(QString);
};
#endif // TAB3_H
