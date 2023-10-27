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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loginWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *serverwidget;
    QLabel *serverstatelabel;
    QLineEdit *serverstatelineEdit;
    QLabel *servergetlabel;
    QLineEdit *servergetlineEdit;
    QWidget *clientwidget_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QPushButton *pushbutton;
    QPushButton *pushbutton2;

    void setupUi(QWidget *loginWidget)
    {
        if (loginWidget->objectName().isEmpty())
            loginWidget->setObjectName(QString::fromUtf8("loginWidget"));
        loginWidget->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(loginWidget->sizePolicy().hasHeightForWidth());
        loginWidget->setSizePolicy(sizePolicy);
        loginWidget->setMinimumSize(QSize(800, 600));
        loginWidget->setMaximumSize(QSize(800, 600));
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
        serverwidget = new QWidget(loginWidget);
        serverwidget->setObjectName(QString::fromUtf8("serverwidget"));
        serverstatelabel = new QLabel(serverwidget);
        serverstatelabel->setObjectName(QString::fromUtf8("serverstatelabel"));
        serverstatelabel->setGeometry(QRect(100, 30, 111, 31));
        serverstatelineEdit = new QLineEdit(serverwidget);
        serverstatelineEdit->setObjectName(QString::fromUtf8("serverstatelineEdit"));
        serverstatelineEdit->setGeometry(QRect(280, 20, 281, 41));
        servergetlabel = new QLabel(serverwidget);
        servergetlabel->setObjectName(QString::fromUtf8("servergetlabel"));
        servergetlabel->setGeometry(QRect(43, 80, 191, 81));
        servergetlineEdit = new QLineEdit(serverwidget);
        servergetlineEdit->setObjectName(QString::fromUtf8("servergetlineEdit"));
        servergetlineEdit->setGeometry(QRect(280, 80, 391, 91));

        verticalLayout->addWidget(serverwidget);

        clientwidget_2 = new QWidget(loginWidget);
        clientwidget_2->setObjectName(QString::fromUtf8("clientwidget_2"));
        label = new QLabel(clientwidget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 10, 54, 41));
        label_2 = new QLabel(clientwidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 90, 54, 31));
        label_3 = new QLabel(clientwidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(60, 150, 141, 41));
        label_4 = new QLabel(clientwidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(23, 240, 81, 20));
        lineEdit = new QLineEdit(clientwidget_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(140, 20, 221, 31));
        lineEdit_2 = new QLineEdit(clientwidget_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(140, 90, 221, 31));
        lineEdit_3 = new QLineEdit(clientwidget_2);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(150, 140, 251, 71));
        lineEdit_4 = new QLineEdit(clientwidget_2);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(120, 230, 281, 51));
        pushbutton = new QPushButton(clientwidget_2);
        pushbutton->setObjectName(QString::fromUtf8("pushbutton"));
        pushbutton->setGeometry(QRect(410, 20, 80, 24));
        pushbutton->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";\n"
"color: rgb(170, 0, 0);"));
        pushbutton2 = new QPushButton(clientwidget_2);
        pushbutton2->setObjectName(QString::fromUtf8("pushbutton2"));
        pushbutton2->setGeometry(QRect(480, 250, 80, 24));
        pushbutton2->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";\n"
"color: rgb(170, 0, 0);"));

        verticalLayout->addWidget(clientwidget_2);


        retranslateUi(loginWidget);

        QMetaObject::connectSlotsByName(loginWidget);
    } // setupUi

    void retranslateUi(QWidget *loginWidget)
    {
        loginWidget->setWindowTitle(QCoreApplication::translate("loginWidget", "QQ", nullptr));
        serverstatelabel->setText(QCoreApplication::translate("loginWidget", "<html><head/><body><p><span style=\" font-size:14pt; color:#aa0000;\">\347\212\266\346\200\201</span></p></body></html>", nullptr));
        servergetlabel->setText(QCoreApplication::translate("loginWidget", "<html><head/><body><p><span style=\" font-size:16pt; color:#aa0000;\">\345\256\242\346\210\267\347\253\257\345\217\221\351\200\201\346\235\245\347\232\204\346\225\260\346\215\256</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("loginWidget", "<html><head/><body><p><span style=\" font-size:14pt; color:#aa0000;\">\344\270\273\346\234\272</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("loginWidget", "<html><head/><body><p><span style=\" font-size:12pt; color:#aa0000;\">\347\253\257\345\217\243</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("loginWidget", "<html><head/><body><p><span style=\" font-size:14pt; color:#aa0000;\">\347\212\266\346\200\201</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("loginWidget", "<html><head/><body><p><span style=\" font-size:12pt; color:#aa0000;\">\345\217\221\351\200\201\347\232\204\346\225\260\346\215\256</span></p></body></html>", nullptr));
        pushbutton->setText(QCoreApplication::translate("loginWidget", "\350\277\236\346\216\245", nullptr));
        pushbutton2->setText(QCoreApplication::translate("loginWidget", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loginWidget: public Ui_loginWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIDGET_H
