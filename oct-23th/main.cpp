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
tcp_client_manage *currentSession;

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

    pWidget = new QWidget;

    pUi = new Ui_Widget;
    pUi->setupUi(pWidget);
    pUi->serverIpEdit->setText(get_local_addresses(QAbstractSocket::IPv4Protocol));

    myServer = new tcp_server_manage(pWidget);

    //主页面切换
    QAbstractAnimation::connect(pUi->serverButton ,&QToolButton::clicked,pWidget,[&]() {
        pUi->stackedWidget->setCurrentIndex(1);
    });
    QAbstractButton::connect(pUi->clientButton ,&QToolButton::clicked,pWidget,[&]() {
        pUi->stackedWidget->setCurrentIndex(0);
    });

    QAbstractButton::connect(pUi->requestButton ,&QToolButton::clicked,pWidget,[&]() {
        //客户端发起连接请求
        tcp_client_manage *client = new tcp_client_manage(pWidget);
        client->start(pUi->clientIpEdit->text(), pUi->clientPortEdit->text().toInt());

        pUi->requestButton->setDisabled(true);
        //连接成功
        QAbstractAnimation::connect(client, &tcp_client_manage::connected, pWidget,[=](QString ip, quint16 port){
            //新建标签保存对应通会话指针
            tag *pTag = new tag(pUi->clientView, ip, port);
            pTag->pClient = client;

            pUi->requestButton->setDisabled(false);
            //点击标签按钮断开连接
            QAbstractAnimation::connect(pTag, &tag::close, pWidget,[=](){
                client->clear();
            });

            //点击标签显示对应聊天记录
            QAbstractAnimation::connect(pUi->clientView, &QListWidget::itemClicked, pWidget,[=](QListWidgetItem *item){
                pUi->recEdit->clear();
                //找到QListWidget中item的Widget
                QWidget *itemWidget = pUi->clientView->itemWidget(item);

                //此Widget即为tag的父类指针,通过dynamic_cast强制转为其真实指针tag *
                tag *mTag = dynamic_cast<tag*>(itemWidget);

                pUi->recEdit->setText(mTag->pClient->message());

                currentSession = mTag->pClient;
                QString title = "客户端\nip: " + currentSession->local_address() + " port: " + QString::number(currentSession->local_port());
                pUi->nameLabel->setText(title);
            });
        });
        //连接失败
        QAbstractAnimation::connect(client, &tcp_client_manage::errorOccurred, pWidget,[&](QString message){
            QMessageBox::information(NULL, "tcp请求连接失败", message);
            pUi->requestButton->setDisabled(false);
        });
    });

    QAbstractAnimation::connect(myServer ,&tcp_server_manage::newConnection,pWidget,[&](tcp_client_manage * client, QString ip, quint16 port) {
        //新建标签保存对应通会话指针
        tag *pTag = new tag(pUi->servetView, ip, port);
        pTag->pClient = client;

        //点击标签按钮断开连接
        QAbstractAnimation::connect(pTag, &tag::close, pWidget,[=](){
            client->clear();
        });

        //点击标签显示对应聊天记录
        QAbstractAnimation::connect(pUi->servetView, &QListWidget::itemClicked, pWidget,[=](QListWidgetItem *item){
            pUi->recEdit->clear();
            //找到QListWidget中item的Widget
            QWidget *itemWidget = pUi->servetView->itemWidget(item);

            //此Widget即为tag的父类指针,通过dynamic_cast强制转为其真实指针tag *
            tag *mTag = dynamic_cast<tag*>(itemWidget);

            pUi->recEdit->setText(mTag->pClient->message());

            currentSession = mTag->pClient;
            QString title = "服务端\nip: " + currentSession->local_address() + " port: " + QString::number(currentSession->local_port());
            pUi->nameLabel->setText(title);
        });
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

    QAbstractAnimation::connect(pUi->sendButton ,&QToolButton::clicked,pWidget,[&]() {
        if(currentSession == nullptr)
            return;
        auto sendMessage = pUi->sendEdit->toPlainText().toUtf8();
        qDebug()<<sendMessage;
        currentSession->sendMessage(sendMessage);
    });


    //按键效果
    QAbstractAnimation::connect(pUi->serverButton ,&QToolButton::clicked,pWidget,[&]() {
        pUi->serverButton->setStyleSheet("background-color: rgb(0, 0, 0);"
                                         "border-radius:6px;"
                                         "border:2px solid #000000;");
        pUi->clientButton->setStyleSheet(  "border-radius:6px;"
                                         "border:2px solid #000000;"
                                         );
    });
    QAbstractAnimation::connect(pUi->clientButton ,&QToolButton::clicked,pWidget,[&]() {
        pUi->clientButton->setStyleSheet("background-color: rgb(0, 0, 0);"
                                         "border-radius:6px;"
                                         "border:2px solid #000000;");
        pUi->serverButton->setStyleSheet(  "border-radius:6px;"
                                         "border:2px solid #000000;"
                                         );
    });

    pWidget->show();

    return a.exec();
}
