#include "mainwindow.h"

// в конструкторе создаем меню, добавляем layout под картинку, создаем сервер с хостом 3000
MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), label_of_image(new QLabel(this)), server(nullptr)
{
    create_menu();
    this->setFixedSize(1080, 600);
    label_of_image->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    label_of_image->setScaledContents(true);
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(label_of_image);
    QWidget* center = new QWidget(this);
    center->setLayout(layout);
    setCentralWidget(center);
    create_server();
    server->listen(QHostAddress::Any, 3000);
}

// отдельная функция по созданию сервера и соединению его со слотом connection()
void MainWindow::create_server()
{
    server = new QTcpServer(this);
    connect(server, &QTcpServer::newConnection, this, &MainWindow::connection);
}

// отдельная функция по удалению сервера
void MainWindow::destroy_server() {
    server->close();
    delete server;
    server = nullptr;
}

// запуск ранее не запущенного сервера
void MainWindow::start_server()
{
    if (!server)
    {
        create_server();
        if (server->listen(QHostAddress::Any, 3000)) QMessageBox::information(this, SERVER, SERVER_RUN);
        else
        {
            QMessageBox::warning(this, SERVER_ERROR_TITLE, SERVER_ERROR_UNABLE);
            destroy_server();
        }
    }
    else QMessageBox::warning(this, SERVER_ERROR_TITLE, SERVER_ERROR_RUN);
}

// остановка запущенного сервера
void MainWindow::stop_server()
{
    if (server)
    {
        destroy_server();
        QMessageBox::information(this, SERVER, SERVER_STOP);
    }
    else QMessageBox::warning(this, SERVER_ERROR_TITLE, SERVER_ERROR_STOP);
}

// открытие изображения
void MainWindow::open_image()
{
    // если сервер не запущен, выходим из функции, откидывая предупреждение
    if (!server) {
        QMessageBox::warning(this, SERVER_ERROR_TITLE, SERVER_ERROR_STOP);
        return;
    }
    // предоставления диалогового окна для выбора картинки и ее открытие
    QString path_to_file = QFileDialog::getOpenFileName(this, CHOOSE_PIC, QDir::homePath(), "Только форматы (*.png *.jpg *.bmp)");
    if (!path_to_file.isEmpty())
    {
        QPixmap image(path_to_file);
        label_of_image->setPixmap(image);
        int width = size().width() * 2 / 3;
        int height = size().height() * 2 / 3;
        label_of_image->setFixedSize(width, height);
    }
}

// обнаружение нового подключения
void MainWindow::connection()
{
    QTcpSocket* sock = server->nextPendingConnection();
    // если обнаружилось, устанавливаются соединения для обработки чтения и отключения
    if (sock)
    {
        connect(sock, &QTcpSocket::readyRead, this, &MainWindow::read_image);
        connect(sock, &QTcpSocket::disconnected, sock, &QTcpSocket::deleteLater);
    }
}

// чтение картинки, вызывается при готовности сокета к чтению
void MainWindow::read_image()
{
    QTcpSocket* sock = qobject_cast<QTcpSocket*>(sender());
    if (sock && sock->canReadLine())
    {
        QByteArray requestData = sock->readAll();
        if (requestData.startsWith("GET /")) http_resp(sock);
    }
}

// отправка ответа с изображением
void MainWindow::http_resp(QTcpSocket* sock)
{
    // формирование http ответа со следующими заголовками
    QByteArray response;
    response.append("HTTP/1.1 200 OK\r\n");
    response.append("Content-Type: image\r\n");
    response.append("\r\n");
    QFile image_file(path_to_image);
    if (image_file.open(QIODevice::ReadOnly))
    {
        // изображение считывается и добавляется к ответу
        response.append(image_file.readAll());
        image_file.close();
        // Записываем ответ в сокет
        if (sock->write(response) != -1)
        {
            // Открываем новое изображение только после успешной записи ответа
            QString path_to_file = QFileDialog::getOpenFileName(this, CHOOSE_PIC, QDir::homePath(), "Только форматы (*.png *.jpg *.bmp)");

            if (!path_to_file.isEmpty())
            {
                QPixmap image(path_to_file);
                label_of_image->setPixmap(image);

                int width = size().width() * 2 / 3;
                int height = size().height() * 2 / 3;
                label_of_image->setFixedSize(width, height);
            }
        }
    }

    sock->disconnectFromHost();
}

// создание меню со всеми необходимыми пунктами и привязываем к слотам
void MainWindow::create_menu()
{
    QMenu* fileMenu = menuBar()->addMenu("Файл");
    QMenu* helpMenu = menuBar()->addMenu("Помощь");
    QAction* start_Action = new QAction("Запустить сервер", this);
    QAction* stop_Action = new QAction("Остановить сервер", this);
    QAction* open_Action = new QAction("Открыть изображение", this);
    QAction* exit_Action = new QAction("Выход", this);
    QAction* author_Action = new QAction("О программе", this);

    connect(start_Action, &QAction::triggered, this, &MainWindow::start_server);
    fileMenu->addAction(start_Action);
    connect(stop_Action, &QAction::triggered, this, &MainWindow::stop_server);
    fileMenu->addAction(stop_Action);
    connect(open_Action, &QAction::triggered, this, &MainWindow::open_image);
    fileMenu->addAction(open_Action);
    connect(exit_Action, &QAction::triggered, qApp, &QApplication::quit);
    fileMenu->addAction(exit_Action);
    connect(author_Action, &QAction::triggered, this, &MainWindow::show_author);
    helpMenu->addAction(author_Action);
}

// слот для открытия сведений о программе
void MainWindow::show_author()
{
    QString aboutText = "Автор программы: Демешко Дмитрий\nEmail: dodemeshko@edu.hse.ru\nВерсия библиотеки QT: ";
    aboutText += QString(QT_VERSION_STR);

    QMessageBox::about(this, SERVER_AUTHOR, aboutText);
}


