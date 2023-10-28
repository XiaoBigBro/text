
#ifndef TCP_CLIENT_MANAGE_H
#define TCP_CLIENT_MANAGE_H


#include <QObject>

#include <QtNetwork>
#include "qtcpsocket.h"


class tcp_client_manage : public QObject
{
    Q_OBJECT
public:
    explicit tcp_client_manage(QObject *parent = nullptr ,
                               const QString &hostName = "127.0.0.1", quint16 port = 80);

private:
    QTcpSocket* mSocket;    //tcp客户端


};

#endif // TCP_CLIENT_MANAGE_H
