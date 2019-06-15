#ifndef FOLDER_H
#define FOLDER_H

#include <QList>
#include "image.h"

class Folder
{
public:
    Folder();

    Folder(QString id);

    QString getId() const;
    void setId(const QString &value);

    QList<Folder> getSubFolders() const;
    void setSubFolders(const QList<Folder> &value);

    QList<Image> getImages() const;
    void setImages(const QList<Image> &value);

private:
    QString id;
    QList<Folder> subFolders;
    QList<Image> images;
};

#endif // FOLDER_H
