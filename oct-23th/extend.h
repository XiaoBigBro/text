#ifndef EXTEND_H
#define EXTEND_H

#include <QWidget>

namespace Ui {
class extend;
}

class extend : public QWidget
{
    Q_OBJECT

public:
    explicit extend(QWidget *parent = nullptr);
    ~extend();

private:
    Ui::extend *ui;
};

#endif // EXTEND_H
