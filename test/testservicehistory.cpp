#include "testservicehistory.h"
#include <QtTest/QtTest>

void TestServiceHistory::init()
{
    service=&ServiceHistory::Instance();
}
