#ifndef TAG_H
#define TAG_H

#include "qtoolbutton.h"
#include <QWidget>

namespace Ui {
class tag;
}

class tag : public QToolButton
{
    Q_OBJECT

public:
    explicit tag(QWidget *parent = nullptr,
                 const QString &hostName = "127.0.0.1", const QString &port = "80");
    ~tag();

private:
    Ui::tag *ui;
};

#endif // TAG_H
