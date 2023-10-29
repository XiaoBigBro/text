
#include "tcp_client_manage.h"

tcp_client_manage::tcp_client_manage(QObject *parent)
    : QObject{parent}
{
    mSocket = new QTcpSocket(parent);
}

void tcp_client_manage::start(const QString &hostName, quint16 port)
{
    // 将代理类型改为 NoProxy
    mSocket->setProxy(QNetworkProxy::NoProxy);

    connect(mSocket,&QTcpSocket::readyRead,this,[&](){
        QByteArray message = mSocket->read(mSocket->bytesAvailable());
        addMessage(message);
        auto temp = QString ("\n").toUtf8();
        addMessage(temp);
        qDebug()<<"客户端收到消息:"<<message;
    });

    connect(mSocket, &QTcpSocket::connected,this,[=](){
        //响应
        qDebug()<<("成功和服务器进行连接");
        auto temp = QString ("成功和服务器进行连接\n").toUtf8();
        addMessage(temp);
        //答复
        auto response = QString ("这里是端口: ").toUtf8() + QString::number(local_port()).toUtf8();
        sendMessage(response);
        emit connected(local_address(), local_port());
    });

    connect(mSocket, &QTcpSocket::disconnected,this,[&](){
        qDebug()<<("已断开服务器连接");
        auto temp = QString ("已断开服务器连接\n").toUtf8();
        addMessage(temp);
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
    if(mSocket->isOpen())
        mSocket->close();
}

void tcp_client_manage::clear()
{
    close();
    delete mSocket;
    delete this;
}

QString tcp_client_manage::local_address()
{
    return mSocket->localAddress().toString();
}

quint16 tcp_client_manage::local_port()
{
    return mSocket->localPort();
}

QByteArray tcp_client_manage::message()
{
    return data;
}

void tcp_client_manage::addMessage(QByteArray& message)
{
    data.append(message);
}

void tcp_client_manage::sendMessage(QByteArray& message)
{
    if(mSocket->isOpen())
        mSocket->write(message);
    else
        qDebug()<<"未建立连接";
}
