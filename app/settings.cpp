#include "settings.h"
#include "ui_settings.h"

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
}

Settings::~Settings()
{
    delete ui;
}

void Settings::on_pushButton_clicked()
{
    QString ip = ui->ipEdit->toPlainText();
    QString port = ui->portEdit->toPlainText();
//    Client::getInstance()->loadHost(ip, port);
    close();
}
