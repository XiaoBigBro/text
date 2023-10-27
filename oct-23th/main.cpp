#include <QApplication>
#include <QAbstractSocket>
#include "qtcpserver.h"
#include "qtcpsocket.h"
#include "ui_wechat.h"

const auto MEMBER_IP    =   "127.0.0.1";
const auto MEMBER_PORT  =   6666;

QTcpServer* m_tcpServer;    //tcp服务端
QTcpSocket* m_tcpSocket1;    //tcp套接字
QTcpSocket* m_tcpSocket;    //tcp客户端



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Ui_Widget *pUi = new Ui_Widget();
    QWidget wechat;
    pUi->setupUi(&wechat);
    wechat.show();

    QAbstractButton::connect(pUi->serverButton ,&QToolButton::clicked,&wechat,[&]() {
        pUi->stackedWidget->setCurrentIndex(1);
    });
    QAbstractButton::connect(pUi->clientButton ,&QToolButton::clicked,&wechat,[&]() {
        pUi->stackedWidget->setCurrentIndex(0);
    });
    QAbstractButton::connect(pUi->clientSendButton ,&QToolButton::clicked,&wechat,[&]() {
        auto sendData = pUi->clientSendEdit->toPlainText().toUtf8();
        m_tcpSocket->write(sendData);
    });
    QAbstractButton::connect(pUi->serverSendButton ,&QToolButton::clicked,&wechat,[&]() {
        auto sendData = pUi->serverSendEdit->toPlainText().toUtf8();
        m_tcpSocket1->write(sendData);
    });

    m_tcpServer=new QTcpServer(&wechat);
    //服务端监听客户端发来的请求
    if(!m_tcpServer->listen(QHostAddress::AnyIPv4,6666)){
        qDebug()<<m_tcpServer->errorString();
        m_tcpServer->close();
    }
    QAbstractButton::connect(m_tcpServer,&QTcpServer::newConnection,&wechat,[&](){
        //当前连接的客户端
        m_tcpSocket1=m_tcpServer->nextPendingConnection();
        //断开连接
        QAbstractButton::connect(m_tcpSocket1,&QTcpSocket::disconnected,
                                 m_tcpSocket1,&QTcpSocket::deleteLater);
        //显示收到数据
        QAbstractButton::connect(m_tcpSocket1,&QTcpSocket::readyRead,&wechat,[&](){
            QByteArray bt=m_tcpSocket1->readAll();
            pUi->serverRecEdit->append(bt);
            qDebug()<<"服务端："<<bt;
        });
    });
    QAbstractButton::connect(m_tcpServer,&QTcpServer::newConnection,&wechat,[&](){
        QString str="你好，客户端！";
        m_tcpSocket1->write(str.toUtf8());
    });

    m_tcpSocket=new QTcpSocket(&wechat);
    //socket有数据来了，做处理
    QAbstractButton::connect(m_tcpSocket,&QTcpSocket::readyRead,&wechat,[&](){
        QByteArray bt;
        bt.resize(m_tcpSocket->bytesAvailable());
        m_tcpSocket->read(bt.data(),bt.size());
        pUi->clientRecEdit->append(bt);
        //将客户端反馈的数据显示到标签上
        qDebug()<<"客户端："<<bt;
    });

    //连接服务端
    m_tcpSocket->abort();
    m_tcpSocket->connectToHost(MEMBER_IP,MEMBER_PORT);

    return a.exec();
}
