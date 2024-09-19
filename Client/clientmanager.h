#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H

#include <QObject>

#include <QTcpSocket>

class ClientManager : public QObject
{
    Q_OBJECT
public:
    explicit ClientManager(QHostAddress ip = QHostAddress::LocalHost, ushort port = 4500, QObject *parent = nullptr);

    void connectToServer();
    void sendMessage(QString message);

signals:
    void connected();
    void dataReceived(QByteArray data);
    void disconnected();

private slots:
    void readyRead();

private:
    QHostAddress _ip;
    QTcpSocket *_socket;
    ushort _port;
};

#endif // CLIENTMANAGER_H
