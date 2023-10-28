
#include "tcp_client_manage.h"

tcp_client_manage::tcp_client_manage(QObject *parent,const QString &hostName, quint16 port)
    : QObject{parent}
{
    mSocket = new QTcpSocket(parent);
    // 将代理类型改为 NoProxy
    mSocket->setProxy(QNetworkProxy::NoProxy);

    connect(mSocket,&QTcpSocket::readyRead,parent,[&](){
        QByteArray temp = mSocket->read(mSocket->bytesAvailable());
        data.append(temp);
        qDebug()<<"客户端："<<temp;
    });

    connect(mSocket, &QTcpSocket::connected,parent,[&](){
        qDebug()<<("成功和服务器进行连接");
        data.append("成功和服务器进行连接");
        emit connected();
    });
    connect(mSocket, &QTcpSocket::disconnected,parent,[&](){
        qDebug()<<("已断开服务器连接");
        data.append("已断开服务器连接");
        emit disconnected();
    });

    //连接服务端
    mSocket->abort();
    mSocket->connectToHost(hostName,port);
    int res = mSocket->waitForConnected(300);
    if(res == false)
        qDebug()<<("连接主机失败");

}

void tcp_client_manage::close()
{
    if(mSocket->isOpen())
        mSocket->close();
}

