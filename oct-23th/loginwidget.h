#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H
#include <QTcpServer>
#include<QPushButton>
#include <QWidget>
#include <QTcpSocket>


QT_BEGIN_NAMESPACE
namespace Ui { class loginWidget; }
QT_END_NAMESPACE

class loginWidget : public QWidget
{
    Q_OBJECT

public:
    loginWidget(QWidget *parent = nullptr);
    ~loginWidget();
private slots:
    void onNewConnect();    //客户端新的连接请求处理
    void onSendBackMsg();   //反馈信息给客户端新的连接
    void onReadMsg();       //服务端读取客户端发来的数据


    void onReadMessage();   //处理服务端反馈的数据
    void onDisplayError(QAbstractSocket::SocketError e);    //打印错误信息
    void on_pushbutton_clicked();   //点击连接按钮响应信号的槽函数
    void on_pushbutton2_clicked();  //点击发送按钮响应的槽函数


private:
    Ui::loginWidget *ui;
    QTcpServer* m_tcpServer;    //tcp服务端
    QTcpSocket* m_tcpSocket1;    //tcp套接字
    QTcpSocket* m_tcpSocket;    //tcp客户端



};
#endif // LOGINWIDGET_H
