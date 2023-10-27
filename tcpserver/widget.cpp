#include "widget.h"
#include "ui_widget.h"
#include <QAbstractSocket>
#include <QDebug>

const int gTcpPort=6666;
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_tcpSocket=new QTcpSocket(this);
    //socket有数据来了，做处理
    connect(m_tcpSocket,&QTcpSocket::readyRead,
            this,&Widget::onReadMessage);
    connect(m_tcpSocket,SIGNAL(QAbstractSocket::SocketError),
            this,SLOT(onDisplayError(QAbstractSocket::SocketError)));
    //设置客户端连接默认的主机地址及端口号
    ui->lineEdit->setText("127.0.0.1");
    ui->lineEdit_2->setText(QString::number(gTcpPort));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::onReadMessage()
{
    QByteArray bt;
    bt.resize(m_tcpSocket->bytesAvailable());
    m_tcpSocket->read(bt.data(),bt.size());
    //将客户端反馈的数据显示到标签上
    ui->lineEdit_3->setText(bt);
}
void Widget::onDisplayError(QAbstractSocket::SocketError e)
{

    qDebug()<<"SocketError:"<<e<<Qt::endl
             <<m_tcpSocket->errorString();

}

void Widget::on_pushButton_clicked()
{
    m_tcpSocket->abort();
    //连接服务端
    m_tcpSocket->connectToHost(ui->lineEdit->text(),
                               ui->lineEdit_2->text().toInt());
}
void Widget::on_pushButton_2_clicked()
{
    m_tcpSocket->write(ui->lineEdit_4->text().toUtf8());
    m_tcpSocket->flush();//清空缓冲区
}
