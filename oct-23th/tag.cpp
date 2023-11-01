#include "tag.h"
#include "ui_tag.h"
#include "extend.h"


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

}





tag::~tag()
{
    delete ui;
}



void tag::on_extendButton_clicked()
{
    extend *one = new extend;
    one->show();
    QPoint globalPos =this->mapToGlobal(QPoint(0, 0));
    one->move(globalPos.x() + 180, globalPos.y() + 40);
}

