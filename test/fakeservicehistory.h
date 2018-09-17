#ifndef FAKESERVICEHISTORY_H
#define FAKESERVICEHISTORY_H
#include "src/iservicehistory.h"
#include "src/listelementhistory.h"

class FakeServiceHistory : public IServiceHistory
{
public:
    FakeServiceHistory();
    bool deleteAll();
    bool deleteRow(int id);
    bool insertRow(QString langFrom,QString langTo,QString textFrom,QString textTo);
    ListElementhistory readAll();
};

#endif // FAKESERVICEHISTORY_H
