#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>

class Client : public QObject
{
    static Client *getInstance();

    void initHost(QString ip, QString port, QString path);

    void updateHost(QString ip, QString port);

    void GET(QString path, QNetworkRequest request);

    void PUT(QString path, QNetworkRequest request, QString data);

    void POST(QString path, QNetworkRequest request, QString data);

    void DELETE(QString path, QNetworkRequest request);

signals:
    void readyRead(QString data);

public slots:
    void replyFinished(QNetworkReply *reply);

private:
    static Client *instance;
    QNetworkAccessManager *manager;
    QString ip;
    QString port;
    QString path;
    QString defaultPath;

    Client();
};

#endif // CLIENT_H
