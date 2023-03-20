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
        QHostAddress sender;
        quint16 senderPort;
        QByteArray datagrama;
        datagrama.resize(mSocket->pendingDatagramSize());
        mSocket->readDatagram(datagrama.data(), datagrama.size(), &sender, &senderPort);
        ui->listWidget->addItem(QString(datagrama));
        }
    });
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_receive_clicked()
{
    mSocket->bind(ui->spinPort->value()+1); // ui->spinPort->value()
}


void Widget::on_pushButton_clicked()
{
    QByteArray datagrama1 = "Client_1: " + ui->msg->text().toLocal8Bit();
    mSocket->writeDatagram(datagrama1, QHostAddress::LocalHost, ui->spinPort->value());
}

