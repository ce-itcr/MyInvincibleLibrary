#include "client.h"

void Client::initHost(QString ip, QString port, QString path)
{
    defaultPath = path;
    updateHost(ip, port);
}

void Client::updateHost(QString ip, QString port)
{
    path = "http://" + ip + ":" + port + defaultPath;
}

void Client::GET(QString path, QNetworkRequest request)
{
    QUrl url(Client::path + path);
    request.setUrl(url);

    qDebug() << "Client GET request to: " << url.toString();
    manager->get(request);

    QObject::connect(manager, &QNetworkAccessManager::finished, this, &Client::replyFinished);
}

void Client::PUT(QString path, QNetworkRequest request, QString data)
{
    QUrl url(Client::path + path);
    request.setUrl(url);

    qDebug() << "Client PUT request to: " << url.toString();
    manager->put(request, data.toUtf8());

    QObject::connect(manager, &QNetworkAccessManager::finished, this, &Client::replyFinished);
}

void Client::POST(QString path, QNetworkRequest request, QString data)
{
    QUrl url(Client::path + path);
    request.setUrl(url);

    qDebug() << "Client POST request to: " << url.toString();
    manager->post(request, data.toUtf8());

    QObject::connect(manager, &QNetworkAccessManager::finished, this, &Client::replyFinished);
}

void Client::DELETE(QString path, QNetworkRequest request)
{
    QUrl url(Client::path + path);
    request.setUrl(url);

    qDebug() << "Client DELETE request to: " << url.toString();
    manager->deleteResource(request);

    QObject::connect(manager, &QNetworkAccessManager::finished, this, &Client::replyFinished);
}

void Client::replyFinished(QNetworkReply *reply)
{
    QString message = reply->readAll();
    int status = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    qDebug() << "Reply finished with status code: " << status;

    if (message != "") readyRead(message);
}

Client::Client()
{
    manager = new QNetworkAccessManager();
}
