#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include<QTcpServer>

#include<QPushButton>
#include <QWidget>
#include <QVBoxLayout>//垂直布局
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
    void onNewConnect();//客户端新的连接请求处理
    void onSendBackMsg();//反馈信息给客户端新的连接
    void onReadMsg();//服务端读取客户端发来的数据
private:
    Ui::loginWidget *ui;
    QTcpServer *m_tcpServer;//tcp服务端
    QTcpSocket *m_tcpSocket;//tcp套接字





};
#endif // LOGINWIDGET_H
