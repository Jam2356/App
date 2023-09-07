#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    qApp->installEventFilter(this);
}

Widget::~Widget()
{
    delete ui;
}

bool Widget::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type() == QEvent::Close && fCloseWC == 0)
    {
        emit closeWidgetClicked();
        fCloseWC = 1;
    }

    return QObject::eventFilter(watched, event);
}


void Widget::on_receive_clicked()
{
    emit connectClicked(QHostAddress::LocalHost, ui->spinPort->value());
}

void Widget::on_send_clicked()
{
    if(!ui->msg->text().isEmpty())
    {
        emit sendClicked(ui->msg->text().toUtf8());
        ui->msg->clear();
    }
}

void Widget::datagramToDisplay(QString datagram)
{
    ui->chat->addItem(datagram);
}

void Widget::connectUnavailable()
{
    ui->receive->setEnabled(false);
    ui->receive->setText("Connect");
}
