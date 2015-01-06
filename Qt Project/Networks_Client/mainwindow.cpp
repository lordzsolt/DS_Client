#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "qdebug.h"
#include "QString"

#include "Controllers/Session.h"

using namespace std;

Q_DECLARE_METATYPE(shared_ptr<LoginMessage>)

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(this, &MainWindow::message_Received,
            this, &MainWindow::update_UI);
    qRegisterMetaType<shared_ptr<LoginMessage> >("std::shared_ptr<LoginMessage>");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    NetworkingCallback lamdaCallback = [this] (bool success) {
        emit message_Received(nullptr);
    };

    Session::activeSession().networking().login(username.toUtf8().constData(),
                                                password.toUtf8().constData(),
                                                lamdaCallback);
}

void MainWindow::update_UI(shared_ptr<LoginMessage> message)
{
    qDebug() << "I fkin got here!";
}
