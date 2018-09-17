#include "testservicehistory.h"
#include <QtTest>

void TestServiceHistory::init()
{
    service=new FakeServiceHistory();
}

void TestServiceHistory::readAll()
{
    QCOMPARE(service->readAll().size(), 1);
}

void TestServiceHistory::insertRow()
{
    QCOMPARE(service->insertRow("en","ru","Hello,World!","Привет,Мир!"), true);
}

void TestServiceHistory::deleteRow()
{
    QCOMPARE(service->deleteRow(-5), false);
}

void TestServiceHistory::deleteAll()
{
    QCOMPARE(service->deleteAll(), true);
}
