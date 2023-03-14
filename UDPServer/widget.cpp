#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mSocket = new QUdpSocket(this);
    connect(mSocket, &QUdpSocket::readyRead, [&]() {
        if(mSocket->hasPendingDatagrams()){
        QHostAddress host;
        quint16 hostPort;
        QByteArray datagrama;
        datagrama.resize(mSocket->pendingDatagramSize());
        mSocket->readDatagram(datagrama.data(), datagrama.size(), &host, &hostPort);
        ui->listWidget->addItem(QString(datagrama));
        }
    });//теперь то окно, которое первое нажало receive то и получает сообщения, нажатие receive на втором окне не дает забиндить порт
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_send_clicked()
{
    auto datagrama1 = "Server: " + ui->msg->text().toLatin1();
    mSocket->writeDatagram(datagrama1, QHostAddress::LocalHost, ui->spinPort->value()+1); //Broadcast рассылка всем
}


void Widget::on_receive_clicked()
{
    mSocket->bind(ui->spinPort->value(), QUdpSocket::ShareAddress);
}

