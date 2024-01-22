#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CertificateViewer viewer;
    viewer.show();

    return a.exec();
}
