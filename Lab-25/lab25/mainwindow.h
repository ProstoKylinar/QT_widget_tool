#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QProcess>
#include <QStandardPaths>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void scan();

private:
    QLineEdit *addressLineEdit;
    QPushButton *scanButton;
    QTextEdit *resultTextEdit;
    QString findNmapPath();
};
#endif // MAINWINDOW_H
