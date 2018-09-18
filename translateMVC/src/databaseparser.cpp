#include "databaseparser.h"
#include <QDebug>

DatabaseParser::DatabaseParser()
{

}

ElementHistory DatabaseParser::fromRecord(const QSqlRecord &rec)
{
    return toElement(rec);
}

ElementHistory DatabaseParser::fromStrings(QString langFrom, QString langTo, QString textFrom, QString textTo)
{
    ElementHistory element;
    element.setLangF(langFrom);
    element.setLangT(langTo);
    element.setTextF(textFrom);
    element.setTextT(textTo);
    return element;
}

ElementHistory DatabaseParser::fromStringList(QStringList list)
{
    if(list.size()<4) return ElementHistory();
    ElementHistory element;
    element.setLangF(list.at(0));
    element.setLangT(list.at(1));
    element.setTextF(list.at(2));
    element.setTextT(list.at(3));
    return element;
}

ListElementhistory DatabaseParser::fromListRecords(ListRecords recs)
{
    ListElementhistory list;
    for(int i=0;i<recs.size();i++){
        list.add(toElement(recs.getAt(i)));
    }
    return list;
}

ElementHistory DatabaseParser::toElement(const QSqlRecord &rec)
{
    ElementHistory element;
    element.setId(rec.value(0).toInt());
    element.setLangF(rec.value(1).toString());
    element.setLangT(rec.value(2).toString());
    element.setTextF(rec.value(3).toString());
    element.setTextT(rec.value(4).toString());
    return element;
}

