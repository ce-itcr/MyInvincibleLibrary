#ifndef CLIENTINTERFACE_H
#define CLIENTINTERFACE_H

#include "client.h"


class ClientInterface
{
public:
    static void getFolders(QString folderId);

    static void createFolders(QString folderId, QString jsonFolder);

    static void modifiedFolders(QString folderId, QString jsonFolder);

    static void deleteFolders(QString folderId);

private:
    static Client *client;
    static QString foldersPath;
};

#endif // CLIENTINTERFACE_H
