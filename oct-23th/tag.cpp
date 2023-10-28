#include "tag.h"
#include "ui_tag.h"

tag::tag(QWidget *parent,const QString &hostName, const QString &port) :
    QToolButton(parent),
    ui(new Ui::tag)
{
    ui->setupUi(this);

    ui->ip->setText("ip: " + hostName);
    ui->port->setText("port: " + port);

    this->setAutoRaise(true);
}

tag::~tag()
{
    delete ui;
}
