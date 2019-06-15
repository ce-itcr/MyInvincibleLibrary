#ifndef JSONSERIALIZER_H
#define JSONSERIALIZER_H

#include "jsonserializable.h"

#include <QJsonObject>
#include <QJsonDocument>

class JsonSerializer
{
public:
    static QJsonObject serialize(const JsonSerializable &obj);

    static void parse(const QString &json, JsonSerializable &jsonSerializable);
};

#endif // JSONSERIALIZER_H
