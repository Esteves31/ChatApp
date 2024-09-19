#include "chatitemwidget.h"
#include "ui_chatitemwidget.h"

ChatItemWidget::ChatItemWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChatItemWidget)
{
    ui->setupUi(this);
}

ChatItemWidget::~ChatItemWidget()
{
    delete ui;
}

void ChatItemWidget::setMessage(QString message, bool isMyMessage)
{
    if (isMyMessage)
        ui->labelMessage->setAlignment(Qt::AlignRight);
    else
        ui->labelMessage->setAlignment(Qt::AlignLeft);

    ui->labelMessage->setText(message);
    ui->labelTime->setText(QDateTime::currentDateTime().toString("HH:mm"));
}
