#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
//    mSocket = new QUdpSocket(this);
//    connect(mSocket, &QUdpSocket::readyRead, [&]() {
//        if(mSocket->hasPendingDatagrams()){
//        QHostAddress host;
//        quint16 hostPort;
//        QByteArray datagrama;
//        datagrama.resize(mSocket->pendingDatagramSize());
//        mSocket->readDatagram(datagrama.data(), datagrama.size(), &host, &hostPort);
//        ui->listWidget->addItem(QString(datagrama));
//        }
//    });
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_send_clicked()
{
//  auto datagrama1 = "Server: " + ui->msg->text().toLatin1();
//  mSocket->writeDatagram(datagrama1, QHostAddress::LocalHost, ui->spinPort->value()+1); //Broadcast рассылка всем
}


void Widget::on_receive_clicked() //при нажатии кнопки receive отправляем порт на сервер и там происходит bind
{
    emit receiveClicked(QHostAddress::LocalHost, ui->spinPort->value());
    //mSocket->bind(ui->spinPort->value(), QUdpSocket::ShareAddress);
}
//получаем датаграмму из сокета c помощью datagramToInterface в слот datagramToDisplay и выводим ее в chat
void Widget::datagramToDisplay(QString datagram)
{
    ui->chat->addItem(datagram);
}
