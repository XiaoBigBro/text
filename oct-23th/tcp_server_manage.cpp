
#include "tcp_server_manage.h"

tcp_server_manage::tcp_server_manage(QObject *parent)
{
    mServer = new QTcpServer(parent);

    //新客户端连接
    connect(mServer,&QTcpServer::newConnection,parent,[&](){
        tcp_client_manage * mClient = new tcp_client_manage(parent);
        mClient->mSocket = mServer->nextPendingConnection();

        QString clientAddress = mClient->mSocket->peerAddress().toString();
        quint16 clientPort = mClient->mSocket->peerPort();

        connect(mClient->mSocket,&QTcpSocket::disconnected,mClient->mSocket,&QTcpSocket::deleteLater);
        connect(mClient->mSocket,&QTcpSocket::disconnected,mClient->mSocket,[=](){
            qDebug()<<"用户断开:";
            qDebug()<<("ip: " + clientAddress +"    端口: "+ QString::number(clientPort));
            auto temp = QString ("用户断开:ip: " + clientAddress +"    端口: "+ QString::number(clientPort)).toUtf8();
            mClient->addMessage(temp);
            emit disconnected(clientAddress , clientPort);
        });

        connect(mClient->mSocket,&QTcpSocket::readyRead,parent,[=](){
            QByteArray message=mClient->mSocket->readAll();
            mClient->addMessage(message);
            auto temp = QString ("\n").toUtf8();
            mClient->addMessage(temp);
            qDebug()<<"服务端收到数据："<<message;
        });

        QString str = "你好：" + clientAddress + "    端口: "+ QString::number(clientPort);
        mClient->mSocket->write(str.toUtf8());
        qDebug()<<"用户接入:";
        qDebug()<<("ip: " + clientAddress + "    端口: "+ QString::number(clientPort));

        clientList.append(mClient);
        emit newConnection(mClient, clientAddress , clientPort);
    });

}
bool tcp_server_manage::is_listen()
{
    return mServer->isListening();
}

void tcp_server_manage::start_listen(const QHostAddress &address, quint16 port)
{
    stop_listen();

    int isListen = mServer->listen(address,port);

    //启动失败
    if(isListen == false)
        qDebug()<<mServer->errorString();
    else
        qDebug()<<"开始监听端口:" + QString::number(port);

}


void tcp_server_manage::stop_listen(void)
{
    if(is_listen())
        mServer->close();
}

qint64 tcp_server_manage::send(QTcpSocket* &targetSocket, const char *data)
{
    if(mServer->isListening() && targetSocket->isOpen()){
        qDebug()<<"发送失败，检查连接";
        return -1;
    }

    return targetSocket->write(data);

}


