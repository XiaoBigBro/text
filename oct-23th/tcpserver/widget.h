#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void onReadMessage();   //处理服务端反馈的数据
    void onDisplayError(QAbstractSocket::SocketError e);    //打印错误信息
    void on_pushButton_clicked();   //点击连接按钮响应信号的槽函数
    void on_pushButton_2_clicked();  //点击发送按钮响应的槽函数


private:
    Ui::Widget *ui;
     QTcpSocket* m_tcpSocket;    //tcp客户端
};
#endif // WIDGET_H
