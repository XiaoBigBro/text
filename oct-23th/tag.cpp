#include "tag.h"
#include "ui_tag.h"
#include "extend.h"
#include <QApplication>
#include <QObject>
#include <QAbstractSocket>
#include <QListView>




tag::tag(QListWidget *mListWidget, const QString &hostName, const quint16 &port) : ui(new Ui::tag)
{

    ui->setupUi(this);

    ui->ip->setText("ip: " + hostName);
    ui->port->setText("port: " + QString::number(port));
    name = ui->ip->text() + ui->port->text();

    ui->ip->setStyleSheet("background-color: transparent;");
    ui->port->setStyleSheet("background-color: transparent;");

    sign = new QWidget();
    sign->setFixedSize(8,8);
    sign->setParent(ui->label);
    sign->move(22,0);
    sign->setStyleSheet("background-color: rgb(0, 0, 0);");




    if(mListWidget != nullptr){
        item=new QListWidgetItem(mListWidget);
        item->setSizeHint(QSize(this->sizeHint()));
        mListWidget->setItemWidget(item,this);
    }


    connect(ui->extendButton,&QToolButton::clicked, mListWidget, [=](){
        extend *one = new extend;
        one->show();
        QPoint globalPos =this->mapToGlobal(QPoint(0, 0));
        one->move(globalPos.x() + 180, globalPos.y() + 40);

        connect(one->deleteButton,&QPushButton::clicked, mListWidget, [=](){
            //从列表中移除item
            auto p = mListWidget->takeItem(mListWidget->row(item));
            emit close();
            one->close();
        });
        connect(one->unreadButton,&QPushButton::clicked, mListWidget, [=](){
        sign->setStyleSheet("background-color: rgb(255, 0, 0);");
        one->close();
        });


    });






}

tag::~tag()
{
    delete ui;
}





