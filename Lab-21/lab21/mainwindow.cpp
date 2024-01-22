#include "mainwindow.h"
#include "tab1.h"
#include "tab2.h"
#include "tab3.h"

#include <QTabWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QMouseEvent>
#include <QFileSystemModel>

Widget::Widget(QWidget *p) : QWidget(p)
{
    QHBoxLayout *l = new QHBoxLayout(this);
    QTabWidget * tab = new QTabWidget(this);
    tab -> setMinimumSize(600, 800);
    l -> addWidget(tab);

    QWidget *tab1 = new QWidget(tab);
    tab->addTab(tab1, "&Basic Widgets");
    QVBoxLayout * lt1 = new QVBoxLayout(tab1);

    myComboBox * combo = new myComboBox(tab1);
    connect(combo, SIGNAL(info(QString)), this, SLOT(changeInfo(QString)));
    lt1 -> addWidget(combo);

    myCheckBox * check = new myCheckBox("&MYCheckBox");
    connect(check, SIGNAL(info(QString)), this, SLOT(changeInfo(QString)));
    lt1 -> addWidget(check);

    myCommandLinkButton * command = new myCommandLinkButton(tab1);
    connect(command, SIGNAL(info(QString)), this, SLOT(changeInfo(QString)));
    lt1 -> addWidget(command);

    myDateEdit * edit = new myDateEdit(tab1);
    connect(edit, SIGNAL(info(QString)), this, SLOT(changeInfo(QString)));
    lt1 -> addWidget(edit);

    myDateTimeEdit * edit_t = new myDateTimeEdit(tab1);
    connect(edit_t, SIGNAL(info(QString)), this, SLOT(changeInfo(QString)));
    lt1 -> addWidget(edit_t);

    myDial * dial = new myDial(tab1);
    connect(dial, SIGNAL(info(QString)), this, SLOT(changeInfo(QString)));
    lt1 -> addWidget(dial);

    myDoubleSpinBox * spin = new myDoubleSpinBox(tab1);
    connect(spin, SIGNAL(info(QString)), this, SLOT(changeInfo(QString)));
    lt1 -> addWidget(spin);

    myFocusFrame * focus_frame = new myFocusFrame(tab1);
    connect(focus_frame, SIGNAL(info(QString)), this, SLOT(changeInfo(QString)));
    lt1 -> addWidget(focus_frame);

    myFontComboBox * font_combo = new myFontComboBox(tab1);
    connect(font_combo, SIGNAL(info(QString)), this, SLOT(changeInfo(QString)));
    lt1 -> addWidget(font_combo);

    myLCDNumber * number = new myLCDNumber(tab1);
    connect(number, SIGNAL(info(QString)), this, SLOT(changeInfo(QString)));
    lt1 -> addWidget(number);

    myLabel * label = new myLabel(tab1);
    connect(label, SIGNAL(info(QString)), this, SLOT(changeInfo(QString)));
    lt1 -> addWidget(label);

    myLineEdit * line_edit = new myLineEdit(tab1);
    connect(line_edit, SIGNAL(info(QString)), this, SLOT(changeInfo(QString)));
    lt1 -> addWidget(line_edit);

    myMenu * menu = new myMenu(tab1);
    connect(menu, SIGNAL(info(QString)), this, SLOT(changeInfo(QString)));
    lt1 -> addWidget(menu);

    myProgressBar * progress = new myProgressBar(tab1);
    connect(progress, SIGNAL(info(QString)), this, SLOT(changeInfo(QString)));
    lt1 -> addWidget(progress);

    myPushButton * push_btn = new myPushButton(tab1);
    connect(push_btn, SIGNAL(info(QString)), this, SLOT(changeInfo(QString)));
    lt1 -> addWidget(push_btn);

    myRadioButton * radio_btn = new myRadioButton("&Radio button");
    connect(radio_btn, SIGNAL(info(QString)), this, SLOT(changeInfo(QString)));
    lt1 -> addWidget(radio_btn);

    myScrollArea * scroll = new myScrollArea(tab1);
    connect(scroll, SIGNAL(info(QString)), this, SLOT(changeInfo(QString)));
    QLabel *text1_1 = new QLabel;
    text1_1 -> setText("Some text about Page"
                       "Some text about Page"
                       "Some text about Page"
                       "Some text about Page"
                       "Some text about Page"
                       "Some text about Page"
                       "Some text about Page"
                       "Some text about Page"
                       "Some text about Page"
                       "Some text about Page"
                       "Some text about Page");
    scroll->setWidget(text1_1);
    lt1 -> addWidget(scroll);

    myScrollBar * scroll_b = new myScrollBar(tab1);
    connect(scroll_b, SIGNAL(info(QString)), this, SLOT(changeInfo(QString)));
    lt1 -> addWidget(scroll_b);

    mySizeGrip * size_grip = new mySizeGrip(tab1);
    connect(size_grip, SIGNAL(info(QString)), this, SLOT(changeInfo(QString)));
    lt1 -> addWidget(size_grip);

    mySlider * slider = new mySlider(tab1);
    connect(slider, SIGNAL(info(QString)), this, SLOT(changeInfo(QString)));
    lt1 -> addWidget(slider);

    mySpinBox * spin_box = new mySpinBox(tab1);
    connect(spin_box, SIGNAL(info(QString)), this, SLOT(changeInfo(QString)));
    lt1 -> addWidget(spin_box);

    myTabBar * tab_bar = new myTabBar(tab1);
    connect(tab_bar, SIGNAL(info(QString)), this, SLOT(changeInfo(QString)));
    lt1 -> addWidget(tab_bar);

    myTabWidget * tab_widget = new myTabWidget(tab1);
    connect(tab_widget, SIGNAL(info(QString)), this, SLOT(changeInfo(QString)));
    QWidget *widget_on_tab_1_1 = new QWidget;
    QWidget *widget_on_tab_2_1 = new QWidget;
    QLabel *text_on_page_1_1 = new QLabel(widget_on_tab_1_1);
    QLabel *text_on_page_2_1 = new QLabel(widget_on_tab_2_1);
    text_on_page_1_1 -> setText("Some text about Page 1");
    text_on_page_2_1 -> setText("Some text about Page 2");
    tab_widget -> addTab(widget_on_tab_1_1, "Page 1");
    tab_widget -> addTab(widget_on_tab_2_1, "Page 2");
    lt1 -> addWidget(tab_widget);

    myTimeEdit * time_edit = new myTimeEdit(tab1);
    connect(time_edit, SIGNAL(info(QString)), this, SLOT(changeInfo(QString)));
    lt1 -> addWidget(time_edit);

    myToolBox * tool_box = new myToolBox(tab1);
    connect(tool_box, SIGNAL(info(QString)), this, SLOT(changeInfo(QString)));
    lt1 -> addWidget(tool_box);

    myWidget * widget = new myWidget(tab1);
    connect(widget, SIGNAL(info(QString)), this, SLOT(changeInfo(QString)));
    lt1 -> addWidget(widget);


    QWidget *tab2 = new QWidget(tab);
    tab->addTab(tab2, "&Advanced Widgets");
    QVBoxLayout * lt2 = new QVBoxLayout(tab2);
    QFileSystemModel *model = new QFileSystemModel;
    model->setRootPath(QDir::rootPath());

    myCalendarWidget * calendar_widget = new myCalendarWidget(tab2);
    connect(calendar_widget, SIGNAL(info(QString)), this, SLOT(changeInfo(QString)));
    lt2 -> addWidget(calendar_widget);

    myColumnView * col_view = new myColumnView(tab2);
    connect(col_view, SIGNAL(info(QString)), this, SLOT(changeInfo(QString)));
    col_view->setModel(model);
    lt2 -> addWidget(col_view);

    myListView * list_view = new myListView(tab2);
    connect(list_view, SIGNAL(info(QString)), this, SLOT(changeInfo(QString)));
    list_view->setModel(model);
    lt2 -> addWidget(list_view);

    myTableView * table_view = new myTableView(tab2);
    myTreeView * tree_view = new myTreeView(tab2);
    connect(tree_view, SIGNAL(info(QString)), this, SLOT(changeInfo(QString)));
    connect(table_view, SIGNAL(info(QString)), this, SLOT(changeInfo(QString)));
    table_view->setModel(model);
    tree_view->setModel(model);
    lt2->addWidget(table_view);
    lt2->addWidget(tree_view);

    myUndoView * undo_view = new myUndoView(tab2);
    connect(undo_view, SIGNAL(info(QString)), this, SLOT(changeInfo(QString)));
    undo_view->setModel(model);
    lt2 -> addWidget(undo_view);


    QWidget *tab3 = new QWidget(tab);
    tab->addTab(tab3, "&Organizer Widgets");
    QVBoxLayout * lt3 = new QVBoxLayout(tab3);

    myGroupBox * group_box = new myGroupBox("Group Radio button Box");
    connect(group_box, SIGNAL(info(QString)), this, SLOT(changeInfo(QString)));
    myRadioButton * rad_btn_1 = new myRadioButton(tr("Radio button_1"));
    myRadioButton * rad_btn_2 = new myRadioButton(tr("Radio button_2"));
    QHBoxLayout *lv3 = new QHBoxLayout();
    lv3->addWidget(rad_btn_1);
    lv3->addWidget(rad_btn_2);
    group_box->setLayout(lv3);
    lt3 -> addWidget(group_box);

    mySplitter * splitter = new mySplitter(tab3);
    connect(splitter, SIGNAL(info(QString)), this, SLOT(changeInfo(QString)));
    myTableView * t_v = new  myTableView;
    myTreeView * tr_v = new myTreeView;
    t_v -> setModel(model);
    tr_v -> setModel(model);
    splitter -> addWidget(t_v);
    splitter -> addWidget(tr_v);
    lt3 -> addWidget(splitter);

    mySplitter * sp = new mySplitter;
    mySplitterHandle * splitter_h = new mySplitterHandle(Qt::Orientation::Vertical, sp);
    connect(splitter_h, SIGNAL(info(QString)), this, SLOT(changeInfo(QString)));
    lt3 -> addWidget(splitter_h);

    myTabWidget * tab_widget_2 = new myTabWidget(tab3);
    QWidget *widget_on_tab_1 = new QWidget;
    QWidget *widget_on_tab_2 = new QWidget;
    QLabel *text_on_page_1 = new QLabel(widget_on_tab_1);
    QLabel *text_on_page_2 = new QLabel(widget_on_tab_2);
    text_on_page_1 -> setText("Some text about Page 1");
    text_on_page_2 -> setText("Some text about Page 2");
    tab_widget_2 -> addTab(widget_on_tab_1, "Page 1");
    tab_widget_2 -> addTab(widget_on_tab_2, "Page 2");
    connect(tab_widget_2, SIGNAL(info(QString)), this, SLOT(changeInfo(QString)));
    lt3 -> addWidget(tab_widget_2);

    myGroupBox *groupBox_0 = new myGroupBox("Radio Buttons");
    myRadioButton *radioBtn_0 = new myRadioButton("&Radio Button 1");
    myRadioButton *radioBtn_1 = new myRadioButton("R&adio Button 2");
    myRadioButton *radioBtn_2 = new myRadioButton("Ra&dio Button 3");
    QVBoxLayout *vLayout_0 = new QVBoxLayout;
    vLayout_0->addWidget(radioBtn_0);
    vLayout_0->addWidget(radioBtn_1);
    vLayout_0->addWidget(radioBtn_2);
    groupBox_0->setLayout(vLayout_0);

    myGroupBox *groupBox_1 = new myGroupBox("Checkboxes");
    myCheckBox *checkBox_0 = new myCheckBox("&Checkbox 1");
    myCheckBox *checkBox_1 = new myCheckBox("C&heckbox 2");
    myCheckBox *checkBox_2 = new myCheckBox("Tr&istate button");
    checkBox_2->setTristate(true);
    QVBoxLayout *vLayout_1 = new QVBoxLayout;
    vLayout_1->addWidget(checkBox_0);
    vLayout_1->addWidget(checkBox_1);
    vLayout_1->addWidget(checkBox_2);
    groupBox_1->setLayout(vLayout_1);

    myComboBox *pageComboBox = new myComboBox(tab3);
    pageComboBox->addItem(tr("Page 1"));
    pageComboBox->addItem(tr("Page 2"));

    myStackedWidget * stacked_widget = new myStackedWidget(tab3);
    myStackedWidget * stacked_widget_2 = new myStackedWidget(tab3);

    stacked_widget->addWidget(groupBox_0);
    stacked_widget->addWidget(groupBox_1);

    lt3->addWidget(pageComboBox);
    lt3->addWidget(stacked_widget);
    lt3->addWidget(stacked_widget_2);
    connect(stacked_widget_2, SIGNAL(info(QString)), this, SLOT(changeInfo(QString)));
    connect(pageComboBox, SIGNAL(activated(int)), stacked_widget, SLOT(setCurrentIndex(int)));

    frame = new QFrame(this);
    frame -> setFrameShape(QFrame::Box);
    frame -> setMinimumSize(200, 600);
    l -> addWidget(frame);

    frame_text = new QLabel(frame);
    frame_text -> setMinimumSize(200, 600);
    frame_text -> setWordWrap(true);
    frame_text -> setText("<h1>Widget description");
}

void Widget::changeInfo(QString s) {
    frame_text -> setText(s);
}


