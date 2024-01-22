#include "tab1.h"

myComboBox::myComboBox(QWidget * parent) : QComboBox(parent) {
    setMouseTracking(true);
}

void myComboBox::mouseMoveEvent(QMouseEvent *e) {
    emit info("<b>QComboBox</b><p>The QComboBox widget is a combined button and popup list."
              "A QComboBox provides a means of presenting a list of options to the user in a way that takes up the minimum amount of screen space."
              "A combobox is a selection widget that displays the current item, and can pop up a list of selectable items. A combobox may be editable,"
              "allowing the user to modify each item in the list."
              "Comboboxes can contain pixmaps as well as strings; the insertItem() and setItemText() functions are suitably overloaded. "
              "For editable comboboxes, the function clearEditText() is provided, to clear the displayed string without changing the combobox's contents.<p>");
    QComboBox::mouseMoveEvent(e);
}

myCheckBox::myCheckBox(const QString parent) : QCheckBox(parent) {
    setMouseTracking(true);
}

void myCheckBox::mouseMoveEvent(QMouseEvent *e) {
    emit info("<b>QCheckBox</b><p>The QCheckBox widget provides a checkbox with a text label."
              "A QCheckBox is an option button that can be switched on (checked) or off (unchecked). "
              "Checkboxes are typically used to represent features in an application that can be enabled or "
              "disabled without affecting others, but different types of behavior can be implemented. "
              "For example, a QButtonGroup can be used to group check buttons logically, allowing exclusive checkboxes. "
              "However, QButtonGroup does not provide any visual representation.<p>");
    QCheckBox::mouseMoveEvent(e);
}

myCommandLinkButton::myCommandLinkButton(QWidget * parent) : QCommandLinkButton(parent) {
    setMouseTracking(true);
}

void myCommandLinkButton::mouseMoveEvent(QMouseEvent *e) {
    emit info("<b>QCommandLinkButton</b><p>The command link is a new control that was introduced by Windows Vista. "
              "It's intended use is similar to that of a radio button in that it is used to choose between a set of mutually exclusive options."
              "Command link buttons should not be used by themselves but rather as an alternative to radio buttons in Wizards and dialogs "
              "and makes pressing the next button redundant. The appearance is generally similar to that of a flat pushbutton, but it allows "
              "for a descriptive text in addition to the normal button text. By default it will also carry an arrow icon, indicating that pressing "
              "the control will open another window or page.<p>");
    QCommandLinkButton::mouseMoveEvent(e);
}

myDateEdit::myDateEdit(QWidget * parent) : QDateEdit(parent) {
    setMouseTracking(true);
}

void myDateEdit::mouseMoveEvent(QMouseEvent *e) {
    emit info("<b>QDateEdit</b><p>The QDateEdit class provides a widget for editing dates based on the QDateTimeEdit widget."
              "Many of the properties and functions provided by QDateEdit are implemented in QDateTimeEdit:"
              "date holds the date displayed by the widget."
              "minimumDate defines the minimum (earliest) date that can be set by the user."
              "maximumDate defines the maximum (latest) date that can be set by the user."
              "displayFormat contains a string that is used to format the date displayed in the widget.<p>");
    QDateEdit::mouseMoveEvent(e);
}

myDateTimeEdit::myDateTimeEdit(QWidget * parent) : QDateTimeEdit(parent) {
    setMouseTracking(true);
}

void myDateTimeEdit::mouseMoveEvent(QMouseEvent *e) {
    emit info("<b>QDateTimeEdit</b><p>The QDateTimeEdit class provides a widget for editing dates and times."
              "QDateTimeEdit allows the user to edit dates by using the keyboard or the arrow keys to increase and decrease date and time values"
              "The arrow keys can be used to move from section to section within the QDateTimeEdit box. Dates and times appear in accordance with "
              "the format set; see setDisplayFormat().<p>");
    QDateTimeEdit::mouseMoveEvent(e);
}

myDial::myDial(QWidget * parent) : QDial(parent) {
    setMouseTracking(true);
}

void myDial::mouseMoveEvent(QMouseEvent *e) {
    emit info("<b>QDial</b><p>The QDial class provides a rounded range control (like a speedometer or potentiometer)."
              "QDial is used when the user needs to control a value within a program-definable range, and the range either wraps around (for example, "
              "with angles measured from 0 to 359 degrees) or the dialog layout needs a square widget."
              "Since QDial inherits from QAbstractSlider, the dial behaves in a similar way to a slider. When wrapping() is false (the default setting) "
              "there is no real difference between a slider and a dial. They both share the same signals, slots and member functions. Which one you use "
              "depends on the expectations of your users and on the type of application.<p>");
    QDial::mouseMoveEvent(e);
}

myDoubleSpinBox::myDoubleSpinBox(QWidget * parent) : QDoubleSpinBox(parent) {
    setMouseTracking(true);
}

void myDoubleSpinBox::mouseMoveEvent(QMouseEvent *e) {
    emit info("<b>QDoubleSpinBox</b><p>The QDoubleSpinBox class provides a spin box widget that takes doubles."
              "QDoubleSpinBox allows the user to choose a value by clicking the up and down buttons or by pressing Up or Down on "
              "the keyboard to increase or decrease the value currently displayed. The user can also type the value in manually. "
              "The spin box supports double values but can be extended to use different strings with validate(), textFromValue() and valueFromText().<p>");
    QDoubleSpinBox::mouseMoveEvent(e);
}

myFocusFrame::myFocusFrame(QWidget * parent) : QFocusFrame(parent) {
    setMouseTracking(true);
}

void myFocusFrame::mouseMoveEvent(QMouseEvent *e) {
    emit info("<b>QFocusFrame</b><p>The QFocusFrame widget provides a focus frame which can be outside of a widget's normal paintable area."
              "Normally an application will not need to create its own QFocusFrame as QStyle will handle this detail for you. A style writer can "
              "optionally use a QFocusFrame to have a focus area outside of the widget's paintable geometry."
              "In this way space need not be reserved for the widget to have focus but only set on a QWidget with QFocusFrame::setWidget. "
              "It is, however, legal to create your own QFocusFrame on a custom widget and set its geometry manually via QWidget::setGeometry "
              "however you will not get auto-placement when the focused widget changes size or placement.<p>");
    QFocusFrame::mouseMoveEvent(e);
}

myFontComboBox::myFontComboBox(QWidget * parent) : QFontComboBox(parent) {
    setMouseTracking(true);
}

void myFontComboBox::mouseMoveEvent(QMouseEvent *e) {
    emit info("<b>QFontComboBox</b><p>The QFontComboBox widget is a combobox that lets the user select a font family."
              "The combobox is populated with an alphabetized list of font family names, such as Arial, Helvetica, and Times New Roman. "
              "Family names are displayed using the actual font when possible."
              "For fonts such as Symbol, where the name is not representable in the font itself, a sample of the font is displayed next to the family name.<p>");
    QFontComboBox::mouseMoveEvent(e);
}

myLCDNumber::myLCDNumber(QWidget * parent) : QLCDNumber(parent) {
    setMouseTracking(true);
}

void myLCDNumber::mouseMoveEvent(QMouseEvent *e) {
    emit info("<b>QLCDNumber</b><p>The QLCDNumber widget displays a number with LCD-like digits."
              "It can display a number in just about any size. It can display decimal, hexadecimal, octal or binary numbers. "
              "It is easy to connect to data sources using the display() slot, which is overloaded to take any of five argument types."
              "There are also slots to change the base with setMode() and the decimal point with setSmallDecimalPoint().<p>");
    QLCDNumber::mouseMoveEvent(e);
}

myLabel::myLabel(QWidget * parent) : QLabel(parent) {
    setMouseTracking(true);
}

void myLabel::mouseMoveEvent(QMouseEvent *e) {
    emit info("<b>QLabel</b><p>The QLabel widget provides a text or image display."
              "QLabel is used for displaying text or an image. No user interaction functionality is provided. "
              "The visual appearance of the label can be configured in various ways, and it can be used for specifying a focus mnemonic key for another widget.<p>");
    QLabel::mouseMoveEvent(e);
}

myLineEdit::myLineEdit(QWidget * parent) : QLineEdit(parent) {
    setMouseTracking(true);
}

void myLineEdit::mouseMoveEvent(QMouseEvent *e) {
    emit info("<b>QLineEdit</b><p>The QLineEdit widget is a one-line text editor."
              "A line edit allows the user to enter and edit a single line of plain text with a useful collection of editing functions, "
              "including undo and redo, cut and paste, and drag and drop."
              "By changing the echoMode() of a line edit, it can also be used as a write-only field, for inputs such as passwords.<p>");
    QLineEdit::mouseMoveEvent(e);
}

myMenu::myMenu(QWidget * parent) : QMenu(parent) {
    setMouseTracking(true);
}

void myMenu::mouseMoveEvent(QMouseEvent *e) {
    emit info("<b>QMenu</b><p>The QMenu class provides a menu widget for use in menu bars, context menus, and other popup menus."
              "A menu widget is a selection menu. It can be either a pull-down menu in a menu bar or a standalone context menu"
              "Pull-down menus are shown by the menu bar when the user clicks on the respective item or presses the specified shortcut key. "
              "Use QMenuBar::addMenu() to insert a menu into a menu bar."
              "Context menus are usually invoked by some special keyboard key or by right-clicking. "
              "They can be executed either asynchronously with popup() or synchronously with exec(). "
              "Menus can also be invoked in response to button presses; these are just like context menus except for how they are invoked.<p>");
    QMenu::mouseMoveEvent(e);
}

myProgressBar::myProgressBar(QWidget * parent) : QProgressBar(parent) {
    setMouseTracking(true);
}

void myProgressBar::mouseMoveEvent(QMouseEvent *e) {
    emit info("<b>QProgressBar</b><p>The QProgressBar widget provides a horizontal or vertical progress bar."
              "A progress bar is used to give the user an indication of the progress of an operation and to reassure them that the application is still running."
              "The progress bar uses the concept of steps. You set it up by specifying the minimum and maximum possible step values, "
              "and it will display the percentage of steps that have been completed when you later give it the current step value. "
              "The percentage is calculated by dividing the progress (value() - minimum()) divided by maximum() - minimum().<p>");
    QProgressBar::mouseMoveEvent(e);
}

myPushButton::myPushButton(QWidget * parent) : QPushButton(parent) {
    setMouseTracking(true);
}

void myPushButton::mouseMoveEvent(QMouseEvent *e) {
    emit info("<b>QPushButton</b><p>The QPushButton widget provides a command button."
              "The push button, or command button, is perhaps the most commonly used widget in any graphical user interface."
              "Push (click) a button to command the computer to perform some action, or to answer a question. Typical buttons are OK, "
              "Apply, Cancel, Close, Yes, No and Help.<p>");
    QPushButton::mouseMoveEvent(e);
}

myRadioButton::myRadioButton(const QString parent) : QRadioButton(parent) {
    setMouseTracking(true);
}

void myRadioButton::mouseMoveEvent(QMouseEvent *e) {
    emit info("<b>QRadioButton</b><p>The QRadioButton widget provides a radio button with a text label."
              "A QRadioButton is an option button that can be switched on (checked) or off (unchecked). "
              "Radio buttons typically present the user with a one of many choice. "
              "In a group of radio buttons only one radio button at a time can be checked; if the user selects another button, "
              "the previously selected button is switched off.<p>");
    QRadioButton::mouseMoveEvent(e);
}

myScrollArea::myScrollArea(QWidget * parent) : QScrollArea(parent) {
    setMouseTracking(true);
}

void myScrollArea::mouseMoveEvent(QMouseEvent *e) {
    emit info("<b>QScrollArea</b><p>The QScrollArea class provides a scrolling view onto another widget."
              "A scroll area is used to display the contents of a child widget within a frame. If the widget exceeds the size of the frame, "
              "the view can provide scroll bars so that the entire area of the child widget can be viewed. The child widget must be specified with setWidget().<p>");
    QScrollArea::mouseMoveEvent(e);
}

myScrollBar::myScrollBar(QWidget * parent) : QScrollBar(parent) {
    setMouseTracking(true);
}

void myScrollBar::mouseMoveEvent(QMouseEvent *e) {
    emit info("<b>QScrollBar</b><p>The QScrollBar widget provides a vertical or horizontal scroll bar."
              "A scroll bar is a control that enables the user to access parts of a document that is larger than the widget used to display it. "
              "It provides a visual indication of the user's current position within the document and the amount of the document that is visible. "
              "Scroll bars are usually equipped with other controls that enable more accurate navigation. Qt displays scroll bars in a way that "
              "is appropriate for each platform.<p>");
    QScrollBar::mouseMoveEvent(e);
}

mySizeGrip::mySizeGrip(QWidget * parent) : QSizeGrip(parent) {
    setMouseTracking(true);
}

void mySizeGrip::mouseMoveEvent(QMouseEvent *e) {
    emit info("<b>QSizeGrip</b><p>The QSizeGrip class provides a resize handle for resizing top-level windows."
              "This widget works like the standard Windows resize handle. In the X11 version this resize handle generally works differently "
              "from the one provided by the system if the X11 window manager does not support necessary modern post-ICCCM specifications.<p>");
    QSizeGrip::mouseMoveEvent(e);
}

mySlider::mySlider(QWidget * parent) : QSlider(parent) {
    setMouseTracking(true);
}

void mySlider::mouseMoveEvent(QMouseEvent *e) {
    emit info("<b>QSlider</b><p>The QSlider widget provides a vertical or horizontal slider."
              "The slider is the classic widget for controlling a bounded value. It lets the user move a slider handle along a horizontal "
              "or vertical groove and translates the handle's position into an integer value within the legal range.<p>");
    QSlider::mouseMoveEvent(e);
}


mySpinBox::mySpinBox(QWidget * parent) : QSpinBox(parent) {
    setMouseTracking(true);
}

void mySpinBox::mouseMoveEvent(QMouseEvent *e) {
    emit info("<b>QSpinBox</b><p>The QSpinBox class provides a spin box widget."
              "QSpinBox is designed to handle integers and discrete sets of values (e.g., month names); use QDoubleSpinBox for floating point values."
              "QSpinBox allows the user to choose a value by clicking the up/down buttons or pressing up/down on the keyboard to increase/decrease the value currently displayed."
              "The user can also type the value in manually. The spin box supports integer values but can be extended to use different strings with validate(), textFromValue() and valueFromText().<p>");
    QSpinBox::mouseMoveEvent(e);
}

myTabBar::myTabBar(QWidget * parent) : QTabBar(parent) {
    setMouseTracking(true);
}

void myTabBar::mouseMoveEvent(QMouseEvent *e) {
    emit info("<b>QTabBar</b><p>The QTabBar class provides a tab bar, e.g. for use in tabbed dialogs."
              "QTabBar is straightforward to use; it draws the tabs using one of the predefined shapes, and emits a signal when a tab is selected."
              "It can be subclassed to tailor the look and feel. Qt also provides a ready-made QTabWidget.<p>");
    QTabBar::mouseMoveEvent(e);
}

myTabWidget::myTabWidget(QWidget * parent) : QTabWidget(parent) {
    setMouseTracking(true);
}

void myTabWidget::mouseMoveEvent(QMouseEvent *e) {
    emit info("<b>QTabWidget</b><p>The QTabWidget class provides a stack of tabbed widgets."
              "A tab widget provides a tab bar (see QTabBar) and a page area that is used to display pages related to each tab. By default, the tab bar is shown above the page area,"
              "but different configurations are available (see TabPosition). Each tab is associated with a different widget (called a page)."
              "Only the current page is shown in the page area; all the other pages are hidden. The user can show a different page by clicking on its tab or by pressing its Alt+letter shortcut if it has one.<p>");
    QTabWidget::mouseMoveEvent(e);
}

myTimeEdit::myTimeEdit(QWidget * parent) : QTimeEdit(parent) {
    setMouseTracking(true);
}

void myTimeEdit::mouseMoveEvent(QMouseEvent *e) {
    emit info("<b>QTimeEdit</b><p>The QTimeEdit class provides a widget for editing times based on the QDateTimeEdit widget."
              "Many of the properties and functions provided by QTimeEdit are implemented in QDateTimeEdit. <p>");
    QTimeEdit::mouseMoveEvent(e);
}

myToolBox::myToolBox(QWidget * parent, Qt::WindowFlags f) : QToolBox(parent, f) {
    setMouseTracking(true);
}

void myToolBox::mouseMoveEvent(QMouseEvent *e) {
    emit info("<b>QToolBox</b><p>The QToolBox class provides a column of tabbed widget items."
              "A toolbox is a widget that displays a column of tabs one above the other, with the current item displayed below the current tab."
              "Every tab has an index position within the column of tabs. A tab's item is a QWidget.<p>");
    QToolBox::mouseMoveEvent(e);
}

myWidget::myWidget(QWidget * parent) : QWidget(parent) {
    setMouseTracking(true);
}

void myWidget::mouseMoveEvent(QMouseEvent *e) {
    emit info("<b>QWidget</b><p>The QWidget class is the base class of all user interface objects."
              "The widget is the atom of the user interface: it receives mouse, keyboard and other events from the window system,"
              "and paints a representation of itself on the screen. Every widget is rectangular, and they are sorted in a Z-order."
              "A widget is clipped by its parent and by the widgets in front of it.<p>");
    QWidget::mouseMoveEvent(e);
}
