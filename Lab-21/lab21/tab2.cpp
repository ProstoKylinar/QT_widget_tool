#include "tab2.h"

myCalendarWidget::myCalendarWidget(QWidget * parent) : QCalendarWidget(parent) {
    setMouseTracking(true);
}

void myCalendarWidget::mouseMoveEvent(QMouseEvent *e) {
    emit info("<b>QCalendarWidget</b><p>The widget is initialized with the current month and year, but "
              "QCalendarWidget provides several public slots to change the year and month that is shown."
              "By default, today's date is selected, and the user can select a date using both mouse and keyboard."
              "The currently selected date can be retrieved using the selectedDate() function. It is possible to constrain "
              "the user selection to a given date range by setting the minimumDate and maximumDate properties. Alternatively, "
              "both properties can be set in one go using the setDateRange() convenience slot. Set the selectionMode property "
              "to NoSelection to prohibit the user from selecting at all. Note that a date also can be selected programmatically using the setSelectedDate() slot.<p>");
    QCalendarWidget::mouseMoveEvent(e);
}

myColumnView::myColumnView(QWidget * parent) : QColumnView(parent) {
    setMouseTracking(true);
}

void myColumnView::mouseMoveEvent(QMouseEvent *e) {
    emit info("<b>QColumnView</b><p>QColumnView displays a model in a number of QListViews, "
              "one for each hierarchy in the tree. This is sometimes referred to as a cascading list."
              "The QColumnView class is one of the Model/View Classes and is part of Qt's model/view framework."
              "QColumnView implements the interfaces defined by the QAbstractItemView class to allow it to display "
              "data provided by models derived from the QAbstractItemModel class.<p>");
    QColumnView::mouseMoveEvent(e);
}

myListView::myListView(QWidget * parent) : QListView(parent) {
    setMouseTracking(true);
}

void myListView::mouseMoveEvent(QMouseEvent *e) {
    emit info("<b>QListView</b><p>A QListView presents items stored in a model, either as a simple non-hierarchical list, "
              "or as a collection of icons. This class is used to provide lists and icon views that were previously provided "
              "by the QListBox and QIconView classes, but using the more flexible approach provided by Qt's model/view architecture."
              "The QListView class is one of the Model/View Classes and is part of Qt's model/view framework."
              "This view does not display horizontal or vertical headers; to display a list of items with a horizontal header, use QTreeView instead."
              "QListView implements the interfaces defined by the QAbstractItemView class to allow it to display data provided by models derived "
              "from the QAbstractItemModel class.<p>");
    QListView::mouseMoveEvent(e);
}

myTableView::myTableView(QWidget * parent) : QTableView(parent) {
    setMouseTracking(true);
}

void myTableView::mouseMoveEvent(QMouseEvent *e) {
    emit info("<b>QTableView</b><p>A QTableView implements a table view that displays items from a model."
              "This class is used to provide standard tables that were previously provided by the QTable class, but using the "
              "more flexible approach provided by Qt's model/view architecture."
              "The QTableView class is one of the Model/View Classes and is part of Qt's model/view framework."
              "QTableView implements the interfaces defined by the QAbstractItemView class to allow it to display "
              "data provided by models derived from the QAbstractItemModel class.<p>");
    QTableView::mouseMoveEvent(e);
}

myTreeView::myTreeView(QWidget * parent) : QTreeView(parent) {
    setMouseTracking(true);
}

void myTreeView::mouseMoveEvent(QMouseEvent *e) {
    emit info("<b>QTreeView</b><p>A QTreeView implements a tree representation of items from a model. "
              "This class is used to provide standard hierarchical lists that were previously provided"
              " by the QListView class, but using the more flexible approach provided by Qt's model/view architecture."
              "The QTreeView class is one of the Model/View Classes and is part of Qt's model/view framework."
              "QTreeView implements the interfaces defined by the QAbstractItemView class to allow it to display "
              "data provided by models derived from the QAbstractItemModel class.<p>");
    QTreeView::mouseMoveEvent(e);
}

myUndoView::myUndoView(QWidget * parent) : QUndoView(parent) {
    setMouseTracking(true);
}

void myUndoView::mouseMoveEvent(QMouseEvent *e) {
    emit info("<b>QUndoView</b><p>QUndoView is a QListView which displays the list of commands pushed on "
              "an undo stack. The most recently executed command is always selected. Selecting a different command "
              "results in a call to QUndoStack::setIndex(), rolling the state of the document backwards or forward to the new command."
              "The stack can be set explicitly with setStack(). Alternatively, a QUndoGroup object can be set with setGroup()."
              "The view will then update itself automatically whenever the active stack of the group changes.<p>");
    QUndoView::mouseMoveEvent(e);
}
