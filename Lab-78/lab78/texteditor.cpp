#include "texteditor.h"

TextEditor::TextEditor(QWidget *parent)    : QMainWindow(parent) {
    // Создание области редактирования текста и установка ее в качестве центрального виджета
    textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);
    // Создание действий и меню
    createActions();
    createMenus();
}

void TextEditor::createActions() {
    // Создание действий для изменения размера шрифта, цвета шрифта, цвета фона и сохранения/загрузки настроек
    fontSizeAction = new QAction("Change Font Size", this);
    connect(fontSizeAction, &QAction::triggered, this, &TextEditor::changeFontSize);
    fontColorAction = new QAction("Change Font Color", this);
    connect(fontColorAction, &QAction::triggered, this, &TextEditor::changeFontColor);
    bgColorAction = new QAction("Change Background Color", this);
    connect(bgColorAction, &QAction::triggered, this, &TextEditor::changeBackgroundColor);
    saveSettingsAction = new QAction("Save Settings", this);
    connect(saveSettingsAction, &QAction::triggered, this, &TextEditor::saveSettings);
    loadSettingsAction = new QAction("Load Settings", this);
    connect(loadSettingsAction, &QAction::triggered, this, &TextEditor::loadSettings);
}

void TextEditor::createMenus() {
    // Создание меню "File" и "Format" и добавление действий в меню
    fileMenu = menuBar()->addMenu("File");
    fileMenu->addAction(saveSettingsAction);
    fileMenu->addAction(loadSettingsAction);
    formatMenu = menuBar()->addMenu("Format");
    formatMenu->addAction(fontSizeAction);
    formatMenu->addAction(fontColorAction);
    formatMenu->addAction(bgColorAction);
}

void TextEditor::changeFontSize() {
    // Изменение размера шрифта с использованием диалогового окна
    bool ok;
    int newSize = QInputDialog::getInt(this, "Change Font Size", "Enter Font Size:", textEdit->font().pointSize(), 1, 100, 1, &ok);
    if (ok) {
        QFont font = textEdit->font();
        font.setPointSize(newSize);
        textEdit->setFont(font);    }
}

void TextEditor::changeFontColor() {
    // Изменение цвета шрифта с использованием диалогового окна
    QColor color = QColorDialog::getColor(textEdit->textColor(), this, "Choose Font Color");
    if (color.isValid()) {
        textEdit->setTextColor(color);
    }
}

void TextEditor::changeBackgroundColor() {
    // Изменение цвета фона с использованием диалогового окна
    QColor color = QColorDialog::getColor(textEdit->textBackgroundColor(), this, "Choose Background Color");
    if (color.isValid()) {
        textEdit->setTextBackgroundColor(color);
    }
}

void TextEditor::saveSettings() {
    // Сохранение настроек в файл формата XML
    QString fileName = QFileDialog::getSaveFileName(this, "Save Settings", "", "XML Files (*.xml)");
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QXmlStreamWriter xml(&file);
            xml.setAutoFormatting(true);
            xml.writeStartDocument();
            xml.writeStartElement("Settings");
            writeSettings(xml);
            xml.writeEndElement();
            xml.writeEndDocument();
            file.close();
        }
    }
}

void TextEditor::loadSettings() {
    // Загрузка настроек из файла формата XML
    QString fileName = QFileDialog::getOpenFileName(this, "Load Settings", "", "XML Files (*.xml)");
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QXmlStreamReader xml(&file);
            while (!xml.atEnd()) {
                xml.readNext();
                if (xml.isStartElement() && xml.name() == "Settings") {
                    readSettings(xml);
                }
            }
            file.close();
        }
    }
}

void TextEditor::writeSettings(QXmlStreamWriter &xml) {
    // Запись настроек в XML
    xml.writeTextElement("FontSize", QString::number(textEdit->font().pointSize()));
    xml.writeTextElement("FontColor", textEdit->textColor().name());
    xml.writeTextElement("BgColor", textEdit->textBackgroundColor().name());
}

void TextEditor::readSettings(QXmlStreamReader &xml) {
    // Чтение настроек из XML
    while (!xml.atEnd()) {
        xml.readNext();
        if (xml.isStartElement()) {
            if (xml.name() == "FontSize") {
                bool ok;
                int fontSize = xml.readElementText().toInt(&ok);
                if (ok) {
                    QFont font = textEdit->font();
                    font.setPointSize(fontSize);
                    textEdit->setFont(font);
                }
            } else if (xml.name() == "FontColor") {
                QColor fontColor = QColor(xml.readElementText());
                textEdit->setTextColor(fontColor);
            } else if (xml.name() == "BgColor") {
                QColor bgColor = QColor(xml.readElementText());
                textEdit->setTextBackgroundColor(bgColor);
            }

        }
    }
}
