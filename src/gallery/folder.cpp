#include "folder.h"

Folder::Folder()
{
    id = "";
}

Folder::Folder(QString id)
{
    this->id = id;
}

Folder::~Folder()
{
    for (Folder *folder : subFolders) delete folder;
    for (Image *image : images) delete image;
}

void Folder::write(QJsonObject &jsonObj) const
{
    //QString jsonSubFolders = JsonConverter::qListToJson(subFolders);
    //QString jsonImages = JsonConverter::qListToJson(images);

    jsonObj["id"] = id;
    //jsonObj["subFolders"] = jsonSubFolders;
    //jsonObj["images"] = jsonImages;
}

void Folder::read(const QJsonObject &jsonObj)
{
    QString jsonSubFolders = jsonObj["subFolders"].toString();
    QString jsonImages = jsonObj["images"].toString();

    id = jsonObj["id"].toString();
    subFolders = JsonConverter::jsonToQList<Folder *>(jsonSubFolders);
    images = JsonConverter::jsonToQList<Image *>(jsonImages);
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
