#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QMainWindow>
#include <QTextEdit>
#include <QMenu>
#include <QMenuBar>
#include <QColorDialog>
#include <QFontDialog>
#include <QInputDialog>
#include <QFileDialog>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QFile>

class TextEditor : public QMainWindow {
    Q_OBJECT

public:
    TextEditor(QWidget *parent = nullptr);

private slots:
    // Слоты для обработки событий
    void changeFontSize();
    void changeFontColor();
    void changeBackgroundColor();
    void saveSettings();
    void loadSettings();

private:
    // Методы для создания интерфейса и обработки событий
    void createActions();
    void createMenus();
    void writeSettings(QXmlStreamWriter &xml);
    void readSettings(QXmlStreamReader &xml);

    // Область редактирования текста
    QTextEdit *textEdit;

    // Меню и действия
    QMenu *fileMenu;
    QMenu *formatMenu;
    QAction *fontSizeAction;
    QAction *fontColorAction;
    QAction *bgColorAction;
    QAction *saveSettingsAction;
    QAction *loadSettingsAction;
};

#endif // TEXTEDITOR_H
