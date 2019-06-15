#include "image.h"

Image::Image()
{
    id = "";
    parentId = "";
    name = "";
    autor = "";
    year = "";
    size = 0;
    description = "";
}

Image::Image(QString id, QString parentId)
{
    this->id = id;
    this->parentId = parentId;
    name = "";
    autor = "";
    year = "";
    size = 0;
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

QString Image::getAutor() const
{
    return autor;
}

void Image::setAutor(const QString &value)
{
    autor = value;
}

QString Image::getYear() const
{
    return year;
}

void Image::setYear(const QString &value)
{
    year = value;
}

int Image::getSize() const
{
    return size;
}

void Image::setSize(int value)
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
