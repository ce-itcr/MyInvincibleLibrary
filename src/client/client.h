#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>

class Client : public QObject
{
    Q_OBJECT

public:
    static Client *getInstance();

    Client *initHost(QString ip, QString port, QString path);

    void updateHost(QString ip, QString port);

    void GET(QString path, QNetworkRequest request = QNetworkRequest());

    void PUT(QString path, QString data, QNetworkRequest request = QNetworkRequest());

    void POST(QString path, QString data, QNetworkRequest request = QNetworkRequest());

    void DELETE(QString path, QNetworkRequest request = QNetworkRequest());

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
