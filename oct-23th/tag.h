#ifndef TAG_H
#define TAG_H

#include "qlistwidget.h"
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

private:
    QListWidgetItem *item;
    Ui::tag *ui;

signals:
    void close();
};

#endif // TAG_H
