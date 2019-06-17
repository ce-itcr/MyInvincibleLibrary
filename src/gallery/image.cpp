#include "image.h"

Image::Image()
{
    id = "";
    parentId = "";
    name = "";
    author = "";
    date = "";
    size = "";
    description = "";
}

Image::Image(QString id, QString parentId)
{
    this->id = id;
    this->parentId = parentId;
    name = "";
    author = "";
    date = "";
    size = "";
    description = "";
}

void Image::write(QJsonObject &jsonObj) const
{
    jsonObj["id"] = id;
    jsonObj["parentId"] = parentId;
}

void Image::read(const QJsonObject &jsonObj)
{
    id = jsonObj["id"].toString();
    parentId = jsonObj["parentId"].toString();
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

QString Image::getName() const
{
    return name;
}

void Image::setName(const QString &value)
{
    name = value;
}

QString Image::getAuthor() const
{
    return author;
}

void Image::setAuthor(const QString &value)
{
    author = value;
}

QString Image::getDate() const
{
    return date;
}

void Image::setDate(const QString &value)
{
    date = value;
}

QString Image::getSize() const
{
    return size;
}

void Image::setSize(const QString &value)
{
    size = value;
}

QString Image::getDescription() const
{
    return description;
}

void Image::setDescription(const QString &value)
{
    description = value;
}
