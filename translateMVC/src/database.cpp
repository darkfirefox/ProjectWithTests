#include "database.h"

Database::Database()
{
    name="HistoryDB";
}

bool Database::init()
{
    path=QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir dir(path);
    db=QSqlDatabase::addDatabase("QSQLITE",name);
    const QString dbFileName(QLatin1String("HistoryDB.sqlite"));
    db.setDatabaseName(dir.absoluteFilePath(dbFileName));
    query=QSqlQuery(QSqlDatabase::database(name));
    return query.exec("CREATE TABLE IF NOT EXISTS historyTranslate (fromL varchar(2),fromT varchar(2),toL varchar(255), toT varchar(255))");
}

bool Database::insertRow(ElementHistory element)
{
    query.prepare("INSERT INTO historyTranslate  VALUES(?, ?, ?, ?)");
    query.addBindValue(element.getLangF());
    query.addBindValue(element.getLangT());
    query.addBindValue(element.getTextF());
    query.addBindValue(element.getTextT());
    return query.exec();
}

bool Database::deleteRow(const int id)
{

    query.prepare("delete from historyTranslate where rowid = ?");
    query.addBindValue(id);
    return query.exec();
}

bool Database::deleteAll()
{
    return query.exec("delete from historyTranslate");
}

ListRecords Database::readAll()
{
    query.exec("SELECT rowid,fromL,fromT,toL,toT FROM historyTranslate order by rowid desc");
    ListRecords list;
    while(query.next()){
        list.add(query.record());
    }
    return list;
}
