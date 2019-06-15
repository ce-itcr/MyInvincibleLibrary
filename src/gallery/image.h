#ifndef IMAGE_H
#define IMAGE_H

#include <QList>

class Image
{
public:
    Image();

    Image(QString id, QString parentId);

    QString getId() const;
    void setId(const QString &value);

    QString getParentId() const;
    void setParentId(const QString &value);

private:
    QString id;
    QString parentId;
};

#endif // IMAGE_H
