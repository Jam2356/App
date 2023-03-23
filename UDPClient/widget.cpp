#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_receive_clicked()
{
    emit receiveClicked(QHostAddress::LocalHost);
}

void Widget::on_send_clicked()
{
    if(!ui->msg->text().isEmpty())
    {
        emit sendClicked(ui->msg->text().toUtf8(), QHostAddress::LocalHost, ui->spinPort->value());
        ui->msg->clear();
    }
}

void Widget::datagramToDisplay(QString datagram)
{
    ui->chat->addItem(datagram);
}

