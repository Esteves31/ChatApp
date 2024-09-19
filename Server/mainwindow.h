#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QTcpSocket>

#include "chatprotocol.h"
#include "ServerManager.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void newClientConnected(QTcpSocket *client);
    void clientDisconneted(QTcpSocket *client);
    void setClientName(QString name);
    void setClientStatus(ChatProtocol::Status status);

private:
    ServerManager *_server;
    Ui::MainWindow *ui;

private: // methods
    void setupServer();

};
#endif // MAINWINDOW_H
