#include <QApplication>
#include <QAbstractSocket>
#include "qtcpserver.h"
#include "qtcpsocket.h"
#include "ui_wechat.h"

#include <QtNetwork>

const auto MEMBER_IP    =   "127.0.0.1";
const auto MEMBER_PORT  =   6666;

QTcpServer* m_tcpServer;    //tcp服务端
QTcpSocket* m_tcpSocket1;    //tcp套接字
QTcpSocket* m_tcpSocket;    //tcp客户端

QString get_local_addresses(int mVersions){

    QHostInfo hostInfo = QHostInfo::fromName(QHostInfo::localHostName());
    qDebug() <<"IP地址:";
    QList<QHostAddress> list = hostInfo.addresses();
    foreach (auto item, list) {
        if(item.protocol() == mVersions)
            return item.toString();
        qDebug()<<item.toString()<< Qt::endl;
    }
    return nullptr;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Ui_Widget *pUi = new Ui_Widget();
    QWidget wechat;
    pUi->setupUi(&wechat);
    wechat.show();
    pUi->serverIpEdit->setText(get_local_addresses(QAbstractSocket::IPv4Protocol));
    //主页面切换
    QAbstractButton::connect(pUi->serverButton ,&QToolButton::clicked,&wechat,[&]() {
        pUi->stackedWidget->setCurrentIndex(1);
    });
    QAbstractButton::connect(pUi->clientButton ,&QToolButton::clicked,&wechat,[&]() {
        pUi->stackedWidget->setCurrentIndex(0);
    });
    //发送信息
    QAbstractButton::connect(pUi->clientSendButton ,&QToolButton::clicked,&wechat,[&]() {
        auto sendData = pUi->clientSendEdit->toPlainText().toUtf8();
        m_tcpSocket->write(sendData);
    });
    QAbstractButton::connect(pUi->serverSendButton ,&QToolButton::clicked,&wechat,[&]() {
        auto sendData = pUi->serverSendEdit->toPlainText().toUtf8();
        m_tcpSocket1->write(sendData);
    });

    //请求连接
    QAbstractButton::connect(pUi->requestButton ,&QToolButton::clicked,&wechat,[&]() {

        if(m_tcpSocket == nullptr){
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

            QAbstractAnimation::connect(m_tcpSocket, &QTcpSocket::connected,&wechat,[&](){
                pUi->clientRecEdit->append("成功和服务器进行连接");
                pUi->requestButton->setText("断开连接");
            });
            QAbstractAnimation::connect(m_tcpSocket, &QTcpSocket::disconnected,&wechat,[&](){
                pUi->clientRecEdit->append("已断开服务器连接");
            });
            // 将代理类型改为 NoProxy
            m_tcpSocket->setProxy(QNetworkProxy::NoProxy);

            QString mIp = pUi->clientIpEdit->text();
            quint16 mPort = pUi->clientPortEdit->text().toInt() ;
            //连接服务端
            m_tcpSocket->abort();
            m_tcpSocket->connectToHost(mIp,mPort);
            int res = m_tcpSocket->waitForConnected(300);
            if(res == false){
                m_tcpSocket->close();
                m_tcpSocket->deleteLater();
                m_tcpSocket = nullptr;
                pUi->clientRecEdit->append("连接主机失败");
            }
        }else{
            if(m_tcpSocket->isOpen()){
                m_tcpSocket->close();
                m_tcpSocket->deleteLater();
                m_tcpSocket = nullptr;
                pUi->requestButton->setText("请求连接");
            }
        }
    });

    //开始监听
    QAbstractButton::connect(pUi->monitorButton ,&QToolButton::clicked,&wechat,[&]() {
        if(m_tcpServer == nullptr){
            m_tcpServer=new QTcpServer(&wechat);
            //服务端监听客户端发来的请求
            quint16 mPort = pUi->serverPortEdit->text().toInt() ;
            int startListen = m_tcpServer->listen(QHostAddress::Any,mPort);
           //启动失败
            if(!startListen){
                qDebug()<<m_tcpServer->errorString();
                m_tcpServer->close();
                m_tcpServer->deleteLater();
                m_tcpServer = nullptr;
                pUi->serverRecEdit->append(m_tcpServer->errorString());
                return;
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
                    qDebug()<<"服务端收到数据："<<bt;
                });
                pUi->serverRecEdit->append("新客户端接入:" + m_tcpSocket1->peerAddress().toString()+
                                           QString::number(m_tcpSocket1->peerPort()));
            });
            QAbstractButton::connect(m_tcpServer,&QTcpServer::newConnection,&wechat,[&](){
                QString str="这里是服务器响应";
                m_tcpSocket1->write(str.toUtf8());
            });

            pUi->serverRecEdit->append("开始监听端口:" + QString::number(mPort));

            pUi->monitorButton->setText("停止监听");
        }else{
            if(m_tcpServer->isListening()){
                m_tcpServer->close();
                m_tcpServer->deleteLater();
                m_tcpServer = nullptr;
                pUi->monitorButton->setText("开始监听");
                pUi->serverRecEdit->append("已停止监听");
            }
        }
    });




    return a.exec();
}
