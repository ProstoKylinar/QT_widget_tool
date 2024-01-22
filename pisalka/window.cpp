#include "window.h"
#include <QDate>

about::about(QWidget* p)
{
    setWindowTitle(tr("Создатель и версия Qt"));
    setGeometry(100,100,640,580);
    about_me= new QLabel(tr("Тут должно быть имя и фамилия чела, который делал лабу"),this);
    about_qt= new QLabel(QString("Версия QT: ") + QString(qVersion()),this);

    QDate data = QDate::currentDate();

    about_time= new QLabel((data.toString()),this);
    about_me->move(50,10);
    about_qt->move(50,30);
    about_time->move(50,50);
    QPixmap pic(":/photo/me.jpg" );
    label= new QLabel(this);
    label->setPixmap(pic);
    label->move(50,70);
}
