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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QSpinBox *spinPort;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *receive;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *msg;
    QPushButton *pushButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(300, 295);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setObjectName("verticalLayout");
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

        horizontalLayout->addWidget(spinPort);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        receive = new QPushButton(Widget);
        receive->setObjectName("receive");

        horizontalLayout_2->addWidget(receive);


        verticalLayout->addLayout(horizontalLayout_2);

        listWidget = new QListWidget(Widget);
        listWidget->setObjectName("listWidget");

        verticalLayout->addWidget(listWidget);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        msg = new QLineEdit(Widget);
        msg->setObjectName("msg");

        horizontalLayout_3->addWidget(msg);

        pushButton = new QPushButton(Widget);
        pushButton->setObjectName("pushButton");

        horizontalLayout_3->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "Port:", nullptr));
        receive->setText(QCoreApplication::translate("Widget", "Receive", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "Send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
