#include <QObject>
#include <QIODevice>
#include <QHostAddress>
#include <QTimer>
#include <QDebug>

#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <unistd.h>

class IcmpSocket : public QIODevice
{
    Q_OBJECT

public:
    IcmpSocket(QObject* parent = nullptr);
    ~IcmpSocket() override;

    bool open(QIODevice::OpenMode mode) override;
    void close() override;

    qint64 writeData(const char* data, qint64 maxSize) override;

private slots:
    void readPendingDatagrams();

private:
    int m_socketDescriptor;
};
