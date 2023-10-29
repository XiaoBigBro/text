#include "tag.h"
#include "ui_tag.h"

tag::tag(QListWidget *mListWidget, const QString &hostName, const QString &port) : ui(new Ui::tag)
{
    ui->setupUi(this);

    ui->ip->setText("ip: " + hostName);
    ui->port->setText("port: " + port);

    ui->ip->setStyleSheet("background-color: transparent;");
    ui->port->setStyleSheet("background-color: transparent;");

    if(mListWidget != nullptr){
        QListWidgetItem *item=new QListWidgetItem(mListWidget);
        item->setSizeHint(QSize(this->sizeHint()));
        mListWidget->setItemWidget(item,this);
    }

}

tag::~tag()
{
    delete ui;
}
