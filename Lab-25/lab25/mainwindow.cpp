#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    addressLineEdit = new QLineEdit(this);
    scanButton = new QPushButton("Scan", this);
    resultTextEdit = new QTextEdit(this);
    resultTextEdit->setReadOnly(true);

    connect(scanButton, &QPushButton::clicked, this, &MainWindow::scan);

    QHBoxLayout *layout = new QHBoxLayout;

    layout->addWidget(addressLineEdit);
    layout->addWidget(scanButton);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layout);
    mainLayout->addWidget(resultTextEdit);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{
}

// поиск пути до nmap в системе
QString MainWindow::findNmapPath()
{
    QString possiblePaths = QStandardPaths::findExecutable("nmap");
    if (!possiblePaths.isEmpty())
        return possiblePaths;

    return "";
}

void MainWindow::scan()
{
    resultTextEdit->clear();

    // проверка, доступен ли nmap
    QString nmapPath = findNmapPath();
    if (nmapPath.isEmpty())
    {
        QMessageBox::critical(this, "Error", "nmap is not available. Please make sure it is installed.");
        return;
    }

    // получение IP адреса из поля ввода
    QString ipAddress = addressLineEdit->text();

    // Создание nmap процесса
    QProcess nmapProcess;
    QStringList arguments;
    arguments << "-p" << "1-1024" << "--open" << ipAddress;

    nmapProcess.setProgram(nmapPath);
    nmapProcess.setArguments(arguments);

    nmapProcess.start();
    if (!nmapProcess.waitForStarted())
    {
        QMessageBox::critical(this, "Error", "Failed to start nmap process");
        return;
    }

    if (!nmapProcess.waitForFinished())
    {
        QMessageBox::critical(this, "Error", "Failed to finish nmap process");
        return;
    }

    // Чтение вывода nmap
    QString result = nmapProcess.readAllStandardOutput();
    resultTextEdit->setPlainText(result);
}
