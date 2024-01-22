#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    system("openssl genpkey -algorithm gost2012_256 -pkeyopt paramset:A -out private.key");
    std::fstream key("private.key");
    std::string line1;
    std::string line2;
    std::getline(key, line1);
    std::getline(key, line1);
    std::getline(key, line2);
    key.close();
    std::string *line = new std::string;
    *line = line1 + line2;
    QString str = QString::fromStdString(*line);
    ui->label->setText(str);
    delete line;
}
