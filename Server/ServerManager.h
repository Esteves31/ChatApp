#ifndef SERVERMANAGER_H
#define SERVERMANAGER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class ServerManager : public QObject
{
    Q_OBJECT
public:
    explicit ServerManager(ushort port = 4500, QObject *parent = nullptr);


signals:
    void newClientConnected(QTcpSocket *client);
    void clientDisconnected(QTcpSocket *client);

private slots:
    void newClientConnectionReceived();
    void onClientDisconnected();

private: // fields
    QList<QTcpSocket *> _clients;
    QTcpServer *_server;

private: // methods
    void setupServer(ushort port);
};

#endif // SERVERMANAGER_H
