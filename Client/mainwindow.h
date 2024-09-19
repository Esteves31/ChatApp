#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "clientmanager.h"

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
    void dataReceived(QString message);
    void onTyping();
    void on_actionConnect_triggered();
    void on_actionDisconnect_triggered();
    void on_btnSend_clicked();
    void on_lineClientName_editingFinished();
    void on_comboStatus_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    ClientManager *_client;
};
#endif // MAINWINDOW_H
