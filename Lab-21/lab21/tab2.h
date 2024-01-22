#ifndef TAB2_H
#define TAB2_H

#include <QWidget>
#include <QMouseEvent>
#include <QCalendarWidget>
#include <QColumnView>
#include <QListView>
#include <QTableView>
#include <QTreeView>
#include <QUndoView>


class myCalendarWidget : public QCalendarWidget
{
    Q_OBJECT
public:
    myCalendarWidget(QWidget * parent = 0);
protected:
    void mouseMoveEvent(QMouseEvent *e);
signals:
    void info(QString);
};

class myColumnView : public QColumnView
{
    Q_OBJECT
public:
    myColumnView(QWidget *parent = 0);
protected:
    void mouseMoveEvent(QMouseEvent *e);
signals:
    void info(QString);
};

class myListView : public QListView
{
    Q_OBJECT
public:
    myListView(QWidget *parent = 0);
protected:
    void mouseMoveEvent(QMouseEvent *e);
signals:
    void info(QString);
};

class myTableView : public QTableView
{
    Q_OBJECT
public:
    myTableView(QWidget *parent = 0);
protected:
    void mouseMoveEvent(QMouseEvent *e);
signals:
    void info(QString);
};

class myTreeView : public QTreeView
{
    Q_OBJECT
public:
    myTreeView(QWidget *parent = 0);
protected:
    void mouseMoveEvent(QMouseEvent *e);
signals:
    void info(QString);
};

class myUndoView : public QUndoView
{
    Q_OBJECT
public:
    myUndoView(QWidget *parent = 0);
protected:
    void mouseMoveEvent(QMouseEvent *e);
signals:
    void info(QString);
};

#endif // TAB2_H
