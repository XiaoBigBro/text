
#include "tcp_server_manage.h"

tcp_server_manage::tcp_server_manage(QObject *parent)
{
    mServer = new QTcpServer(parent);

    //新客户端连接
    connect(mServer,&QTcpServer::newConnection,parent,[&](){
        mSocket = mServer->nextPendingConnection();

        QString clientAddress = mSocket->peerAddress().toString();
        QString clientPort = QString::number(mSocket->peerPort());

        connect(mSocket,&QTcpSocket::disconnected,mSocket,&QTcpSocket::deleteLater);
        connect(mSocket,&QTcpSocket::disconnected,mSocket,[=](){
            qDebug()<<"用户断开:";
            qDebug()<<("ip: " + clientAddress +"    端口: "+ clientPort);
        });

        connect(mSocket,&QTcpSocket::readyRead,parent,[&](){
            QByteArray bt=mSocket->readAll();
            qDebug()<<"服务端收到数据："<<bt;
        });

        QString str = "你好：" + clientAddress;
        mSocket->write(str.toUtf8());
        qDebug()<<"用户接入:";
        qDebug()<<("ip: " + clientAddress +"    端口: "+ clientPort);
    });

}

bool tcp_server_manage::start_listen(const QHostAddress &address, quint16 port)
{
    int isListen = mServer->listen(address,port);

    //启动失败
    if(isListen == false)
        qDebug()<<mServer->errorString();
    else
        qDebug()<<"开始监听端口:" + QString::number(port);

    return isListen;
}

bool tcp_server_manage::stop_listen(void)
{
    int isListen = mServer->isListening();
    //停止监听
    if(isListen)
        mServer->close();

    return isListen;
}

qint64 tcp_server_manage::send(QTcpSocket &targetSocket, const char *data)
{
    if(mServer->isListening() && targetSocket.isOpen()){
        qDebug()<<"发送失败，检查连接";
        return -1;
    }

    return mSocket->write(data);

}


