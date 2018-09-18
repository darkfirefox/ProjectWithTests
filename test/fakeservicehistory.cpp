#include "fakeservicehistory.h"

FakeServiceHistory::FakeServiceHistory()
{

}

bool FakeServiceHistory::deleteAll()
{
    return true;
}

bool FakeServiceHistory::deleteRow(int id)
{
    if(id<0) return false;
    return true;
}

ListRecords FakeServiceHistory::readAll()
{
    QSqlRecord rec;
    ListRecords lr;
    lr.add(rec);
    return lr;
}

bool FakeServiceHistory::insertRow(ElementHistory el)
{
    if(el.getLangF().size()!=2) return false;
    if(el.getLangT().size()!=2) return false;
    if(el.getTextF().isNull()) return false;
    if(el.getTextT().isNull()) return false;
    return true;
}
