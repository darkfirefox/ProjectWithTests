#ifndef DATABASEPARSER_H
#define DATABASEPARSER_H
#include <QSqlRecord>
#include <QVariant>
#include "src/elementhistory.h"
#include "src/listelementhistory.h"
#include "src/listrecords.h"
#include "answer.h"
#include "inputdata.h"
class DatabaseParser
{
public:
    DatabaseParser();
    ElementHistory fromRecord(const QSqlRecord &rec);
    ElementHistory fromStrings(QString langFrom,QString langTo,QString textFrom,QString textTo);
    ElementHistory fromStringList(QStringList list);
    ElementHistory fromData(InputData inputdata,Answer answer);
    ListElementhistory fromListRecords(ListRecords recs);

private:
    ElementHistory toElement(const QSqlRecord &rec);
};

#endif // DATABASEPARSER_H
