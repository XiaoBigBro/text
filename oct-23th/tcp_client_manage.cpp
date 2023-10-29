
#include "tcp_client_manage.h"

tcp_client_manage::tcp_client_manage(QObject *parent,const QString &hostName, quint16 port)
    : QObject{parent}
{
    mSocket = new QTcpSocket(parent);
    // 将代理类型改为 NoProxy
    mSocket->setProxy(QNetworkProxy::NoProxy);

    connect(mSocket,&QTcpSocket::readyRead,this,[&](){
        QByteArray temp = mSocket->read(mSocket->bytesAvailable());
        data.append(temp);
        qDebug()<<"客户端："<<temp;
    });

    connect(mSocket, &QTcpSocket::connected,this,[&](){
        qDebug()<<("成功和服务器进行连接");
        data.append("成功和服务器进行连接");
        emit connected(local_address(), local_port());
    });

    connect(mSocket, &QTcpSocket::disconnected,this,[&](){
        qDebug()<<("已断开服务器连接");
        data.append("已断开服务器连接");
        emit disconnected(local_address(), local_port());
    });

    connect(mSocket, &QTcpSocket::errorOccurred,this,[&](QAbstractSocket::SocketError){
        qDebug()<<mSocket->errorString();
        emit errorOccurred(mSocket->errorString());
        this->deleteLater();
    });

    //连接服务端
    mSocket->abort();
    mSocket->connectToHost(hostName,port);
}

void tcp_client_manage::close()
{
    qDebug()<<(mSocket==nullptr);
//    mSocket->abort();
}

QString tcp_client_manage::local_address()
{
    return mSocket->localAddress().toString();
}

quint16 tcp_client_manage::local_port()
{
    return mSocket->localPort();
}

