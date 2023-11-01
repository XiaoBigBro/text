#include "extend.h"
#include "ui_extend.h"
#include <QWidget>
extend::extend(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::extend)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Popup);
}

extend::~extend()
{

    delete ui;
}


