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

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private slots:
    void on_receive_clicked();
    void on_send_clicked();
    void datagramToDisplay(QString datagram);
    void connectUnavailable();


private:
    Ui::Widget *ui;
    int fCloseWC = 0; //Флаг что Close was clicked без этого eventFilter срабатывал дважды

signals:
    void connectClicked(QHostAddress, quint16);
    void sendClicked(QString msg);
    void closeWidgetClicked();
};
#endif // WIDGET_H
