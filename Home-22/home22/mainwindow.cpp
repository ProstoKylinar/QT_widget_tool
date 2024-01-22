#include "mainwindow.h"


IcmpSocket::IcmpSocket(QObject* parent)
    : QIODevice(parent), m_socketDescriptor(-1)
{
    m_socketDescriptor = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (m_socketDescriptor == -1) {
        qWarning() << "Failed to create ICMP socket";
    } else {
        connect(this, &IcmpSocket::readyRead, this, &IcmpSocket::readPendingDatagrams);
    }
}

IcmpSocket::~IcmpSocket()
{
    close();
}

bool IcmpSocket::open(QIODevice::OpenMode mode)
{
    Q_UNUSED(mode);
    return m_socketDescriptor != -1;
}

void IcmpSocket::close()
{
    if (m_socketDescriptor != -1) {
        ::close(m_socketDescriptor);
        m_socketDescriptor = -1;
    }
}

qint64 IcmpSocket::writeData(const char* data, qint64 maxSize)
{
    return sendto(m_socketDescriptor, data, maxSize, 0, nullptr, 0);
}

void IcmpSocket::readPendingDatagrams()
{
    char buffer[4096];
    qint64 bytesRead = recv(m_socketDescriptor, buffer, sizeof(buffer), 0);

    if (bytesRead > 0) {
        emit readyRead();
    }
}
