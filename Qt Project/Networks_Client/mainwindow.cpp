#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "qdebug.h"
#include "QString"

#include "Controllers/Session.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    Session::activeSession().networking().login(username.toUtf8().constData(),
                                                password.toUtf8().constData(), nullptr);
}
