
#ifndef TCP_CLIENT_MANAGE_H
#define TCP_CLIENT_MANAGE_H


#include <QObject>

#include <QtNetwork>
#include "qtcpsocket.h"


class tcp_client_manage : public QObject
{
    Q_OBJECT
public:
    explicit tcp_client_manage(QObject *parent = nullptr );

    void start(const QString &hostName = "127.0.0.1", quint16 port = 80);
    void close(void);
    void clear(void);
    QString local_address(void);
    quint16 local_port(void);

    QByteArray message();
    void addMessage(QByteArray &message);
    void sendMessage(QByteArray &message);


public:
    QTcpSocket* mSocket;    //tcp客户端
private:
    QByteArray  data;    //tcp客户端

signals:
    void connected(QString ip , quint16 port);
    void disconnected(QString ip , quint16 port);
    void errorOccurred(QString message);
};

#endif // TCP_CLIENT_MANAGE_H
