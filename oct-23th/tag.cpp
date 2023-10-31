#include "tag.h"
#include "ui_tag.h"

tag::tag(QListWidget *mListWidget, const QString &hostName, const quint16 &port) : ui(new Ui::tag)
{
    ui->setupUi(this);

    ui->ip->setText("ip: " + hostName);
    ui->port->setText("port: " + QString::number(port));
    name = ui->ip->text() + ui->port->text();

    ui->ip->setStyleSheet("background-color: transparent;");
    ui->port->setStyleSheet("background-color: transparent;");

    if(mListWidget != nullptr){
        item=new QListWidgetItem(mListWidget);
        item->setSizeHint(QSize(this->sizeHint()));
        mListWidget->setItemWidget(item,this);
    }

    connect(ui->closeButton,&QToolButton::clicked, mListWidget, [=](){
        //从列表中移除item
        auto p = mListWidget->takeItem(mListWidget->row(item));
        emit close();
    });
}

tag::~tag()
{
    delete ui;
}
