#ifndef FAKESERVICEHISTORY_H
#define FAKESERVICEHISTORY_H
#include "src/iservicehistory.h"
#include "src/listelementhistory.h"
#include "src/listrecords.h"
#include <QSqlRecord>

class FakeServiceHistory : public IServiceHistory
{
public:
    FakeServiceHistory();
    bool deleteAll();
    bool deleteRow(int id);
    bool insertRow(ElementHistory el);
    ListRecords readAll();
};

#endif // FAKESERVICEHISTORY_H
