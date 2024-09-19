#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H

#include <QObject>

#include <QTcpSocket>

#include "chatprotocol.h"

class ClientManager : public QObject
{
    Q_OBJECT
public:
    explicit ClientManager(QHostAddress ip = QHostAddress::LocalHost, ushort port = 4500, QObject *parent = nullptr);
    explicit ClientManager(QTcpSocket *client, QObject *parent = nullptr);

    QString name() const;
    void connectToServer();
    void sendIsTyping();
    void sendMessage(QString message);
    void sendName(QString name);
    void sendStatus(ChatProtocol::Status status);

signals:
    void connected();
    //void dataReceived(QByteArray data);
    void disconnected();
    void isTyping();
    void nameChanged(QString name);
    void statusChanged(ChatProtocol::Status status);
    void textMessageReceived(QString message);


private slots:
    void readyRead();

private:
    QHostAddress _ip;
    QTcpSocket *_socket;
    ChatProtocol _protocol;
    ushort _port;

private:
    void setupClient();
};

#endif // CLIENTMANAGER_H
