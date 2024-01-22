#include "mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QInputDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QMenu>
#include <QMenuBar>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QEventLoop>
#include <QSslCertificate>
#include <QSslCipher>
#include <QSslConfiguration>
#include <QDebug>
#include <QSslSocket>
#include <QSslKey>
#include <QStandardPaths>

CertificateViewer::CertificateViewer(QWidget *parent)
    : QMainWindow(parent)
{
    createMenu();
    createMainArea();
}

void CertificateViewer::openCertificate()

{
    QString filePath = QFileDialog::getOpenFileName(this, tr("Открыть сертификат"), "", tr("Файлы сертификатов (*.pem *.crt);;Все файлы (*.*)"));
    if (!filePath.isEmpty()) {
        loadCertificate(filePath);
    }
}

void CertificateViewer::downloadCertificate(){
    QString url = QInputDialog::getText(this, tr("Загрузить сертификат"), tr("Введите URL:"));
    QNetworkAccessManager manager;
    QNetworkReply *reply = manager.get(QNetworkRequest(QUrl(url)));
    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray certificateData = reply->readAll();
        QSslCertificate certificate(certificateData, QSsl::Pem);
        loadCertificate(certificate);
    } else {
        QMessageBox::warning(this, tr("Ошибка"), tr("Не удалось загрузить сертификат: ") + reply->errorString());
    }
    reply->deleteLater();
}

void CertificateViewer::createMenu()
{
    QMenu *fileMenu = menuBar()->addMenu("Файл");
    QAction *openAction = new QAction(tr("Открыть сертификат"), this);
    connect(openAction, &QAction::triggered, this, &CertificateViewer::openCertificate);
    fileMenu->addAction(openAction);

    downloadAction = new QAction(tr("Загрузить сертификат"), this);
    connect(downloadAction, &QAction::triggered, this, &CertificateViewer::downloadCertificate);
    fileMenu->addAction(downloadAction);

    saveAction = new QAction(tr("Сохранить сертификат"), this);
    saveAction->setEnabled(false);  // Недоступно, пока сертификат не загружен
    fileMenu->addAction(saveAction);

    fileMenu->addSeparator();

    QAction *exitAction = new QAction(tr("Выход"), this);
    connect(exitAction, &QAction::triggered, qApp, &QApplication::quit);
    fileMenu->addAction(exitAction);
}

void CertificateViewer::createMainArea()
{
    setFixedSize(600, 800);
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    infoLabel = new QLabel("Здесь появится информация о сертификате");
    infoLabel->setWordWrap(true);
    infoLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);
    infoLabel->setOpenExternalLinks(true);
    infoLabel->setTextFormat(Qt::RichText);
    infoLabel->setAlignment(Qt::AlignTop);
    layout->addWidget(infoLabel);
}


void CertificateViewer::loadCertificate(const QString &filePath){
    QSslCertificate certificate;
    if (!certificate.fromPath(filePath).isEmpty()) {
        loadCertificate(certificate);
    } else {
        QMessageBox::warning(this, tr("Ошибка"), tr("Не удалось загрузить сертификат."));
    }
}


void CertificateViewer::loadCertificate(const QSslCertificate &certificate)
{
    QString cipherInfo = QString("Шифр: %1").arg(certificate.publicKey().algorithm());
    QString subjectInfo = QString("Субъект: %1").arg(certificate.subjectInfo(QSslCertificate::CommonName).join(" "));
    QString issuerInfo = QString("Издатель: %1").arg(certificate.issuerInfo(QSslCertificate::CommonName).join(" "));
    QString effectiveDate = QString("Срок действия: %1 - %2")
                                .arg(certificate.effectiveDate().toString())
                                .arg(certificate.expiryDate().toString());

    auto info = QString("%1<br>%2<br>%3<br>%4")
                       .arg(cipherInfo)
                       .arg(subjectInfo)
                       .arg(issuerInfo)
                       .arg(effectiveDate);

    infoLabel->setText(info);
    saveAction->setEnabled(true);
}
