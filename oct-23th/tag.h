#ifndef TAG_H
#define TAG_H

#include "qlistwidget.h"
#include "tcp_client_manage.h"
#include <QWidget>

namespace Ui {
class tag;
}

class tag : public QWidget
{
    Q_OBJECT

public:
    explicit tag(QListWidget* mListWidget ,const QString &hostName = "127.0.0.1", const quint16 &port = 80);
    ~tag();
    tcp_client_manage *pClient;
    QString name;
private:
    QListWidgetItem *item;
    Ui::tag *ui;
    QWidget *sign;
signals:
    void close();


};

#endif // TAG_H
