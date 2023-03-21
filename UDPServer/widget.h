#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QHostAddress>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_send_clicked();
    void on_receive_clicked();
    void datagramToDisplay(QString datagram);
    void on_endReceive_clicked();

private:
    Ui::Widget *ui;

signals:
    void receiveClicked(QHostAddress, quint16 port);
    void endReceiveClicked();
    void sendClicked(QString msg, QHostAddress, quint16 port);
};
#endif // WIDGET_H
