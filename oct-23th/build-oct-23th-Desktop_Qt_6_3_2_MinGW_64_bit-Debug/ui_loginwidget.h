/********************************************************************************
** Form generated from reading UI file 'loginwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWIDGET_H
#define UI_LOGINWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loginWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QLineEdit *lineEdit;
    QLabel *label;
    QLineEdit *lineEdit_2;

    void setupUi(QWidget *loginWidget)
    {
        if (loginWidget->objectName().isEmpty())
            loginWidget->setObjectName(QString::fromUtf8("loginWidget"));
        loginWidget->resize(426, 327);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(loginWidget->sizePolicy().hasHeightForWidth());
        loginWidget->setSizePolicy(sizePolicy);
        loginWidget->setMinimumSize(QSize(426, 327));
        loginWidget->setMaximumSize(QSize(426, 327));
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("face-angel");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8(":/oct-23th/icon/QQ.png"), QSize(), QIcon::Normal, QIcon::Off);
        }
        loginWidget->setWindowIcon(icon);
        loginWidget->setWindowOpacity(10.000000000000000);
        loginWidget->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(255, 255, 255);"));
        verticalLayout = new QVBoxLayout(loginWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(loginWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(130, 130, 261, 31));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(13, 130, 111, 20));
        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(140, 60, 251, 41));

        verticalLayout->addWidget(widget);


        retranslateUi(loginWidget);

        QMetaObject::connectSlotsByName(loginWidget);
    } // setupUi

    void retranslateUi(QWidget *loginWidget)
    {
        loginWidget->setWindowTitle(QCoreApplication::translate("loginWidget", "QQ", nullptr));
        lineEdit->setText(QCoreApplication::translate("loginWidget", "\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("loginWidget", " \345\256\242\346\210\267\347\253\257\345\217\221\346\235\245\347\232\204\346\225\260\346\215\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loginWidget: public Ui_loginWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIDGET_H
