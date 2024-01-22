#include "tab3.h"

myGroupBox::myGroupBox(const QString parent) : QGroupBox(parent) {
    setMouseTracking(true);
}

void myGroupBox::mouseMoveEvent(QMouseEvent *e) {
    emit info("<b>QGroupBox</b><p>A group box provides a frame, a title on top, a keyboard shortcut, and displays various other widgets inside itself."
              "The keyboard shortcut moves keyboard focus to one of the group box's child widgets."
              "QGroupBox also lets you set the title (normally set in the constructor) and the title's alignment. "
              "Group boxes can be checkable. Child widgets in checkable group boxes are enabled or disabled depending on whether or not the group box is checked.<p>");
    QGroupBox::mouseMoveEvent(e);
}

mySplitter::mySplitter(QWidget * parent) : QSplitter(parent) {
    setMouseTracking(true);
}

void mySplitter::mouseMoveEvent(QMouseEvent *e) {
    emit info("<b>QSplitter</b><p>A splitter lets the user control the size of child widgets by dragging the boundary"
              "between them. Any number of widgets may be controlled by a single splitter. The typical use of a QSplitter"
              "is to create several widgets and add them using insertWidget() or addWidget()."
              "If a widget is already inside a QSplitter when insertWidget() or addWidget() is called, it will move to the new position."
              "This can be used to reorder widgets in the splitter later. You can use indexOf(), widget(), and count() to get access to the widgets inside the splitter."
              "A default QSplitter lays out its children horizontally (side by side); you can use setOrientation(Qt::Vertical) to lay its children out vertically.<p>");
    QSplitter::mouseMoveEvent(e);
}

mySplitterHandle::mySplitterHandle(Qt::Orientation f, QSplitter * e) : QSplitterHandle(f, e) {
    setMouseTracking(true);
}

void mySplitterHandle::mouseMoveEvent(QMouseEvent *e) {
    emit info("<b>QSplitterHandle</b><p>QSplitterHandle is typically what people think about when they think about a splitter."
              "It is the handle that is used to resize the widgets."
              "A typical developer using QSplitter will never have to worry about QSplitterHandle. "
              "It is provided for developers who want splitter handles that provide extra features, such as popup menus."
              "The typical way one would create splitter handles is to subclass QSplitter and then reimplement QSplitter::createHandle()"
              "to instantiate the custom splitter handle. <p>");
    QSplitterHandle::mouseMoveEvent(e);
}

myStackedWidget::myStackedWidget(QWidget * parent) : QStackedWidget(parent) {
    setMouseTracking(true);
}

void myStackedWidget::mouseMoveEvent(QMouseEvent *e) {
    emit info("<b>QStackedWidget</b><p>QStackedWidget can be used to create a user interface similar to the one provided by QTabWidget. "
              "It is a convenience layout widget built on top of the QStackedLayout class."
              "Like QStackedLayout, QStackedWidget can be constructed and populated with a number of child widgets"
              "QStackedWidget provides no intrinsic means for the user to switch page. This is typically done through a "
              "QComboBox or a QListWidget that stores the titles of the QStackedWidget's pages. <p>");
    QStackedWidget::mouseMoveEvent(e);
}
