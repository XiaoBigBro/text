#include "loginwidget.h"
#include "ui_loginwidget.h"
#include<QTcpSocket>
#include <QAbstractSocket>
const int gTcpPort=6666;


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


    m_tcpSocket=new QTcpSocket(this);
    //socket有数据来了，做处理
    connect(m_tcpSocket,&QTcpSocket::readyRead,
            this,&loginWidget::onReadMessage);
    connect(m_tcpSocket,SIGNAL(QAbstractSocket::SocketError),
            this,SLOT(onDisplayError(QAbstractSocket::SocketError)));
    //设置客户端连接默认的主机地址及端口号
    ui->lineEdit->setText("127.0.0.1");
    ui->lineEdit_2->setText(QString::number(gTcpPort));

}


void loginWidget::onNewConnect()
{
    //当前连接的客户端
    m_tcpSocket1=m_tcpServer->nextPendingConnection();
    //断开连接
    connect(m_tcpSocket1,&QTcpSocket::disconnected,
            m_tcpSocket1,&QTcpSocket::deleteLater);
    //socket有数据时会发送readyRead信号
    connect(m_tcpSocket1,&QTcpSocket::readyRead,
            this,&loginWidget::onReadMsg);
}
void loginWidget::onSendBackMsg()
{
    QString str="你好，客户端！";
    m_tcpSocket1->write(str.toUtf8());
    ui->serverstatelineEdit->setText("反馈数据成功！");

}

void loginWidget::onReadMsg()
{
    //服务端将客户端发来的数据显示到标签上
    QByteArray bt=m_tcpSocket1->readAll();
    ui->servergetlineEdit->setText(bt);
}

void loginWidget::onReadMessage()
{
    QByteArray bt;
    bt.resize(m_tcpSocket->bytesAvailable());
    m_tcpSocket->read(bt.data(),bt.size());
    //将客户端反馈的数据显示到标签上
    ui->lineEdit_3->setText(bt);
}

void loginWidget::onDisplayError(QAbstractSocket::SocketError e)
{
    qDebug()<<"SocketError:"<<e<<Qt::endl
             <<m_tcpSocket->errorString();
}

void loginWidget::on_pushbutton_clicked()
{
    m_tcpSocket->abort();
    //连接服务端
    m_tcpSocket->connectToHost(ui->lineEdit->text(),
                               ui->lineEdit_2->text().toInt());
}

void loginWidget::on_pushbutton2_clicked()
{
    m_tcpSocket->write(ui->lineEdit_4->text().toUtf8());
    m_tcpSocket->flush();//清空缓冲区
}



loginWidget::~loginWidget()
{
    delete ui;
}

