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

void Widget::on_send_clicked()
{
    if(!ui->msg->text().isEmpty())
    {
        emit sendClicked(ui->msg->text().toUtf8(), QHostAddress::LocalHost);
        ui->msg->clear();
    }
}

//получаем датаграмму из сокета c помощью datagramToInterface в слот datagramToDisplay и выводим ее в chat
void Widget::datagramToDisplay(QString datagram)
{
    ui->chat->addItem(datagram);
}


