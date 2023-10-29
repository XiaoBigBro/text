#include <QApplication>
#include <QAbstractSocket>
#include <QPushButton>
#include <QListView>
#include <QMessageBox>

#include "ui_wechat.h"

#include "tag.h"
#include "tcp_server_manage.h"
#include "tcp_client_manage.h"


Ui_Widget *pUi ;
QWidget *pWidget;
tcp_server_manage *myServer;

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

    myServer = new tcp_server_manage(pWidget);

    pUi->serverIpEdit->setText(get_local_addresses(QAbstractSocket::IPv4Protocol));
    //主页面切换
    QAbstractAnimation::connect(pUi->serverButton ,&QToolButton::clicked,pWidget,[&]() {
        pUi->stackedWidget->setCurrentIndex(1);
    });
    QAbstractButton::connect(pUi->clientButton ,&QToolButton::clicked,pWidget,[&]() {
        pUi->stackedWidget->setCurrentIndex(0);
    });

    QAbstractButton::connect(pUi->sendButton ,&QToolButton::clicked,pWidget,[&]() {
        auto sendData = pUi->sendEdit->toPlainText().toUtf8();
        pUi->sendEdit->clear();
    });


    //请求连接
    QAbstractButton::connect(pUi->requestButton ,&QToolButton::clicked,pWidget,[&]() {
        //客户端发起连接请求
        auto client = new tcp_client_manage(pWidget, pUi->clientIpEdit->text(), pUi->clientPortEdit->text().toInt());

        pUi->requestButton->setDisabled(true);
        //连接成功
        QAbstractAnimation::connect(client, &tcp_client_manage::connected, pWidget,[&](QString ip, quint16 port){
            auto pTag = new tag(pUi->clientView, ip, port);
            pUi->requestButton->setDisabled(false);
            //点击标签按钮断开连接
            QAbstractAnimation::connect(pTag, &tag::close, pWidget,[=](){

            });
        });
        //连接失败
        QAbstractAnimation::connect(client, &tcp_client_manage::errorOccurred, pWidget,[&](QString message){
            QMessageBox::information(NULL, "tcp请求连接失败", message);
            pUi->requestButton->setDisabled(false);
        });
    });


    QAbstractAnimation::connect(myServer ,&tcp_server_manage::newConnection,pWidget,[&](QString ip, quint16 port) {
        new tag(pUi->servetView, ip, port);
    });

    QAbstractAnimation::connect(pUi->monitorButton ,&QToolButton::clicked,pWidget,[&]() {
        if(myServer->is_listen()){
            myServer->stop_listen();
            pUi->monitorButton->setText("开始监听");
        }else{
            myServer->start_listen(QHostAddress::Any , pUi->serverPortEdit->text().toInt());
            pUi->monitorButton->setText("停止监听");
        }

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
    QAbstractAnimation::connect(pUi->serverButton ,&QToolButton::clicked,pWidget,[&]() {
        pUi->serverButton->setStyleSheet("background-color: rgb(0, 0, 0);"
                                         "border-radius:6px;"
                                         "border:2px solid #000000;");
        pUi->clientButton->setStyleSheet(  "border-radius:6px;"
                                         "border:2px solid #000000;"
                                         );
    });





    return a.exec();
}
