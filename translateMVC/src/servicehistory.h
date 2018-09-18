#ifndef SERVICEHISTORY_H
#define SERVICEHISTORY_H
#include "database.h"
#include "elementhistory.h"
#include "listelementhistory.h"
#include "listrecords.h"
#include "iservicehistory.h"

class ServiceHistory:public QObject,public IServiceHistory
{
    Q_OBJECT
public:
    explicit ServiceHistory(QObject *parent = nullptr);
    bool deleteAll();
    bool deleteRow(int id);
    bool insertRow(ElementHistory element);
    ListRecords readAll();
private:
    Database db;
};

#endif // SERVICEHISTORY_H
