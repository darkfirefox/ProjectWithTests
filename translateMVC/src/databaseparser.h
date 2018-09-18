#ifndef DATABASEPARSER_H
#define DATABASEPARSER_H
#include <QSqlRecord>
#include <QVariant>
#include "elementhistory.h"
#include "listelementhistory.h"
#include "listrecords.h"
class DatabaseParser
{
public:
    DatabaseParser();
    ElementHistory fromRecord(const QSqlRecord &rec);
    ElementHistory fromStrings(QString langFrom,QString langTo,QString textFrom,QString textTo);
    ElementHistory fromStringList(QStringList list);
    ListElementhistory fromListRecords(ListRecords recs);

private:
    ElementHistory toElement(const QSqlRecord &rec);
};

#endif // DATABASEPARSER_H
