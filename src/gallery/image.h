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

    QString getAuthor() const;
    void setAuthor(const QString &value);

    QString getDate() const;
    void setDate(const QString &value);

    QString getSize() const;
    void setSize(const QString &value);

    QString getDescription() const;
    void setDescription(const QString &value);

    QString getMetadata() const;
    void setMetadata(const QString &value);

    QString getData() const;
    void setData(const QString &value);

private:
    QString id;
    QString parentId;
    QString name;
    QString author;
    QString date;
    QString size;
    QString description;
    QString metadata;
    QString data;
};

#endif // IMAGE_H
