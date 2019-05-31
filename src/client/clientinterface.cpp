#include "clientinterface.h"

Client *ClientInterface::client = Client::getInstance()->initHost("localHost", "9080", "MyIncibleLibrary_war_exploded");
QString ClientInterface::foldersPath = "/folders/";

void ClientInterface::getFolders(QString folderId)
{
    QString path = foldersPath + folderId;
    client->GET(path);

    //QObject::connect(client, &Client::readyRead, receiver, &Receiver::slot);
}

void ClientInterface::createFolders(QString folderId, QString jsonFolder)
{
    QString path = foldersPath + folderId;
    QNetworkRequest request;
    client->PUT(path, jsonFolder);

    //QObject::connect(client, &Client::readyRead, receiver, &Receiver::slot);
}

void ClientInterface::modifiedFolders(QString folderId, QString jsonFolder)
{
    QString path = foldersPath + folderId;
    client->POST(path, jsonFolder);

    //QObject::connect(client, &Client::readyRead, receiver, &Receiver::slot);
}

void ClientInterface::deleteFolders(QString folderId)
{
    QString path = foldersPath + folderId;
    client->DELETE(path);

    //QObject::connect(client, &Client::readyRead, receiver, &Receiver::slot);
}
