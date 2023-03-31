/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QSpinBox *spinPort;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *receive;
    QListWidget *chat;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *msg;
    QPushButton *send;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(300, 295);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label = new QLabel(Widget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        spinPort = new QSpinBox(Widget);
        spinPort->setObjectName("spinPort");
        spinPort->setMaximum(65000);
        spinPort->setValue(100);

        horizontalLayout->addWidget(spinPort);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 2);

        horizontalSpacer_3 = new QSpacerItem(193, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        receive = new QPushButton(Widget);
        receive->setObjectName("receive");

        gridLayout->addWidget(receive, 1, 1, 1, 1);

        chat = new QListWidget(Widget);
        chat->setObjectName("chat");

        gridLayout->addWidget(chat, 2, 0, 1, 2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        msg = new QLineEdit(Widget);
        msg->setObjectName("msg");

        horizontalLayout_3->addWidget(msg);

        send = new QPushButton(Widget);
        send->setObjectName("send");

        horizontalLayout_3->addWidget(send);


        gridLayout->addLayout(horizontalLayout_3, 3, 0, 1, 2);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "Port:", nullptr));
        receive->setText(QCoreApplication::translate("Widget", "Receive", nullptr));
        send->setText(QCoreApplication::translate("Widget", "Send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
