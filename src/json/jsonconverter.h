#ifndef JSONCONVERTER_H
#define JSONCONVERTER_H

#include <QDebug>
#include <QList>
#include <QJsonArray>
#include <QJsonDocument>

#include "jsonserializer.h"

class JsonConverter
{
public:
    static QString qListToJson(QList<JsonSerializable *> serializableList);

    template<class T>
    static QList<T *> jsonToQList(QString json);

private:
    static QJsonArray stringToJsonArray(const QString &data);
};

#endif // JSONCONVERTER_H
