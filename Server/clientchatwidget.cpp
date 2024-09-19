#include "clientchatwidget.h"
#include "ui_clientchatwidget.h"

ClientChatWidget::ClientChatWidget(QTcpSocket *client, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ClientChatWidget)
    , _client(client)
{
    ui->setupUi(this);

    connect(_client, &QTcpSocket::readyRead, this, &ClientChatWidget::dataReceived);
    connect(_client, &QTcpSocket::disconnected, this, &ClientChatWidget::clientDisconnected);
}

ClientChatWidget::~ClientChatWidget()
{
    delete ui;
}

void ClientChatWidget::clientDisconnected()
{
    ui->wdgSend->setEnabled(false);
}

void ClientChatWidget::dataReceived()
{
    auto data = _client->readAll();
    ui->listMessages->addItem(data);
}

void ClientChatWidget::on_btnSend_clicked()
{
    _client->write(ui->lineMessage->text().trimmed().toUtf8());
    ui->lineMessage->setText("");
}

