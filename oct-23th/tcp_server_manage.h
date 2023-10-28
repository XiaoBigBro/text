
#ifndef TCP_SERVER_MANAGE_H
#define TCP_SERVER_MANAGE_H

#include <QObject>

#include <QtNetwork>
#include "qtcpserver.h"
#include "qtcpsocket.h"


class tcp_server_manage : public QObject
{
    Q_OBJECT
public:
    tcp_server_manage(QObject *parent = nullptr);
    bool start_listen(const QHostAddress &address = QHostAddress::Any, quint16 port = 80);
    bool stop_listen(void);
    qint64 send(QTcpSocket &targetSocket, const char *data);

private:

public:

private:
    QTcpServer* mServer;    //tcp服务端
    QTcpSocket* mSocket;    //tcp套接字
};

#endif // TCP_SERVER_MANAGE_H
