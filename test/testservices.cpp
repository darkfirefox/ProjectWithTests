#include "testservices.h"

void TestServices::init()
{
    services=&ServicesT::Instance();
    stream=&StreamData::Instance();
}

void TestServices::translate()
{
    QSignalSpy spy(services,SIGNAL(addedAnswer()));
    services->transalate("en","ru","hi");
    QStringList streamList=stream->readAll();
    QCOMPARE(streamList.size(),4);
    QCOMPARE(spy.count(),1);
}

void TestServices::deleteRow()
{
    QCOMPARE(services->deleteRow(-5),false);
    (services->deleteRow(1),true);
}

void TestServices::deleteAll()
{
    QCOMPARE(services->deleteAll(),true);
}

void TestServices::readAll()
{
    ListElementhistory lr=services->readAll();
    QVERIFY(lr.size()>0);
}
