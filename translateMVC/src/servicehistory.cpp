#include "servicehistory.h"

ServiceHistory::ServiceHistory(QObject *parent) : QObject(parent)
{
    db.init();
}

bool ServiceHistory::deleteAll()
{
    return db.deleteAll();
}

bool ServiceHistory::deleteRow(int id)
{
    return db.deleteRow(id);
}

bool ServiceHistory::insertRow(ElementHistory element)
{
    return db.insertRow(element);
}

ListRecords ServiceHistory::readAll()
{
    return db.readAll();;
}
