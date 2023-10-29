#include <QApplication>
#include <QAbstractSocket>

#include "ui_wechat.h"

#include "tcp_server_manage.h"
#include "tcp_client_manage.h"


Ui_Widget *pUi ;
QWidget *pWidget;


QString get_local_addresses(int mVersions){
    //只查找ipv4和ipv6
    if(mVersions != QAbstractSocket::IPv4Protocol &&
        mVersions != QAbstractSocket::IPv6Protocol )
        return nullptr;

    QHostInfo hostInfo = QHostInfo::fromName(QHostInfo::localHostName());
    qDebug() ;
    QList<QHostAddress> list = hostInfo.addresses();
    foreach (auto item, list) {
        if(item.protocol() == mVersions){
            qDebug()<<"IP地址:"<<item.toString();
                                       return item.toString();
        }
    }
    return nullptr;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    pUi = new Ui_Widget();
    pWidget = new QWidget();

    pUi->setupUi(pWidget);
    pWidget->show();

    auto myServer = new tcp_server_manage(pWidget);
    myServer->start_listen();
    auto client1 = new tcp_client_manage(pWidget);

    pUi->serverIpEdit->setText(get_local_addresses(QAbstractSocket::IPv4Protocol));
    //主页面切换
    QAbstractButton::connect(pUi->serverButton ,&QToolButton::clicked,pWidget,[&]() {
        pUi->stackedWidget->setCurrentIndex(1);
    });
    QAbstractButton::connect(pUi->clientButton ,&QToolButton::clicked,pWidget,[&]() {
        pUi->stackedWidget->setCurrentIndex(0);
    });
    //发送信息
    QAbstractButton::connect(pUi->sendButton ,&QToolButton::clicked,pWidget,[&]() {
        auto sendData = pUi->sendEdit->toPlainText().toUtf8();
        pUi->sendEdit->clear();
    });


    //请求连接
    QAbstractButton::connect(pUi->requestButton ,&QToolButton::clicked,pWidget,[&]() {

    });


    //按键样式设置效果
    QAbstractButton::connect(pUi->requestButton ,&QToolButton::pressed,pWidget,[&]() {
        pUi->requestButton->setStyleSheet("background-color:#000000;");
    });
    QAbstractButton::connect(pUi->requestButton ,&QToolButton::released,pWidget,[&]() {
         pUi->requestButton->setStyleSheet("background-color:#c3e9e5;");
    });
    QAbstractButton::connect(pUi->monitorButton ,&QToolButton::pressed,pWidget,[&]() {
        pUi->monitorButton->setStyleSheet("background-color:#000000;");
    });
    QAbstractButton::connect(pUi->monitorButton ,&QToolButton::released,pWidget,[&]() {
        pUi->monitorButton->setStyleSheet("background-color:#c3e9e5;");
    });
    QAbstractButton::connect(pUi->sendButton ,&QToolButton::pressed,pWidget,[&]() {
        pUi->sendButton->setStyleSheet("background-color:#000000;");
    });
    QAbstractButton::connect(pUi->sendButton ,&QToolButton::released,pWidget,[&]() {
        pUi->sendButton->setStyleSheet("background-color:#c3e9e5;");
    });




    return a.exec();
}
