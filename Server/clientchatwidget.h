#ifndef CLIENTCHATWIDGET_H
#define CLIENTCHATWIDGET_H

#include <QWidget>

#include <QTcpSocket>

#include "clientmanager.h"

namespace Ui {
class ClientChatWidget;
}

class ClientChatWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ClientChatWidget(QTcpSocket *client, QWidget *parent = nullptr);
    ~ClientChatWidget();

signals:
    void clientNameChanged(QString name);
    void clientStatusChanged(ChatProtocol::Status status);
    void isTyping(QString message);

private slots:
    void clientDisconnected();
    void onTyping();
    void textMessageReceived(QString message);
    void on_btnSend_clicked();

private:
    ClientManager *_client;
    Ui::ClientChatWidget *ui;
};

#endif // CLIENTCHATWIDGET_H
