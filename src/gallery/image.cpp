#include "image.h"

Image::Image()
{
    id = "";
    parentId = "";
}

Image::Image(QString id, QString parentId)
{
    this->id = id;
    this->parentId = parentId;
}

QString Image::getId() const
{
    return id;
}

void Image::setId(const QString &value)
{
    id = value;
}

QString Image::getParentId() const
{
    return parentId;
}

void Image::setParentId(const QString &value)
{
    parentId = value;
}
