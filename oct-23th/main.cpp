#include <QApplication>
#include <QAbstractSocket>
#include <QPushButton>

#include "ui_wechat.h"

#include "tag.h"
#include "tcp_server_manage.h"
#include "tcp_client_manage.h"


Ui_Widget *pUi;
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

    pUi = new Ui_Widget;
    pWidget = new QWidget;

    pUi->setupUi(pWidget);
    pWidget->show();

    auto myServer = new tcp_server_manage(pWidget);
    myServer->start_listen();
    auto client1 = new tcp_client_manage(pWidget);
    client1->close();
    pUi->serverIpEdit->setText(get_local_addresses(QAbstractSocket::IPv4Protocol));
    //主页面切换
    QAbstractAnimation::connect(pUi->serverButton ,&QToolButton::clicked,pWidget,[&]() {
        pUi->stackedWidget->setCurrentIndex(1);
    });
    QAbstractButton::connect(pUi->clientButton ,&QToolButton::clicked,pWidget,[&]() {
        pUi->stackedWidget->setCurrentIndex(0);
    });
    //发送信息
    QAbstractButton::connect(pUi->sendButton ,&QToolButton::clicked,pWidget,[&]() {
        auto sendData = pUi->sendEdit->toPlainText().toUtf8();
    });


    //请求连接
    QAbstractButton::connect(pUi->requestButton ,&QToolButton::clicked,pWidget,[&]() {

        auto client = new tcp_client_manage(pWidget);

        auto *pTag = new tag(pWidget,client->address(),client->port());
        pUi->clientWidgetLayout->addWidget(pTag);
    });

    return a.exec();
}
