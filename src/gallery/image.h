#ifndef IMAGE_H
#define IMAGE_H

#include <QList>

#include "json/jsonserializable.h"
#include "json/jsonconverter.h"

class Image : public JsonSerializable
{
public:
    Image();

    Image(QString id, QString parentId);

    void write(QJsonObject &jsonObj) const;
    void read(const QJsonObject &jsonObj);

    QString getId() const;
    void setId(const QString &value);

    QString getParentId() const;
    void setParentId(const QString &value);

    QString getName() const;
    void setName(const QString &value);

    QString getAutor() const;
    void setAutor(const QString &value);

    QString getYear() const;
    void setYear(const QString &value);

    int getSize() const;
    void setSize(int value);

    QString getDescription() const;
    void setDescription(const QString &value);

private:
    QString id;
    QString parentId;
    QString name;
    QString autor;
    QString year;
    int size;
    QString description;
};

#endif // IMAGE_H
