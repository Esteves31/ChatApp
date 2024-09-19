#ifndef CLIENTCHATWIDGET_H
#define CLIENTCHATWIDGET_H

#include <QWidget>
#include <QTcpSocket>

namespace Ui {
class ClientChatWidget;
}

class ClientChatWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ClientChatWidget(QTcpSocket *client, QWidget *parent = nullptr);
    ~ClientChatWidget();

private slots:
    void clientDisconnected();
    void dataReceived();
    void on_btnSend_clicked();

private:
    QTcpSocket *_client;
    Ui::ClientChatWidget *ui;
};

#endif // CLIENTCHATWIDGET_H
