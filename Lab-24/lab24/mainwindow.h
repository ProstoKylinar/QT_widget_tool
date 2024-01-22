#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QFileDialog>
#include <QMessageBox>
#include <QLabel>
#include <QPixmap>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTcpServer>
#include <QTcpSocket>
#include <QFile>
#include <QString>

const QString SERVER = "Сервер";
const QString SERVER_RUN = "Сервер запущен";
const QString SERVER_STOP = "Сервер остановлен";
const QString SERVER_ERROR_TITLE = "Ошибка сервера";
const QString SERVER_ERROR_RUN = "Сервер уже запущен";
const QString SERVER_ERROR_UNABLE = "Сейчас невозможно запустить сервер, проверьте, доступен ли порт 3000";
const QString SERVER_ERROR_STOP = "Сервер не запущен";
const QString CHOOSE_PIC = "Выберите картинку";
const QString SERVER_AUTHOR = "О программе";

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QLabel* label_of_image;
    QString path_to_image;
    QTcpServer* server;
public:
    MainWindow(QWidget* parent = nullptr);
private slots:
    void start_server();
    void stop_server();
    void open_image();
    void create_server();
    void destroy_server();
    void connection();
    void read_image();
    void http_resp(QTcpSocket* clientConnection);
    void create_menu();
    void show_author();
};



#endif // MAINWINDOW_H
