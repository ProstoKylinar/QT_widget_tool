#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include <QApplication>
#include <QFileDialog>
#include <QInputDialog>
#include <QSslCertificate>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>

class CertificateViewer : public QMainWindow
{
    Q_OBJECT

public:
    CertificateViewer(QWidget *parent = nullptr);

private slots:
    void openCertificate();
    void downloadCertificate();

private:
    void createMenu();
    void createMainArea();
    void loadCertificate(const QString &filePath);
    void loadCertificate(const QSslCertificate &certificate);

    QAction *downloadAction;
    QAction *saveAction;
    QLabel* infoLabel;
};
#endif // MAINWINDOW_H
