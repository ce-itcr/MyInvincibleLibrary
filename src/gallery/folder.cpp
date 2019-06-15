#include "folder.h"

Folder::Folder()
{
    id = "";
}

Folder::Folder(QString id)
{
    this->id = id;
}

QString Folder::getId() const
{
    return id;
}

void Folder::setId(const QString &value)
{
    id = value;
}

QList<Folder> Folder::getSubFolders() const
{
    return subFolders;
}

void Folder::setSubFolders(const QList<Folder> &value)
{
    subFolders = value;
}

QList<Image> Folder::getImages() const
{
    return images;
}

void Folder::setImages(const QList<Image> &value)
{
    images = value;
}
