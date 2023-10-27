/********************************************************************************
** Form generated from reading UI file 'wechat.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WECHAT_H
#define UI_WECHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout_7;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QToolButton *clientButton;
    QToolButton *serverButton;
    QToolButton *toolButton_3;
    QToolButton *toolButton_4;
    QToolButton *toolButton_5;
    QToolButton *toolButton_9;
    QSpacerItem *verticalSpacer;
    QToolButton *toolButton_8;
    QToolButton *toolButton_6;
    QToolButton *toolButton_7;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QHBoxLayout *horizontalLayout_8;
    QFrame *frame1;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *clientIpEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *clientPortEdit;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_7;
    QToolButton *requestButton;
    QSpacerItem *horizontalSpacer_8;
    QWidget *widget_3;
    QFrame *frame2;
    QVBoxLayout *verticalLayout_5;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_4;
    QTextEdit *clientRecEdit;
    QHBoxLayout *horizontalLayout_5;
    QToolButton *toolButton_17;
    QToolButton *toolButton_18;
    QToolButton *toolButton_19;
    QToolButton *toolButton_20;
    QSpacerItem *horizontalSpacer_3;
    QToolButton *toolButton_21;
    QTextEdit *clientSendEdit;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_4;
    QToolButton *clientSendButton;
    QWidget *page_2;
    QHBoxLayout *horizontalLayout_4;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_10;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_3;
    QLineEdit *serverIpEdit;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_4;
    QLineEdit *serverPortEdit;
    QHBoxLayout *horizontalLayout_13;
    QSpacerItem *horizontalSpacer;
    QToolButton *monitorButton;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_4;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout_8;
    QWidget *widget_7;
    QVBoxLayout *verticalLayout_9;
    QTextEdit *serverRecEdit;
    QHBoxLayout *horizontalLayout_11;
    QToolButton *toolButton_23;
    QToolButton *toolButton_24;
    QToolButton *toolButton_25;
    QToolButton *toolButton_26;
    QSpacerItem *horizontalSpacer_5;
    QToolButton *toolButton_27;
    QTextEdit *serverSendEdit;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer_6;
    QToolButton *serverSendButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1045, 640);
        horizontalLayout_7 = new QHBoxLayout(Widget);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(Widget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setToolTipDuration(-1);
        frame->setLayoutDirection(Qt::LeftToRight);
        frame->setStyleSheet(QString::fromUtf8("background:rgb(46, 46, 46)"));
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        clientButton = new QToolButton(frame);
        clientButton->setObjectName(QString::fromUtf8("clientButton"));
        clientButton->setStyleSheet(QString::fromUtf8("background:rgb(190, 192, 193)"));

        verticalLayout->addWidget(clientButton);

        serverButton = new QToolButton(frame);
        serverButton->setObjectName(QString::fromUtf8("serverButton"));
        serverButton->setStyleSheet(QString::fromUtf8("background:rgb(190, 192, 193)"));

        verticalLayout->addWidget(serverButton);

        toolButton_3 = new QToolButton(frame);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        toolButton_3->setStyleSheet(QString::fromUtf8("background:rgb(190, 192, 193)"));

        verticalLayout->addWidget(toolButton_3);

        toolButton_4 = new QToolButton(frame);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        toolButton_4->setStyleSheet(QString::fromUtf8("background:rgb(190, 192, 193)"));

        verticalLayout->addWidget(toolButton_4);

        toolButton_5 = new QToolButton(frame);
        toolButton_5->setObjectName(QString::fromUtf8("toolButton_5"));
        toolButton_5->setStyleSheet(QString::fromUtf8("background:rgb(190, 192, 193)"));

        verticalLayout->addWidget(toolButton_5);

        toolButton_9 = new QToolButton(frame);
        toolButton_9->setObjectName(QString::fromUtf8("toolButton_9"));
        toolButton_9->setStyleSheet(QString::fromUtf8("background:rgb(190, 192, 193)"));

        verticalLayout->addWidget(toolButton_9);

        verticalSpacer = new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        toolButton_8 = new QToolButton(frame);
        toolButton_8->setObjectName(QString::fromUtf8("toolButton_8"));
        toolButton_8->setStyleSheet(QString::fromUtf8("background:rgb(190, 192, 193)"));

        verticalLayout->addWidget(toolButton_8);

        toolButton_6 = new QToolButton(frame);
        toolButton_6->setObjectName(QString::fromUtf8("toolButton_6"));
        toolButton_6->setStyleSheet(QString::fromUtf8("background:rgb(190, 192, 193)"));

        verticalLayout->addWidget(toolButton_6);

        toolButton_7 = new QToolButton(frame);
        toolButton_7->setObjectName(QString::fromUtf8("toolButton_7"));
        toolButton_7->setStyleSheet(QString::fromUtf8("background:rgb(190, 192, 193)"));

        verticalLayout->addWidget(toolButton_7);


        horizontalLayout_7->addWidget(frame);

        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        horizontalLayout_8 = new QHBoxLayout(page);
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        frame1 = new QFrame(page);
        frame1->setObjectName(QString::fromUtf8("frame1"));
        verticalLayout_2 = new QVBoxLayout(frame1);
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        frame_2 = new QFrame(frame1);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        verticalLayout_3 = new QVBoxLayout(frame_2);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(frame_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        clientIpEdit = new QLineEdit(frame_2);
        clientIpEdit->setObjectName(QString::fromUtf8("clientIpEdit"));

        horizontalLayout->addWidget(clientIpEdit);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        clientPortEdit = new QLineEdit(frame_2);
        clientPortEdit->setObjectName(QString::fromUtf8("clientPortEdit"));

        horizontalLayout_2->addWidget(clientPortEdit);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        requestButton = new QToolButton(frame_2);
        requestButton->setObjectName(QString::fromUtf8("requestButton"));
        requestButton->setMinimumSize(QSize(100, 0));

        horizontalLayout_3->addWidget(requestButton);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);


        verticalLayout_3->addLayout(horizontalLayout_3);


        verticalLayout_2->addWidget(frame_2);

        widget_3 = new QWidget(frame1);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setStyleSheet(QString::fromUtf8("background:rgb(232, 231, 230)"));

        verticalLayout_2->addWidget(widget_3);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 12);

        horizontalLayout_8->addWidget(frame1);

        frame2 = new QFrame(page);
        frame2->setObjectName(QString::fromUtf8("frame2"));
        verticalLayout_5 = new QVBoxLayout(frame2);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        widget_6 = new QWidget(frame2);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        verticalLayout_4 = new QVBoxLayout(widget_6);
        verticalLayout_4->setSpacing(3);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        clientRecEdit = new QTextEdit(widget_6);
        clientRecEdit->setObjectName(QString::fromUtf8("clientRecEdit"));

        verticalLayout_4->addWidget(clientRecEdit);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        toolButton_17 = new QToolButton(widget_6);
        toolButton_17->setObjectName(QString::fromUtf8("toolButton_17"));

        horizontalLayout_5->addWidget(toolButton_17);

        toolButton_18 = new QToolButton(widget_6);
        toolButton_18->setObjectName(QString::fromUtf8("toolButton_18"));

        horizontalLayout_5->addWidget(toolButton_18);

        toolButton_19 = new QToolButton(widget_6);
        toolButton_19->setObjectName(QString::fromUtf8("toolButton_19"));

        horizontalLayout_5->addWidget(toolButton_19);

        toolButton_20 = new QToolButton(widget_6);
        toolButton_20->setObjectName(QString::fromUtf8("toolButton_20"));

        horizontalLayout_5->addWidget(toolButton_20);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        toolButton_21 = new QToolButton(widget_6);
        toolButton_21->setObjectName(QString::fromUtf8("toolButton_21"));

        horizontalLayout_5->addWidget(toolButton_21);


        verticalLayout_4->addLayout(horizontalLayout_5);

        clientSendEdit = new QTextEdit(widget_6);
        clientSendEdit->setObjectName(QString::fromUtf8("clientSendEdit"));

        verticalLayout_4->addWidget(clientSendEdit);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);

        clientSendButton = new QToolButton(widget_6);
        clientSendButton->setObjectName(QString::fromUtf8("clientSendButton"));
        clientSendButton->setMinimumSize(QSize(80, 0));

        horizontalLayout_6->addWidget(clientSendButton);


        verticalLayout_4->addLayout(horizontalLayout_6);

        verticalLayout_4->setStretch(0, 36);
        verticalLayout_4->setStretch(1, 1);
        verticalLayout_4->setStretch(2, 6);
        verticalLayout_4->setStretch(3, 1);

        verticalLayout_5->addWidget(widget_6);

        verticalLayout_5->setStretch(0, 3);

        horizontalLayout_8->addWidget(frame2);

        horizontalLayout_8->setStretch(0, 2);
        horizontalLayout_8->setStretch(1, 8);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        horizontalLayout_4 = new QHBoxLayout(page_2);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        frame_3 = new QFrame(page_2);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        verticalLayout_10 = new QVBoxLayout(frame_3);
        verticalLayout_10->setSpacing(0);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        frame_4 = new QFrame(frame_3);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        verticalLayout_6 = new QVBoxLayout(frame_4);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(2);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_3 = new QLabel(frame_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_9->addWidget(label_3);

        serverIpEdit = new QLineEdit(frame_4);
        serverIpEdit->setObjectName(QString::fromUtf8("serverIpEdit"));
        serverIpEdit->setReadOnly(true);

        horizontalLayout_9->addWidget(serverIpEdit);


        verticalLayout_7->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(0);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_4 = new QLabel(frame_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_10->addWidget(label_4);

        serverPortEdit = new QLineEdit(frame_4);
        serverPortEdit->setObjectName(QString::fromUtf8("serverPortEdit"));

        horizontalLayout_10->addWidget(serverPortEdit);


        verticalLayout_7->addLayout(horizontalLayout_10);


        verticalLayout_6->addLayout(verticalLayout_7);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer);

        monitorButton = new QToolButton(frame_4);
        monitorButton->setObjectName(QString::fromUtf8("monitorButton"));
        monitorButton->setMinimumSize(QSize(100, 0));

        horizontalLayout_13->addWidget(monitorButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_2);


        verticalLayout_6->addLayout(horizontalLayout_13);


        verticalLayout_10->addWidget(frame_4);

        widget_4 = new QWidget(frame_3);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setStyleSheet(QString::fromUtf8("background:rgb(232, 231, 230)"));

        verticalLayout_10->addWidget(widget_4);

        verticalLayout_10->setStretch(0, 1);
        verticalLayout_10->setStretch(1, 9);

        horizontalLayout_4->addWidget(frame_3);

        frame_5 = new QFrame(page_2);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        verticalLayout_8 = new QVBoxLayout(frame_5);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        widget_7 = new QWidget(frame_5);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        verticalLayout_9 = new QVBoxLayout(widget_7);
        verticalLayout_9->setSpacing(3);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        serverRecEdit = new QTextEdit(widget_7);
        serverRecEdit->setObjectName(QString::fromUtf8("serverRecEdit"));

        verticalLayout_9->addWidget(serverRecEdit);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        toolButton_23 = new QToolButton(widget_7);
        toolButton_23->setObjectName(QString::fromUtf8("toolButton_23"));

        horizontalLayout_11->addWidget(toolButton_23);

        toolButton_24 = new QToolButton(widget_7);
        toolButton_24->setObjectName(QString::fromUtf8("toolButton_24"));

        horizontalLayout_11->addWidget(toolButton_24);

        toolButton_25 = new QToolButton(widget_7);
        toolButton_25->setObjectName(QString::fromUtf8("toolButton_25"));

        horizontalLayout_11->addWidget(toolButton_25);

        toolButton_26 = new QToolButton(widget_7);
        toolButton_26->setObjectName(QString::fromUtf8("toolButton_26"));

        horizontalLayout_11->addWidget(toolButton_26);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_5);

        toolButton_27 = new QToolButton(widget_7);
        toolButton_27->setObjectName(QString::fromUtf8("toolButton_27"));

        horizontalLayout_11->addWidget(toolButton_27);


        verticalLayout_9->addLayout(horizontalLayout_11);

        serverSendEdit = new QTextEdit(widget_7);
        serverSendEdit->setObjectName(QString::fromUtf8("serverSendEdit"));

        verticalLayout_9->addWidget(serverSendEdit);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_6);

        serverSendButton = new QToolButton(widget_7);
        serverSendButton->setObjectName(QString::fromUtf8("serverSendButton"));
        serverSendButton->setMinimumSize(QSize(80, 0));

        horizontalLayout_12->addWidget(serverSendButton);


        verticalLayout_9->addLayout(horizontalLayout_12);

        verticalLayout_9->setStretch(0, 36);
        verticalLayout_9->setStretch(1, 1);
        verticalLayout_9->setStretch(2, 6);
        verticalLayout_9->setStretch(3, 1);

        verticalLayout_8->addWidget(widget_7);

        verticalLayout_8->setStretch(0, 3);

        horizontalLayout_4->addWidget(frame_5);

        horizontalLayout_4->setStretch(0, 2);
        horizontalLayout_4->setStretch(1, 8);
        stackedWidget->addWidget(page_2);

        horizontalLayout_7->addWidget(stackedWidget);


        retranslateUi(Widget);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        clientButton->setText(QCoreApplication::translate("Widget", "\345\256\242\346\210\267\347\253\257", nullptr));
        serverButton->setText(QCoreApplication::translate("Widget", "\346\234\215\345\212\241\347\253\257", nullptr));
        toolButton_3->setText(QCoreApplication::translate("Widget", "\345\276\205\345\274\200\345\217\221", nullptr));
        toolButton_4->setText(QCoreApplication::translate("Widget", "\345\276\205\345\274\200\345\217\221", nullptr));
        toolButton_5->setText(QCoreApplication::translate("Widget", "\345\276\205\345\274\200\345\217\221", nullptr));
        toolButton_9->setText(QCoreApplication::translate("Widget", "\345\276\205\345\274\200\345\217\221", nullptr));
        toolButton_8->setText(QCoreApplication::translate("Widget", "\345\276\205\345\274\200\345\217\221", nullptr));
        toolButton_6->setText(QCoreApplication::translate("Widget", "\345\276\205\345\274\200\345\217\221", nullptr));
        toolButton_7->setText(QCoreApplication::translate("Widget", "\345\276\205\345\274\200\345\217\221", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\344\270\273\346\234\272IP\357\274\232", nullptr));
        clientIpEdit->setText(QCoreApplication::translate("Widget", "127.0.0.1", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\350\277\236\346\216\245\347\253\257\345\217\243\357\274\232", nullptr));
        clientPortEdit->setText(QCoreApplication::translate("Widget", "456", nullptr));
        requestButton->setText(QCoreApplication::translate("Widget", "\350\257\267\346\261\202\350\277\236\346\216\245", nullptr));
        toolButton_17->setText(QCoreApplication::translate("Widget", "...", nullptr));
        toolButton_18->setText(QCoreApplication::translate("Widget", "...", nullptr));
        toolButton_19->setText(QCoreApplication::translate("Widget", "...", nullptr));
        toolButton_20->setText(QCoreApplication::translate("Widget", "...", nullptr));
        toolButton_21->setText(QCoreApplication::translate("Widget", "...", nullptr));
        clientSendButton->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\346\234\254\346\234\272IP\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "\347\233\221\345\220\254\347\253\257\345\217\243\357\274\232", nullptr));
        serverPortEdit->setText(QCoreApplication::translate("Widget", "456", nullptr));
        monitorButton->setText(QCoreApplication::translate("Widget", "\345\274\200\345\247\213\347\233\221\345\220\254", nullptr));
        toolButton_23->setText(QCoreApplication::translate("Widget", "...", nullptr));
        toolButton_24->setText(QCoreApplication::translate("Widget", "...", nullptr));
        toolButton_25->setText(QCoreApplication::translate("Widget", "...", nullptr));
        toolButton_26->setText(QCoreApplication::translate("Widget", "...", nullptr));
        toolButton_27->setText(QCoreApplication::translate("Widget", "...", nullptr));
        serverSendButton->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WECHAT_H
