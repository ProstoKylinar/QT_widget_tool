#include "geometric.h"
#include <QPainterPath>
#include <QPainter>
#include <QRect>
#include <QMenu>
#include <QDebug>
#include <QInputDialog>
#include <QTransform>
#include <QRectF>

GeomFigure::GeomFigure(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(area_wid, area_heig);
    my_path.addRect(QRect(-45,-30, 90, 60));
    inside_figure = my_path.subtracted(QPainterPath());
    setMouseTracking(true);
    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, &QWidget::customContextMenuRequested, this, &GeomFigure::showContextMenu);
    angle = 0; scale_f = 1.0;
}

void GeomFigure::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    QTransform orig = p.transform();
    p.setRenderHint(QPainter::Antialiasing,true);
    p.translate(area_wid/2,area_heig/2);
    p.rotate(angle);
    p.scale(scale_f, scale_f);
    p.setPen(Qt::black);
    p.setBrush(QBrush(fill_colour));
    my_path = orig.map(my_path);
    inside_figure = my_path.subtracted(QPainterPath());
    p.drawPath(my_path);
}

void GeomFigure::mousePressEvent(QMouseEvent *event)
{
    x = event->pos().x();
    y = event->pos().y();
    is_pressed = true;
}

void GeomFigure::mouseMoveEvent(QMouseEvent *event)
{
    qDebug() <<""<<event->pos();
    if (is_pressed) {
        int delta_x = event->pos().x() - x;
        int delta_y = event->pos().y() - y;
        move(pos().x()+delta_x, pos().y()+delta_y);
    }
    if(is_filled &&!inside_figure.contains(QPoint(event->pos().x()-(area_wid*scale_f)/2,event->pos().y()-(area_heig*scale_f)/2)))
    {
        is_filled=false;
        fill_colour=QColor(0,0,0,0);
        update();
    }
    if(inside_figure.contains(QPoint(event->pos().x()-(area_wid*scale_f)/2,event->pos().y()-(area_heig*scale_f)/2))){
        fill_colour= QColor(255,255,0);
        is_filled = true;
        update();
    }

    event->ignore();

}

void GeomFigure::mouseReleaseEvent(QMouseEvent *event) {
    is_pressed = false;
}

void GeomFigure::showContextMenu(const QPoint &pos)
{
    QMenu contextMenu(this);
    QAction rotateAction("Rotate", this);
    connect(&rotateAction, &QAction::triggered, this, &GeomFigure::rotate);
    contextMenu.addAction(&rotateAction);

    QAction resizeAction("Resize", this);
    connect(&resizeAction, &QAction::triggered, this, &GeomFigure::resize);
    contextMenu.addAction(&resizeAction);

    contextMenu.exec(mapToGlobal(pos));
    is_pressed = false;
}

void GeomFigure::rotate()
{
    bool flag;
    int a = QInputDialog::getInt(this, "Rotate", "Enter the angle of rotation of the figure in degrees:", 0, -360, 360, 1, &flag);
    if (flag) {
        angle = a;
        update();
    }
}

void GeomFigure::resize()
{
    bool flag;
    int size = QInputDialog::getInt(this, "Resize", "Enter a new figure size:", 100, 10, 150, 1, &flag);
    if (flag) {
        scale_f = static_cast<double>(size) / 100.0;
        update();
    }
}
