#include "extend.h"
#include "ui_extend.h"
#include <QWidget>
#include <QPushButton>


extend::extend(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::extend)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Popup);
    setFixedSize(80,69);



    //置顶按钮
    topButton = new QPushButton("置顶",this);
    topButton->move(0,0);
    topButton->resize(80,23);
    topButton->setStyleSheet("color: rgb(0, 0, 0);"
                             " border:1px solid #ffffff;");
    connect(this->topButton ,&QPushButton::pressed,this,[&]() {
        this->topButton->setStyleSheet("background-color: rgb(176, 176, 176);");
    });
    connect(this->topButton ,&QPushButton::released,this,[&]() {
        this->    topButton->setStyleSheet("color: rgb(0, 0, 0);"
                                       " border:1px solid #ffffff;");
    });

    //未读按钮
    unreadButton = new QPushButton("标为未读",this);
    unreadButton->move(0,23);
    unreadButton->resize(80,23);
    unreadButton->setStyleSheet("color: rgb(0, 0, 0);"
                             " border:1px solid #ffffff;");
    connect(this->unreadButton ,&QPushButton::pressed,this,[&]() {
        this->unreadButton->setStyleSheet("background-color: rgb(176, 176, 176);");
    });
    connect(this->unreadButton ,&QPushButton::released,this,[&]() {
        this->    unreadButton->setStyleSheet("color: rgb(0, 0, 0);"
                                       " border:1px solid #ffffff;");
    });

    //删除按钮
    deleteButton = new QPushButton("删除",this);
    deleteButton->move(0,46);
    deleteButton->resize(80,23);
    deleteButton->setStyleSheet("color: rgb(0, 0, 0);"
                             " border:1px solid #ffffff;");
    connect(this->deleteButton ,&QPushButton::pressed,this,[&]() {
        this->deleteButton->setStyleSheet("background-color: rgb(176, 176, 176);");
    });
    connect(this->deleteButton ,&QPushButton::released,this,[&]() {
        this-> deleteButton->setStyleSheet("color: rgb(0, 0, 0);"
                                          " border:1px solid #ffffff;");
    });






}

extend::~extend()
{

    delete ui;
}


