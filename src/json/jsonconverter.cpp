#include "jsonconverter.h"

QString JsonConverter::qListToJson(QList<JsonSerializable *> serializableList)
{
    QJsonArray jsonArray;
    for(JsonSerializable *serializableObj : serializableList)
    {
        QJsonObject value = JsonSerializer::serialize(*serializableObj);
        jsonArray.push_back(value);
    }
    QJsonDocument doc(jsonArray);
    QString data = doc.toJson(QJsonDocument::Compact);
    return data;
}


template<class T>
QList<T *> JsonConverter::jsonToQList(QString json)
{
    QList<T *> *list = new QList<T *>();
   QJsonArray jsonArray = stringToJsonArray(json);
   for(QJsonValue jsonValue : jsonArray)
   {
       T *obj = new T();
       QJsonDocument doc(jsonValue.toObject());
       QString strJson(doc.toJson(QJsonDocument::Compact));
       JsonSerializer::parse(strJson, *obj);
       list->push_back(obj);
   }
   return list;
}

QJsonArray JsonConverter::stringToJsonArray(const QString &data)
{
    QJsonArray array;
    QJsonDocument doc = QJsonDocument::fromJson(data.toUtf8());

    if(!doc.isNull())
    {
        if(doc.isArray()) array = doc.array();
        else qDebug() << "Document is not an object";
    }
    else qDebug() << "Invalid JSON...\n" << data;

    return array;
}
