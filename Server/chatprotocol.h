#ifndef CHATPROTOCOL_H
#define CHATPROTOCOL_H

#include <QByteArray>
#include <QIODevice>
#include <QString>

class ChatProtocol
{
public:
    enum MessageType {
        Text,
        File,
        IsTyping,
        SetName,
        SetStatus
    };

    enum Status {
        None,
        Available,
        Away,
        Busy
    };

    ChatProtocol();

    QString message() const;
    QString name() const;
    ChatProtocol::Status status() const;
    ChatProtocol::MessageType type() const;
    QByteArray isTypingMessage();
    QByteArray loadData(QByteArray data);
    QByteArray textMessage(QString message);
    QByteArray setNameMessage(QString name);
    QByteArray setStatusMessage(Status status);

private:
    QByteArray getData(MessageType type, QString data);

private:
    QString _message;
    QString _name;
    MessageType _type;
    Status _status;

};

#endif // CHATPROTOCOL_H
