#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "chatitemwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralwidget->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionConnect_triggered()
{
    _client = new ClientManager();

    connect(_client, &ClientManager::connected, [this](){
        ui->centralwidget->setEnabled(true);
    });
    connect(_client, &ClientManager::disconnected, [this](){
        ui->centralwidget->setEnabled(false);
    });
    connect(_client, &ClientManager::textMessageReceived, this, &MainWindow::dataReceived);
    connect(_client, &ClientManager::nameChanged, this, &MainWindow::setWindowTitle);
    connect(_client, &ClientManager::isTyping, this, &MainWindow::onTyping);
    connect(ui->lineMessage, &QLineEdit::textChanged, _client, &ClientManager::sendIsTyping);

    _client->connectToServer();
}

void MainWindow::dataReceived(QString message)
{
    auto chatWidget = new ChatItemWidget(this);
    chatWidget->setMessage(message);
    auto listWidgetItem = new QListWidgetItem();
    listWidgetItem->setSizeHint(QSize(0, 65));
    ui->listMessages->addItem(listWidgetItem);
    listWidgetItem->setBackground(QColor(167, 255, 237));
    ui->listMessages->setItemWidget(listWidgetItem, chatWidget);
}

void MainWindow::on_btnSend_clicked()
{
    auto message = ui->lineMessage->text().trimmed().toUtf8();
    _client->sendMessage(message);
    ui->lineMessage->setText("");

    auto chatWidget = new ChatItemWidget(this);
    chatWidget->setMessage(message, true);
    auto listWidgetItem = new QListWidgetItem();
    listWidgetItem->setSizeHint(QSize(0, 65));
    ui->listMessages->addItem(listWidgetItem);
    ui->listMessages->setItemWidget(listWidgetItem, chatWidget);
}

void MainWindow::on_actionDisconnect_triggered()
{
    _client->disconnect();
}

void MainWindow::on_lineClientName_editingFinished()
{
    auto name = ui->lineClientName->text().trimmed();
    _client->sendName(name);
}


void MainWindow::on_comboStatus_currentIndexChanged(int index)
{
    auto status = (ChatProtocol::Status)index;
    _client->sendStatus(status);
}

void MainWindow::onTyping()
{
    statusBar()->showMessage("Server is typing...", 750);
}
