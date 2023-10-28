
#include "tcp_client_manage.h"

tcp_client_manage::tcp_client_manage(QObject *parent,const QString &hostName, quint16 port)
    : QObject{parent}
{
    mSocket = new QTcpSocket(parent);

    //socket有数据来了，做处理
    connect(mSocket,&QTcpSocket::readyRead,parent,[&](){
        QByteArray bt;
        bt.resize(mSocket->bytesAvailable());
        mSocket->read(bt.data(),bt.size());
        qDebug()<<"客户端："<<bt;
    });

    connect(mSocket, &QTcpSocket::connected,parent,[&](){
        qDebug()<<("成功和服务器进行连接");
    });
    connect(mSocket, &QTcpSocket::disconnected,parent,[&](){
        qDebug()<<("已断开服务器连接");
    });
    // 将代理类型改为 NoProxy
    mSocket->setProxy(QNetworkProxy::NoProxy);

    //连接服务端
    mSocket->abort();
    mSocket->connectToHost(hostName,port);
    int res = mSocket->waitForConnected(300);
    if(res == false){
        mSocket->close();
        mSocket->deleteLater();
        mSocket = nullptr;
        qDebug()<<("连接主机失败");
    }

    if(mSocket->isOpen()){
        mSocket->close();
        mSocket->deleteLater();
        mSocket = nullptr;
    }
}

