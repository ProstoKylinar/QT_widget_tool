#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class QFrame;
class QLabel;



class Widget : public QWidget
{
    Q_OBJECT

    QFrame *frame;
    QLabel *frame_text;
public:
    Widget(QWidget *p = 0);

public slots:
    void changeInfo(QString s);
};

#endif // MAINWINDOW_H
