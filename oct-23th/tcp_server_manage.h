
#ifndef TCP_SERVER_MANAGE_H
#define TCP_SERVER_MANAGE_H

#include <QObject>

#include <QtNetwork>
#include "qtcpserver.h"
#include "qtcpsocket.h"
#include "tcp_client_manage.h"


class tcp_server_manage : public QObject
{
    Q_OBJECT
public:
    tcp_server_manage(QObject *parent = nullptr);
    bool is_listen(void);
    void start_listen(const QHostAddress &address = QHostAddress::Any, quint16 port = 80);
    void stop_listen(void);
    qint64 send(QTcpSocket* &targetSocket, const char *data);

private:

public:

private:
    QTcpServer* mServer;
    QList<tcp_client_manage *> clientList;

signals:
    void newConnection(tcp_client_manage * mClient, QString clientAddress , quint16 clientPort);
    void disconnected(QString clientAddress , quint16 clientPort);
};

#endif // TCP_SERVER_MANAGE_H
