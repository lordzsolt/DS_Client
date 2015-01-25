#include "LoginWindow.h"
#include "ui_mainwindow.h"

#include "qdebug.h"
#include "QString"

#include "../Controllers/ApplicationController.h"
#include "../Controllers/NetworkingControllers/Networking.h"

using namespace std;

Q_DECLARE_METATYPE(shared_ptr<LoginMessage>)

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(this, &LoginWindow::message_Received,
            this, &LoginWindow::update_UI);
    qRegisterMetaType<shared_ptr<LoginMessage> >("std::shared_ptr<LoginMessage>");
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    NetworkingCallback lamdaCallback = [this] (bool success) {
        emit message_Received(nullptr);
    };

    ApplicationController::currentApplication().networking().login(username.toUtf8().constData(),
                                                                   password.toUtf8().constData(),
                                                                   nullptr);
}

void LoginWindow::update_UI(shared_ptr<LoginMessage> message)
{
}
