#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <memory>

#include "Models/MessageModels/Messages/LoginMessage.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void message_Received(std::shared_ptr<LoginMessage> message);

private slots:
    void on_pushButton_login_clicked();
    void update_UI(std::shared_ptr<LoginMessage> message);

private:
    void messageReceived(bool success);

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
