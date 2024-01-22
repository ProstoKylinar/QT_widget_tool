#ifndef GEOMETRIC_H
#define GEOMETRIC_H
#include <QWidget>
#include <QMouseEvent>
#include <QPainterPath>
#include <QPoint>

class GeomFigure : public QWidget
{
    Q_OBJECT

    int x,y;
    int area_wid = 180;
    int area_heig = 180;
    int rect_wid = 90;
    int rect_heig = 60;
    int angle;
    double scale_f;
    QPoint * center = new QPoint(area_wid/2, area_heig/2);
public:
    QPainterPath my_path;
    QPainterPath inside_figure;
    bool is_filled = false;
    bool is_pressed = false;
    QColor fill_colour = QColor(0,0,0,0);
    GeomFigure(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private slots:
    void showContextMenu(const QPoint &pos);
    void rotate();
    void resize();
};

bool is_near_border(const QPoint *pos);
#endif // GEOMETRIC_H
