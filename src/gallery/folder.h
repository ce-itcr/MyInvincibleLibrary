#ifndef FOLDER_H
#define FOLDER_H

#include <QJsonObject>
#include <QList>

#include "image.h"
#include "json/jsonserializable.h"
#include "json/jsonconverter.h"

class Folder : public JsonSerializable
{
public:
    Folder();

    Folder(QString id);

    ~Folder();

    void write(QJsonObject &jsonObj) const;
    void read(const QJsonObject &jsonObj);

    QString getId() const;
    void setId(const QString &value);

    QList<Folder> getSubFolders() const;
    void setSubFolders(const QList<Folder> &value);

    QList<Image> getImages() const;
    void setImages(const QList<Image> &value);

private:
    QString id;
    QList<Folder *> subFolders;
    QList<Image *> images;
};

#endif // FOLDER_H
