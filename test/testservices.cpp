#include "testservices.h"

void TestServices::init()
{
    services=&Services::Instance();
    services->setService(new FakeServiceHistory);
    services->setService(new FakeServiceHTTP);
    stream=&StreamData::Instance();
}

void TestServices::translate()
{
    QSignalSpy spy(services,SIGNAL(writeInputData(InputData)));
    services->transalate("en","ru","hi");
    Answer answer=stream->getAnswer();
    QCOMPARE(answer.getAnswer().size(),0);
    QCOMPARE(spy.count(),1);
}

void TestServices::deleteRow()
{
    QCOMPARE(services->deleteRow(-5),false);
    QCOMPARE(services->deleteRow(1),true);
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
