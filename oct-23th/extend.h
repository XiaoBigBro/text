#ifndef EXTEND_H
#define EXTEND_H
#include <QPushButton>
#include <QWidget>
#include "qlistwidget.h"

namespace Ui {
class extend;
}

class extend : public QWidget
{
    Q_OBJECT

public:
    explicit extend(QWidget *parent = nullptr);
    ~extend();
    QPushButton* topButton;
    QPushButton* unreadButton;
    QPushButton* deleteButton;

private:
    Ui::extend *ui;
    QListWidgetItem *item;



};

#endif // EXTEND_H
