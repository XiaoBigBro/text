#include "loginwidget.h"
#include "ui_loginwidget.h"
#include<QTcpSocket>

loginWidget::loginWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::loginWidget)
{
    ui->setupUi(this);
    m_tcpServer=new QTcpServer(this);
        //服务端监听客户端发来的请求
    if(!m_tcpServer->listen(QHostAddress::AnyIPv4,6666)){
        qDebug()<<m_tcpServer->errorString();
        close();
    }
    connect(m_tcpServer,&QTcpServer::newConnection,this,&loginWidget::onNewConnect);
    connect(m_tcpServer,&QTcpServer::newConnection,this,&loginWidget::onSendBackMsg);

}
void loginWidget::onNewConnect()
{
    //当前连接的客户端
    m_tcpSocket=m_tcpServer->nextPendingConnection();
    //断开连接
    connect(m_tcpSocket,&QTcpSocket::disconnected,
            m_tcpSocket,&QTcpSocket::deleteLater);
    //socket有数据时会发送readyRead信号
    connect(m_tcpSocket,&QTcpSocket::readyRead,
            this,&loginWidget::onReadMsg);
}

void loginWidget::onSendBackMsg()
{
    QString str="你好，客户端！";
    m_tcpSocket->write(str.toUtf8());
    ui->lineEdit_2->setText("反馈数据成功！");

}

void loginWidget::onReadMsg()
{
    //服务端将客户端发来的数据显示到标签上
    QByteArray bt=m_tcpSocket->readAll();
    ui->lineEdit->setText(bt);
}


loginWidget::~loginWidget()
{
    delete ui;
}

