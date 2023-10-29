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
    explicit tag(QListWidget* mListWidget ,const QString &hostName = "127.0.0.1", const QString &port = "80");
    ~tag();

private:
    Ui::tag *ui;
};

#endif // TAG_H
