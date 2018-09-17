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

bool FakeServiceHistory::insertRow(QString langFrom, QString langTo, QString textFrom, QString textTo)
{
    if(langFrom.size()!=2) return false;
    if(langTo.size()!=2) return false;
    if(textFrom.isNull()) return false;
    if(textTo.isNull()) return false;
    return true;
}

ListElementhistory FakeServiceHistory::readAll()
{
    ListElementhistory list;
    ElementHistory el;
    el.setId(0);
    el.setLangF("en");
    el.setLangT("ru");
    el.setTextF("1");
    el.setTextT("Один");
    list.add(el);
    return list;
}
