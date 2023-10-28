#include "tag.h"
#include "ui_tag.h"

tag::tag(QWidget *parent,const QString &hostName, quint16 port) :
    QToolButton(parent),
    ui(new Ui::tag)
{
    ui->setupUi(this);

    ui->ip->setText("ip: "+hostName);
    ui->port->setText("port: "+QString::number(port));

    this->setAutoRaise(true);
}

tag::~tag()
{
    delete ui;
}
